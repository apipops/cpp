#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input)
{
    int i = ScalarConverter::_findType(input);
    if (i == EMPTY)
        std::cout << "Error: empty string." << std::endl;
    else if (i == WRONG)
        std::cout << "Error: invalid input." << std::endl;
    else if (i == CHAR)
        ScalarConverter::_convertChar(input);
    else if (i == INT)
        ScalarConverter::_convertInt(input);
    else if (i == FLOAT)
        ScalarConverter::_convertFloat(input);
    else if (i == DOUBLE)
        ScalarConverter::_convertDouble(input);
    else if (i == SPECIAL)
        ScalarConverter::_convertSpecial(input);
} 
    // Cannot use pointers to static member functions because
    // C++ does not register the address of a static member function

bool ScalarConverter::_isChar(std::string input)
{
    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
        return true;
    return false;
}

bool ScalarConverter::_isInt(std::string input)
{
    if ((input[0] == '-' || input[0] == '+') && input.length() == 1)
        return false;
    int start = 0;
    if (input[start] == '-' || input[start] == '+')
        start++;
    for (int i = start; i < (int)input.length(); i++)
    {
        if (!std::isdigit(input[i]))
            return false;
    }
    if (std::atof(input.c_str()) < INT_MIN || std::atof(input.c_str()) > INT_MAX)
        return false;
    return true;
}

bool ScalarConverter::_isFloat(std::string input)
{
    if (input[input.length() - 1] != 'f')
        return false;
    if ((input[0] == '-' || input[0] == '+') && input.length() == 1)
        return false;
    int start = 0;
    bool flagDot = 0;
    if (input[start] == '-' || input[start] == '+')
        start++;
    for (int i = start; i < (int)input.length(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            if (input[i] == '.')
            {
                if (flagDot || i == start)
                    return false;
                flagDot = 1;
            }
            else if (input[i] == 'f')
            {
                if (i < (int)input.length() - 1)
                    return false;
                return true;
            }
            else
                return false;
        }
    }
        if (std::atof(input.c_str()) < -FLT_MAX || std::atof(input.c_str()) > FLT_MAX)
        return false;
    return true;
}

bool ScalarConverter::_isDouble(std::string input)
{
    if ((input[0] == '-' || input[0] == '+') && input.length() == 1)
        return false;
    int start = 0;
    bool flagDot = 0;
    if (input[start] == '-' || input[start] == '+')
        start++;
    for (int i = start; i < (int)input.length(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            if (input[i] == '.')
            {
                if (flagDot)
                    return false;
                flagDot = 1;
            }
            else 
                return false;
        }
    }
    if (std::atof(input.c_str()) < -DBL_MAX || std::atof(input.c_str()) > DBL_MAX)
        return false;
    return true;
}

int  ScalarConverter::_findType(std::string input)
{
    if (input.empty())
        return EMPTY;
    else if (ScalarConverter::_isChar(input))
        return CHAR;
    else if (ScalarConverter::_isInt(input))
        return INT;
    else if (ScalarConverter::_isFloat(input))
        return FLOAT;
    else if (ScalarConverter::_isDouble(input))
        return DOUBLE;
    else if (input == "-inf" || input == "-inff"
        || input == "+inf" || input == "+inff"
        || input == "nan" || input == "nanf")
        return SPECIAL;
    else   
        return WRONG;
}

void ScalarConverter::_convertChar(std::string input)
{
    char c = input[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::_convertInt(std::string input)
{
    int i = std::atoi(input.c_str());
    if (i < 0 || i > 255)
        std::cout << "char: Overflow" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::_convertFloat(std::string input)
{
    float f = std::atof(input.c_str());
    float decimal = f - static_cast<int>(f);

    // char
    if (f < 0 || f > 255)
        std::cout << "char: Overflow" << std::endl;
    else if (f < 32 || f > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

    // int
    if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
        std::cout << "int: Overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    // float & decimals
    if (decimal)
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else
    {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    }
}

void ScalarConverter::_convertDouble(std::string input)
{
    double d = std::atof(input.c_str());
    double decimal = d - static_cast<int>(d);

    // char
    if (d < 0 || d > 255)
        std::cout << "char: Overflow" << std::endl;
    else if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

    // int
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: Overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    // floats
    if (d < -FLT_MAX || d > FLT_MAX)
        std::cout << "float: Overflow" << std::endl;
    else if (decimal)
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "float: " << d << ".0f" << std::endl;

    // double
    if (decimal)
        std::cout << "double: " << d << std::endl;
    else
        std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::_convertSpecial(std::string input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout  << "int: impossible" << std::endl;
    if (input == "-inf" || input == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout  << "double: -inf" << std::endl;
    }
    if (input == "+inf" || input == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout  << "double: +inf" << std::endl;
    }
    if (input == "nan" || input == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout  << "double: nan" << std::endl;
    }
}