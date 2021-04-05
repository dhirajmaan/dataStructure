#include <iostream>
using namespace std;
int length(char *input)
{
    if (input[0] == '\0')
    {
        return 0;
    }
    return 1 + length(input + 1);
}
void pairStar(char *input)
{
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] == input[1])
    {
        int len = length(input);
        for (int i = len; i >= 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
    }
    pairStar(input + 1);
}
int main()
{
    char input[100];
    cin >> input;
    cout << input << endl;
    pairStar(input);
    cout << input << endl;
    return 0;
}