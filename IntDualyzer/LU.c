#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int LU_num_flops(int N);
void LU_copy_matrix(int M, int N, int **lu, int **A);
int LU_factor(int M, int N, int **A, int *pivot);
void init_arrF2(int **a, int i, int j, int m, int n);
int** new_Array2D_double(int M, int N);

void error_() {
assert(0);
} 

int dim = 10;

void main()
{
  int jp = 1;
  int t = 0;
  int **A;
  if ((A = new_Array2D_double(dim, dim)) == 0)
	error_(); 
	// Original code, replaced by : exit(1); 

  int pivot[10];
  init_arrF2(A,0,0,dim-1,dim-1);

  //printf("before LU: %1.0f-%1.0f-..\n",A[0][0],A[0][1]);
  LU_factor(dim,dim,A,pivot);
  //printf("after LU: %1.0f-%1.0f-..\n",A[0][0],A[0][1]);
}


int** new_Array2D_double(int M, int N)
{
    int i=0;
    int failed = 0;

    int **A = (int**) malloc(sizeof(int*)*M);
    if (A == 0)
        return 0;

    for (i=0; i<M; i++)
    {
        A[i] = (int*) malloc(N * sizeof(int));
        if (A[i] == 0)
        {
            failed = 1;
            break;
        }
    }

    /* if we didn't successfully allocate all rows of A      */
    /* clean up any allocated memory (i.e. go back and free  */
    /* previous rows) and return NULL                        */

    if (failed)
    {
        i--;
        for (; i<=0; i--)
            free(A[i]);
        free(A);
        return 0;
    }
    else
        return A;
} 

void init_arrF2(int **a, int i, int j, int m, int n) {
  while (i<=n) {
    while (j<=m) {
      a[i][j]=random();
      j=j+1;
    }
    j=0;
    i=i+1;
  }
}

int LU_num_flops(int N)
{
        /* rougly 2/3*N^3 */

    int Nd = (int) N;

    return (2 * Nd *Nd *Nd/ 3);
}


void LU_copy_matrix(int M, int N, int **lu, int **A)
{
    int i;
    int j;

    for (i=0; i<M; i++)
        for (j=0; j<N; j++) {
if (i<0 || i>=dim) { error_(); };
if (j<0 || j>=dim) { error_(); };
if (i<0 || i>=dim) { error_(); };
if (j<0 || j>=dim) { error_(); };
            lu[i][j] = A[i][j];
          }
}


int LU_factor(int M, int N, int **A,  int *pivot)
{
 

    int minMN =  M < N ? M : N;
    int j=0,jp,i,ii,k,jj;
    int t,ab,AiiJ;
    int *tA, *Aii, *Aj;
    int recp;

    for (j=0; j<minMN; j++)
    {
        /* find pivot in column j and  test for singularity. */

        jp=j; // removed local declaration of jp, moved above, fgarnier*/
        /*int i; declaration moved above*/
        
if (j<0 || j>=dim) { error_(); };
if (j<0 || j>=dim) { error_(); };
        	 t = abs(A[j][j]); /* removed double t declaration. fgarnier*/
        for (i=j+1; i<M; i++)
        {
if (i<0 || i>=dim) { error_(); };
if (j<0 || j>=dim) { error_(); };
            	 ab = abs(A[i][j]); /* removed double ab local declaration, fgarnier */
            if ( ab > t)
            {
                jp = i;
                t = ab;
            }
        }
        
if (j<0 || j>=dim) { error_(); };
        pivot[j] = jp;

        /* jp now has the index of maximum element  */
        /* of column j, below the diagonal          */

if (jp<0 || jp>=dim) { error_(); };
if (j<0 || j>=dim) { error_(); };
        if ( A[jp][j] == 0 )                 
            return 1;       /* factorization failed because of zero pivot */


        if (jp != j)
        {
            /* swap rows j and jp */
if (j<0 || j>=dim) { error_(); };
            tA = A[j]; /* removed double *tA declaration */
if (j<0 || j>=dim) { error_(); };
if (jp<0 || jp>=dim) { error_(); };
            A[j] = A[jp];
if (jp<0 || jp>=dim) { error_(); };
            A[jp] = tA;
        }

        if (j<M-1)                /* compute elements j+1:M of jth column  */
        {
            /* note A(j,j), was A(jp,p) previously which was */
            /* guarranteed not to be zero (Label #1)         */

if (j<0 || j>=dim) { error_(); };
if (j<0 || j>=dim) { error_(); };
        // Local variables declaration of int k and double recp moved 
	// on function header.   
	recp =  1 / A[j][j];
        	   
	
            for (k=j+1; k<M; k++){
if (k<0 || k>=dim) { error_(); };
if (j<0 || j>=dim) { error_(); };
                A[k][j] *= recp;
              }
        }


        if (j < minMN-1)
        {
            /* rank-1 update to trailing submatrix:   E = E - x*y; */
            /* E is the region A(j+1:M, j+1:N) */
            /* x is the column vector A(j+1:M,j) */
            /* y is row vector A(j,j+1:N)        */

            //int ii;
            for (ii=j+1; ii<M; ii++)
            {
if (ii<0 || ii>=dim) { error_(); };
                //double *Aii = A[ii];
		Aii = A[ii];

if (j<0 || j>=dim) { error_(); };
               // double *Aj = A[j];
	 	 Aj = A[j];

if (j<0 || j>=dim) { error_(); };
                //double AiiJ = Aii[j];
                //int jj;
        	 AiiJ = Aii[j];
                jj;
       

	 for (jj=j+1; jj<N; jj++){
if (jj<0 || jj>=dim) { error_(); };
if (jj<0 || jj>=dim) { error_(); };
                  Aii[jj] -= AiiJ * Aj[jj];
                }

            }
        }
    }

    return 0;
}

