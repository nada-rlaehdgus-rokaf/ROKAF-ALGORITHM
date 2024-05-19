#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;
int n;
bool comp(pair<int,int> t, pair<int,int> u )
{
    return t.second != u.second ? t.second < u.second : t.first < u.first;
}


int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin >> a>> b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end(),comp);
    
    //  for(int i=0; i<n; i++)
    // {
    //     cout << v[i].first <<" " << v[i].second <<"\n";
    // }
    
    //cout<<"Hello World";
    int last = 0;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(v[i].first >= last)
        {
            last = v[i].second;
            count ++;
        }
    }


    cout << count <<"\n";
    
    return 0;
}
