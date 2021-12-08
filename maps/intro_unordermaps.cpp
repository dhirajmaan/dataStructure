#include <iostream>
using namespace std;
#include <unordered_map>
int main()
{
    unordered_map<string, int> mymap;
    //insering into the maps
    pair<string, int> p("abc", 1);
    mymap.insert(p);
    mymap["def"] = 2;

    //access it
    cout << mymap.at("abc") << endl;
    cout << mymap["def"] << endl;
    //this line has inserted "ghi" into our map ans assigned it to 0
    cout << mymap["ghi"] << endl;
    //check presence
    cout << mymap.count("ghi") << endl;
    cout << mymap.count("jkl") << endl;
    //check map size
    cout << mymap.size() << endl;

    //delete from our map
    mymap.erase("abc");
    cout << mymap.size() << endl;




}