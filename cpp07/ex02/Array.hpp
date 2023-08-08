#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <cstddef>


template< typename T>
class Array 
{
private:
	T* 				_array;
	unsigned int	_size;

public: 
	// constructeurs et destructeur
	Array<T>():_array(new T()), _size(0) {}
	Array<T>(unsigned int n): _array(new T[n]), _size(n) {}
	Array<T>(Array<T> const & src) { *this = src; }
	~Array<T>() { delete [] this->_array; }

	// surcharge d'operateur =
	Array<T> & operator=(Array<T> const & src) {
		if (this != &src) {
			delete [] this->array;
			this->_size = src->_size;
			this->_array = new T[src._size];
			for (unsigned int i = 0; i < src._size; i++)
				this->_array[i] = src._array[i];
			return *this;
		}
	}

	// surcharge d'operateur []
	T & operator[](unsigned int i) const {
		if (i > this->_size - 1)
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
}

template<typename T>
std::ostream & operator<<(std::ostream & out, T const & array)
{
	for (unsigned int i = 0; i < array.size(); i++)
	{
		out << array[i];
		if (i < array.size() - 1)
			out << ", ";
		else
			out << std::endl;
	}
	return out;
}


#endif