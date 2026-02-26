#include <stdio.h>
void count(int numAr[], int numArSize);
int main() {
    int score1[] = {7,11,9,8};
    int score2[] = {7,11,9,8};
    int top3[3];

    for (int i = 0; i < 3; i++) {
        int max = 0;
        for (int j = 1; j < 4; j++) {
            if (score1[j] > score1[max]) {
                max = j;
        }
        }
        top3[i] = score1[max];
        score1[max] = -1;
    }
    for (int i = 0; i < 3; i++) {
        printf("%d ", top3[i]);
    }
    
    printf("\n");

    count(score2,4);
    for (int i = 1; i < 4; i++) {
        top3[i-1] = score2[i];
    }
    for (int i = 0; i < 3; i++) {
        printf("%d ", top3[i]);
    }

    return 0;
}

void count(int numAr[], int numArSize) {
    int i, j, t;
    for (i = 0; i < numArSize - 1; i++) {
        for (j = 0; j < numArSize - i - 1; j++) {
            if (numAr[j] > numAr[j+1]) {
                t = numAr[j];
                numAr[j] = numAr[j+1];
                numAr[j+1] = t;
            }
        }
    }
}
