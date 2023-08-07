#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>
# include <iostream>
# include "data.hpp"

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	// 'static' : pas besoin d'être instancié

private:
	Serializer();
	Serializer(Serializer const & src);
	Serializer & operator=(Serializer const & src);
	~Serializer();
	// classe statique : ne peut être instanciée
};

#endif