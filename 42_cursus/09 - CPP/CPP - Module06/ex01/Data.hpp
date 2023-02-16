#pragma once

#include <iostream>

class Data
{
	private:
	public:
		Data();
		Data(Data const &cpy);
		Data &operator=(Data const &rhs);
		~Data();
};
