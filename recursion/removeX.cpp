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
        int i = 1;
        for (; input[i] != '\0'; i++)
        {
            input[i - 1] = input[i];
        }
        input[i - 1] = input[i]; //to copy null chracter also

        remove(input); /*if the string have 2 'x' simultaneously xxwteyg
                          first and then call to input+1 and the x will be remaning 
                          so we need to call removeX() on the same string again*/
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