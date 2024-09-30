#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int n,m,k; 

int smell[21][21]; //SharkSmell


vector<int> InitialD;
vector<vector<vector<int>>> fourDSave;

vector<int> WhereShrak[21][21];
vector<vector<pair<int,int>>> map(21,vector<pair<int,int>>(21,{0,0}));

int result = 0 ; 

struct Shark
{
    int y;
    int x;
    int firstd;
    int num;
    bool live;
    vector<vector<int>> fourD;
};

vector<Shark> Sharks;

void AliveShark(queue<Shark> &q)
{
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(map[i][j].second == k)
            {
                Shark shark;
                shark = Sharks[map[i][j].first-1];
                q.push(shark);
                
            }
        }
    }

}

void CountSmell()
{
    for(int i = 0 ; i < n;  i++)
    {
        for(int j = 0 ; j<n; j++)
        {
            if(map[i][j].first == 0)
                continue;
            map[i][j].second -=1;
            if(map[i][j].second == 0)
            {
                map[i][j].first = 0;
            }
        }
    }
}

void ArrangeShark()
{
    for(int i = 0 ; i < Sharks.size(); i++)
    {
        if(!Sharks[i].live)
            continue;
        int y = Sharks[i].y;
        int x = Sharks[i].x;
        // 자기 자신의 영역으로 들어갈 경우 
        // 다른 영역으로 들어 간 경우 
        if(map[y][x].first == Sharks[i].num )
        {
            map[y][x].first = Sharks[i].num;
            map[y][x].second = k;
        }
        else if(map[y][x].first < Sharks[i].num ) 
        {
            Sharks[i].live = false;
        }
        else if(map[y][x].first == 0 ){
            map[y][x].first = Sharks[i].num;
            map[y][x].second = k ;
        }
    
       
    }
}


void solution()
{
    while(1)
    {
        queue<Shark> q;
        // 상어가 잘 있는지 확인 하는 함수 
        AliveShark(q);

        if(result > 1000)
        {

            if(q.size() > 1)
            {
                cout << -1 <<"\n";
                return;
            }

        }
        if(q.size() == 1)
        {
            cout << result <<"\n";
            return;
        }
        
        while(!q.empty())
        {
            Shark shark = q.front();
            q.pop();
            int y = shark.y;
            int x=  shark.x;
            int num = shark.num;
            int d = shark.firstd;
            bool live = shark.live;
            vector<vector<int>> fourD =  shark.fourD;

            // cout << y <<" " << x <<"\n";
            // for(int i = 0 ; i < fourD.size(); i++)
            // {
            //     for(int j = 0 ; j < fourD[i].size(); j++)
            //     {
            //         cout << fourD[i][j] <<" ";
            //     }
            //     cout << "\n";
            // }
            bool flag = false;
            for(int i = 0 ; i <4 ; i++)
            {
                int ny = y + dy[fourD[d-1][i]-1];
                int nx = x + dx[fourD[d-1][i]-1];
                if(ny < 0  || ny  >=n || nx < 0 || nx>=n)
                    continue;
                if(map[ny][nx].first != 0  || map[ny][nx].second > 0 )
                    continue;
                
                flag = true;
                Sharks[num-1].y = ny;
                Sharks[num-1].x = nx;
                map[ny][nx].second -=1;
                if(map[ny][nx].second == 0)
                {
                    map[ny][nx].first = 0;
                }
                break;
        
            }

            if(!flag)
            {
                for(int i = 0 ; i <4 ; i++)
                {
                    int ny = y + dy[fourD[d-1][i]-1];
                    int nx = x + dx[fourD[d-1][i]-1];
                    if(ny < 0  || ny  >=n || nx < 0 || nx>=n)
                        continue;
                    if(map[ny][nx].first == num)
                    {
                        Sharks[num-1].y = ny;
                        Sharks[num-1].x = nx;
                        Sharks[num-1].firstd = fourD[d-1][i];
                        break;
                    }
            
                }
            }


        }

        // 냄새 -1 해주는 함수 
        CountSmell();

        ArrangeShark();

        result ++; 

        // for(int i = 0 ; i < n ; i ++)
        // {
        //     for(int j = 0 ; j < n; j++)
        //     {
        //         cout<< map[i][j].first << " " << map[i][j].second <<"||";
        //     }
        //     cout <<"\n";
        // }


    }


}


int main()
{
    cin >> n >> m >> k;
    for(int i = 0;  i < n; i ++)
    {
        for(int j = 0 ; j < n; j++)
        {
            pair<int,int> p;
            cin >> p.first ;
            if(p.first >= 1 && p.first <=m)
            {
                map[i][j].first = p.first;
                map[i][j].second = k;
            }
            else{
                map[i][j].second = 0 ;
            }
           
        }
    }
  

    for(int i = 0  ; i < m; i++)
    {
        int d;
        cin >> d;
        InitialD.push_back(d);
    }
    
    for(int i = 0 ; i < m; i++)
    {
        vector<vector<int>> fourD(4,vector<int>(4,0));
        for(int j = 0 ; j < 4; j++)
        {
            for(int u = 0; u< 4; u++)
            {
                int d;
                cin >> d;
                fourD[j][u] = d;
            }
        }
        fourDSave.push_back(fourD);
    }


    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(map[i][j].first >=1 && map[i][j].first <= m)
            {
                Shark shark;
                shark.y = i;
                shark.x = j ;
                shark.num = map[i][j].first;
                shark.firstd = InitialD[map[i][j].first-1] ;
                shark.live = true;
                shark.fourD = fourDSave[map[i][j].first-1];
                Sharks.push_back(shark);
            }
            
        }
    }
    
    for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < n; j++)
            {
                cout<< map[i][j].first << " " << map[i][j].second <<"||";
            }
            cout <<"\n";
        }
    solution();


    return 0;
}