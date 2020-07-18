/*given an array length N and an integer x.
You need to find if x is present in the array or not.
Return true or false*/

#include <iostream>
using namespace std;
bool find(int arr[], int size, int num)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] == num)
    {
        return true;
    }
    find(arr + 1, size - 1, num);
}
int main()
{
    int arr[] = {6, 5, 6, 8, 99, 33, 7};
    int size = 7;
    int num = 99;
    cout << find(arr, size, num);
}