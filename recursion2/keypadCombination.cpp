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

int keypadCombination(string num, string *output)
{
    if (num.empty())
    {
        output[0] = "";
        return 1;
    }
    int smallOutputSize = keypadCombination(num.substr(1), output);
    string option = getString(num[0]);

    for (int i = 0; i < option.length() - 1; i++)
    {
        for (j = 0; i < count; i++)
        {
            /* code */
        }
    }
}
int main()
{
    string num;
    cin >> num;
    string *output = new string[1000];
    int outputSize = keypadCombination(num, output);
    for (int i = 0; i < outputSize; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}