#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int n ,  m , t;

vector<vector<int>> Board(52,vector<int>(52,0));
vector<pair<pair<int,int>,int>> command;  // x, d, k 
int result  = 0 ;

void Rotate(int x, int d, int k)
{
    if(d == 0)
    {
        for(int i = 1 ; x * i <= n ; i++)
        {
            vector<int> CopyBoard(m+1,0);
            for(int j = 1; j <=m ; j ++)
            {
                int pos = (j+k) % m > 0 ? (j+k) % m : m;
                CopyBoard[pos]= Board[x*i][j] ;
            }
            for(int j = 1; j <= m ; j++)
            {
                Board[x*i][j] = CopyBoard[j];
            }
        }
    }
    else if(d == 1)
    {
        for(int i = 1 ; x * i <= n ; i++)
        {
            vector<int> CopyBoard(m+1,0);
            for(int j = 1; j <=m ; j ++)
            {
                int pos;
                pos =  j - k > 0 ? j-k : m - (k-j);
                CopyBoard[pos]= Board[x*i][j] ;
            }
            for(int j = 1; j <= m ; j++)
            {
                Board[x*i][j] = CopyBoard[j];
            }
        }
    }

}
void DeleteN()
{
    // 해당 반지름 원에서 인접하게 같음 
    // 다른 반지름 끼리 인전하게 같음 
    vector<vector<int>> CopyBoard(52,vector<int>(52,0)); // -1 표시 해서 나중에 지우기
    int cnt = 0 ;
    for(int i = 1 ; i <= n ; i ++ )
    {
        for(int j = 1; j <= m ; j++)
        {
            if(Board[i][j] == -1)
                continue;
            int standard = Board[i][j] ;
            int leftpos = (j+ 1) %  m  > 0  ? (j+1) % m : m ;
            int rightpos =  j - 1 > 0 ? j-1 : m;
            int left = Board[i][leftpos];
            int right = Board[i][rightpos];
            if(standard == left)
            {
                CopyBoard[i][j] = -1;
                CopyBoard[i][leftpos] = - 1;
            }
            if(standard==right)
            {
                CopyBoard[i][j] = -1;
                CopyBoard[i][rightpos] = - 1;
            }
            
        }
    }
    for(int i = 1 ; i <=m  ; i ++ )
    {
        for(int j = 1; j< n;  j++)
        {
            if(Board[j][i] == Board[j+1][i])
            {
                CopyBoard[j][i] = -1 ; 
                CopyBoard[j+1][i] = -1;
            }
        }
    }

    for(int i = 1 ;i <=n ; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(Board[i][j] == -1)
                continue;   
            if(CopyBoard[i][j] == -1)
            {
                Board[i][j] = CopyBoard[i][j];
                cnt ++; 
            }
        }
    }
   // cout << "cnt : " << cnt <<"\n";
    if(cnt == 0)
    {
        int sum = 0 ; 
        int aliven = 0 ;
        for(int i = 1 ;i <=n ; i++)
        {
            for(int j = 1; j<= m; j++)
            {
                if(Board[i][j] == -1)
                    continue;
                sum += Board[i][j];
                aliven ++; 
            }
        }
        float avg = (double)sum / aliven;
        //cout << "avg: "<< avg << " " <<sum <<" "<<aliven <<"\n";
        for(int i = 1 ;i <=n ; i++)
        {
            for(int j = 1; j<= m; j++)
            {
                if(Board[i][j] == -1)
                    continue;
                if(avg > Board[i][j])
                {
                    Board[i][j] ++;
                }
                else if(avg < Board[i][j])
                {
                    Board[i][j] --;
                }
            }
        }

    }


}

void solution()
{
    // 회전 시계 반시계 몇번 
    for(int i = 0 ; i < t; i ++)
    {
        int x, d, k  ;  // x 는 배수 , d는 방향 k는 몇번 
        x = command[i].first.first;
        d=  command[i].first.second;
        k = command[i].second;
        Rotate(x,d,k);
        /* cout << "===============" <<"\n"; 
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                cout << Board[i][j] <<" ";
            }
            cout <<"\n";
        }
        cout << "===============" <<"\n";  */
        DeleteN();
    }   

    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(Board[i][j] == -1)
                continue;
            result += Board[i][j];
        }
    }

}





int main()
{
    cin >> n >> m >> t;
    for(int i  = 1 ; i <= n;  i++)
    {
        for(int j = 1  ; j <=m;  j ++)
        {
            cin >> Board[i][j] ;
        }
    }
    for(int i = 0 ; i < t;  i++)
    {
        int x, d, k ;
        cin >> x >> d >> k  ;
        command.push_back({{x,d},k});
    }

    solution();
   /*  for(int i = 1; i<= n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            cout << Board[i][j] <<" ";
        }
        cout <<"\n";
    }
 */
    cout << result <<"\n";

    return 0;
}