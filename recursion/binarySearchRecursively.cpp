#include <iostream>
using namespace std;
int binarySearch(int *arr, int si, int ei, int key)
{
    int mid = (si+(ei-1))/ 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (key>arr[mid])
    {
       return  binarySearch(arr, mid + 1, ei, key);
    }
    if (key<arr[mid])
    {
        return binarySearch(arr, si, mid - 1, key);
    }

    return -1;
}
int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}