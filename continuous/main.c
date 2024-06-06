#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// alpha по умолчанию 2

int payload(int magic);
void fillArray(int M, int N, int magic, int array[][N], int* ones);
void countZeros(int M, int N, int array[][N], int zeros[][N]);
double getTheta(int M, int N, int zeros[][N],int* ones);

int main(int argc, char* argv[]) {
    srand(time(0));
    int M = atol(argv[1]);
    int N = atoi(argv[2]);
    int magic = atoi(argv[3]);
    int array[M][N];
    int zeros[M][N];
    int ones[M];
    double Theta;
    fillArray(M, N, magic, array, ones);
    countZeros(M, N, array, zeros);
    Theta = getTheta(M, N, zeros, ones);
    printf("M = %d N = %d p = %f \nα = 2 \nϴ = %e\n", M, N, 1.0/magic, Theta);
    return 0;
}

int payload(int magic){
    int number = (rand() % magic) + 1;
    if (number == magic)
        return 1;
    return 0;
}

void fillArray(int M, int N, int magic, int array[][N], int* ones){
    for (size_t i = 0; i < M; i++){
        for (size_t j = 0; j < N; j++){
            array[i][j] = payload(magic);
            if (array[i][j] == 1)
                ones[i]++;
        }
    }
}

void countZeros(int M, int N, int array[][N], int zeros[][N]){
    int count = 0;
    for (size_t i = 0; i < M; i++) {
        int index = 0;
        for (size_t j = 0; j < N; j++){
            if (array[i][j] == 1) {
                zeros[i][index] = count;
                count = 0;
                index++;
            } else {
                count++;
            }
        }
    }
}

double getTheta(int M, int N, int zeros[][N],int* ones){
    double sumOfZeros = 0;
    double sumOfOnes = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            sumOfZeros += zeros[i][j];
        }
        sumOfOnes += ones[i];
    }
    return sumOfZeros/sumOfOnes;
}