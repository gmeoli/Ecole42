#include "RPN.hpp"

RPN::RPN() {
	throw std::runtime_error("Error\nArgument not valid");
}

RPN::RPN(RPN const &copy) {
	this->_expression = copy._expression;
	this->_stack = copy._stack;
	*this = copy;
}

RPN &RPN::operator=(RPN const &rhs) {
	if (this == &rhs)
		return *this;
	this->_expression = rhs._expression;
	this->_stack = rhs._stack;
	return *this;
}

RPN::~RPN() {
	if (!_stack.empty())
		while (_stack.empty())
			_stack.pop();
}

RPN::RPN(const std::string &expression) {
	if (!evaluate(expression))
		throw std::runtime_error("Error");
}

bool RPN::evaluate(const std::string &expression) {
	if (expression.find_first_not_of("0123456789-+/* "))
		return true;
	for (int i = 0; expression[i]; i++) {
	}
	return false;
}
