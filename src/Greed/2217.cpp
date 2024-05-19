#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> save;
int sum;
int avg;
int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
       // sum+=a;
    }
    //avg = sum/n;
    
    // for(int i=0; i<n; i++)
    // {
    //     if(v[i] >= avg)
    //     {
    //         save.push_back(v[i]);
    //     }
    // }
    sort(v.begin(),v.end());

    int result = 0;
    
    // for(int i=n-2; i>=0 ; i--)
    // {
    //     if( v[i] * (n-i) > result)
    //         result = v[i] * (n-i);
    //     else{
    //         break;
    //     }
    // }
    // cout << result <<"\n";
    //cout<<"Hello World";
    for(int i=1; i <=n; i++)
    {
        result = max(result,v[n-i]*i);
    }
    
    cout << result <<"\n";
    return 0;
}

