#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int r,c;
char map[1501][1501];
int visit[1501][1501]; // 
queue<pair<int,int>>  sq;
queue<pair<int,int>> temsq;
pair<int,int> L1({-1,-1});
//pair<int,int> L2({-1,-1});
queue<pair<int,int>> wq;
queue<pair<int,int>> temwq;
bool Lfind = false;


void sbfs()  // check 할 때 처음부터 다시 해버리면 시간초과되는듯? 
{
    

    while(!sq.empty())
    {
        int y = sq.front().first;
        int x = sq.front().second;
        sq.pop();
        //cout << y <<" " << x <<"\n";
        for(int i=0 ; i< 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >=c)
                continue;
            if(visit[ny][nx] == 1)
                continue;
            visit[ny][nx] = 1;
            if(map[ny][nx] == 'X')
            {
                temsq.push({ny,nx});
            }
            else if (map[ny][nx] == '.')
            {
                sq.push({ny,nx});
            }
            else if (map[ny][nx] == 'L')
            {
                Lfind = true;
                break;
            }
        }
    }

   
    
}
void wbfs()
{
    
    while(!wq.empty())
    {
  
        int y = wq.front().first;
        int x = wq.front().second;
        wq.pop();
        //cout << "wy : " << y <<" " <<"wx : "<< x <<"\n";
        //bool isice = false;
        for(int j=0; j<4; j++)
        {
            int ny = y + dy[j];
            int nx = x + dx[j];
                
            if(ny < 0 || ny >= r || nx < 0 || nx >=c)
                continue;
            if(map[ny][nx] == 'X')
            {    
                map[ny][nx] = '.';
                temwq.push({ny,nx});
            }
        }
     
    }

}


void meet(){
    int result = 0;
    while(!Lfind)
    {
        sbfs();
        if(Lfind) break;
        wbfs();
      /*  for(int i = 0; i < r; i ++)
        {
           
            for(int j=0 ; j< c; j++)
            {
                cout << map[i][j] <<" ";
            }
            cout <<"\n";
        }*/
        wq = temwq;
        sq = temsq;
        
        while (!temwq.empty()) temwq.pop();
        while (!temsq.empty()) temsq.pop();
        result ++;
    }
    cout << result <<"\n";
}

int main()
{
    cin >> r >> c;
    for(int i = 0; i < r; i ++)
    {
        string str;
        cin >> str;
        for(int j=0 ; j< str.size(); j++)
        {
            map[i][j] = str[j];
            if(str[j] == '.')
            {
                wq.push({i,j}); // y , x 
            }
            if(str[j] == 'L')
            {
                if(L1.first == -1)
                {
                    L1.first = i ;
                    L1.second = j;
                }
                wq.push({i,j}); // 백조도 물 공간이다 
            }
        }
    }
    
   //cout << L1.first <<" " << L1.second <<"\n";
    
    sq.push({L1.first,L1.second});
    visit[L1.first][L1.second] = 1;
    
    meet();
    
    

    return 0;
}