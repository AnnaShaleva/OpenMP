#include "omp.h" 
#include <iostream>
#include <vector>
#include <chrono>
#include "scalar_product.hh"

int main()
{
	std::vector<double> v1, v2;
	for (int i = 0; i < 10000000; i++)
	{
		v1.push_back(i / 4.0);
		v2.push_back(i / 8.0);
	}

	auto start1 = std::chrono::system_clock::now();
	double result1 = scalar_product(v1, v2, false);
	auto end1 = std::chrono::system_clock::now();

	auto start2 = std::chrono::system_clock::now();
	double result2 = scalar_product(v1, v2, true);
	auto end2 = std::chrono::system_clock::now();

	std::cout << "result1: " << result1 << std::endl;
	std::cout << "Single thread scalar product: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << "result2: " << result2 << std::endl;
	std::cout << "Multy thread scalar product: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds" << std::endl;
	return 0;
}
