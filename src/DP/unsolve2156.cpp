#include <iostream>
#include <vector>

using namespace std;
int dp[10001][4];
int main()
{
    int n;
    cin >> n;
    vector<int> arr(10001,0);
    for(int i=1; i<n+1; i++){
        int a;
        cin >> a;
        arr[i] = a;
    }
    
    int sum = 0;
    for(int i=1; i<n+1; i++){
        if(i == 1)
        {
            dp[i][1] = arr[i];
        }
        else{
            dp[i][]
        }
        
        
    }
    
    

    return 0;
}
