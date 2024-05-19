#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n;
vector<int> arr;
int result = 0;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a; 
        arr.push_back(a);
    }

    // 1 2 3 1 2 1개씩 5
    // 12 23 31  12  4
    // 123 231 312 3
    // 1231 2312 
    // 12312 
    //index =  1; 
    while(index <= n-1 )
    {
        for(int i = 0 ; i< n; i++)
        {
            
            if(i+index >= n )
            {
                break;
            }
            for(int j = i ; j <= i+index; j++)
            {
                
            }
            
            
            
            
            
        }
        
    }
    
    

    return 0;
}



