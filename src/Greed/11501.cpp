#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int t;

 /// 자료형을 주의할것 
int main()
{
    cin >> t;
    vector<vector<int>> arr;
    for(int i=0; i<t; i++)
    {
        vector<int> test;
        int n;
        cin >> n;
        for(int j=0; j<n; j++)
        {
            int a;
            cin >> a;
            test.push_back(a);
        }
        arr.push_back(test);
    }
    
/*    
     for(int i=0; i<t; i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {
         cout << arr[i][j] <<" ";
        }
        cout << "\n";

    }*/
    
    // for(int i=0; i<t; i++)
    // {
    //     // int index = arr[i][0];
    //     int sum = 0;
    //     for(int j=0; j<arr[i].size(); j++)
    //     {
    //         int index = arr[i][j];
    //         int minus = 0;
    //       for(int k = j+1; k<arr[i].size(); k++)
    //       {
    //         if(minus < arr[i][k] - index)  
    //         {
    //             minus =  arr[i][k] - index;
    //         }
    //       }
    //       sum += minus;
    //     }
    //     result.push_back(sum);
    // }
        vector<long long> result;
    for(int i=0; i<t; i++)
    {
        int index = arr[i][arr[i].size()-1];
        long long sum = 0;
        for(int j=arr[i].size()-2; j>=0; j--)
        {
            if(index < arr[i][j])
            {
                index = arr[i][j];
            }
            else{
                sum+=index - arr[i][j];
            }
            
        }
        result.push_back(sum);
    }
    
    for(int i=0; i<t; i++)
    {
        cout << result[i] <<"\n";
    }
    

    return 0;
}
