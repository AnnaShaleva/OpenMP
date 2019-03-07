#include "omp.h"
#include <iostream>
#include <chrono>
#include "integral.hh"
 

int main()
{
	auto start1 = std::chrono::system_clock::now();
	double result1 = integral(true);
	auto end1 = std::chrono::system_clock::now();

	auto start2 = std::chrono::system_clock::now();
	double result2 = integral(false);
	auto end2 = std::chrono::system_clock::now();

	std::cout << "result1: " << result1 << std::endl;
	std::cout << "Single thread integral: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << "result2: " << result2 << std::endl;
	std::cout << "Multy thread integral: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds" << std::endl;

	return 0;
}
