#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool findNum(int *arr, int size, int element, int myIndex)
{
    for (int i = 0; i < size; i++)
    {
        if (i == myIndex)
        {
            continue;
        }
        if (arr[i] == element)
        {
            return false;
        }
    }
    return true;
}
vector<int> *unique(int *arr, int size)
{
    vector<int> *ans = new vector<int>;
    for (int i = 0; i < size; i++)
    {
        if (findNum(arr, size, arr[i], i))
        {
            ans->push_back(arr[i]);
        }
    }
    return ans;
}
void printUnique_map(int *arr, int size)
{
    map<int, int> myMap;

    for (int i = 0; i < size; i++)
    {
        myMap[arr[i]]++;
    }
    map<int, int>::iterator it = myMap.begin();
    while (it != myMap.end())
    {
        if (it->second == 1)
        {
            cout << it->first << " ";
        }
        it++;
    }
}

// Online IDE - Code Editor, Compiler, Interpreter

void findDuplicate(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count == 2)
        {
            cout << arr[i] << " ";
        }
    }
}


int main()
{
    int arr[] = {2, 3, 4, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    // vector<int> *output = unique(arr, size);
    // for (int i = 0; i < output->size(); i++)
    // {
    //     cout << output->at(i) << " ";
    // }
    // printUnique_map(arr, size);
    findDuplicate(arr, size);
    return 0;
}