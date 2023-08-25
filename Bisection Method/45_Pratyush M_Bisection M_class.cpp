#include <stdio.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {

	double a,b,f,n=0,x,xt;
	
	cout<<"Enter the value of \"a\" : ";
	cin>>a;
	
	cout<<"Enter the value of \"b\" : ";
	cin>>b;
	
	while (n<11){
	
	x=(a+b)/2;
	xt= pow(x,3);
	
	cout<<"The value of \"x\" : "<<x<<"\n";
	f = xt - 2*x -5;
	
	cout<<"The value of f(x) is: "<<f<<"   Iteration no.- "<<n<<"\n";
	if (f>0){
	b=x;
	}
	
	else if (f<0){
	a=x;
	}
	
	n=n+1;
	
	}
	cout<<"\nAfter 11 iterations the value of f(x) is:"<<f<<"\n";
	
	
}
