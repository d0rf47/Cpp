/**************************************************/
/*                                                */
/*  Lab 1 Starter file                            */
/*                                                */
/*  Name:Michael Falconi                          */
/*  Student number:143152189                      */
/*                                                */
/**************************************************/
/* remember to code these in an iterative only manner*/
#include <vector>

unsigned int factorial(unsigned int n) {
	unsigned int nbang = 1;
	if (n == 0)
		return 1;
	while (n >= 1)
	{
		--n;
		nbang += (nbang * n);
	}
	return nbang;
}

double power(double base, unsigned int n) {
	double power = 1;
	if (n == 0)
		return power;
	for (unsigned int i = 0; i < n; i++)
	{
		power = base * power;
	}
	return power;
}
unsigned int fibonacci(unsigned int n) {
	std::vector<unsigned int> fib{ 0, 1 };
	for (unsigned int i = 2; i <= n; i++)
	{
		fib.push_back(fib[i - 1] + fib[i - 2]);
	}
	return fib[n];
}