#include <iostream>
using namespace std;

void remove(char *input)
{
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] == input[1])
    {
        int i = 0;
        for (; input[i] != '\0'; i++)
        {
            input[i] = input[i + 1];
        }
        input[i] = input[i + 1];
        remove(input);
    }
    else
    {
        remove(input + 1);
    }
    return;
}
int main()
{
    char input[100];
    cin >> input;
    remove(input);
    cout << input;
    return 0;
}