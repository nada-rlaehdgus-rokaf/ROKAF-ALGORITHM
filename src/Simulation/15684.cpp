#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stdlib.h>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int laddx[3] = {-1,1,0};
int laddy[3] ={0,0,1};
#define INF 987654321

int n,m,h; // n 세로줄 x 좌표 ,  m 가로줄 개수 ,  h 세로 줄 y 좌표 

int map[32][11];
int Colvisited[1000]; // 9 * 30 
vector<int> ChooseColumnidx;

int ans = -1 ; 

bool Answer(vector<pair<int,int>>colv , vector<int> idxv)
{
    int copymap[31][11]; 
    for(int i = 0; i <= h+1; i++ )
    {
        for(int j = 1; j <= n ; j ++)
        {
            copymap[i][j] = 0 ;
        }
    }

    for(int i = 1 ; i <=h ; i++)
    {
        for(int j = 1; j <=n; j ++)
        {
            copymap[i][j] = map[i][j] ; 
        }
    }

    for(int i = 0 ; i < idxv.size(); i ++ )
    {
        int y = colv[idxv[i]].first;
        int x = colv[idxv[i]].second;
        copymap[y][x] = 1;
        copymap[y][x+1] =1  ; 
    }
    // for(int i = 1 ; i <= h ; i++)
    // {
    //     for(int j=1; j<=n;  j++)
    //     {
    //         cout << copymap[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    vector<int> result(n+1,0); // 뭐가 들어갓는지 

    int mapvisited[31][11];
    for(int i = 1 ; i <= h + 1 ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            mapvisited[i][j] = INF ; 
        }
    }


    for(int i = 1; i <= n ; i ++)
    {
        queue<pair<int,int>> q ;
        q.push({0,i});
        mapvisited[0][i] = 1; 
        while(!q.empty())
        {
            int y = q.front().first;
            int x=  q.front().second;
            //cout << "y : " <<y <<"x :  " << x << "\n";
            q.pop();
            if(y==h+1)
            {
                result[x]= i ; 
                break;
            }
            
            for(int j = 0 ; j < 3; j++)
            {
                
                int ny = y +laddy[j];
                int nx = x + laddx[j];
               // cout << "ny : "<< ny <<"nx :" << nx <<"\n";                


                if( nx <1 || nx > n )
                    continue;
                if(j==0 || j==1)
                {
                    if(copymap[ny][nx] == 1 && copymap[y][x] == 1)
                    {
                        if(mapvisited[ny][nx] == INF)
                        {
                            mapvisited[ny][nx] = mapvisited[y][x] + 1; 
                            q.push({ny,nx});
                            break;
                        }
                        else if(mapvisited[ny][nx] > mapvisited[y][x] + 1)
                        {
                            mapvisited[ny][nx] = mapvisited[y][x] + 1; 
                            q.push({ny,nx});
                            break;
                        }
                    }
                }
                else if(j==2)
                {
                     if(mapvisited[ny][nx] == INF)
                        {
                            mapvisited[ny][nx] = mapvisited[y][x] + 1; 
                            q.push({ny,nx});
                            break;
                        }
                        else if(mapvisited[ny][nx] > mapvisited[y][x] + 1)
                        {
                            mapvisited[ny][nx] = mapvisited[y][x] + 1; 
                            q.push({ny,nx});
                            break;
                        }
                }
                
               
            }

        }
         for(int a = 1 ; a <= h +1  ; a++)
        {
            for(int b = 1 ; b <= n ; b++)
            {
                mapvisited[a][b] = INF ; 
            }
        }

    }
    for(int i = 1; i <=n; i++)
    {
        cout << "result : " <<result[i] << " ";
    }
    cout << "\n";

    bool flag = true;

    for(int i = 1 ; i <= n ; i++ )
    {
        if(result[i] != i)
        {
            flag = false;
        }
    }
    if(flag)
    {
        return true;
    }
    else{
        return false;
    }

}





void ChooseColumn(vector<pair<int,int>> colv , 
int coln,int cnt , int idx)
{
    if(cnt == coln)
    {
        for(int i= 0 ; i<ChooseColumnidx.size(); i++)
        {
            cout << ChooseColumnidx[i] << " ";
        }
        cout <<"\n";
        bool flag = false;
        flag = Answer(colv,ChooseColumnidx);
        if(flag)
        {
            ans = coln;
        }
        return;
    }
    for(int i = idx ; i<colv.size(); i++ )
    {
        ChooseColumnidx.push_back(i);
        ChooseColumn(colv,coln, cnt+1, i+1);
        ChooseColumnidx.pop_back();
    }    
}

void InspectColumn(int coln) // 가로선 추가 개수 
{
    // 가로선 추가 할 수 있는 것을 vector로 저장
    vector<pair<int,int>> colv; // 세로 가로 
    for(int i = 1 ; i <= h ; i++)
    {
        for(int j = 1 ; j <=n-1 ; j ++)
        {
            if(map[i][j] == 1 || map[i][j+1] == 1 || map[i][j-1] == 1)
                continue;
            colv.push_back({i,j});
        }
    }
    

   
    ChooseColumn(colv,coln,0,0) ;
    // cout << "falg : " << flag <<"\n";
    // if(flag){
    //     return true;
    // }
    // else{
    //     return false; 
    // }
 
}



void solution()
{
 
    bool flag = false; 
    for(int i = 0 ; i <=3; i ++)
    {
        cout << i <<"\n";
        InspectColumn(i);
        if(ans != -1)
        {
            flag = true;
            cout << ans <<"\n";

            break;
        }
    }

    if(flag == false)
    {
        cout << -1 <<"\n";
    }
    // 0 개 추가  1 개 추가 2 개 추가 3개 추가 
    
    // 추가 가능한 줄에서 조합으로 뽑는 것 

    // 줄을 추가 하는 함수 

    // 맵을 복사 해서 조합으로 뽑은 위치에 줄을 추가 하고 
    
    // 답을 내는 함수
    // 밑으로 내려가면서 i가 i번째에 잘 들어가는 지에 대한 함수 

}


int main()
{
    cin >> n >> m >> h; 
    
    for(int i = 0 ; i < m; i++)
    {
        int a,b;
        cin >> a >> b; 
        map[a][b] = 1;
        map[a][b+1] = 1; 
    }


    solution(); 

    return 0;
}