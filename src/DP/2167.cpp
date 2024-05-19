#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
int arr[301][301];
int sum[301][301];
vector<pair<pair<int,int>,pair<int,int>>> v;
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m ; j++)
        {
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    cin >> k;
    for(int i=0; i<k ; i++)
    {
        int f1,f2, s1,s2;
        cin >> f1 >> f2 >> s1 >> s2;
        v.push_back({{f1,f2},{s1,s2}});
    }
    
    for(int i=1; i<= n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            sum[i][j] = arr[i][j] + sum[i][j-1];
        }
        
    }
    
    for(int i=1; i<= m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            sum[j][i] += sum[j-1][i];
        }
    }
    
    // for(int i=1; i<= n; i++ )
    // {
    //     for(int j=1; j<=m; j++)
    //     {
    //         cout << sum[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    
    for(int i=0; i<k; i++)
    {
        int f1,f2, s1,s2; // 상하 좌우 
        f1 = v[i].first.first;
        f2 = v[i].first.second;
        s1 = v[i].second.first;
        s2 = v[i].second.second;
        cout << sum[s1][s2]-sum[s1][f2-1] - sum[f1-1][s2] 
        + sum[f1-1][f2-1] <<"\n";
    }
    
    //cout<<"Hello World";

    return 0;
}
