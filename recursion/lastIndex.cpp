#include <iostream>
using namespace std;
int lastIndex(int *arr, int size, int num)
{
    if (size == 0)
    {
        return -1;
    }
    int ans = lastIndex(arr + 1, size - 1, num);
    if (ans == -1)
    {
        if (arr[0] == num)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return ans + 1;
    }
}

int main()
{
    int arr[] = {6, 5, 7, 8, 99, 5, 11};
    int size = 7;
    int num = 5;
    cout << lastIndex(arr, size, num) << endl;
}