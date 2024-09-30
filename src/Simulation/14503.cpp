#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {0,1,0,0};
int dy[4] = {-1,0,1,-1};

int n,m;
int r,c,d; // d 0 북 1 동 2 남 3 서 
int map[51][51];
int result = 0 ; 
pair<pair<int,int>,int> Robot; // r ,c , d 

int ReverseClock90(int temp)
{
    switch (temp)
    {
    case 0:
        temp = 3;
        break;
    case 1 : 
        temp = 0;
        break;
    case 2: 
        temp = 1;
        break;
    case 3 :
        temp = 2;
        break;
    }
    return temp;
}


void solution()
{
    queue<pair<pair<int,int>,int>> q;
    q.push(Robot);

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        bool notclean = false;
        q.pop();

        cout << r << " " << c <<" " << d <<"\n";
        if(map[r][c] == 0)
        {
            map[r][c] = 2;
        }
        for(int i = 0 ; i < 4; i ++)
        {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if(map[nr][nc] == 0)
            {
                notclean= true;
            }
        }
        if(!notclean) // 주변 4칸에 청소 할 곳이 없을 때 
        {
            int br = (r - dy[d]);
            int bc = (c - dx[d]);
            if (map[br][bc] == 1 
            || br < 0  || br >=n || bc < 0 || bc >=m) 
            {
                break;
            }
            pair<pair<int,int>,int> back;
            back.first.first = br ;
            back.first.second = bc;
            back.second = d;
            q.push(back);
        }
        else{
            for(int i = 0 ; i <4; i++)
            {
                d = ReverseClock90(d);
                int fr = (r+dy[d]);
                int fc = (c+dx[d]);
                if (map[fr][fc] == 1 || map[fr][fc] == 2)
                {
                    continue;
                }
                if (fr <0 || fr >=n || fc <0 || fc>=m)
                    continue;
                pair<pair<int,int>,int> front;
                front.first.first = fr ;
                front.first.second = fc;
                front.second = d;
                q.push(front);
               
            }
        }

    }

    for(int i = 0 ; i <n; i++)
    {
        for(int j =0 ; j<m; j++)
        {
            cout << map[i][j] <<" ";
        }
        cout <<"\n";
    }
    for(int i = 0 ; i < n; i ++)
    {
        for(int j = 0 ; j<m; j++)
        {
            if(map[i][j] == 2)
                result++;
        }
    }



}

int main()
{
    cin >> n >> m ;
    cin >> r >> c >> d;
    for(int i = 0 ; i < n;  i ++ )
    {
        for(int j = 0 ; j <m ; j++)
        {
            cin >> map[i][j] ; 
        }
    }

    Robot.first.first = r ;
    Robot.first.second = c;
    Robot.second = d;

    solution();

    cout << result <<"\n";

    return 0;
}