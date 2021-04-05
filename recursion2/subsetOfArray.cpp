#include <iostream>
using namespace std;

int subSet(int *arr, int size, int output[][100])
{
    if (size == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    int smallOutput = subSet(arr + 1, size - 1, output);
    for (int i = 0; i < smallOutput; i++)
    {
        output[i + smallOutput][0] = output[i][0] + 1;
        for (int j = 1; j <= output[i][0]; j++)
        {
            if (j == 1)
                output[i + smallOutput][j] = arr[0];
            else
                output[i + smallOutput][j] = output[i][j - 1];
        }
    }
    return smallOutput * 2;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    int output[100][100];
    int lenOfRows = subSet(arr, size, output);
    for (int i = 0; i < lenOfRows; i++)
    {
        for (int j = 1; j < output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}