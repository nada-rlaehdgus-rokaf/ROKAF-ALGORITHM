#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int treey[8] = {-1,0,1,-1,1,-1,0,1};
int treex[8] = {-1,-1,-1,0,0,1,1,1};

int n,m,k;
 
int map[11][11]; 
int fert[11][11];


int result = 0 ;

vector<int> tree[11][11];
void spring(vector<int> dead[11][11],vector<int> alive[11][11] )
{
    for(int i = 1 ; i <= n; i ++ )
    {
        for(int j = 1; j<=n; j++)
        {
            if(tree[i][j].size()==0)
                continue;
            for(int k = 0 ; k< tree[i][j].size(); k++)
            {
                if(tree[i][j][k] == 0)
                    continue;
                if(map[i][j] >= tree[i][j][k])
                {
                    map[i][j] -= tree[i][j][k] ;
                    alive[i][j].push_back(tree[i][j][k]+1);
                }
                else{
                    dead[i][j].push_back(tree[i][j][k]);
                }
            }
        }
    }

}

void summer(vector<int> dead[11][11])
{
    for(int i = 1; i<=n; i++ )
    {
        for(int j = 1; j<=n; j++)
        {
            if(dead[i][j].size()==0)
                continue;
            for(int k = 0; k< dead[i][j].size(); k++)
            {
                map[i][j] += (dead[i][j][k] / 2);
            }
        }
    }


}
void autumn(vector<int> alive[11][11])
{
    for(int i = 1; i<=n; i++ )
    {
        for(int j = 1; j<=n; j++)
        {
            if(alive[i][j].size()==0)
                continue;
            for(int k = 0; k < alive[i][j].size(); k++)
            {
                if(alive[i][j][k] %5 == 0 )
                {
                    int x = i;
                    int y = j;
                    for(int s = 0 ; s<8; s++)
                    {
                        int nx = x + treex[s];
                        int ny = y + treey[s];
                        if(nx < 1 || nx > n 
                        || ny < 1 || ny > n )
                            continue;
                        alive[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
}
void winter()
{
    for(int i = 1 ; i <=n ; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            map[i][j] += fert[i][j];
        }
    }


}
void initialize(vector<int> alive[11][11])
{
     for(int j = 1; j <= n; j++)
    {
        for(int s=1 ; s<=n; s++)
        {
            alive[j][s] = tree[j][s];
        }
    }

}


void solution()
{
    
    for(int i = 0; i < k ; i ++)
    {
        vector<int> dead[11][11];
        vector<int> alive[11][11];
        //initialize(alive);
        spring(dead,alive);
        summer(dead);
        autumn(alive);
        winter();
        for(int j = 1; j <= n; j++)
        {
            for(int s=1 ; s<=n; s++)
            {
                tree[j][s].clear();
            }
        }

         for(int j = 1; j <= n; j++)
        {
            for(int s=1 ; s<=n; s++)
            {
               
                tree[j][s] = alive[j][s];
            }
        }
        // for (int j = 1; j <=n; j++)
        // {
        //     for(int s=1; s<=n; s++)
        //     {
        //         cout << "j : " <<j << "s :  " << s <<"\n";
        //         for(int a = 0 ; a < tree[j][s].size(); a++ )
        //         {
        //             cout << tree[j][s][a] <<" ";
        //         }
        //         cout <<"\n";
        //     }
        // }

        for(int j = 1; j <= n; j++)
        {
            for(int s = 1; s <= n; s++)
            {
                sort(tree[j][s].begin(), tree[j][s].end());
            }
        }   
    }






}

int main()
{
    cin >> n >> m >> k; 
    for(int i = 1; i<= n; i++)
    {
        for(int j = 1 ; j <= n; j++)
        {
            cin >> fert[i][j];
        }
    }

    for(int i = 0; i < m; i++)
    {
        int x,y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }
    for(int i = 1; i<=n ; i++)
    {
        for(int j= 1; j<=n; j++)
        {
            map[i][j] = 5 ;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sort(tree[i][j].begin(), tree[i][j].end());
        }
    }

    solution();

    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(tree[i][j].size() == 0)
                continue;
            for(int k = 0 ; k < tree[i][j].size(); k++)
            {
                result++;
            }
        }
    }

    cout << result <<"\n";

    return 0;
}