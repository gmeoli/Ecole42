#pragma once

#include <iostream>
#include <stack>
#include <string>

class RPN {
	private:
		std::stack<int>	_stack;
		std::string		_expression;
		bool			_hasError;
	public:
		RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &rhs);
		~RPN();
		
		RPN(const std::string &expression);
		bool evaluate(int &result);
};
