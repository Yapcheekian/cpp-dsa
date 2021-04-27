#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");;
    for(i=0; i<arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if(index > 0 && index <= arr->length)
    {
        for(i=arr->length; i>index; i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    
    if(index>=0 && index < arr->length)
    {
        x = arr->A[index];
        for(i=index; i < arr->length -1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for(i=0; i < arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while(l <= h)
    {
        mid = (l + h) / 2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(int a[], int l, int h, int key)
{
    if(l <= h)
    {
        int mid = (l + h) / 2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return RBinarySearch(a, l, mid - 1, key);
        else
            return RBinarySearch(a, mid + 1, h, key);
    }
    return -1;
}

void Reverse(struct Array *arr)
{
    int *B;
    int i, j;
    
    B = (int *)malloc(arr->length * sizeof(int));
    
    for(i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    
    for(i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr)
{
    int i, j;
    
    for(i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main(int argc, const char * argv[]) {
    
    struct Array arr = {{2,4,7,8,9}, 10, 5};
    Insert(&arr, 3, 100);
    Reverse2(&arr);
    Display(arr);
    printf("\nlinear search %d\n", BinarySearch(arr, 9));
    
    return 0;
}
