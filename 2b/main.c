#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    unsigned long long num = 2, prime, i;
    int is_prime;
    clock_t t1;

    t1 = clock();
    while( ((clock() - t1)/(double)(CLOCKS_PER_SEC)) < 1799.9 ) {
        is_prime = 0;
        for(i=2;i<num;i++){
			if(num%i==0){
                is_prime = 1;
                break;
			}
		}
		if(is_prime == 0) prime = num;
        num++;
    }
    printf("Largest prime: %llu", prime);
    return 0;
}
