#ifndef SCALE_CONVERTER
# define SCALE_CONVERTER

# include <string>
# include <iostream>
# include <cstdlib>
# include <climits>
# include <cfloat>
# include <cmath>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define SPECIAL 4
# define WRONG -1
# define EMPTY -2

class ScalarConverter
{
    public:
        static void convert(std::string input);
        // static : pas besoin d'être instanciée
        
    private: 
        ScalarConverter();
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter);
        ~ScalarConverter();
        // classe statique : ne peut être instanciée

        static bool _isChar(std::string input);
        static bool _isInt(std::string input);
        static bool _isFloat(std::string input);
        static bool _isDouble(std::string input);
        static bool _isOverflow(int type, std::string input);
        static int  _findType(std::string input);

        static void _convertChar(std::string input);
        static void _convertInt(std::string input);
        static void _convertFloat(std::string input);
        static void _convertDouble(std::string input);
        static void _convertSpecial(std::string input);
};

#endif