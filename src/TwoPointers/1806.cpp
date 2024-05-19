#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define INF 1234567899
using namespace std;

int n;
long long s;



int main()
{
    cin >> n >> s;
    vector<int> arr;
    
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    int result = INF;
    // 가능한 최소 길이 출력 
    // 연속되는 수열 

    int en = 0 ; 
    int index = arr[en] ; 
    for(int st = 0 ; st < n ; st ++)
    {
        //bool flag = false;
        while(index < s && en < n)
        {
            en++;
            if(en != n)
                index += arr[en];
           
        }
        if(en == n)
        {
            break;
        }
        result = min(result,en-st + 1) ;
        index -= arr[st];
        
    }
    
    
    
    if(result == INF)
    {
        cout << 0<<"\n";
    }
    else
    {
        cout << result <<"\n";
    }

    

    return 0;
}


