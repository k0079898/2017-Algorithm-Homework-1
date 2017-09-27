#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *input, *output;
    char s[50];
    unsigned long long num, i;
    int is_prime = 0;

    input = fopen("input_prime.txt", "r");
    fgets(s, 50, input);
    num = atoll(s);
    printf("%llu\n", num);
    fclose(input);

    output = fopen("output_prime.txt", "w");
    if(num==1) {
        fprintf(output, "F\n1\n");
    }else {
        for(i=2;i<num;i++){
			if(num%i==0){
                if(is_prime == 0) {
                    fprintf(output, "F\n1");
                    is_prime = 1;
                }
				fprintf(output, " %llu", i);
			}
		}
		if(is_prime == 0) fprintf(output, "T");
		fprintf(output, "\n");
    }
    fclose(output);

    return 0;
}
