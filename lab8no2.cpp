#include <stdio.h>
int checkscore(char std[], char keys[]);
void ansno1(char std[][10], char key[]);
void HardestQ(char std[][10], char key[]);

int main() {
    int i;
    char ans[8][10] = {
        {'A','B','A','C','C','D','E','E','A','D'}, //7
        {'D','B','A','B','C','A','E','E','A','D'}, //6
        {'E','D','D','A','C','B','E','E','A','D'}, //5
        {'C','B','A','E','D','C','E','E','A','D'}, //4
        {'A','B','D','C','C','D','E','E','A','D'}, //8
        {'B','B','E','C','C','D','E','E','A','D'}, //7
        {'B','B','A','C','C','D','E','E','A','D'}, //7
        {'E','B','E','C','C','D','E','E','A','D'}  //7
    };

    char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};

    for(i = 0; i < 8; i++) {
        printf("std %d => %d\n", (i+1), checkscore(ans[i], keys));
    }

    ansno1(ans, keys);
    HardestQ(ans, keys);

    return 0;
}

int checkscore(char std[], char keys[]) {
    int score = 0;
    for (int i = 0; i < 10; i++) {
        if (std[i] == keys[i]) {
            score++;
        }
    }
    return score;
}

void ansno1(char std[][10], char key[]) {
    int n = 0;
    for (int i = 0; i < 8; i++) {
        if (std[i][0] == key[0]) {
            n++;
        }
    }
    printf("Q1 answer correct is %d\n", n); 
}

void HardestQ(char std[][10], char key[]) {
    int low = 8;
    int high = 1;

    for (int i = 0; i < 10; i++) {
        int Correct = 0;
        for (int j = 0; j < 8; j++) {
            if (std[j][i] == key[i]) {
                Correct++;
            }
        }
        if (Correct < low) {
            low = Correct;
            high = i + 1;
        }
    }
    printf("Hardest Q is %d\n", high);
}
