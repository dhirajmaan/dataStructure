#include <iostream>
#include <stack>
using namespace std;
bool redudant(string s)
{
    stack<char> ss;
    for (int i = 0; i < s.size(); i++)
    {
        //if we have ( or + or - or * or / push it into a stack
        //if we have ) then there must be one or more operator in the top of stack
        //when we encounter ) then the top should not have (
        //example (a) or a+(b) or

        if (s[i] == '(' or s[i] == '+' && s[i] == '-' or s[i] == '*' or s[i] == '/')
        {
            ss.push(s[i]);
            continue;
        }
        if (s[i] == ')')
        {
            if (ss.top() == '(')
            {
                return true;
            }
            //pop our any operator and after that the bracket as well
            while (ss.top() == '+' or ss.top() == '-' or ss.top() == '*' or ss.top() == '/')
            {
                ss.pop();
            }
            ss.pop();
        }
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    cout << redudant(s) << endl;

    return 0;
}

/*
if (s[i] == '(' or s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
        {
            ss.push(s[i]);
            continue;
        }
        else if (s[i] == ')')
        {
            if (ss.top() == '(')
            {
                return true;
            }
            ss.pop();
            if (ss.top() != '(')
            {
                return true;
            }
            else
            {
                if (ss.empty())
                {
                    return true;
                }
                ss.pop();
            }
        }
*/