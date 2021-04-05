#include <iostream>
using namespace std;
void merge(int *arr, int si, int mid, int ei)
{
    int newSize = (ei - si) + 1;
    int *newArr = new int[newSize];
    int i = si;
    int j = mid + 1;
    int k = 0;
    while (i <= mid, j <= ei)
    {
        if (arr[i] < arr[j])
        {
            newArr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            newArr[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        newArr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= ei)
    {
        newArr[k] = arr[j];
        j++;
        k++;
    }
    int l = 0;
    for (int i = si; i <= ei; i++)
    {
        arr[i] = newArr[l];
        l++;
    }
}

void mergeSort(int *arr, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

int main()
{
    int arr[] = {2, 5, 6, 8, 1, 4, 7, 9, 8};
    int size = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}