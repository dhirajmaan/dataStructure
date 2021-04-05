/*
Check AB
Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Sample Input:
abb
Sample Output:
true
*/
#include <iostream>
using namespace std;
bool check(string input)
{
    if (input.length() == 0)
    {
        return true;
    }
    if (input[0] != 'a')
    {
        return false;
    }
    if (input[1] == 'b' && input[2] == 'b')
    {
        return check(input.substr(3));
    }
    else
    {
        return false;
    }
    return check(input.substr(1));
}

int main()
{
    string input;
    cin >> input;
    cout << check(input);

    return 0;
}