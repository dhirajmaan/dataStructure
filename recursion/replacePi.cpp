#include <iostream>
using namespace std;

int length(char *input)
{
    int len = 0;
    int i = 0;

    while (input[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}
void replacePi(char *input)
{
    if (input[0] == '\0')
    {
        return;
    }
    replacePi(input + 1);

    if (input[0] == 'p' && input[1] == 'i')
    {
        int len = length(input);
        for (int i = len - 1; i >= 2; i--)
        {
            input[i + 2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}
int main()
{
    char input[100];
    cin >> input;
    replacePi(input);
    cout << input;
}