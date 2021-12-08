#include <iostream>
using namespace std;
#include <queue>
void kSortedArray(int *arr, int size, int k)
{
    //insert the first k element in the priority queue
    priority_queue<int> p;
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }

    int j = 0;
    for (int i = k; i < size; i++)
    {
        arr[j] = p.top();
        p.pop();
        p.push(arr[i]);
        j++;
    }
    while (!p.empty())
    {
        arr[j] = p.top();
        p.pop();
        j++;
    }
}
int main()
{
    int arr[] = {12, 15, 7, 4, 9};
    int size = sizeof(arr) / sizeof(int);
    kSortedArray(arr, size, 3);
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}