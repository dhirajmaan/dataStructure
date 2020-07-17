#include <iostream>
using namespace std;
bool isSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    bool smallerOutput = isSorted(arr + 1, size - 1);
    return smallerOutput;
}

int main()
{
    int arr[] = {1,3,5,6,7};
    cout << isSorted(arr, 5) << endl;
}