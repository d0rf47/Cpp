/********************************************************************/
/*                                                                  */
/*   lab 2 timing file                                              */
/*                                                                  */
/*   To compile: g++ lab2.cpp lab2timing.cpp timer.cpp -std=c++0x   */
/*                                                                  */
/*                                                                  */
/********************************************************************/
#include "timer.h"
#include <iostream>
#include <fstream>
using namespace std;

unsigned int factorial (unsigned int n);
double power (double base, unsigned int n);
unsigned int fibonacci (unsigned int n);

int main(void){	
	unsigned int rc;
	ofstream outfile;

	for(int i = 21; i < 46; i++)
	{
		outfile.open("fibonacciRecords.txt", ios_base::app);
		Timer t;
		t.start();
		rc=fibonacci(i);
		t.stop();
		outfile << "fibonacci (" << i << ") = " << rc << endl;
		outfile << "fibonacci (" << i << ") took " << t.currtime() << " s" << endl;	
		outfile.close();
		cout << "Done" << endl;
	}
	
	return 0;
}
