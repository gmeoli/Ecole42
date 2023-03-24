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
		while (_stack.empty())
			_stack.pop();
}

RPN::RPN(const std::string &str) {
	if (!risolve_expression(str))
		throw std::runtime_error("Error");
}

bool RPN::risolve_expression(const std::string &str) {
	int i = 0;
	int sum;
	int next;
	while(str[i] == ' ')
		i++;
	sum = str[i++] - '0';
	while(str[i] == ' ')
		i++;
	next = str[i++] - '0';
	str.find_first_of("*-+/");
	while (i < str.length()) {
		i++;
	}
	std::cout << sum << next << std::endl;
	return false;
}
