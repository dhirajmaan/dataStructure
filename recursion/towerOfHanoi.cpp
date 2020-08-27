#include <iostream>
using namespace std;
void towerOfHanoi(int n, char source, char destination, char auxilary)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, source, auxilary, destination);
    cout << source << "-->>>>" << destination << endl;
    towerOfHanoi(n - 1, auxilary, destination, source);
}
int main()
{
    int n = 3;
    char source = 's';
    char destination = 'd';
    char auxilary = 'a';
    towerOfHanoi(n, source, destination, auxilary);
}