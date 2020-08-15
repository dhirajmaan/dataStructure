#include <iostream>
#include <string>
using namespace std;
bool palindromeHelper(string input, int si, int ei)
{
    if ((ei - si + 1) <= 1)
    {
        return true;
    }
    if (input[si] == input[ei])
    {

        return (true || palindromeHelper(input, si + 1, ei - 1));
    }
    else
    {
        return false;
    }
}
bool palindrome(string input)
{
    int si = 0;
    int ei = input.length() - 1;

    return palindromeHelper(input, si, ei);
}

int main()
{
    string input;
    cin >> input;
    cout << palindrome(input);
}