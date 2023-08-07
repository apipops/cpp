#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t tmp;
	
	tmp = reinterpret_cast<uintptr_t>(ptr);
	return tmp;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* tmp;
	
	tmp = reinterpret_cast<Data *>(raw);
	return tmp;
}