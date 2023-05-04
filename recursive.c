#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int n);
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

    // Note the order of appearance of elements should
    // be maintained - we copy elements of left subarray
    // first followed by that of right subarray

    // copy negative elements of left subarray
    while (i < n1 && L[i] < 0)
        arr[k++] = L[i++];

    // copy negative elements of right subarray
    while (j < n2 && R[j] < 0)
        arr[k++] = R[j++];

    // copy positive elements of left subarray
    while (i < n1)
        arr[k++] = L[i++];

    // copy positive elements of right subarray
    while (j < n2)
        arr[k++] = R[j++];
}
void SegregationPosNeg(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l + r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        SegregationPosNeg(arr, l, m);
         SegregationPosNeg(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main() {

   int Size, i, j = 0;

 printf("\n Please Enter the Size of an Array :  ");
 scanf("%d", &Size);
   int a[Size];
 printf("\n Please Enter the Array Elements  :  ");
 for(i = 0; i < Size; i++)
 {
      scanf("%d", &a[i]);
 }



    int n = sizeof(a) / sizeof(a[0]);

    printf("Given array is \n");
    printArray(a, Size);

    SegregationPosNeg(a, 0, n - 1);

    printf("Segregate array is \n");
    printArray(a, Size);
    return 0;


}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
