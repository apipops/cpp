#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::string list)
{
	PmergeMe::_parseList(list);
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
	this->_vector = src._vector;
	this->_deque = src._deque;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void 	PmergeMe::execute()
{
	std::cout << "Before<vector>: ";
	PmergeMe::_display();
	PmergeMe::_sortVector(0, this->_vector.size() - 1);
	std::cout << "After<vector>: ";
	PmergeMe::_display();

	std::cout << "Before<deque>: ";
	PmergeMe::_displayDeque();
	PmergeMe::_sortDeque(0, this->_deque.size() - 1);
	std::cout << "After<deque>: ";
	PmergeMe::_displayDeque();
	// afficher la liste avant
	// initialisation du chrono
	// tri pour vector + calcul temps
	// tri pour list + calcul temps
	// affichier liste apres
	// afficher le temps pour vector
	// afficher le temps pour list
}


/*------------------------------------------------------------PARSING & UTILS------------------------------------------------------------*/

void	PmergeMe::_parseList(std::string & list)
{
	std::stringstream	ss(list);
	std::string			token;

	while (std::getline(ss, token, ' '))
	{
		if (!token.empty() && PmergeMe::_isDigitStr(token)) {
			int value = std::atoi(token.c_str());
			this->_vector.push_back(value);
			this->_deque.push_back(value);
		}
		else if (!token.empty()) {
			std::cout << "Error" << std::endl;
			return ;
		}
	}
}

bool PmergeMe::_isDigitStr(std::string & str) const
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (!std::isdigit(*it))
			return false;
	}
	return true;
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

void PmergeMe::_displayDeque() const 
{
	std::deque<unsigned int>::const_iterator it;
	for (it = this->_deque.begin(); it != this->_deque.end(); it++) {
		std::cout << *it;
		if (it < this->_deque.end() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

/*------------------------------------------------------------VECTORS------------------------------------------------------------*/

void 	PmergeMe::_sortVector(int begin, int end)
{
    if (end - begin < 10)
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
    if (end - begin < 10)
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