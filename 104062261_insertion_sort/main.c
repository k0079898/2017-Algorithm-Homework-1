#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    FILE *input, *output;
    int *Buffer;
    char text[20];
    int size, num, i, j, key;

    input = fopen("input.txt", "r");
    fgets(text, 20, input);
    size = atoi(text);
    //printf("Test case size:%d\n", size);
    fgets(text, 20, input);
    num = atoi(text);
    //printf("%d\n", num);
    Buffer = calloc(size, sizeof(int));
    for(i=0;i<size;i++) {
        //fgets(text, 20, input);
        fscanf(input, "%s", text);
        //printf("%d\n", atoi(text));
        Buffer[i] = atoi(text);
    }
    fclose(input);

    for(i=1;i<size;i++) {
        key = Buffer[i];
        j = i - 1;
        while(j >= 0 && Buffer[j] > key) {
            Buffer[j+1] = Buffer[j];
            j = j - 1;
        }
        Buffer[j+1] = key;
    }

    output = fopen("output.txt", "w");
    fprintf(output, "%d", Buffer[num-1]);
    fclose(output);

    free(Buffer);
    return 0;
}
