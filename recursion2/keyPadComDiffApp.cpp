#include <iostream>
using namespace std;

string getString(char num)
{
    if (num == '2')
    {
        return "abc";
    }
    if (num == '3')
    {
        return "def";
    }
    if (num == '4')
    {
        return "ghi";
    }
    if (num == '5')
    {
        return "jkl";
    }
    if (num == '6')
    {
        return "mno";
    }
    if (num == '7')
    {
        return "pqrs";
    }
    if (num == '8')
    {
        return "tuv";
    }
    if (num == '9')
    {
        return "wxyz";
    }
}

void printComb(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }
    for (int i = 0; i < getString(input[0]).size(); i++)
    {
        printComb(input.substr(1), output + getString(input[0])[i]);
    }
}
int main()
{
    string input;
    cin >> input;
    string output = "";

    printComb(input, output);

    return 0;
}