#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr(12,0);
int dp[13];
int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i=4; i<= 12; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    for(int i=0; i<n; i++)
    {
        cout << dp[arr[i]] <<"\n";
    }
    //cout<<"Hello World";

    return 0;
}
