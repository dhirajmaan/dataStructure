#include <iostream>
using namespace std;

void inplaceHeapSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        //down heapify
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (arr[parentIndex] > arr[childIndex])
            {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int n = size;
    while (n > 1)
    {
        int temp = arr[n - 1];
        arr[n - 1] = arr[0];
        arr[0] = temp;
        n--;

        //down heapify
        int parentIndex = 0;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;
        while (leftChildIndex < n)
        {
            int minIndex = parentIndex;

            if (arr[minIndex] > arr[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (arr[minIndex] > arr[rightChildIndex] and rightChildIndex < n)
            {
                minIndex = rightChildIndex;
            }
            if (parentIndex == minIndex)
            {
                break;
            }
            //swap
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = (2 * parentIndex) + 2;
        }
    }
}
int main()
{
    int arr[] = {3, 2, 5, 1};
    int size = 4;
    inplaceHeapSort(arr, size);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}