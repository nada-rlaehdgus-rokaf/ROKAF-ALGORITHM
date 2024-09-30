
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

#define INF 987654321

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int dx3[6] = {-1,1,0,0,0,0};
int dy3[6] = {0,0,-1,1,0,0};
int dz3[6] = {0,0,0,0,-1,1};

int result = INF;


vector<vector<int>> map(5,vector<int>(5,0));
vector<vector<vector<int>>> cube(5,vector<vector<int>>(5,vector<int>(5,0)));
vector<int> order = {0,1,2,3};
int select_visited[5];

vector<vector<int>> TurnRight90(vector<vector<int>> copy )
{
    vector<vector<int>> temp(5,vector<int>(5,0));
    for(int i = 0; i<5; i++)
    {
        for(int j = 0 ;j <5; j++)
        {
            temp[4-j][i] = copy[i][j];
        }
    }
    return temp;
}
vector<vector<int>> TurnRight180(vector<vector<int>> copy )
{
    vector<vector<int>> temp(5,vector<int>(5,0));
    for(int i = 0; i<5; i++)
    {
        for(int j = 0 ;j <5; j++)
        {
            temp[4-i][4-j] = copy[i][j];
        }
    }
    return temp;
}

vector<vector<int>> TurnRight270(vector<vector<int>> copy )
{
    vector<vector<int>> temp(5,vector<int>(5,0));
    for(int i = 0; i<5; i++)
    {
        for(int j = 0 ;j <5; j++)
        {
            temp[j][4-i] = copy[i][j];
        }
    }
    return temp;
}

void bfs(int num,vector<vector<vector<int>>> copy_qube )
{
    vector<pair<int,pair<int,int>>> start = {{0,{0,0}},{ 0,{0 ,4}} ,{0,{4,4}},{0,{4,0}}};
    vector<pair<int,pair<int,int>>> finish = {{4,{4,4}},{ 4,{4 ,0}} ,{4,{0,0}},{4,{0,4}}};
    queue<pair<int,pair<int,int>>> q;
    // 시작이 ( z, y, x ) 0,0,0  / 0,0 ,5 / 0,5,5 / 0,5,0  4개 
    int visited[5][5][5];
    for(int i = 0 ; i< 5; i++)
    {
        for(int j =0 ; j< 5; j++)
        {
            for(int k = 0; k< 5; k++)
            {
                visited[i][j][k] = INF;
            }
        }
    }
    if(copy_qube[start[num].first][start[num].second.first][start[num].second.second] == 0 ||
     copy_qube[finish[num].first][finish[num].second.first][finish[num].second.second] == 0)
    {
        return;
    }
    q.push(start[num]);
    visited[start[num].first][start[num].second.first][start[num].second.second] = 0;

    while(!q.empty())
    {
        if(q.front() == finish[num])
        {
            result = min(result,visited[finish[num].first][finish[num].second.first][finish[num].second.second]);
            break;

        }
        int z = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        int dist = visited[z][y][x] ;
        //cout << z << " " << y << " " << x << " " << dist << "\n";
        q.pop();
        for(int i = 0 ; i< 6; i++)
        {
            int nz = z + dz3[i];
            int ny = y + dy3[i];
            int nx = x + dx3[i];
            if(nz <0 || nz >= 5 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5 )
                continue;
            if (copy_qube[nz][ny][nx] == 0) 
                continue;
            if(visited[nz][ny][nx] == INF)
            {
                visited[nz][ny][nx] = dist + 1;
                q.push({nz,{ny,nx}});
            }
            else if(visited[nz][ny][nx] > dist + 1 )
            {
                visited[nz][ny][nx] = dist + 1;
                q.push({nz,{ny,nx}});
            }
            
        }
    
    }

    //cout << result <<"\n";

}
void make_cube(vector<vector<vector<int>>> &copy_cube,vector<int> cube_order ,vector<int> permutation_order)
{
    for(int i = 0 ; i< 5; i++)
    {
        if(permutation_order[i] == 0)
        {
            copy_cube[i] = cube[cube_order[i]];
        }
        else if(permutation_order[i] == 1)
        {
            copy_cube[i] = TurnRight90(cube[cube_order[i]]);
        }
        else if(permutation_order[i] == 2)
        {
            copy_cube[i] = TurnRight180(cube[cube_order[i]]);
        }
        else if(permutation_order[i] == 3)
        {
            copy_cube[i] = TurnRight270(cube[cube_order[i]]);
        }
    }
}

void select_cube(int cnt, vector<int> cube_order, vector<int> permutation_order)
{
    if(cnt == 5)
    {
        vector<vector<vector<int>>> copy_cube(5,vector<vector<int>>(5,vector<int>(5,0)));
        make_cube(copy_cube,cube_order,permutation_order);
        for(int i = 0 ; i< 4; i++)
        {
            if(result == 12)
            {
                break;
            }
            bfs(i,copy_cube);
           
        }
        return;
    }
    for(int i = 0 ; i< 5; i++)
    {
        if(select_visited[i] == 0)
        {
            select_visited[i] = 1;
            cube_order[cnt] = i;
            select_cube(cnt+1,cube_order,permutation_order);
            select_visited[i] = 0;
        }
    
    }
}



void dfs(int cnt, vector<int> cube_order, vector<int> permutation_order)
{
    if(cnt == 5)
    {
        select_cube(0,cube_order,permutation_order);
        return;
        
    }
    for(int i = 0 ; i< 4; i++)
    {
        permutation_order[cnt] = i;
        dfs(cnt+1,cube_order,permutation_order);
    }

}




void solution()
{
    

    // 중복 순열 후에 bfs 돌리기 
    // 0, 1 ,2 ,3 을 이용해 5개 선택  
    vector<int> permutation_order(5,0);
    vector<int> cube_order(5,0);
    dfs(0,cube_order,permutation_order);
    


}









int main()
{
    for(int i = 0 ; i< 5; i++)
    {
        for(int j =0 ; j< 5; j++)
        {
            for(int k = 0; k< 5; k++)
            {
                cin >> cube[i][j][k];
            }
        }
        
    }


    solution();


    // for(int i = 0 ; i< 5; i++)
    // {
    //     for(int j =0 ; j< 5; j++)
    //     {
    //         for(int k = 0; k< 5; k++)
    //         {
    //             cout << qube[i][j][k]  << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    if(result == INF)
    {
        cout << -1 << "\n";
    }
    else{
        cout << result << "\n";
    }

    return 0;
}