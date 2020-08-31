#include <iostream>
#include <math.h>
using namespace std;
int subSequence(string input, string *output)
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1);
    int smallOutputSize = subSequence(smallString, output);
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return (2 * smallOutputSize);
}
int main()
{
    string input;
    cin >> input;
    int size = input.length();
    size = pow(2, size);
    cout << size << endl;

    string *output = new string[size];
    int o = subSequence(input, output);
    for (int i = 0; i < o; i++)
    {
        cout << output[i] << endl;
    }
    delete output;
    return 0;
}