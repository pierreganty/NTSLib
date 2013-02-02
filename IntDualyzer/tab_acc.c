#include <stdlib.h>

int iplus ( int a, int b){
 return a+b;
}

int main (void){
 int t[5];
 int val;
 t[2]=4;

 int *g=(int *)malloc(10*sizeof(int));

// val=fplus(t[2],t[1]);
 val=iplus(g[2],g[0]);
 if (val>1)
	 return 0;
 else 
	return 1;
 
}
