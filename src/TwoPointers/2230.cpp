#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n,m;


int main()
{
    
    cin >> n >> m;
    
    vector<int> arr;
    
    for(int i=0; i< n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    sort(arr.begin(),arr.end());
    
    int result = 123456789;
    int en = 0;
    for(int st=0; st<arr.size(); st++)
    {
        while(en < n && arr[en] - arr[st] < m) 
            en ++;
        if(en == n) 
            break;
        result = min (result,arr[en]- arr[st]);
    
    }
    
    cout << result <<"\n";
    

    return 0;
}


