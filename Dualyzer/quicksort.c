void quick_sort(float a[], int l, int h);
int partition(float a[], int l, int h);
int changeM(float a[], int m, int i, int h, float v);
void swap(float a[], int i, int j);

void error_() {
ERROR: goto ERROR;
} 

int dim=10;

int main() {
  float A[10]={9,8,7,6,5,4,3,2,1,0};
  //printf("unsorted vector: %1.0f-%1.0f-..\n",A[0],A[1]);
  quick_sort(A,0,dim-1);
  //printf("sorted vector: %1.0f-%1.0f-..\n",A[0],A[1]);
}

void quick_sort(float a[], int l, int h) {
  if (l<h) {
    int p=partition(a,l,h);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,h);
  }
}

int partition(float a[], int l, int h) {
  if (l<0 || l>=dim) { error_(); };
  float v=a[l];
  int j=l+1;
  int m=changeM(a,l,j,h,v);
  swap(a,l,m);
  return m;
}

int changeM(float a[], int m, int i, int h, float v) {
  while (i<=h) {
    if (i<0 || i>=dim) { error_(); };
    if (a[i]<v) {
      swap(a,m+1,i);
      m=m+1;i=i+1;
      continue;
    } else {
      i=i+1;
      continue;
    }
  }
  return m;
}

void swap(float a[], int i, int j) {
  if (i<0 || i>=dim) { error_(); };
  float t=a[i];
  if (i<0 || i>=dim) { error_(); };
  if (j<0 || j>=dim) { error_(); };
  a[i]=a[j];
  if (j<0 || j>=dim) { error_(); };
  a[j]=t;
}
