#include <stdlib.h>

double fplus ( double a, double b){
 return a+b;
}

int main (void){
 double t[5];
 double val;
 t[2]=4;

 double *g=(double *)malloc(10*sizeof(double));

// val=fplus(t[2],t[1]);
 val=fplus(g[2],g[0]);
 if (val>1.0)
	 return 0;
 else 
	return 1;
 
}
