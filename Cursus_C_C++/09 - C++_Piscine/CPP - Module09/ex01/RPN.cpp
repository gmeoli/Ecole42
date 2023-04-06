#include "RPN.hpp"

RPN::RPN() {
	throw std::runtime_error("Error\nArgument not valid");
}

RPN::RPN(RPN const &copy) {
	this->_stack = copy._stack;
	*this = copy;
}

RPN &RPN::operator=(RPN const &rhs) {
	if (this == &rhs)
		return *this;
	this->_stack = rhs._stack;
	return *this;
}

RPN::~RPN() {
	if (!_stack.empty())
		while (!_stack.empty())
			_stack.pop();
}

RPN::RPN(const std::string &str) {
	std::string	token;

	for (size_t i = 0; i < str.length(); i++) {
		char c = str[i];
		if (c == ' ')
			continue;
		else if (isdigit(c))
			token += c;
		else if (isOperator(c)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Error\nInsufficient operands");
			int num2 = _stack.top();
			_stack.pop();
			int num1 = _stack.top();
			_stack.pop();

			// mathematical calculations
			if (c == '+')
				_stack.push(num1 + num2);
			if (c == '/') {
				if (num2 == 0)
					throw std::runtime_error("Error\nDivision by zero");
				_stack.push(num1 / num2);
				}
			if (c == '*')
				_stack.push(num1 * num2);
			if (c == '-')
				_stack.push(num1 - num2);
		}
		else
			throw std::runtime_error("Error\nInvalid token");
		if (!token.empty()) {
			_stack.push(atoi(token.c_str()));
			token.clear();
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error\nToo many operands");
	int result = _stack.top();
	_stack.pop();

	std::cout << result << std::endl;
}

bool RPN::isOperator(char c) {
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}
