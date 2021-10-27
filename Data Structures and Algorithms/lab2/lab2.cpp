/**************************************************/
/*                                                */
/*  Lab 2 Starter file                            */
/*                                                */
/*  Name:Michael                                  */
/*  Student number:143152189                      */
/*                                                */
/**************************************************/

/* remember to code these in an recursive only manner*/


unsigned int factorial(unsigned int n) {
	if (n == 0 || n == 1)
		return 1;
	return n*factorial(n - 1);
}

double power (double base, unsigned int n){
	if (n == 0)
		return 1;
	return base * power(base, n - 1);
			
}
unsigned int fibonacci (unsigned int n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
