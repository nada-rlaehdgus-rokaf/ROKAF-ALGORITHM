#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// int dx[4] = {-1,1,0,0};
// int dy[4] = {0,0,1,-1};
int dx[3] = {-1,1,2};
int visited[100001];
int n, k;

void solution(){
    queue<pair<int,int>> q; // 위치 시간 
    q.push({n,0});
    
    
    while(!q.empty())
    {
        int curx = q.front().first;
        int curt = q.front().second;
        q.pop();
        // 순서에 따른 생각 곱하기를 먼저 했을 경우 큐 특성상
        // 곱하기 먼저 큐로 들어가기 때문에 원하는 답을 얻는다.
        if(curx == k) 
        {
            cout << curt <<"\n";
            return;
        }
        int index = curx * 2; 
        
        if(index <= 100000 && visited[index] == 0 )
        {
            visited[index] = 1;
            q.push({index,curt});
        }
        for(int i=0; i<2; i++)
        {
            int nx = curx + dx[i];
            if(nx < 0 || nx > 100000)
                continue;
            if(visited[nx] == 1)
            {
                continue;
            }
            
            
            visited[nx] = 1;
            q.push({nx,curt+1});
        }
       
        
        
    }
    
    
}

int main()
{
    cin >> n >> k;
    
    solution();
    
    return 0;
}
