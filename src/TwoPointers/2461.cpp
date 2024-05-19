#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define INF 1234567899
using namespace std;

int n,m;
int arr[1001][1001];


int main()
{
   cin >> n >> m; 
   
   for(int i=0; i<n ; i++)
   {
       for(int j = 0 ; j<m; j++)
       {
           int a;
           cin >> a;
           arr[i][j] = a;
       }
   }
   
   
    //
    for(int i= 0 ; i< n; i++)
    {
        
        sort(arr[i],arr[i]+m);
    }
   
   
    
    
   
/*   for(int i= 0 ; i< n;  i++)
   {
       for(int j= 0; j< m ; j++)
        {
            cout << arr[i][j] <<" ";
        }
        cout <<"\n";
       
   }
   */
   
   
   

    return 0;
}
