/*suppose you have a string S made up of only 'a's and 'b's .write a recursive function 
that checks if the string was generated using the folloeing rules 
a. the string begins with an 'a'
b. each 'a' is followed by nothing or an 'a' or 'bb'
c. each 'bb' is followed by nothing or an 'a'

if all the rules are followed by the given string return true otherwise return false
*/
#include <iostream>
using namespace std;
bool checkAB(string input)
{
    if (input.length() == 0)
    {
        return true;
    }
    if (input[0] == 'a')
    {
        if (input.substr(1, 2) == "bb" && input.substr(1).length() > 1)
        {
            return checkAB(input.substr(3));
        }
        else
        {
            return checkAB(input.substr(1));
        }
    }
    else
    {
        return false;
    }
}
int main()
{
    string input;
    cin >> input;
    cout << checkAB(input);
    return 0;
}