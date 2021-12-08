#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;
    char x;
    for (int i = 0; i < s.length(); i++)
    {
        // cout << s.length() << endl;
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            continue;
        }
        //if there is no any of the opening bracket
        if (st.empty())
        {
            return false;
        }
        switch (s[i])
        {
        case ')':
            x = st.top();
            st.pop();
            if (x == '{' || x == '[')
            {
                return false;
            }
            break;

        case '}':
            x = st.top();
            st.pop();
            if (x == '(' || x == '[')
            {
                return false;
            }

            break;

        case ']':
            x = st.top();
            st.pop();
            if (x == '(' || x == '{')
            {
                return false;
            }
            break;
        }
    }
    return (st.empty());
}
int main()
{
    cout << isBalanced("[{{()}(){}}]");

    return 0;
}