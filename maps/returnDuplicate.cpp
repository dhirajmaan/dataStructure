#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicate(int *arr, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(arr[i]) > 0)
        {
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 3, 2, 1, 6, 78, 9, 9, 78};
    int size = 13;
    vector<int> output = removeDuplicate(arr, size);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}