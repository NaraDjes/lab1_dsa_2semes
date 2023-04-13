#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>  
int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubble_sort(int* array, int n)
{
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}
void Print_Array(int *array, int n)
{
    int i;
    for (i = 0; i < n ; ++i) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    double time_spent = 0.0;
    clock_t begin = clock();
    int n = 1000000;
    int array[n];
    for (int i = 0; i<n;i++)
        array[i] = getrand(0,100000);
    bubble_sort(array, n);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds\n", time_spent);
    return 0;
} 
