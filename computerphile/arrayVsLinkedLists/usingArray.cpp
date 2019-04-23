
#include <stdio.h>
#include <stdlib.h>

struct arrayItem{
  int p, q;
  arrayItem(int a=0, int b=0){
    this->p = a;
    this->q = b;
  }
};

int sumArray(arrayItem *a, int n){
  int sum = 0;
  for (int i=0; i<n; i++) sum+=a[i].p;
  return sum;
}

int main(int argc, char **argv){
  int n = 100;
  arrayItem *a = new arrayItem[n];
  for (int i=0; i<n; i++){
    a[i].p = rand();
  }
  printf("%d\n", sumArray(a, n));
  return 0;
}
