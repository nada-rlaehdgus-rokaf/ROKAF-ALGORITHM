
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dn[2] = {-1,1};
//int dy[4] = {0,0,1,-1};

int n,k ;
int v[500001][2];

void solution(){
    // 수빈이 동생 시간 
    // 찾는 위치 50000 이상 queue 탈출 하면 -1 
    
    queue<int> q;
    q.push(n);
    int move = 1;
    while(!q.empty())
    {
        k+=move;
        
        if(k>500000)
        {
            cout<< -1 <<"\n";
            return;
        }
        
        if(v[k][move%2])
        {
            cout<< move <<"\n";
            return;
        }
        int size = q.size();
        
        for(int i=0; i<size; i++)
        {
            int x = q.front();
            q.pop();
            
            for(int nx : {x-1,x+1,x*2})
            {
                //cout << "nx :" << nx <<"\n";
                if(nx == k)
                {
                    cout<< move <<"\n";
                    return;
                    
                }
                if(nx < 0 || nx > 500000 )
                    continue;
                if(v[nx][move%2])
                    continue;
                v[nx][move%2] = 1;
                q.push(nx);
            
            }
            
            
        }
        move++;
    }
    cout << -1 <<"\n";
    
}

int main()
{
    cin >> n >> k;
    if (n == k) {
        cout << 0;
        return 0;
    }
    solution();
    
    return 0;
}



