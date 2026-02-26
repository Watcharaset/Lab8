#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random1to100();
void printAr(int numAr[],int numArSize);
int checkNum(int numAr[],int numArSize);
int searchNum(int numAr[],int numArSize,int target);
int searchNum2(int numAr[], int numArSize, int target);

int main() {
    int N,i,j,New;
    int A1[100];
    int A2[100];
    scanf("%d",&N);
    if (N>100) 
        N=100;
    srand(time(NULL));
    for (i=0;i<N;i++) {
        New=checkNum(A1,i);
        j = i-1;
        while (j >= 0 && A1[j] > New) {
            A1[j + 1] = A1[j];
            j--;
        }
        A1[j + 1] = New;
	}
       
    printf("\n********\nLinear Search : ");
    printAr(A1,N);
    printf("\nBinary Search : ");
    for (i = 0; i < N; i++) {
        New = checkNum(A2, i); 
        j = i - 1;
        while (j >= 0 && A2[j] > New) {
            A2[j + 1] = A2[j];
            j--;
        }
        A2[j + 1] = New;
    }
    printAr(A2,N);
    return 0;
}

void printAr(int numAr[],int numArSize) {
    int i;
    for (i=0;i<numArSize;i++)
        printf("%d ",numAr[i]);
} 

int checkNum(int numAr[],int numArSize) {
    int rnum;
    rnum=random1to100();
    while (searchNum(numAr,numArSize,rnum)) {
        rnum=random1to100();
    }
    return rnum;
}

int searchNum(int numAr[], int numArSize, int target) {
    int i, found = 0;
    for (i = 0; i < numArSize; i++) {
        if (numAr[i] == target) {
            found = 1;
            break;
        }
    }
    return found;
}

int searchNum2(int numAr[],int numArSize, int target) {
    int left = 0,right = numArSize - 1;
    int found = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (numAr[mid] == target) {
            found = 1; 
            break;
        }
        if (numAr[mid] < target) {
            left = mid + 1; 
        } 
        else {
            right = mid - 1; 
        }
    }
        return found;
}

int random1to100() {
    int random_num = (rand() % 100) + 1;
    printf("%d ", random_num);
    return random_num;
}

