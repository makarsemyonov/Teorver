#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EDGE 6

int rollDice();
double runExperiment(long long num, int *results, double *chances);
void printResults(long long num, int *results, double *chances, double cpu_time_used);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./diceroll <num of rolls>\n");
        return 1;
    }
    long long num = atoll(argv[1]);
    int results[EDGE] = {0, 0, 0, 0, 0, 0};
    double chances[EDGE] = {0, 0, 0, 0, 0, 0};
    srand(time(0));
    double time = runExperiment(num, results, chances);
    printResults(num, results, chances, time);
    return 0;
}

int rollDice(){
    int number = (rand() % EDGE) + 1;
    return number;
}

double runExperiment(long long num, int *results, double *chances){
    int step;
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for (size_t i = 0; i < num; ++i){
        step = rollDice();
        results[step-1]++;
    }
    for (size_t i = 0; i < EDGE; ++i){
        chances[i] = (double)results[i]/num;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

void printResults(long long num, int *results, double *chances, double cpu_time_used){
    printf("Количество бросков: %lld\n", num);
    printf("Номера граней | Кол-во выпадений | Рассчитанная вер-ть\n");
    for (size_t i = 0; i < EDGE; ++i){
        printf("\t%ld\t|\t%d\t|\t%e\n", i+1, results[i], chances[i]);
    }
    printf("\n");

    printf("Время выполнения: %f миллисекунд\n", cpu_time_used * 1000);
}