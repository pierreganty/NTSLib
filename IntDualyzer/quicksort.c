#include <assert.h>

void quick_sort(int a[], int l, int h);
int partition(int a[], int l, int h);
int changeM(int a[], int m, int i, int h, int v);
void swap(int a[], int i, int j);

void error_() {
assert(0);
} 

int dim=10;

int main() {
  int A[10]={9,8,7,6,5,4,3,2,1,0};
  //printf("unsorted vector: %1.0f-%1.0f-..\n",A[0],A[1]);
  quick_sort(A,0,dim-1);
  //printf("sorted vector: %1.0f-%1.0f-..\n",A[0],A[1]);
}

void quick_sort(int a[], int l, int h) {
  if (l<h) {
    int p=partition(a,l,h);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,h);
  }
}

int partition(int a[], int l, int h) {
  int v,j,m;
  if (l<0 || l>=dim) { error_(); };
   v=a[l];
   j=l+1;
   m=changeM(a,l,j,h,v);
  swap(a,l,m);
  return m;
}

int changeM(int a[], int m, int i, int h, int v) {
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

void swap(int a[], int i, int j) {
  int t;
  if (i<0 || i>=dim) { error_(); };
   t=a[i];
  if (i<0 || i>=dim) { error_(); };
  if (j<0 || j>=dim) { error_(); };
  a[i]=a[j];
  if (j<0 || j>=dim) { error_(); };
  a[j]=t;
}
