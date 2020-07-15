/* find out and return the number of digits present in the number recursively*/

#include <iostream>
using namespace std;
int count(int n){
    if(n%10==n){
        return 1;
    }
    return count(n/10)+1;
}
int main()
{
    cout<<"Enter the number"<<endl;
    int n;
    cin>>n;
    int ans=count(n);
    cout<<ans<<endl;
}