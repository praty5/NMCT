#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {

	double a,b,f=1,n=1,x,stop = 0.001;
	
	cout<<"Enter the value of \"a\" : ";
	cin>>a;
	
	cout<<"Enter the value of \"b\" : ";
	cin>>b;
	
	
	
	ofstream MyFile("output.txt");
	MyFile <<left<< setw(4) << "n" << setw(10) << "a" << setw(10) << "b" << setw(10) << "x" << setw(15) << "f(x)" << "\n";
	
	while (abs(f)>stop){
	
	x=(a+b)/2;

	f = x*x*x - 2*x -5;
	
	cout<<"The value of x is: "<<setw(7)<<x<<" and f(x) is: "<<setw(12)<<f<<" Iteration: "<<n<<"\n";
	MyFile<<left<< setw(4) << n << setw(10) << a << setw(10) << b << setw(10) << x << setw(15) << f << "\n";
	
	if (f>0){
	b=x;
	}
	
	else if (f<0){
	a=x;
	}
	
	n=n+1;
	}
	
	MyFile.close();
	cout<<"\nAfter "<<n-1<<" iterations the value of f(x) is: "<<f<<"\n";
	
	
}
