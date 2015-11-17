#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

//input an array f, which contains x-values at which fct should be evaluated 
void calc_fct(double* f, const int N){
  for( int i=0; i<N; i++){
    f[i]=exp(-f[i]*f[i]);
  }
}

void calc_derv(double* f, const int N, const double dx){
  double fstart, fend;
  fstart = f[1];
  fend = f[N-2];
  
  double abhilfe = 0;

  //Derivatives except the boundary ones
  for( int i=1; i<N-1; i++){
    double temp=f[i];
    f[i]=(f[i+1] - abhilfe ) / (2*dx);
    abhilfe = temp;
  }
  
  //Boundary Derivatives, f(-1)=f(N)=0
  f[0] = fstart/(2*dx);
  f[N-1] = -fend/(2*dx);
}


int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);
  
  // write x-values in p
  for( int i=0; i<N; i++){
    p[i]=xmin + (i*dx); 
  }
  
  calc_fct(p, N);
  calc_derv(p, N, dx);
  print(p,N,dx,xmin);

  return 0;
}
