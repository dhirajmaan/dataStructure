#include <iostream>
using namespace std;

void subSequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    subSequence(input.substr(1), output);
    subSequence(input.substr(1), output + input[0]);
}
int main()
{
    string input;
    cin >> input;
    string output = "";
    subSequence(input, output);
    return 0;
}