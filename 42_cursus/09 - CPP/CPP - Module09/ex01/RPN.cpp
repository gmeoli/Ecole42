#include "RPN.hpp"

RPN::RPN() {
	throw std::runtime_error("Error\nArgument not valid");
}

RPN::RPN(RPN const &copy) {
	this->_stack = copy._stack;
	this->_queue = copy._queue;
	*this = copy;
}

RPN &RPN::operator=(RPN const &rhs) {
	if (this == &rhs)
		return *this;
	this->_stack = rhs._stack;
	this->_queue = rhs._queue;
	return *this;
}

RPN::~RPN() {
	if (!_stack.empty())
		while (_stack.empty())
			_stack.pop();
	if (!_queue.empty())
		while (_queue.empty())
			_queue.pop();
}

RPN::RPN(const std::string &str) {
	// int i = 0;
	// int sum;
	// int next;
	// while(str[i] == ' ')
	// 	i++;
	// sum = str[i++] - '0';
	// while(str[i] == ' ')
	// 	i++;
	// next = str[i++] - '0';
	// str.find_first_of("+-/*");
	// std::cout << sum * next << std::endl; // debugger print
	// if (risolve_expression(str))
	// 	throw std::runtime_error("Error");
	int i = 0, p;

	while (i < str.size()) {
		p = atoi(str[i]);
		_stack.push(p);
		i++;
	}
	while (!_stack.empty())
		std::cout << _stack.top() << std::endl;
}
