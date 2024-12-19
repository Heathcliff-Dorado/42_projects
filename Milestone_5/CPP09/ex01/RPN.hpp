#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::string _expression;
		std::stack<int> _op;

		void processInput(const std::string &input);
		bool isValidExpression(const std::string &input) const;
		int applyOperator(const int &a, const int &b, const std::string &operatorToken);


	public:
		RPN(const std::string &userInput);
		RPN(const RPN &source);
		RPN &operator=(const RPN &source);
		~RPN();

		void calculateExpression(void);

};

#endif // RPN_HPP
