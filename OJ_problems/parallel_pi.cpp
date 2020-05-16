#include<stdio.h>
#include<omp.h>

int main(){
    double sum = 0, s = 1.0, t = 1.0;
    int i;
    
    #pragma omp parallel for reduction(+: sum)
    for(i = 1; i < 10001; i+=2){
        sum += t/i;
        t*=-1;
    }
    printf("%f", sum*4);
    return 0;
}