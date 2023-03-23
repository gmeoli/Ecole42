#include "RPN.hpp"

RPN::RPN() {
	throw std::runtime_error("Error\nArgument not valid");
}

RPN::RPN(RPN const &copy) {
	*this = copy;
}

RPN &RPN::operator=(RPN const &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}

RPN::~RPN() {}

RPN::RPN(const std::string &expression) {

}

bool RPN::evaluate(int &result) {
	return true;
}
