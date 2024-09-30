#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int map[18][18];

int N, M, D;
vector<int> archors(3,0);
int visited[18];
// 궁수는 3명 배치 
//  mC3 
int result = 0 ;
struct cmp
{
    bool operator()(pair<int,pair<int,int>>& p1 , pair<int,pair<int,int>> &p2){
        if(p1.first > p2.first)
        {
            return true;
        }
        else if(p1.first == p2.first)
        {
            if(p1.second.second > p2.second.second)
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
};

void CaclulatedDist(int idx,vector<pair<int,int>> enemies,
priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, cmp>  &dists,vector<int> isalive,vector<int> archors)
{
    //cout << "4"<<"\n";
    for(int i = 0 ; i < enemies.size(); i ++)
    {
        if(isalive[i] == 0 )
            continue;
        int y  = enemies[i].first;
        int x  = enemies[i].second;
        //cout << y << " " << x <<"\n";
        int dist = abs(y-N) + abs(x-idx);
        if(dist > D)
            continue;
        dists.push( {dist,{y,x} } );
    }
    

}
void CastleDefence(vector<int> archors)
{
    int copymap[18][18] ;
    int enemycnt = 0 ;
    int killenemy = 0;
    vector<pair<int,int>> enemies;
    //cout <<"1" <<"\n";
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0 ; j <M ; j++)
        {
            copymap[i][j] = 0;
        }
    }

    for(int i = 0 ; i < N;  i ++)
    {
        for(int j = 0 ; j < M ; j++)
        {
            copymap[i][j] = map[i][j];
            if(map[i][j] == 1 )
            {
                enemycnt++;
                enemies.push_back({i,j});

            }
        }
    }
    int idxenemycnt = enemycnt;
    vector<int> isalive(idxenemycnt,1);
    /* for(int i = 0 ; i <  archors.size(); i++)
    {
        copymap[N][archors[i]] = -1;
    }

    queue<int>  */

    // 3번 돌아서 거리 계산 후 D 이하중 좌측에  가까운 적을 죽임 
    // 살아 있는 적들은 모두 밑으로 + 1 
    
    while(true)
    {
       // cout <<"2" <<"\n";
       // vector<vector<int>> dists(3,vector<int>(idxenemycnt,1));
        // Loop 탈출 조건 enemy가 0이면 끝 
        // 모든 적이 제외된다면 게임은 종료 
        if(enemycnt == 0 )
        {
            //cout << killenemy <<"\n";
            result = max(result, killenemy);
            break;
        }
        vector<pair<int,int>> die;
        for(int i = 0 ; i < archors.size();  i++)
        {
            priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, cmp> dists;
            int idx = archors[i]; // n+1에 대해서 몇 번째인지 
            CaclulatedDist(idx,enemies,dists,isalive,archors);
            if(dists.empty())
                continue;
            int y = dists.top().second.first;
            int x  = dists.top().second.second;
            die.push_back({y,x});
            // 거리를 비교하고 우선순위를 정함?

        }
        // 죽음
        //cout <<"3"<<"\n";
        for(int i = 0 ; i < die.size(); i ++ )
        {
            int y = die[i].first;
            int x = die[i].second;
            //cout << "y : " << y << "x : " << x <<"\n";
            for(int j  = 0 ; j < enemies.size(); j++)
            {
                if(isalive[j] == 0 )
                    continue;
                if(enemies[j].first == y && enemies[j].second == x)
                {
                    isalive[j] = 0;
                    killenemy++;
                    enemycnt--;

                }
            }

        }
        // 이동 
        for(int i = 0 ;  i < enemies.size(); i ++)
        {
            if(isalive[i] == 0 )
                continue;
            int y = enemies[i].first;
            y +=1;
            enemies[i].first = y;
            //cout << enemies[i].first <<"\n";
        }

        for(int i = 0 ; i < enemies.size(); i++)
        {
            if(isalive[i] == 0 )
                continue;
            if(enemies[i].first == N)
            {
                isalive[i] = 0;
                enemycnt--;
            }
        }

        // 한번에 제거하고 
        // 제거한 것들을 제외한 모든 적군에 대해서 +1 씩 내려감 
        // 만약 성에 N에 도달했다면 사라짐 
        //cout <<"=====================" <<"\n";
    }

    

}



void combination(vector<int> archors, int idx , int cnt)
{
    if(cnt  == 3)
    {
        /* for(int i = 0 ; i < archors.size(); i++)
        {
            cout << archors[i] <<" ";
        }
        cout <<"\n"; */
        CastleDefence(archors);
        return;
    }
    for(int i = idx  ; i <M ; i++)
    {
        archors[cnt] = i;
        combination(archors,i+1,cnt+1);
    }
}

void solution()
{
    combination(archors,0,0);  


}


int main()
{
    cin >> N >> M >> D;    
    for(int i = 0; i <N; i++)
    {
        for(int j  = 0 ; j <M; j++)
        {
            cin>> map[i][j];
        }
    }

    solution();

    cout << result <<"\n";

    return 0;
}