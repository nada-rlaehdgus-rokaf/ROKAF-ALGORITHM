#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;


int n ; 
int result = 0;

void solution()
{
 
    vector<int> prime;
    vector<bool> check(n+1,true);
    check[1] = false;
    for(int i = 2 ; i <= sqrt(n) ; i++) {
        if(!check[i]) continue;
        for(int j = i * i ; j <= n ; j+= i) check[j] = false;
    }
    for(int i= 2; i<=n ; i++)
    {
        if(check[i]) prime.push_back(i);
    }
    
    
    int en =  0 ;
    int st = 0;
    int tot =0;
    int psize = prime.size();
    
    while(en <= psize)
    {
        if(tot >= n)
        {
            tot-= prime[st];
            st++;
        }
        else{
            tot+= prime[en];
            en++;
        }
        
        if(tot == n)
        {
            result++;
        }
        
    }
    
    
    
}


int main()
{
    cin >> n; 
    
    // 소수 인 것을 판별하는 체 
    // 2, 3, 5, 7, 11 .. 
    
    
    solution();
    
    cout << result <<"\n";

    return 0;
}
