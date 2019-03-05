double function(double x)
{
	return 4.0/(1 + x * x);
}

double integral(int thread_num, bool reduct)
{
	double a = .0;
	double b = 1.0;
	int n = 100000;
	double h = (b - a)/n;
	double x[n + 1];
	double f[n + 1];
	double sum = 0.0;
#pragma omp parallel num_threads(thread_num) if (reduct) reduction(+: sum)
#pragma omp parallel for
	for (int i = 0; i < n + 1; i++)
	{
		x[i] = a + (b - a) * i / n;
		f[i] = function(x[i]);
		sum = sum + f[i];
	}

	sum = h*sum;

	return sum;
}

