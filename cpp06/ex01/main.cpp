#include "Serializer.hpp"

void print_data_info(Data *data)
{
	if (data)
	{
		std::cout << "Pointer: " << data << std::endl;
		std::cout << "Name: " << data->name << std::endl;
		std::cout << "Age: " << data->age << std::endl;
		std::cout << "Nationality: " << data->nationality << std::endl;
	}
}

int main()
{
	Data *originalData = new Data;
	uintptr_t	serializedData;
	Data*		deserializedData;

	originalData->name = "Jean";
	originalData->age = 50;
	originalData->nationality = "French";

	serializedData = Serializer::serialize(originalData);
	deserializedData = Serializer::deserialize(serializedData);

	std::cout << "#1 Original Data Info" << std::endl;
	print_data_info(originalData);
	std::cout << std::endl << "#2 Deserialized Data Info" << std::endl;
	print_data_info(deserializedData);

	delete originalData;

}