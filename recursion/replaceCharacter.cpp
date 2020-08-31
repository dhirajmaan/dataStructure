#include <iostream>
using namespace std;
void replace(char *input, char a, char b)
{
    if (input[0] == '\0')
    {
        return;
    }
    replace(input + 1, a, b);
    if (input[0] == a)
    {
        input[0] = b;
    }
    return;
}
int main()
{
    char input[100];
    //relace a with b
    char a, b;
    cin >> input >> a >> b;
    cout << input << endl
         << a << endl
         << b << endl;
    replace(input, a, b);
    cout << input;
}