#include "Converter.hpp"

Converter::Converter( void ) {
	//std::cout << "Converter created" << std::endl;
}

Converter::Converter( const Converter& copy) {
	//std::cout << "Converter copy created" << std::endl;
	*this = copy;
}

Converter&	Converter::operator=( const Converter& copy) {
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		(void) copy;
	}

	return (*this);
}

Converter::~Converter() {
	//std::cout << "Converter deleted" << std::endl;
}

literals	findType( std::string literal ) {

	if (literal == "nan" || literal == "nanf" || literal == "+inf"
		|| literal == "+inff" || literal == "-inf" || literal == "-inff")
		return SPECIAL;
	if (literal.length() == 1 && !isdigit(literal[0]))
		return CHAR;
	//Integer
	try
	{
		size_t pos;
		int value = std::stoi(literal, &pos);
		(void) value;
		if (literal.length() == pos)
			return INT;
	}
	catch(const std::exception &)
	{
	}
	//Float
	try
	{
		size_t pos;
		float value = std::stof(literal, &pos);
		(void) value;
		if (literal.length() - 1 && literal[literal.length() - 1]  == 'f')
			return FLOAT;
	}
	catch(const std::exception &)
	{
	}
	//Double
	try
	{
		size_t pos;
		double value = std::stod(literal, &pos);
		(void) value;
		if (literal.length() == pos)
			return DOUBLE;
	}
	catch(const std::exception &)
	{
	}
	return OTHER;
}

void	Converter::converter (std::string literal) {

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
		{int	value = std::stoi(literal);
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
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;}
		break;
	case FLOAT:
		{float	fvalue = std::stof(literal);
		if (fvalue >= std::numeric_limits<char>::min() && fvalue <= std::numeric_limits<char>::max())
		{
			if (isprint(fvalue))
				std::cout << "char: '" << static_cast<char>(fvalue) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: Impossible" << std::endl;
		std::cout << "int: " << static_cast<int>(fvalue) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << fvalue << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(fvalue) << std::endl;}
		break;
	case DOUBLE:
		{double	dvalue = std::stod(literal);
		if (dvalue >= std::numeric_limits<char>::min() && dvalue <= std::numeric_limits<char>::max())
		{
			if (isprint(dvalue))
				std::cout << "char: '" << static_cast<char>(dvalue) << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: Impossible" << std::endl;
		std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(dvalue) << "f" << std::endl;
		std::cout << "double: " << dvalue << std::endl;}
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
		break;
	default:
		break;
	}
}
