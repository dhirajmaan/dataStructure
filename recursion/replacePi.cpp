#include <iostream>
using namespace std;

int length(char *input1)
{
    int len = 0;
    int i = 0;

    while (input1[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}
void replacePi(char *input1)
{
    if (input1[0] == '\0')
    {
        return;
    }
    replacePi(input1 + 1);

    if (input1[0] == 'p' && input1[1] == 'i')
    {
        int len = length(input1);
        for (int i = len - 1; i >= 2; i--)
        {
            input1[i + 2] = input1[i];
        }
        input1[0] = '3';
        input1[1] = '.';
        input1[2] = '1';
        input1[3] = '4';
    }
}
int main()
{
    char input1[100];
    cin >> input1;
    replacePi(input1);
    cout << input1;
}