#include <iostream>
#include <chrono>
#include "integral.hh"
#include "omp.h" 

int main()
{
	auto start1 = std::chrono::system_clock::now();
	double result1 = integral(1, false);
	auto end1 = std::chrono::system_clock::now();

	auto start2 = std::chrono::system_clock::now();
	double result2 = integral(10, false);
	auto end2 = std::chrono::system_clock::now();

	auto start3 = std::chrono::system_clock::now();
	double result3 = integral(10, true);
	auto end3 = std::chrono::system_clock::now();



	std::cout << "result1: " << result1 << std::endl;
	std::cout << "Single thread integral: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << "ms" << std::endl;

	std::cout << "result2: " << result2 << std::endl;
	std::cout << "Multy thread integral: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << "ms" << std::endl;

	std::cout << "result3: " << result3 << std::endl;
	std::cout << "Multy thread integral with reduction: " << std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() << "ms" << std::endl;
	
	return 0;
}
