#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

double newton(double x){
double ans = x*sin(x) + cos(x);
return ans;
}

double newton_d(double x){
double ans = x*cos(x);
return ans;
}

double next(double x){
double ans = x - (newton(x)/newton_d(x));
return ans;
}

int main() {
        int n=0;
        double stop = 1e-8;
	double x=4.0*atan(1.0);
	double f_x = newton(x);
	double f_x1 = next(x);
	
	cout<<"Iteration: "<<"   X_n"<<setw(7)<<"     f(X_n)"<<f_x<<"          X_n+1 "<<"\n";
	cout<<left<<setw(11)<<n<<setw(11)<<x<<setw(18)<<f_x<<setw(7)<<f_x1<<"\n";
	while(abs(f_x)>stop){
	//ofstream MyFile("output.txt");
	cout<<left<<setw(11)<<n<<setw(11)<<x<<setw(18)<<f_x<<setw(7)<<f_x1<<"\n";
	//MyFile <<left<< setw(4) << "n" << setw(10) << "a" << setw(10) << "b" << setw(10) << "x" << setw(15) << "f(x)" << "\n";
	x = f_x1;
	f_x = newton(f_x1);
	f_x1 = next(f_x1);
	n++;
}
}
