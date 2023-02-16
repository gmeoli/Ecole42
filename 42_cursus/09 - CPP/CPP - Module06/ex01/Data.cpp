#include "Data.hpp"

Data::Data() : _data(0)
{
	std::cout << "Data constructed" << std::endl;
}

Data::Data(int data) : _data(data)
{
	std::cout << "Data constructed" << std::endl;
}

Data::Data(Data const &cpy)
{
	*this = cpy;
	std::cout << "Data constructed" << std::endl;
}

Data &Data::operator=(Data const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_data = rhs.getData();
	return (*this);
}

Data::~Data()
{
	std::cout << "Data destroyed" << std::endl;
}

void	Data::setData(int data)
{
	this->_data = data;
}

int		Data::getData() const
{
	return this->_data;
}
