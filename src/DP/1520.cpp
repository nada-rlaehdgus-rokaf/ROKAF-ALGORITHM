#include <iostream>
#include <vector>
using namespace std;
int arr[501][501];
int graph[501][501];
int n,m;
int dx[4] = {0,0,-1,1}; // 상 하 좌 우
int dy[4] = {-1,1,0,0};
int visited[501][501];
int result = 0;
vector<pair<int,int>> pos_save[501][501];
void solution(int curx,int cury)
{
   
  if(curx == m-1 && cury == n-1 )
  {
      
      //result +=1;
      return;
  }
//     if((curx == m-2 && cury == n-1) || 
//   (curx == m-1 && cury == n-2) )
//   {
//           for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<m; j++)
//         {
            
//             cout << visited[i][j] <<" "; 
//         }
//         cout <<"\n";
//     }
//       //result +=1;
//       return;
//   }
   
    for(int i=0; i<4; i++)
    {
        int nx =  curx +dx[i];
        int ny = cury + dy[i];
        if(nx < 0  || nx >= m || ny < 0 || ny >=n)
            continue;
        // if(visited[ny][nx] == 1)
        //     continue;
        if(arr[cury][curx] <= arr[ny][nx])
            continue;
        
        //visited[ny][nx] = 1;
        // if(visited[ny][nx] == 0)
        // {
        //     visited[ny][nx] = visited[cury][curx];
        //     bt.push_back({ny,nx});
        //     for(int i=0; i< bt.size(); i++)
        //     {
        //         pos_save[ny][nx].push_back(bt[i]);
        //     }
        //     // pos_save[ny][nx].push_back({cury,curx});
        //     solution(nx,ny,bt);
        // }
        // else{
        //     //if(visited)
        //     //visited[ny][nx] += visited[cury][curx];
        //     //pos_save[ny][nx].push_back({cury,curx});
        //     bool flag = false;
        //     for(int i=0 ; i<min(bt.size(),pos_save[ny][nx].size()) ; i++)
        //     {
        //         if(bt[i].first != pos_save[ny][nx][i].first && 
        //         bt[i].second != pos_save[ny][nx][i].second)
        //         {
        //             flag = true;
        //         }
        //     }
        //     if(flag == false)
        //     {
        //         visited[ny][nx] = visited[cury][curx];
        //     }
        //     else{
        //         visited[ny][nx] += visited[cury][curx];
        //     }
        //     bt.push_back({ny,nx});
        //     solution(nx,ny,bt);
        // }
        //visited[ny][nx] = 0;
    }
  
    
    
}


int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int a;
            cin >> a;
            arr[i][j] = a;
            visited[i][j] = -1;
        }
        
    }
    
    // for(int i = 1; i<m; i++)
    // {
    //     for(int j=1; j<n; j++)
    //     {
    //         if(arr[j][i] > arr[j+1][i])
    //         {
    //             graph[j+1][i] =1; 
    //         }
    //         else{
                
    //         }
    //     }
    // }
  
    solution(0,0);
    //cout<<"Hello World";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            
            cout << visited[i][j] <<" "; 
        }
        cout <<"\n";
    }
    cout << visited[n-1][m-1] <<"\n";
    return 0;
}