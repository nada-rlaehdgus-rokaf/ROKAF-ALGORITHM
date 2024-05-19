#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int board[51][51];

int n,m,g,r; // 행 열 초 빨 
int result = 0;

int dy[4] = {-1,1,0,0}; // 상 하 좌 우 
int dx[4] = {0,0,-1,1};
vector<pair<int,int>> cultivated; // i y j x 
int cultivated_visited[11]; 
int g_visited[51][51];
int r_visited[51][51];

void solution(vector<pair<int,int>> gv, vector<pair<int,int>>rv){
    int backup[51][51];
    // 0으로 초기화
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            backup[i][j] = 0;
        }
    }
    //  backup 을 board로 초기화 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            backup[i][j] = board[i][j];
        }
    }

    
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //     {
    //         g_visited[i][j] = 0;
    //         r_visited[i][j] = 0;
    //     }
    // }
    
    queue<pair<int,int>> gq;
    for(int i=0; i<gv.size(); i++){
        int y = gv[i].first; 
        int x = gv[i].second; 
        //r_ground[y][x] = -1;
        g_visited[y][x] = 1;
        gq.push(gv[i]);
        //g_ground[y][x] = 4;
    }
    queue<pair<int,int>>rq;
    for(int i=0; i<rv.size(); i++){
        int y = rv[i].first; 
        int x = rv[i].second; 
        //g_ground[y][x] = -1;
        r_visited[y][x] = 1;
        rq.push(rv[i]);
        //r_ground[y][x] = 4;

    }
    int count = 0;
    //cout << count <<"\n";
    while(!gq.empty() || !rq.empty()){
        // int y = gq.front().first;
        // int x = gq.front().second;
        // gq.pop();
        // cout << "green" <<"\n";
        //cout << "y : "<< y << " " << "x : " << x << "\n";
        int rsize = rq.size();
        for(int i=0; i<rsize;  i++)
        {
            pair<int,int> cur = rq.front();
            rq.pop();
            if(board[cur.first][cur.second] == 3)
                continue;
            for(int j=0; j< 4; j++){
                int ny = cur.first + dy[j];
                int nx = cur.second + dx[j];
                if(ny < 0 || ny >= n ||nx <0 || nx >=m )
                    continue;
                if(board[ny][nx] == 0 || r_visited[ny][nx] )
                    continue;
                if(board[ny][nx] == 3)
                    continue;
                if(g_visited[ny][nx] && r_visited[cur.first][cur.second] +1 
                != g_visited[ny][nx]) continue;
                else if(g_visited[ny][nx] && r_visited[cur.first][cur.second] +1 
                == g_visited[ny][nx]){
                    //cout << ny <<" " << nx <<" \n";
                    board[ny][nx] = 3;
                    count++;
                    r_visited[ny][nx] = r_visited[cur.first][cur.second] + 1;
                    continue;
                }
                //cout << ny <<" " << nx <<" \n";
                r_visited[ny][nx] = r_visited[cur.first][cur.second] + 1;
                rq.push({ny,nx});
            }
        }
        
        int gsize = gq.size();
        for(int i=0; i<gsize;  i++)
        {
            //cout<< "add" <<"\n";
            pair<int,int> cur = gq.front();
            gq.pop();
            if(board[cur.first][cur.second] == 3)
                continue;
            for(int j=0; j< 4; j++){
               int ny = cur.first + dy[j];
                int nx = cur.second + dx[j];
                if(ny < 0 || ny >= n ||nx <0 || nx >=m )
                    continue;
                if(board[ny][nx] == 0 || g_visited[ny][nx] )
                    continue;
                if(board[ny][nx] == 3)
                    continue;
                if(r_visited[ny][nx] && g_visited[cur.first][cur.second] +1 
                != r_visited[ny][nx]) continue;
                else if(r_visited[ny][nx] && g_visited[cur.first][cur.second] +1 
                == r_visited[ny][nx]){
                    //  cout << ny <<" " << nx <<" \n";
                    board[ny][nx] = 3;
                    count++;
                    g_visited[ny][nx] = g_visited[cur.first][cur.second] + 1;
                    continue;
                }
                //  cout << ny <<" " << nx <<" \n";
                g_visited[ny][nx] = g_visited[cur.first][cur.second] + 1;
                gq.push({ny,nx});
                
            }
        }
        
    }
    
    //cout << "adad" <<"\n";
    result = max(result,count);
    //     cout << "--" <<"\n";

    // if(count == 12)
    // {
    //     for(int i=0; i<n; i++)
    //     {
    //         for(int j=0; j<m; j++)
    //         {
    //             cout << board[i][j] <<" ";
    //         }
    //         cout <<"\n";
    //      }
    // }
    //   cout << "--" <<"\n";
    // for(int i=0; i<gv.size(); i++)
    // {
    //     cout << gv[i].first<<" "<<gv[i].second<<"\n";
    // }
    //       cout << "--" <<"\n";

    // for(int i=0; i<rv.size(); i++)
    // {
    //     cout << rv[i].first<<" "<<rv[i].second<<"\n";
    // }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            board[i][j] = backup[i][j];
            g_visited[i][j] = 0;
            r_visited[i][j] = 0;
        }
    }

    //cout << result << "\n";
    
}

void choose(int k,int idx,int rcount,int gcount,vector<pair<int,int>> gv, vector<pair<int,int>>rv){
    if(k == cultivated.size())
    {
        if(rcount == 0 && gcount == 0 ){
            //cout << rcount <<" " << gcount<<"\n";
            solution(gv,rv);
            return;
        }
        else{
            return;
        }
    }   
    for(int i= idx; i<cultivated.size(); i++){
        int y = cultivated[i].first;
        int x = cultivated[i].second;
        // if(cultivated_visited[i] == 1)
        // {
        //     continue;
        // }
        if(gcount > 0 )
        {   
            gv.push_back({y,x});
            //cultivated_visited[i] = 1; 
            choose(k+1,i+1,rcount,gcount-1,gv,rv);
            //cultivated_visited[i] = 0;
            gv.pop_back();
        }
        if(rcount > 0)
        {
            rv.push_back({y,x});
           // cultivated_visited[i] = 1; 
            choose(k+1,i+1,rcount-1,gcount,gv,rv);
           // cultivated_visited[i] = 0;
            rv.pop_back();
        }
        choose(k+1,i+1,rcount,gcount,gv,rv);
    }
    
    return;
}

int main()
{
    cin >> n >> m >> g >> r;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int a;
            cin >> a;
            board[i][j] = a; 
            if(a==2){
                cultivated.push_back({i,j});
                //cultivated_count+=1;
            }
        }
    }
    
    vector<pair<int,int>> gv ;
    vector<pair<int,int>>rv ; 
    
    choose(0,0,r,g,gv,rv);
    

    cout << result << "\n";

    return 0;
}

