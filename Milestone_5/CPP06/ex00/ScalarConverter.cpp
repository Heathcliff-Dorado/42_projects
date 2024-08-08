#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
	//std::cout << "ScalarConverter created" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy) {
	//std::cout << "ScalarConverter copy created" << std::endl;
	*this = copy;
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(void) copy;
	}

	return (*this);
}

ScalarConverter::~ScalarConverter() {
	//std::cout << "Converter deleted" << std::endl;
}

literals	findType( std::string literal ) {

	if (literal == "nan" || literal == "nanf" || literal == "+inf"
		|| literal == "+inff" || literal == "-inf" || literal == "-inff")
		return SPECIAL;
	if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;
	//Integer
	char* end;
	long value = std::strtol(literal.c_str(), &end, 10);
	if (value < INT_MAX && value > INT_MIN && (*end) == '\0')
		return INT;
	//Float
	try
	{
		char* end2;
		float value = std::strtof(literal.c_str(), &end2);
		(void) value;
		//if (literal.length() - 1 && literal[literal.length() - 1]  == 'f')
		if (*end2 == 'f' && *(end2 + 1) == '\0' && literal[literal.length() - 1] == 'f')
			return FLOAT;
	}
	catch(const std::exception &)
	{
	}
	//Double
	try
	{
		char* end3;
		double value = std::strtod(literal.c_str(), &end3);
		(void) value;
		if (end3 == literal.c_str() + literal.size())
			return DOUBLE;
	}
	catch(const std::exception &)
	{
	}
	return OTHER;
}

void	ScalarConverter::converter (std::string literal) {

	if (literal.empty())
	{
		std::cout << "Error! Empty argument!" << std::endl;
		return ;
	}

	literals x = findType( literal );

	switch (x)
	{
	case CHAR:
		if (isprint(literal[0]))
			std::cout << "char: '" << static_cast<char>(literal[0]) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
		break;
	case INT:
		{
			char*	end;
			long	value = std::strtol(literal.c_str(), &end, 10);
			if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
			{
				if (isprint(value))
					std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			else
				std::cout << "char: Impossible" << std::endl;
			std::cout << "int: " << value << std::endl;
			std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
		}
		break;
	case FLOAT:
		{
			char*	end2;
			float	fvalue = std::strtof(literal.c_str(), &end2);
			if (fvalue >= std::numeric_limits<char>::min() && fvalue <= std::numeric_limits<char>::max())
			{
				if (isprint(fvalue))
					std::cout << "char: '" << static_cast<char>(fvalue) << "'" << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			else
				std::cout << "char: Impossible" << std::endl;
			if (fvalue >= (float) INT_MIN && fvalue <= (float) INT_MAX)
				std::cout << "int: " << static_cast<int>(fvalue) << std::endl;
			else
				std::cout << "int: Overflow" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "float: " << fvalue << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(fvalue) << std::endl;
		}
		break;
	case DOUBLE:
		{
			char*	end3;
			double	dvalue = std::strtod(literal.c_str(), &end3);
			if (dvalue >= std::numeric_limits<char>::min() && dvalue <= std::numeric_limits<char>::max())
			{
				if (isprint(dvalue))
					std::cout << "char: '" << static_cast<char>(dvalue) << "'" << std::endl;
				else
					std::cout << "char: Non displayable" << std::endl;
			}
			else
				std::cout << "char: Impossible" << std::endl;
			if (dvalue >= (double) INT_MIN && dvalue <= (double) INT_MAX)
				std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
			else
				std::cout << "int: Overflow" << std::endl;
			std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
			std::cout << "double: " << dvalue << std::endl;
		}
		break;
	case SPECIAL:
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		{
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.erase(literal.length() - 1) << std::endl;
		}
		if (literal == "nan" || literal == "+inf" || literal == "-inf")
		{
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
		}
		break;
	case OTHER:
		std::cout << "Error: Unrecognizable scalar" <<std::endl;
		break;
	default:
		break;
	}
}
