#include <vector>
#include <unordered_map>
//  #include<map>
#include <iostream>
#include <climits>
using namespace std;
int maximumFrequency(int *arr, int n)
{
    unordered_map<int, int> f;
    for (int i = 0; i < n; i++)
    {
        ++f[arr[i]];
    }
    for (auto i : f)
    {
        cout << "key " << i.first << " "
             << "value " << i.second << endl;
    }
    // int max = INT_MIN;
    // int ans;
    // for (auto i : f)
    // {
    //     if (i.second > max)
    //     {
    //         max = i.second;
    //         ans = i.first;
    //     }
    // }
    // return ans;
}
int main()
{
    // int arr[] = {2, 12, 2, 11, -12, 2, -1, 2, 2, 11, 12, 2, -6, -1, -1, -1, 1, -1, -1, -1, -1, -1};
    int arr[] = {4, -5, 1};
    cout << maximumFrequency(arr, 3) << endl;
    return 0;
}