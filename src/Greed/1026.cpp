#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> a;
vector <int> b;
int cur[101];
int main()
{
    cin >> n;
    //cout<<"Hello World";
    
    for(int i =0 ; i<n; i++)
    {
        int s;
        cin >> s;
        a.push_back(s);
    }
     for(int i =0 ; i<n; i++)
    {
        int s;
        cin >> s;
        b.push_back(s);
    }
    
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int sum = 0;
    for(int i=0; i<n; i++)
    {
       sum += a[i] * b[n-i-1];
    }
    
    cout << sum <<"\n";
    
    return 0;
}
