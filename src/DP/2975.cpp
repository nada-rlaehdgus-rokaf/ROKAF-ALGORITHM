#include <iostream>
#include <vector>

using namespace std;

int dp[301][3];
int n;
int arr[301];
int result = 0;
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a; 
    }
    // cout<<"Hello World";
    dp[1][1] = arr[1];

    for(int i=2; i<=n ; i++)
    {
        dp[i][1] = max(dp[i-2][2],dp[i-2][1]) + arr[i];
        dp[i][2] = dp[i-1][1] + arr[i];
    }
    
    for(int i = 1; i<3; i++)
    {
        result = max(result, dp[n][i]);
    }

    cout << result <<"\n";

    return 0;
}
