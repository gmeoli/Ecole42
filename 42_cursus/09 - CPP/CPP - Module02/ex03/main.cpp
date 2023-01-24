#include "Point.hpp"

bool bsp (Point const a, Point const b, Point const c, Point const point);

int main() {
	Point one(2, 0);
	Point two(0, 3);
	Point three(2, 2);
	Point const four(2, 1);
	std::cout << bsp(one, two, three, four) << std::endl;

	Point const five(2, 0);
	std::cout << bsp(one, two, three, five) << std::endl;

	Point const six(0, 2);
	std::cout << bsp(one, two, three, six) << std::endl;

	return 0;
}
