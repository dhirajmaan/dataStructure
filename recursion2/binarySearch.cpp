#include <iostream>
using namespace std;

int binarySearch_helper(int arr[], int si, int ei, int element)
{

    int mid = (si + (ei)) / 2;
    if (arr[mid] == element)
    {
        return mid;
    }
    if (arr[mid] < element)
    {
        return binarySearch_helper(arr, mid + 1, ei, element);
    }
    else if (arr[mid] > element)
    {
        return binarySearch_helper(arr, si, mid - 1, element);
    }
    else
        return -1;
}
int binarySearch(int *arr, int size, int element)
{
    return binarySearch_helper(arr, 0, size - 1, element);
}
int main()
{
    int arr[] = {0, 1, 5, 7, 8, 12, 15, 17, 85, 93, 104, 105};
    int size = sizeof(arr) / sizeof(int);
    int element = 105;
    cout << binarySearch(arr, size, element) << endl;

    return 0;
}