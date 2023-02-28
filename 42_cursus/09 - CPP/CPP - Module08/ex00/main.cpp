#include "easyfind.hpp"

#define CONTAINER_SIZE 100
#define TO_FIND 42

static int	rand_int( int rand_lim ) {
	return ( std::pow(-1, rand() % 2) * ( rand() % ( rand_lim + 1 ) ) );
}

int main() {
	std::vector<int>			v(CONTAINER_SIZE);
	std::vector<int>::iterator	start = v.begin();
	std::vector<int>::iterator	end = v.end();

	srand(time(NULL));

	s_elRandom<int>	randomer = s_elRandom<int>(42, &rand_int);
	std::for_each(start, end, randomer);
	
	std::cout << "Vector is:" << std::endl;
	std::for_each(start, end, print_el<int>);
	std::cout << std::endl;
	
	std::cout << "Finding number: " << TO_FIND << std::endl;
	try {
		std::cout << easyfind(v, TO_FIND) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}
