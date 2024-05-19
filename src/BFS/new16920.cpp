#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n,m,p;

int check[10] ; 

char map[1001][1001];

queue<pair<pair<int,int>,int>> q[10] ;  // y , x 

int visit[1001][1001];


void solution()
{
    
    // check의 최대 수 만큼 나온 것들만 다시 넣어주기 큐 하나 정해서 넣어주기
    // 한round를   정해서 모든 큐를 돌려주기
  
    int game_round = 1;
    
    while(true)
    {
        bool stop = true;
        for(int i=1; i<=p; i++ )
        {
            if(q[i].size() != 0)
                stop = false;
        }
        
        if(stop)
            break;
        
        for(int i = 1 ; i <=p; i++)
        {
            queue<pair<pair<int,int>,int>> tempq;
            //cout << " i : " << i <<"\n";
            while(!q[i].empty())
            {
                int y  = q[i].front().first.first;
                int x =  q[i].front().first.second;
                int move =  q[i].front().second;
                
                q[i].pop();
                
                
                //cout << " y : " << y << " x : "<< x<< "move : " << move << "\n";
                // 걍 바로 스킵하기 위해 4방향으로 체크해주기 
                if(move + 1 > game_round * check[i])
                    continue;

                for(int j=0; j<4; j++)
                {
                    int ny = y + dy[j] ;
                    int nx = x + dx[j] ;
                    
                    if(ny >n || ny < 1 || nx >m || nx < 1)
                        continue;
                    
                    if(map[ny][nx] == '#')
                        continue;
                        
                    if(map[ny][nx] >= '1' 
                        && map[ny][nx] <= '9' )    
                        continue;
                        
                    if(map[ny][nx] == '.')
                    {
                        // 바꾼다음에 숫자 넣기 혹은 일단 바꾸고 숫자 넣기
                        //cout << i +'0' <<"\n";
                        map[ny][nx] = i + '0';
                        q[i].push({{ny,nx},move+1});
                        if(move + 1 == check[i] * game_round)
                            tempq.push({{ny,nx},move+1});
                        
                    }
                }
                
                
                
                
                
            }
            
            q[i] = tempq;
            while(!tempq.empty())
                tempq.pop();
            
            
        }
        
        
        
        game_round++;
        
        
    }
    
}


// #5번  #8번 오류 방향으로 쭉 가는게 아닌 꺾을 수 있다는 것 

int main()
{
    cin >> n >> m >> p ;
    
    for(int i= 1; i<= p ; i++)
    {
        int a;
        cin >> a;
        //cout << a << "\n";
        check[i] = a;
    }
    
    for(int i = 1 ; i<= n; i++)
    {
        for(int j=  1; j <= m; j++)
        {
            char c;
            cin >> c;
            map[i][j] = c;
            if(c != '.' && c != '#')
            {
                q[c-'0'].push({{i,j},0});
               
            }
        }
        
        
    }
    
/*    for(int i=1; i<=p; i++)
    {
        cout << check[i] <<"\n";
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }*/
    solution();
    
    vector<int> result(10,0) ; 
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(map[i][j] >= '1' && map[i][j] <= '9')
            {
                result[map[i][j]-'0'] ++;
            }
            
        }
    }
    
 /*   for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }
    */
    for(int i=1; i<=p; i++)
    {
        cout << result[i] <<" ";
    }
    

    return 0;
}
