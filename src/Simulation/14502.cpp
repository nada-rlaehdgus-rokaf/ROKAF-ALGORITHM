#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n, m ; 
int map[9][9];
int visited[9][9];
vector<pair<int,int>> empty_place; // y , x 
vector<int> choose;
int Answer = -1; 

void Max_Safety_Place()
{
    int copy_map[9][9];
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            copy_map[i][j] = 0;
        }
    }
     for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            copy_map[i][j] = map[i][j];
        }
    }

    queue<pair<int,int>> q;
    for(int i = 0 ; i < choose.size(); i++)
    {
        int y = empty_place[choose[i]].first;
        int x = empty_place[choose[i]].second;
        copy_map[y][x] = 1;
    }
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            if(copy_map[i][j]==2)
            {
                q.push({i,j});
                
            }
        }
    }

    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny < 0 || ny >=n || nx < 0 || nx >=m) // 말도안되는 실수  m을 n으로
                continue;
            if(copy_map[ny][nx] == 1)
                continue;
            if(copy_map[ny][nx] == 2)
                continue;
            q.push({ny,nx});
            copy_map[ny][nx] = 2;
        }

    }
    // for(int i = 0 ; i < n; i++)
    // {
    //     for(int j = 0 ; j<m; j++)
    //     {
    //         cout <<visited[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    int safety_place  = 0 ;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            if(copy_map[i][j] == 1)
                continue;
            if(copy_map[i][j] ==2)
                continue;
            safety_place++;
        }
    }
    //cout << safety_place <<"\n";
    // bool flag =false;
    // if(safety_place == 14)
    // {
    //     flag =true;
    //     for(int i = 0 ; i < n; i++)
    //     {
    //         for(int j = 0 ; j<m; j++)
    //         {
    //             cout <<copy_map[i][j] <<" ";
    //         }
    //         cout<<"\n";
    //     }
       
    // }
    // if(flag)
    // {
    //     return;
    // }
    Answer = max(Answer,safety_place);



}

void combination(int cur, int idx)
{
    if(cur == 3 )
    {
        Max_Safety_Place();
        // for(int i = 0 ; i < choose.size() ; i++)
        // {
        //     cout << choose[i] <<" ";
        // }
        // cout <<"\n";
        return;
    }
    for(int i = idx ; i < empty_place.size(); i++ )
    {
        choose.push_back(i);
        combination(cur+1,i+1);
        choose.pop_back();
    }
}

void solution()
{
    combination(0,0);
}



int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n; i ++)
    {
        for(int j = 0 ;  j < m; j++)
        {
            cin >> map[i][j] ;
            if(map[i][j] == 0)
            {
                empty_place.push_back({i,j});
            }
        }
    }
    // for(int i = 0 ; i < n; i ++)
    // {
    //     for(int j = 0 ;  j < m; j++)
    //     {
    //        cout <<  map[i][j] <<" " ;
          
    //     }
    //     cout <<"\n";
    // }

    solution();

    cout << Answer <<"\n";

    return 0;
}