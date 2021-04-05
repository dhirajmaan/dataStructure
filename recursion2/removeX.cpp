#include <iostream>
using namespace std;

void removeX(char *input)
{
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] == 'x')
    {
        int i = 1;
        for (; input[i] != '\0'; i++)
        {
            input[i - 1] = input[i];
        }
        input[i - 1] = input[i];
        removeX(input);
    }
    else
    {
        removeX(input + 1);
    }
}
int main()
{
    char str[100];
    cin >> str;
    removeX(str);
    cout << str;

    return 0;
}