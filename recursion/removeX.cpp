#include <iostream>
using namespace std;

// int length(char *input1)
// {
//     int len = 0;
//     int i = 0;

//     while (input1[i] != '\0')
//     {
//         len++;
//         i++;
//     }
//     return len;
// }
void replaceX(char *input)
{
    if (input[0] == '\0')
    {
        return;
    }
    replaceX(input + 1);
    if (input[0] == 'x')
    {
        //int len = length(input);
        for (int i = 0; input[i] != '\0'; i++)
        {
            input[i] = input[i + 1];
        }
    }
    else
    {
        return;
    }
}

int main()
{
    char input[100];
    cin >> input;
    replaceX(input);

    cout << input;
}