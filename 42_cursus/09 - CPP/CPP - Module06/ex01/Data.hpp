#pragma once

#include <iostream>

class Data
{
	private:
		int	_data;
	public:
		Data();
		Data(int data);
		Data(Data const &cpy);
		Data &operator=(Data const &rhs);
		~Data();

		void	setData(int data);
		int		getData() const;
};
