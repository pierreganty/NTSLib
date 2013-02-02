void _error() {
ERROR: goto ERROR;
} 

int dim=10;

void main()
{
  float A[10][10];
  init_arrF2(A,0,0,dim-1,dim-1);
  SOR_execute(dim,dim,1.25,A,1);
}




void init_arrF2(float a[10][], int i, int j, int m, int n)
{
  while (i<=n) {
    j=0;
    while(j<=m) {
   	  if (i<0 || i>=dim) { _error(); };
   	  if (j<0 || j>=dim) { _error(); };
      a[i][j]=0;
      j++;
    }
    i++;
  }
}



void SOR_execute(int M, int N, float omega, float G[][], int num_iterations) {
  double omega_over_four = omega * 0.25;
  double one_minus_omega = 1.0 - omega;
  int Mm1=M-1;
  int Nm1=N-1;
  int p;
  int i;
  int j;
        double *Gi;
        double *Gim1;
        double *Gip1; 
        for (p=0; p<num_iterations; p++)
        {
            for (i=1; i<Mm1; i++)
            {
if (i<0 || i>=dim) { _error(); };
                Gi = G[i];
if (i-1<0 || i-1>=dim) { _error(); };
                Gim1 = G[i-1];
if (i+1<0 || i+1>=dim) { _error(); };
                Gip1 = G[i+1];
                for (j=1; j<Nm1; j++){
if (j<0 || j>=dim) { _error(); };
if (j<0 || j>=dim) { _error(); };
if (j<0 || j>=dim) { _error(); };
if (j-1<0 || j-1>=dim) { _error(); };
if (j+1<0 || j+1>=dim) { _error(); };
if (j<0 || j>=dim) { _error(); };
                    Gi[j] = omega_over_four * (Gim1[j] + Gip1[j] + Gi[j-1] 
                                + Gi[j+1]) + one_minus_omega * Gi[j];
                }
            }
        } 
}
