double scalar_product(std::vector<double> v1, std::vector<double> v2, bool is_parallel)
{
	if(v1.size() != v2.size())
	{
		throw "Bad dimentions";
	}
	else
	{
		double result = 0;
		#pragma omp parallel for reduction(+: result) if(is_parallel)
		for(int i = 0; i < v1.size(); i++)
		{
			result += v1[i] * v2[i];
		}
		return result;
	}
}

