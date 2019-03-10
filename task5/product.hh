int* row_product(int** a, int* b, int m, int n, int* threads_num)
{
	int* result = new int[m];
	#pragma omp parallel shared(a, b, result) num_threads(*threads_num)
	{
		std::cout << omp_get_num_threads() << std::endl;
		#pragma omp for
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				result[i] += a[i][j] * b[j];
			}
		}
	}
	return result;
}

int* column_product(int** a, int* b, int m, int n, unsigned int threads_num)
{
	int* result = new int[m];
	#pragma omp parallel shared(a, b, result) num_threads(threads_num)
	{
		#pragma omp for
		for(int j = 0; j < n; j++)
		{
			for(int i = 0; i < m; i++)
			{
				result[i] += a[i][j] * b[j];
			}
		}
	}
	return result;
}
