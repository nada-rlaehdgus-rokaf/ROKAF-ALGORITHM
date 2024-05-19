#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int dp[1000003];
int n;
int ans = 0;

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin >> a;
        dp[a] = dp[a-1] + 1;
        ans = max(dp[a],ans);
    }

    cout << n - ans <<"\n";
    return 0;
}
