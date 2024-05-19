#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> withdraw;
int result = 0;
int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        withdraw.push_back(a);
    }
    //cout<<"Hello World";

// 앞의 수열이 작을 수록 적은 시간이 나오기때문
    
    sort(withdraw.begin(),withdraw.end());
    
    for(int i=0; i<n-1; i++)
    {
        withdraw[i+1]+= withdraw[i];
    }

    
     for(int i=0; i<n; i++)
    {
        result += withdraw[i];
    }
    cout << result <<"\n";

    return 0;
}

