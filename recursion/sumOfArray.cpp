#include <iostream>
using namespace std;
int sum(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    int smallOutput = sum(arr + 1, size - 1);
    return arr[0] + smallOutput;
}
int main()
{
    int arr[] = {2, 5, 6, 7, 8, 4};
    cout << sum(arr, 6) << endl;
}