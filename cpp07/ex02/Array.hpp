#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <cstddef>
# include <cstdlib>


template< typename T>
class Array 
{
private:
	T* 				_array;
	unsigned int	_size;

public: 
	// constructeurs et destructeur
	Array<T>():_array(new T[0]), _size(0) {}
	Array<T>(unsigned int n): _array(new T[n]), _size(n) {}
	Array<T>(Array<T> const & src) {
		this->_size = src._size;
		this->_array = new T[src._size];
		for (unsigned int i = 0; i < src._size; i++)
			this->_array[i] = src._array[i]; }
	~Array<T>() {delete [] this->_array; }

	// surcharge d'operateur =
	Array<T> & operator=(Array<T> const & src) {
		if (this != &src) {
			delete [] this->_array;
			this->_size = src._size;
			this->_array = new T[src._size];
			for (unsigned int i = 0; i < src._size; i++)
				this->_array[i] = src._array[i];
		}
		return *this;
	}

	// surcharge d'operateur []
	T & operator[](int i) const {
		if (i < 0 || i >= static_cast<int>(this->_size))
			throw Array::OutOfRangeException();
		else
			return (this->_array[i]);
	}

	// size()
	unsigned int size() const {
		return (this->_size);
	}

	// exception
	class OutOfRangeException : public std::exception {
		public :
			virtual const char* what() const throw() { return "Index is out of range!";}
	};
};

template<typename T>
std::ostream & operator<<(std::ostream & out, const Array<T>& array)
{
	for (unsigned int i = 0; i < array.size(); i++)
	{
		out << array[i];
 		if (i < array.size() - 1)
			out << ", ";
	}
	return out;
}


#endif