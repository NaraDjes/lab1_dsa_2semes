#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
int getrand(int min, int max)
{
 return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void MergeSort(int *arr,int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = floor((low+high)/2);
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}
void Merge(int *arr, int low, int mid, int high)
{
    int n = high+1;
    int B[n];
    for (int i = low; i<=high;i++)
    {
        B[i] = arr[i];
    }
    int l,r,i;
    l = low;
    r = mid + 1;
    i = low;
    while (l <= mid && r <=high)   
    {
        if (B[l] <= B[r])
            {
                arr[i] = B[l];
                l = l + 1;
            }
        else
        {
            arr[i] = B[r];
            r = r + 1;
        }
        i = i+1;
    }
    while (l <= mid)
    {
        arr[i] = B[l];
        l = l + 1;
        i = i + 1;
    }
    while (r <= high)
    {
        arr[i] = B[r];
        r = r + 1;
        i = i + 1;
    } 
}
void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    double t;
    t = wtime();
    int n = 50000;
    int arr[n];
    for (int i = 0; i<n;i++)
        arr[i] = getrand(0,100000);
    MergeSort(arr,0,n-1);
    printf("Sorted array: \n");
    printArray(arr, n); 
    t = wtime() - t;
    printf("time = %lf\n",t);
    return 0;
}
