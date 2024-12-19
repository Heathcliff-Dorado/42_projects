#include "RPN.hpp"

RPN::RPN(const std::string &userInput)
{
	processInput(userInput);
}

RPN::RPN(const RPN &source) : _op(source._op) {}

RPN &RPN::operator=(const RPN &source)
{
	if (this != &source)
	{
		_op = source._op;
	}

	return (*this);
}

RPN::~RPN() {}

//////////////////////////////////////////////////////////////////////////////////////

void RPN::processInput(const std::string &input)
{
	if (!isValidExpression(input))
		return ;

	_expression = input;
}

bool RPN::isValidExpression(const std::string &input) const
{
	if (input.empty())
	{
		std::cout << "Error: input string is empty" << std::endl;
		return false;
	}

	std::string charsToFind = " 0123456789+-/*";
	size_t pos = input.find_first_not_of(charsToFind);

	if (pos != std::string::npos)
	{
		std::cout << "Error: invalid character in the expression" << std::endl;
		return false;
	}

	return true;
}

int RPN::applyOperator(const int &a, const int &b, const std::string &operatorToken)
{
	if (operatorToken == "+")
	{
		return b + a;
	}
	if (operatorToken == "-")
	{
		return b - a;
	}
	if (operatorToken == "*")
	{
		return b * a;
	}
	if (operatorToken == "/" && a != 0)
	{
		return b / a;
	}

	throw std::invalid_argument("Exception ocurred: Division by 0");
}

void RPN::calculateExpression(void)
{
	if (_expression.empty())
		return;

	std::string operatorToken;
	for (size_t i = 0; i < _expression.size(); i++)
	{
		while (_expression[i] && _expression[i] == ' ')
			i++;
		if (isdigit(_expression[i]))
		{
			int number = 0;
			while (_expression[i] && isdigit(_expression[i])) //_expression[i] != ' ')
			{
				number =  number * 10 + _expression[i] - '0';
				i++;
			}

			_op.push(number);
		}
		else if (!_op.empty() && _expression[i])
		{
			operatorToken = _expression[i];
			int a = _op.top();
			_op.pop();
			if (!_op.empty())
			{
				int b = _op.top();
				_op.pop();
				try
				{
					_op.push(applyOperator(a, b, operatorToken));
				}
				catch(const std::exception &e)
				{
					std::cerr << e.what() << '\n';
					break;;
				}

			}
		}

	}
	if (_op.size() != 1)
	{
		std::cout << "Error: invalid RPN expression" << std::endl;
		return ;
	}

	std::cout << _op.top() << std::endl;
}
