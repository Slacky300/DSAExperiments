#include <stdio.h>
#include <stdlib.h>




void bubbleSort(int a[],int n)
{
    int temp;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }


}



int partitionA(int a[],int l,int h)
{

    int pivot = a[l],i = l+1,j = h,temp;

    do
    {

        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }

        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    while(i<j);

    temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[],int l,int h)
{

    int partition;

    if(l<h)
    {
        partition = partitionA(a,l,h);
        quickSort(a,l,partition-1);
        quickSort(a,partition+1,h);
    }

}

void insertionSort(int a[],int n)
{

    int hold,j;
    for(int i = 0; i<n; i++)
    {
        hold = a[i];
        j = i-1;
        while(j>=0 && a[j]>hold)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = hold;
    }
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;


    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);


        heapify(arr, i, 0);
    }
}


void display(int a[],int n)
{

    for(int i = 0; i<n; i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");
}

void main()
{


    int a[] = {41,25,1,96,87,24};
    int v = sizeof(a)/sizeof(a[0]);
    printf("Sorted array : ");
    //bubbleSort(a,v);
    //quickSort(a,0,v-1);
    //insertionSort(a,v);
    heapSort(a,v);

    display(a,v);

}
