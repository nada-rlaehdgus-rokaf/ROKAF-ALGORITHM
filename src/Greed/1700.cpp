#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int multi[101];
int arr[101];
bool in[101];
int n,k;
int result = 0;

int main()
{
    cin >> n >> k;
    
    for(int i=1; i<k+1; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    for(int i = 1; i<k+1; i++)
    {
        bool flag = false;
        if(in[arr[i]] == true)
            continue;
            
       for(int j = 1; j<n+1; j++)
       {
           if(multi[j] == 0)
           {
               in[arr[i]] = true;
               multi[j] = arr[i];
               flag = true;
               break;
           }
       }
       
       if(flag == false)
       {
           int change_multi_index = 0;
           int change_value = 0;
           for(int j=1; j<n+1; j++)
           {
               int multi_index = 0;
               int value = 0;
               for(int x = i; x < k+1; x++)
               {
                   if(multi[j] == arr[x])
                   {
                       multi_index = j;
                       value = x;
                       break;
                   }
               }
               if(multi_index == 0)
               {
                   change_multi_index = j;
                   break;
               }
               
               if(change_value <  value)
               {
                   change_value = value;
                   change_multi_index = multi_index;
               }
               
           }
           
           in[multi[change_multi_index]] = false;
           multi[change_multi_index] = arr[i];
           in[arr[i]] = true;
           
           result++;
       }
     
       
       
       
    }
    /*for(int i=1 ;i < n+1; i++)
    {
        cout << multi[i] <<" ";
    }
    cout <<"\n";
*/
    cout << result <<"\n";

    return 0;
}