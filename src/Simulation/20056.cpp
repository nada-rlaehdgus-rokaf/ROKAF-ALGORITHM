#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

int fdx[8] = {0,1,1,1,0,-1,-1,-1};
int fdy[8] = {-1,-1,0,1,1,1,0,-1};

int n , m , k ;


struct FireBall
{
    int r,c,m,s,d;   
};

 vector<FireBall> fireballs;
vector<FireBall> map[51][51];

int result = 0 ;


void solution()
{
    queue<FireBall> q ;

    for(int a = 0 ;  a < k ; a ++)
    {
        for(int i = 0 ; i<fireballs.size(); i++)
        {
            q.push(fireballs[i]);
        }

        while(!q.empty())
        {
            
            int r = q.front().r;
            int c = q.front().c;
            int m = q.front().m;
            int s = q.front().s;
            int d = q.front().d;
            q.pop();
            
            int nr = r + fdy[d]*s ;
            int nc = c + fdx[d]*s ;
            int nm = m ;
            int ns = s ;
            int nd = d ;
            
            if(nr < 0 || nr >=n || nc <0 || nc>=n)
                continue;
            //cout << " nr : " << nr << "nc : " << nc <<"\n";
            map[nr][nc].push_back({nr,nc,nm,ns,d});
        }

        for(int i = 0 ;  i < n; i ++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(map[i][j].size() < 2 )
                    continue;
                int fsize = map[i][j].size();
                int sumM = 0 ;
                int sumS = 0 ;
                bool odd = false ;
                bool even = false;
                for(int s = 0 ; s<fsize; s++)
                {
                    sumM += map[i][j][s].m;
                    sumS += map[i][j][s].s;
                    if(map[i][j][s].d % 2 == 0)
                    {
                        even = true; 
                    }
                    else{
                        odd = true;
                    }
                    
                }
                map[i][j].clear();

                sumM = (sumM / 5 );
                sumS = (sumS / fsize);

                if(even == false || odd == false )
                {
                    for(int s = 0 ; s < 4 ; s++)
                    {
                        map[i][j].push_back({i,j,sumM,sumS,s*2});
                    }
                }
                else{
                    for(int s = 0 ; s < 4 ; s++)
                    {
                        map[i][j].push_back({i,j,sumM,sumS,s*2+1});
                    }
                }


            }
        }
        fireballs.clear();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n;  j++)
            {
                if(map[i][j].size() == 0)
                    continue;
                for(int s= 0 ; s < map[i][j].size();  s++)
                {
                    fireballs.push_back(map[i][j][s]);
                }
            }
        }

    }

      for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n;  j++)
            {
                if(map[i][j].size() == 0)
                    continue;
                for(int s = 0 ; s< map[i][j].size(); s++)
                {
                    //cout << map[i][j][s].m << "\n";
                    result += map[i][j][s].m;
                }
            }
        }

}



int main()
{
   
    cin >> n >> m >>  k ;

    
    for(int i = 0 ; i < m ; i++)
    {
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d ;
        FireBall fireball;
        fireball.r = r;
        fireball.c = c;
        fireball.m = m;
        fireball.s = s ;
        fireball.d = d ; 
        fireballs.push_back(fireball);
    }

    solution();

    cout << result <<"\n";


    return 0;
}