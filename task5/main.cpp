#include "omp.h"
#include <iostream>
#include <chrono>
#include "product.hh"
#include <ctime>
#include <fstream>

int main()
{
	std::ofstream outfile;
	outfile.open("out.txt");
	 
	std::srand(unsigned(std::time(0)));
	
	int max_threads_number = 15;
	int max_dimention = 100000;

	for(int dim = 10; dim < max_dimention; dim*=10)
		outfile << dim << " ";
	outfile << std::endl;
	for(int threads_number = 1; threads_number < max_threads_number+1; threads_number++)
	{
		std::cout << "Threads number: " << threads_number << std::endl;
		for(int dimention = 10; dimention < max_dimention; dimention *= 10)
		{
			std::cout << "Dimention: " << dimention << std::endl;
			int m = dimention;
			int n = dimention;
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
			
			auto start = std::chrono::system_clock::now();
			int* result = row_product(a, b, m, n, threads_number);
			auto end = std::chrono::system_clock::now();

			outfile << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";

			for(int i =0; i < m; i++)
			{
				delete[] a[i];
			}
			delete[] a;
			delete[] b;
			delete[] result;
		}
		outfile << std::endl;
	}
	outfile.close();
	return 0;
}

