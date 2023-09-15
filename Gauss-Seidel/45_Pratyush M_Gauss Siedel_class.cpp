#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<fstream>
#include<new>
#include <stdio.h>
#include <iomanip>
#include <bits/stdc++.h>
#include <cstdlib>

#define SQ(x) (x)*(x)
#define RESP(x) 1.0/(x)
#define free_arg char*
#define nr_end 1
#define TINY 1.0e-5

using namespace std;
double *dvector (long nl, long nh);
long *lvector (long nl, long nh);
double **matrix (long nrl, long nrh, long ncl, long nch);
long **lmatrix (long nrl, long nrh, long ncl, long nch);
double ***f3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh);

int main()
{
long i,j,n,k=1;
double **a,x = 0,*xold,*b, error = 1;

ifstream fin("coeff2.txt",ios::in);
	fin>>n;

a=matrix(1,n,1,n+1);

for(i=1;i<=n;++i){
	for(j=1;j<=n+1;++j){
	fin>>a[i][j];
	}}

/*  Test if the matrix is read correctly
for(i=1;i<=n;++i){
for(j=1;j<=n+1;++j)
cout<<a[i][j]<<" ";
cout<<endl;}
    cout<<"Test"<<endl;
        return(0);
*/

xold = dvector(1, n);
b = dvector(1, n);

for(i=1;i<=n;++i){
	b[i]=a[i][n+1];
	}

cout<<"Enter the initial guess:"<<endl;
for (i = 1; i <= n; ++i) {
        cout<<"x"<<i<<": ";
        cin >> xold[i];
}



ofstream MyFile("output.txt");
cout<<"Iteration: ";
MyFile<<"Iteration: ";
for(int g =1;g<=n;++g){     
cout<<setw(7)<<"x"<<g<<": ";
}
MyFile<<endl;
cout<<endl;
while (error > TINY){ 
        for (int i = 1 ; i <= n; i++){
            x = a[i][n+1] / a[i][i] ; 
            for(int j = 1 ; j <= n ; j++){
                 if (i== j){
                    continue ;
                 }
                 x -= (a[i][j]/a[i][i])*xold[j] ; 
            }
            if (i == 1 ){
                error = abs(x-xold[i]);
            }
            else {
                if (error < abs(x-xold[i])){
                        error = abs(x-xold[i]);
                }
                else{
                        error = error ;}
            }
            xold[i] = x ; 
        }
        cout<<right<<setw(11)<<k<< " ";
        MyFile<<right<<setw(11)<<k<< " ";
        for(int i = 1 ; i <= n ; i++){
        cout<<setw(8)<<xold[i] << " ";
        MyFile<<setw(8)<<xold[i] << " ";
    }
    k++;
    MyFile<<endl;
    cout<<endl;
  }

cout << "Solution of the equation is " << endl ;
for(int i = 1 ; i <= n ; i++){
        cout << xold[i] << " ";
    }
cout<<endl;
MyFile.close();

}



double *dvector (long nl, long nh)
// Allocates a double vector with subscript range v[nl..nh]
         {
                 double *v = new double [nh-nl+1+nr_end];
                         if (!v)
                               {
                               cout<< "allocation failure in vector";
                               exit(1);
                               }
                                   return v-nl+nr_end;
                                }

long *lvector (long nl, long nh)
// allocates a long vector with subscript range v[nl..nh]
        {
        long *v = new long [nh-nl+1+nr_end];
        if(!v)
                {
                cout<< "allocation failure in lvector";
                exit(1);
                }
        return v-nl+nr_end;
        }

double **matrix (long nrl, long nrh, long ncl, long nch)
// allocate a double matrix with subscript range m[nrl..nrh][ncl..nch]
        {
        long i, nrow=nrh-nrl+1, ncol=nch-ncl+1;

//allocates pointer to row

        double  **m = new double *[nrow+nr_end];//nr_end=1
        if(!m)
                {
                cout<< "allocation failure 1 in matrix";
                exit(1);
                }
        m+=nr_end;
        m-=nrl;
// allocates rows and set pointers to them
        m[nrl] = new double [nrow*ncol+nr_end];
        if(!m[nrl])
                {
                cout<< "allocation failure 2 in matrix()";
                exit(1);
                }
 m[nrl]+=nr_end;
         m[ncl]-=ncl;
         for(i=nrl+1;i<=nrh;++i)
                m[i]=m[i-1]+ncol;
//return pointer to array of pointers to rows
         return m;
         }

  long **lmatrix (long nrl, long nrh, long ncl, long nch)
// allocate a long matrix with subscript range m[nrl..nrh][ncl..nch]
        {
        long i, nrow=nrh-nrl+1, ncol=nch-ncl+1;

//allocates pointer to row

        long  **m = new long *[nrow+nr_end];
        if(!m)
                {
                cout<< "allocation failure 1 in lmatrix";
                exit(1);
                }
        m+=nr_end;
        m-=nrl;
// allocates rows and set pointers to them
        m[nrl] = new long [nrow*ncol+nr_end];
        if(!m[nrl])
                {
                cout<< "allocation failure 2 in lmatrix()";
                exit(1);
                }
         m[nrl]+=nr_end;
         m[ncl]-=ncl;
         for(i=nrl+1;i<=nrh;++i)
                m[i]=m[i-1]+ncol;
//return pointer to array of pointers to rows
         return m;
         }

 //  To create the three dimensional arrays using pointers.
 double ***f3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
     {
         long i,j,nrow=nrh-nrl+1,ncol=nch-ncl+1, ndep=ndh-ndl+1;
    /*allocate pointer to pointers to row*/
     double ***t = new double **[nrow+nr_end];
      if (!t)
     { cout<<"allocation failure 1 in 3tensor";
       exit(1);
     }
        t +=nr_end;
        t -=nrl;
    /*allocate pointer to rows and set pointers to them*/
      t[nrl]=new double *[nrow*ncol+nr_end];
       if (!t[nrl])
      { cout<<"allocation failure 2 in 3tensor";
         exit(1);
      }
      t[nrl] += nr_end;
      t[nrl] -= ncl;
     /*allocate rows and set pointers to them*/
      t[nrl][ncl] = new double [nrow*ncol*ndep+nr_end];
if (!t[nrl][ncl])
{ cout<<"allocation failure 3 in 3 tensor";
        exit(1);
      }
     t[nrl][ncl] += nr_end;
     t[nrl][ncl] -= ndl;
      for(j=ncl+1;j<=nch;++j)
         t[nrl][j]=t[nrl][j-1]+ndep;
      for(i=nrl+1;i<=nrh;++i)
       {
         t[i]=t[i-1]+ncol;
         t[i][ncl]=t[i-1][ncl]+ncol*ndep;
       for(j=ncl+1;j<=nch;++j)
        t[i][j]=t[i][j-1]+ndep;
       }
     return t;
    }
