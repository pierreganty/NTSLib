void msort (float a[], int i, int j);
void merge (float a[], int i, int iu, int ju);
void mergeF2 (float a[], float t[], int i, int iu, int j, int ju, int k);
void copyseq (float a[], float t[], int i, int j, int k);

void error_() {
ERROR: goto ERROR;
} 

int dim = 10;

int main()
{
  float A[10] = {9,8,7,6,5,4,3,2,1,0};
  //printf("unsorted vector: %1.0f-%1.0f-..\n",A[0],A[1]); 
  msort(A,0,dim-1);
  //printf("sorted vector: %1.0f-%1.0f-..\n",A[0],A[1]); 
}
  
void msort (float a[], int i, int j) { 
  if (i>=j) { return; }
  else { 
    int m = (i+j)/2;
    msort (a,i,m);
    msort (a,m+1,j);
    merge (a,i,m,j);
  }
}

void merge (float a[], int i, int iu, int ju) {
  int j = iu+1;
  int m = ju-i+1;
  if (m<=0) { error_(); };
  float t[m];
  mergeF2 (a,t,i,iu,j,ju,0);
  copyseq (t,a,0,m-1,i);
}

void mergeF2 (float a[], float t[], int i, int iu, int j, int ju, int k) {
  if (i>iu)  { copyseq (a,t,j,ju,k); }
  else {
    if (j>ju) { copyseq (a,t,i,iu,k); }
    else {
      if (i<0 || i>=dim) { error_(); };
      if (j<0 || j>=dim) { error_(); };
      if (a[i] <= a[j]) {
        if (k<0 || k>=dim) { error_(); };
        if (i<0 || i>=dim) { error_(); };
        t[k]=a[i];
        mergeF2 (a,t,i+1,iu,j,ju,k+1);
      } else {
        if (k<0 || k>=dim) { error_(); };
        if (j<0 || j>=dim) { error_(); };
        t[k]=a[j];
        mergeF2 (a,t,i,iu,j+1,ju,k+1);
      }
    }
  }
}

void copyseq (float a[], float t[], int i, int j, int k) {
  if (i>j) { return; }
  else {
    if (k<0 || k>=dim) { error_(); };
    if (i<0 || i>=dim) { error_(); };
    t[k] = a[i];
    copyseq (a, t, i+1,j, k+1);
  }
}
