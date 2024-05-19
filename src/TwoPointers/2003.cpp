#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m;
vector<int> arr; 
int result;

int main()
{
    cin >> n >> m;
    for(int i= 0 ; i<n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    
    
    int st = 0;
    int en = 0 ;
    int index = arr[en] ;
    for(int st = 0 ; st < n; st++)
    {
        while(en <= n && index < m)
        {
            en ++; 
            index += arr[en];
            cout << index << " " << en << "\n";

        }
        if(index == m)
        {
            index -= arr[st];
            result++;
        }
        else if(index > m){
            index -= arr[st];
        }
        if (en == n)
            break;
        
    }
    
    
    /*    int st  = 0;
    int en = 1; 
    int index =  arr[0]; 
    for(int st = 0 ; st< n ; st++ )
    {
        
        while(st < en && index < m)
        {
            cout << index <<"\n";
            if(en == n)
                break;
            index += arr[en];
            en++;
        
        }
        if(en == n)
            break;
        if(index == m)
        {
            index -= arr[st];
            result++;
        }
        else if(index > m){
            index -= arr[st];
        }
        
    }
    */
    cout << result <<"\n";

    return 0;
}