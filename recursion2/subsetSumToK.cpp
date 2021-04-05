#include <iostream>
using namespace std;
int sumOfSubSetToK(int *input, int size, int k, int output[][100])
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    int input[] = {1, 2, 3, 4, 5, 2};
    int size = sizeof(input) / sizeof(int);
    int output[100][100];
    int k = 3;
    int noOfRows = sumOfSubSetToK(input, size, k, output);

    return 0;
}