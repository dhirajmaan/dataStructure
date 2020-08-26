#include <iostream>
#include <math.h>
using namespace std;
int length(char *input1)
{
    int len = 0;
    int i = 0;

    while (input1[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}
int convert(char *input)
{
    int len = length(input);
    if (len == 1)
    {
        return input[0] - '0';
    }
    int recursionAnswer = convert(input + 1);
    int myAnswer = input[0] - '0';
    int fianalAnswer = (myAnswer * (pow(10, len - 1))) + recursionAnswer;
    return fianalAnswer;
}
int main()
{
    char input[100];
    cin >> input;
    cout << convert(input);
}