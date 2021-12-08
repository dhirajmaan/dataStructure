#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    unordered_map<string, int> mymap;
    vector<pair<string, int>> v;
    mymap["a"] = 1;
    mymap["d"] = 21;
    mymap["f"] = 31;
    mymap["b"] = -5;
    auto it = mymap.begin();
    while (it != mymap.end())
    {
        // cout << it->first << ":" << it->second << endl;
        pair<string, int> temp(it->first, it->second);
        v.push_back(temp);
        it++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ":" << v[i].second<<" ";
    }

    return 0;
}