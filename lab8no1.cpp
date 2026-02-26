#include <stdio.h>
void addthree(int number[], int pos[][2], int sizePos); 

int main() {

    int number[5] = {10,20,30,40,50};
    int pos[][2] = {{1,5},{3,10},{4,2}};

    int size = sizeof(pos) / sizeof(pos[0]);
    addthree(number, pos, size);

    for(int i=0; i<5; i++)
        printf("%d ",number[i]);

    return 0;
}

void addthree(int number[],int pos[][2],int sizePos) {
    for(int i = 0; i < sizePos; i++) {
        int index = pos[i][0];
        int value = pos[i][1];
        number[index] += value;
    }
}

