#include <stdio.h>

int factorial(int n){
    return n>0 ? n*factorial(n-1) : 1;
}

int main(){
  int n=8;
  printf("%d! = %d\n",n,factorial(n));
}
