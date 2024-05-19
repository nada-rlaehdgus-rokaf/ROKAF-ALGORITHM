#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m;

int main()
{
    cin >> n ;
    
    vector<int> narr(n,0);
    for(int i = 0 ; i<n; i++)
    {
        int a;
        cin >> a;
        narr[i] = a;
    }
    sort(narr.begin(),narr.end());
    cin >> m;
    vector<int> marr(m,0);
   
    for(int i = 0 ; i<m; i++)
    {
        int a;
        cin >> a;
        marr[i] = a;
    }
   
   
    
    for(int i = 0 ;i<m; i++)
    {
        int a = marr[i];
        bool flag = false;
        int st =  0 ;
        int end = narr.size()-1;
        int mid = (st + end)/2;
        //cout << a <<"\n";
        while(st <= end)
        {
            //cout << st << " " << end <<"\n";
            if(narr[mid] > a)
            {
                end = mid-1; 
                mid = (st + end)/2;
                
            }
            else if(narr[mid] < a)
            {
                st = mid +1 ;
                mid = (st + end)/2;
                
            }
            else if (narr[mid] == a)
            {
                cout << 1 <<"\n";
                flag = true;
                break;
            }
            
            
            
        }
        
        if(!flag)
            cout << 0 <<"\n";    
    }
    

    return 0;
}
