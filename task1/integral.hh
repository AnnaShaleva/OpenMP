double function(double x)
{
	return 4.0/(1 + x * x);
}

double integral(bool is_parallel)
{
	double a = .0;
	double b = 1.0;
	//int n = 100000;
	int n = 10;
	double h = (b - a)/n;
	double x[n + 1];
	double f[n + 1];
	double sum = 0.0;

	#pragma omp parallel 
	{
		std::cout << "Thread number: " << omp_get_thread_num() << std::endl;
		#pragma omp for
		for (int i = 0; i < n + 1; i++)
		{
			x[i] = a + (b - a) * i / n;
			f[i] = function(x[i]);
			sum = sum + f[i];
		}
	}
	sum = h*sum;

	return sum;
}

