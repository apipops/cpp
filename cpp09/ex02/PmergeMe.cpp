#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **av)
{
	PmergeMe::_parseList(av);
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
	this->_vector = src._vector;
	this->_deque = src._deque;
	this->_valid = src._valid;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void 	PmergeMe::execute()
{
	clock_t start, end;
	double	vector, deque;

	// Check parsing
	if (!this->_valid)
		return;

	// Show list before sorting
	std::cout << "Before: ";
	PmergeMe::_display();
	
	// Chrono init and vector sorting
	start = clock();
	PmergeMe::_sortVector(0, this->_vector.size() - 1);
	end = clock();
	vector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	// Chrono init and deque sorting
	start = clock();
	PmergeMe::_sortDeque(0, this->_deque.size() - 1);
	end = clock();
	deque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	// Show list after sorting
	std::cout << "After: ";
	PmergeMe::_display();

	// Show times to process
	std::cout << "Time to process a range of " << this->size() << " elements with std::vector : "<< vector << " us" << std::endl;
	std::cout << "Time to process a range of " << this->size() << " elements with std::deque : "<< deque << " us" << std::endl;
}

unsigned int PmergeMe::size() const
{
	return this->_deque.size();
}


/*------------------------------------------------------------PARSING & UTILS------------------------------------------------------------*/

void	PmergeMe::_parseList(char **av)
{
	int 				i = 1;
	std::string			token;

	while (av[i])
	{
		token = av[i];
		if (!token.empty() && PmergeMe::_isDigitStr(token)) {
			unsigned int value = std::atoi(av[i]);
			this->_vector.push_back(value);
			this->_deque.push_back(value);
		}
		else if (!token.empty()) {
			std::cout << "Error" << std::endl;
			this->_valid = false;
			return ;
		}
		i++;
	}
	if (PmergeMe::_isSorted()) {
		std::cout << "Error: already sorted" << std::endl;
		this->_valid = false;
	}
	else if (PmergeMe::_hasDuplicates()) {
		std::cout << "Error: duplicates found" << std::endl;
		this->_valid = false;
	}
	else 
		this->_valid = true;
}

bool PmergeMe::_isDigitStr(std::string & str) const
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (!std::isdigit(*it))
			return false;
	}
	return true;
}

bool PmergeMe::_isSorted() const
{
	if (this->size() == 1)
		return true;

	std::vector<unsigned int>::const_iterator it;
	unsigned int val = *(this->_vector.begin());

	for (it = this->_vector.begin() + 1; it != this->_vector.end(); it++) {
		if (*it <= val)
			return false;
		val = *it;
	}
	return true;
}

bool PmergeMe::_hasDuplicates() const
{
	std::vector<unsigned int>::const_iterator it1, it2;

	for (it1 = this->_vector.begin(); it1 != this->_vector.end(); it1++) {
		for (it2 = it1 + 1; it2 != this->_vector.end(); it2++) {
			if (*it1 == *it2)
				return true;
		}
	}
	return false;
}

void PmergeMe::_display() const 
{
	std::vector<unsigned int>::const_iterator it;
	for (it = this->_vector.begin(); it != this->_vector.end(); it++) {
		std::cout << *it;
		if (it < this->_vector.end() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

/*------------------------------------------------------------VECTORS------------------------------------------------------------*/

void 	PmergeMe::_sortVector(int begin, int end)
{
    if (end - begin < K)
        PmergeMe::_insertSortVector(begin, end); // Insertion sort vectors below 10 elements
	else {
		int mid = begin + (end - begin) / 2; // Divide in sub-groups
		PmergeMe::_sortVector(begin, mid); // Recursively sort the sub-groups
		PmergeMe::_sortVector(mid + 1, end);
		PmergeMe::_mergeSortVector(begin, mid, end); // Merge sorted sub-groups
	}
}

void	PmergeMe::_insertSortVector(int begin, int end)
{
    int i, j;
	unsigned int value;

	// Check all elements and register the value from the second element
    for (i = begin; i < end; i++) {
        value = this->_vector[i + 1];
        j = i + 1;
 
		// Compare the value with all the previous ones
		// If the value is smaller, move value until it is at the right place
        while (j > begin && this->_vector[j - 1] > value) {
            this->_vector[j] = this->_vector[j - 1];
            j--;
        }
        this->_vector[j] = value; 
    }
}

void 	PmergeMe::_mergeSortVector(int begin, int mid, int end)
{
	int i, j, k;
    int size1 = mid - begin + 1;
    int size2 = end - mid;
	std::vector<unsigned int> vector1(size1);
	std::vector<unsigned int> vector2(size2);
 
    // Copy data to temporary vectors
    for (i = 0; i < size1; i++) {
        vector1[i] = this->_vector[begin + i]; }
    for (j = 0; j < size2; j++) {
        vector2[j] = this->_vector[mid + 1 + j]; }

    // Merge the temp vectors back into _vector
	i = 0;
	j = 0;
	k = begin;
    while (i < size1 && j < size2) // Check the temp vectors
	{
        if (vector1[i] <= vector2[j]) {
            this->_vector[k] = vector1[i];
            i++;
        }
        else {
            this->_vector[k] = vector2[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of vector1 if there is any
    while (i < size1) {
        this->_vector[k] = vector1[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of vector2 if there is any
    while (j < size2) {
        this->_vector[k] = vector2[j];
        j++;
        k++;
    }
}

/*------------------------------------------------------------DEQUE------------------------------------------------------------*/

void 	PmergeMe::_sortDeque(int begin, int end)
{
    if (end - begin < K)
        PmergeMe::_insertSortDeque(begin, end); // Insertion sort deques below 10 elements
	else {
		int mid = begin + (end - begin) / 2; // Divide in sub-groups
		PmergeMe::_sortDeque(begin, mid); // Recursively sort the sub-groups
		PmergeMe::_sortDeque(mid + 1, end);
		PmergeMe::_mergeSortDeque(begin, mid, end); // Merge sorted sub-groups
	}
}

void	PmergeMe::_insertSortDeque(int begin, int end)
{
    int i, j;
	unsigned int value;

	// Check all elements and register the value from the second element
    for (i = begin; i < end; i++) {
        value = this->_deque[i + 1];
        j = i + 1;
 
		// Compare the value with all the previous ones
		// If the value is smaller, move value until it is at the right place
        while (j > begin && this->_deque[j - 1] > value) {
            this->_deque[j] = this->_deque[j - 1];
            j--;
        }
        this->_deque[j] = value; 
    }
}

void 	PmergeMe::_mergeSortDeque(int begin, int mid, int end)
{
	int i, j, k;
    int size1 = mid - begin + 1;
    int size2 = end - mid;
	std::deque<unsigned int> deque1(size1);
	std::deque<unsigned int> deque2(size2);
 
    // Copy data to temporary deques
    for (i = 0; i < size1; i++) {
        deque1[i] = this->_deque[begin + i]; }
    for (j = 0; j < size2; j++) {
        deque2[j] = this->_deque[mid + 1 + j]; }

    // Merge the temp deques back into _deque
	i = 0;
	j = 0;
	k = begin;
    while (i < size1 && j < size2) // Check the temp deques
	{
        if (deque1[i] <= deque2[j]) {
            this->_deque[k] = deque1[i];
            i++;
        }
        else {
            this->_deque[k] = deque2[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of deque1 if there is any
    while (i < size1) {
        this->_deque[k] = deque1[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of deque2 if there is any
    while (j < size2) {
        this->_deque[k] = deque2[j];
        j++;
        k++;
    }
}
