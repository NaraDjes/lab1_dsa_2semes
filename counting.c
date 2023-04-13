#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
void CoutingSort(int *A, int *B, int k,int n)
{
    int C[k];
    for (int i =  0; i<k; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i<n; i++)
    {
        C[A[i]] = C[A[i]] +1;
    }
    for (int i = 1; i<k; i++)
    {
        C[i] = C[i] +C[i-1];
    }
    for (int i = n - 1; i>=0; i--)
    {
        C[A[i]] = C[A[i]] - 1;
        B[C[A[i]]] = A[i];
    }
}
int max(int *A,int n)
{
    int maxi = 1;
    for (int i = 2; i < n; i++)
    {
        if (A[i] > A[maxi]) 
            maxi = i;
    }
    return A[maxi];
}
int main()
{
    double t = wtime();
    int n = 1000000;
    int arr[n];
    int arb[n];
    for (int i = 0; i<n;i++)
        arr[i] = getrand(0,100000);
    int k = max(arr,n) + 1;
    CoutingSort(arr,arb,k,n);
    for (int i = 0; i<n ; i++)
    {
        printf("%d ",arb[i]);
    }
    printf("\n");
    t = wtime() - t;
    printf("time = %lf\n",t);
}
