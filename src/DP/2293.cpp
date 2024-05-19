#include <iostream>
#include <vector>
using namespace std;
int n,k;
vector<int> arr;
int dp[100001];
int freq[101];
int result = 0;
// 중복제거 ?? 
int solution(int m)
{
    if(m == k)
    {
        return 1;
    }
    if(dp[m] != -1)
    {
        return dp[m];
    }
    dp[m] = 0;
    for(int i=0; i<arr.size(); i++)
    {
        int nm = m + arr[i];
        if(nm > k)
            continue;
        dp[m] += solution(nm);
        
    }
    return dp[m];
}



int main()
{
    cin >> n >> k;
    for(int i=0; i<n ;i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i=0; i<k; i++)
    {
        dp[i] = -1;
    }
    
    for(int i=0; i<arr.size(); i++)
        result += solution(arr[i]);
    //cout<<"Hello World";
    cout <<result <<"\n";
    return 0;
}
