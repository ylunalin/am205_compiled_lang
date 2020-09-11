#include <stdio.h>  // For printf
#include <time.h>   // For clock_t, clock, CLOCKS_PER_SEC */
#include <cmath>    // For M_PI
#include <math.h>   // For abs, pow

inline double atan_expansion(double x, int i){
    return pow(-1.0, i)*pow(x, 2.*i+1.)/(2.*i+1.);
}

void gregory_approximate(double precision){
    double pi = 0.0, x=1.0;
    int i = 0;
    while(abs(M_PI - pi) > precision){
        pi += 4*atan_expansion(x, i);
        i++;
    }
    printf("Gregory: number of iterations = %d\n",i);
}

void machin_approximate(double precision){
    double pi = 0.0, x1=1./5., x2 = 1.0/239.0;
    int i = 0;
    while(abs(M_PI - pi) > precision){
        pi += 4*( 4*atan_expansion(x1,i) - atan_expansion(x2,i));
        i++;
    }
    printf("Machin: number of iterations = %d\n",i);
}

int main(){
    clock_t t1 = clock();
    gregory_approximate(pow(10.,-8.));
    clock_t t2 = clock();
    machin_approximate(pow(10.,-8.));
    clock_t t3 = clock();
    printf("gregory: %f seconds.\nmachin: %f seconds\n",
           ((float)(t2-t1))/CLOCKS_PER_SEC,
           ((float)(t3-t2))/CLOCKS_PER_SEC);
    return 0;
}
