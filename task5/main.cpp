#include "omp.h"
#include <iostream>
#include <chrono>
#include "product.hh"
#include <ctime>

int main()
{
	std::srand(unsigned(std::time(0)));
	int m = 10000;
	int n = 10000;

	int** a = new int*[m];
	for(int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for(int j = 0; j < n; j++)
		{
			a[i][j] = std::rand() % 10;
			//std::cout << a[i][j] << " ";
		}
		//std::cout << std::endl;
	}
	//std::cout << std::endl;
	int* b = new int[n];
	for(int i = 0; i < n; i++)
	{
		b[i] = std::rand() % 10;
		//std::cout << b[i] << " ";
	}
	//std::cout << std::endl;
	
	int thread_num1 = 1;		
	int thread_num2 = 5;
	auto start1 = std::chrono::system_clock::now();
	int* result1 = row_product(a, b, m, n, thread_num1);
	auto end1 = std::chrono::system_clock::now();

	auto start2 = std::chrono::system_clock::now();
	int* result2 = row_product(a, b, m, n, thread_num2);
	auto end2 = std::chrono::system_clock::now();

	//std::cout << "result1: " << std::endl;
	//for(int i = 0; i < m; i++)
	//{
		//std::cout << result1[i] << " ";
	//}
	//std::cout << std::endl;

	std::cout << "Single thread algorithm: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	//std::cout << "result2: " << std::endl;
	//for(int i = 0; i < m; i++)
	//{
	//	std::cout << result2[i] << " ";
	//}
	//std::cout << std::endl;

	std::cout << "Multy thread algorithm: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds" << std::endl;


	return 0;
}

