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

int n ;

int map[21][21];
int visited[21][21];



struct Shark
{
    int x;
    int y;
    int size;
    int eat;
    int time;
};
Shark babyshark;

struct Fish
{
    int x;
    int y;
    int dist;
    int size;

};
struct compare
{
    bool operator()(const Fish &f1 , const Fish &f2)
    {
       
            if(f1.dist > f2.dist)
            {
                return true;
            }
            else if(f1.dist == f2.dist)
            {
                if(f1.y > f2. y)
                {
                    return true;
                }
                else if(f1.y ==f2.y)
                {
                    if(f1.x > f2.x)
                    {
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
      
     
    }
};




// void CanEat(int &HowManyCanEat)
// {
//     for(int i = 0 ; i < n; i ++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             if(iseat[i][j] == 1)
//             {
//                 continue;
//             }
//             if(babyshark.size <= map[i][j])
//             {
//                 continue;
//             }
//             HowManyCanEat++;

//         }
//     }

// }

void InitializeVisit()
{
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            visited[i][j] = INF;
        }
    }

}
void solution()
{


    while(1)
    {
        InitializeVisit();
        priority_queue<Fish, vector<Fish>, compare> qfishes;
        queue<pair<pair<int,int>,int>> qShark; // y , x , cur  
        qShark.push({{babyshark.y,babyshark.x},0 });
        visited[babyshark.y][babyshark.x] = 0;

        while(!qShark.empty())
        {
            int y = qShark.front().first.first;
            int x = qShark.front().first.second;
            int size = babyshark.size;
            int dist = qShark.front().second ; 
            qShark.pop();
            //cout << y <<" " << x <<"\n";
            for(int i  = 0 ; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx >= n || nx < 0 || nx >=n)
                    continue;
                if(map[ny][nx] > size )
                    continue;
                if(visited[ny][nx] == INF)
                {
                    visited[ny][nx] = visited[y][x] + 1;
                    qShark.push({{ny,nx},visited[y][x]+1});
                }
                else if (visited[ny][nx]  > visited[y][x] + 1)
                {
                    visited[ny][nx] = visited[y][x] + 1;
                    qShark.push({{ny,nx},visited[y][x]+1});
                }
            }
        }
        for(int i  = 0 ;  i <  n;  i ++)
        {
            for(int j = 0; j < n; j++)
            {
                if(map[i][j] == 0 )
                    continue;
                if(visited[i][j] == INF)
                    continue;
                if(map[i][j] >= babyshark.size)
                    continue;
                // 
                Fish f ;
                f.x = j;
                f.y = i;   
                f.dist = visited[i][j];
                f.size = map[i][j];
                qfishes.push(f);
            }
        }
        // int qsize = qfishes.size();
        // for(int i = 0 ; i < qsize; i++)
        // {
        //    cout <<  qfishes.top().y <<" " << qfishes.top().x << "\n";
        // }

        if(qfishes.size() == 0 )
        {
            cout << babyshark.time << "\n";
            return;
        }
        else if(qfishes.size() == 1)
        {
            //cout <<  qfishes.top().y <<" " << qfishes.top().x << 
            //" "<<qfishes.top().dist <<" " << babyshark.size << " \n";
            babyshark.y = qfishes.top().y;
            babyshark.x = qfishes.top().x;
            babyshark.eat++;
            babyshark.time += qfishes.top().dist;
            map[babyshark.y][babyshark.x] = 0;
            qfishes.pop();
            if(babyshark.size == babyshark.eat)
            {
                babyshark.size++;
                babyshark.eat = 0 ;
            }
        }
        else if(qfishes.size() > 1)
        {
            //cout <<  qfishes.top().y <<" " << qfishes.top().x << 
            //" "<<qfishes.top().dist <<" " << babyshark.size << " \n";
            babyshark.y = qfishes.top().y;
            babyshark.x = qfishes.top().x;
            babyshark.eat++;
            babyshark.time += qfishes.top().dist;
            map[babyshark.y][babyshark.x] = 0;
            qfishes.pop();
            if(babyshark.size == babyshark.eat)
            {
                babyshark.size++;
                babyshark.eat = 0 ;
            }
        }


        // for(int i  =0 ; i<n; i++)
        // {
        //     for(int j = 0 ; j < n; j++)
        //     {
        //         cout << visited[i][j] <<" ";
        //     }
        //     cout <<"\n";
        // }
    }

}


int main()
{
    cin >> n; 
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 9 )
            {
                babyshark.y = i ;
                babyshark.x = j ;
                babyshark.eat = 0 ;
                babyshark.size = 2;
                babyshark.time =  0;        
                map[i][j] = 0;    
            }
        }
    }

    solution();


    return 0;
}