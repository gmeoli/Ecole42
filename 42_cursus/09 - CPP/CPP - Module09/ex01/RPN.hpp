#pragma once

#include <iostream>
#include <stack>
#include <string>

class RPN {
	private:
		std::stack<int>	_stack;
		bool			risolve_expression(const std::string &str);
	public:
		RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &rhs);
		~RPN();
		
		RPN(const std::string &str);
};
