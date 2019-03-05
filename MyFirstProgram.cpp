#include <omp.h>
#include <iostream>

int main()
{
	int n = 1;
	std::cout << "N before = " << n << std::endl;
#pragma omp parallel private(n)
	{
		std::cout << "N at first = " << n << std::endl;
		n = omp_get_thread_num();
		std::cout << "N after = " << n << std::endl;
	}
	std::cout << "N after = " << n << std::endl;
	return 0;
}
