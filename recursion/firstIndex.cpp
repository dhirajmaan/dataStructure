/*we should return the first index of the element given to us 
in array 1|3|5|6|5|9
if num is 5 the we should return 2
*/
#include <iostream>
using namespace std;
int firstIndex(int arr[], int size, int num)
{
    if (size == 0)
    {
        return -1;
    }
    if (arr[0] == num)
    {
        return 0;
    }
    int ans = firstIndex(arr + 1, size - 1, num);
    if (ans != -1)
    {
        return ans + 1;
    }
    else
    {
        return ans;
    } 
}
int main()
{
    int arr[] = {6, 5, 7, 8, 99, 33, 11};
    int size = 7;
    int num = 7;
    cout << firstIndex(arr, size, num) << endl;
}