#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

double fx(double x){
double ans = x*x*x - x*x - x +1;
return ans;
}

double fx_d(double x){
double ans = 3*x*x - 2*x - 1;
return ans;
}

double fx_d2(double x){
double ans = 6*x - 2;
return ans;
}

double next(double x){
double ans = x - (fx(x)/fx_d(x));
return ans;
}

int main() {
        int n=0;
        double stop = 1e-8;
	double x;
	double f_x = fx(x);
	double f_x1 = next(x);
	
	cout<<"Iteration: "<<"   X_n"<<setw(7)<<"     f(X_n)"<<f_x<<"          X_n+1 "<<"\n";
	
	ofstream MyFile("output.txt");
	MyFile<<left<<setw(3)<<"n"<<setw(11)<<"X_n"<<setw(18)<<"f(X_n)"<<setw(7)<<"X_n+1"<<"\n";
	
	while(abs(f_x)>stop){
	
	cout<<left<<setw(11)<<n<<setw(11)<<x<<setw(18)<<f_x<<setw(7)<<f_x1<<"\n";
	
	MyFile<<left<<setw(3)<<n<<setw(11)<<x<<setw(18)<<f_x<<setw(7)<<f_x1<<"\n";
	x = f_x1;
	f_x = fx(f_x1);
	f_x1 = next(f_x1);
	n++;
}
MyFile.close();
}
