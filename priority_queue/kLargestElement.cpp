#include <iostream>
using namespace std;
#include <queue>
void kLargestElement(int *arr, int size, int k)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < k; i++)
    {
        p.push(arr[i]);
    }
    for (int i = k; i < size; i++)
    {
        if (p.top() < arr[i])
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
}
int main()
{
    int arr[] = {12, 15, 7, 4, 9, 0, 2};
    int size = sizeof(arr) / sizeof(int);
    kLargestElement(arr, size, 3);
    return 0;
}