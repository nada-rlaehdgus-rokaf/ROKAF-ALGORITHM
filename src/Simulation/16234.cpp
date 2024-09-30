#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,l,r;
int map[51][51];
int result =  0 ; 

void solution()
{
    
    while(1)
    {
        bool flag = true ;
        int visited[51][51] ;
        for(int i = 0 ; i<n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                visited[i][j] = 0 ;
            }
        }
        int GroupNum =  1; 
        int Group[51][51];
        for(int i = 0 ; i<n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                Group[i][j] = 0 ;
            }
        }
        int copymap[51][51];
         for(int i = 0 ; i<n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                copymap[i][j] = map[i][j] ;
            }
        }

        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(visited[i][j] == 1)
                {
                    continue;
                }
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = 1;
                Group[i][j] = GroupNum; 
                int sum = map[i][j];
                int cnt = 1; 

                while(!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    
                    for(int k = 0 ; k < 4; k ++)
                    {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        
                        if(ny < 0 || nx < 0 ||
                         nx >= n || ny >=n )
                            continue;
                        if(visited[ny][nx] == 1)
                            continue;
                        
                        if(abs(map[y][x] - map[ny][nx]) < l 
                        || abs(map[y][x]- map[ny][nx]) > r )
                            continue;
                        q.push({ny,nx});
                        visited[ny][nx] = 1;
                        Group[ny][nx] = GroupNum;
                        sum += map[ny][nx];
                        cnt++;
                    }
                }

               
               if(cnt >=2 )
               {
                    flag = false;
                    for(int a= 0 ; a<n; a++)
                    {
                        for(int b= 0 ; b< n; b++)
                        {
                            if(visited[a][b] == 1 && Group[a][b] == GroupNum)
                            {
                                copymap[a][b] = ( sum / cnt ); 
                            }
                        }
                    }
               } 
                // cout << GroupNum <<"\n";  
                // for(int a= 0 ; a<n; a++)
                // {
                //     for(int b= 0 ; b< n; b++)
                //     {
                //         cout << copymap[a][b] <<" ";
                //     }
                //     cout <<"\n";
                // }
                 GroupNum ++ ;  

            }
        }

        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j<n; j++)
            {
                map[i][j] = copymap[i][j];
            }
        }
  

        // if(GroupNum == n*n +1) // 끝내는 조건이 시간초과 
        // {
        //     flag = true;
        // }

        if(flag){
            break;
        }

   
        result ++ ; 



    }



}


int main()
{
    cin >> n >> l >> r;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j <n; j++)
        {
            cin >> map[i][j];
        }
    }


    solution();

    cout << result <<"\n";

    return 0;
}