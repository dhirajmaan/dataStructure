#include <iostream>
using namespace std;
int length(char *input)
{
    if (input[0] == '\0')
    {
        return 0;
    }
    int smallerStringLength = length(input + 1);
    return smallerStringLength + 1;
}
int main()
{
    char input[100];
    cin >> input;
    cout << length(input);
}