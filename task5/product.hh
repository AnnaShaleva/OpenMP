int* row_product(int** a, int* b, int m, int n, unsigned int threads_num)
{
	int* result = new int[m];
	for(int i = 0; i < m; i++)
	{
		result[i] = 0;
	}
	#pragma omp parallel shared(a, b, result) num_threads(threads_num)
	{
		#pragma omp for nowait
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
	for(int i = 0; i < m; i++)
	{
		result[i] = 0;
	}
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

int* block_product(int** a, int* b, int m, int n, unsigned int threads_num)
{
	int* result = new int[m];
	for(int i = 0; i < m; i++)
	{
		result[i] = 0;
	}
	//quantity of horizontal blocks
	int s =
	//quantity of vertical blocks
	int q = 	
	for(int block_num = 0; block_num < s * q; block_num++)
	{
		int i = //
		int j = //
		result[i] += b[j] * a[i][j];
	}
