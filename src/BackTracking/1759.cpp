#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char arr[6][6];
int visited[6][6];
int result = 0 ;
int dx[4] = {0,0,-1,1}; // 상 하 좌 우
int dy[4] = {-1,1,0,0};
vector<pair<int,int>> save;

void solution(int k, int county, int counts){
    if(county >=4 ){
        return;
    }
    if(k==7){
        result+=1;
       // cout <<"result : " << result <<"\n";
        return;
    }
    
    for(int k=0; k<save.size(); k++)
    {
        for(int i=0; i<4; i++){
            int ny = dy[i] + save[k].first;
            int nx = dx[i] + save[k].second;
            cout << ny <<" "<<nx <<"\n";
            if (nx <1 || nx > 5 || ny <1 || ny >5)
                continue;
            if (visited[ny][nx] == 1)
                continue;
        // cout << ny <<" "<<nx <<"\n";
        // visited[ny][nx] = 1;
        //solution(k,x,y,county,counts);
        // visited[ny][nx] = 0;
        
        
            if(arr[ny][nx] == 'S')    
            {
                visited[ny][nx] = 1;
                save.push_back({ny,nx});
                solution(k+1,county,counts+1);
                visited[ny][nx] = 0;

            }
            else if(arr[ny][nx] == 'Y')
            {
                visited[ny][nx] = 1;
                save.push_back({ny,nx});
                solution(k+1,county+1,counts);
                visited[ny][nx] = 0;

            }
        
        }   
    }
    
    
    
    
    
}


int main()
{
    // cout<<"Hello World";
    for(int i=1; i<6; i++){
        for(int j=1; j<6; j++){
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }

    // for(int i=1; i< 6; i++)
    //     solution(0,1,i,0,0);
    // for (int i=2; i<6; i++)
    //     solution(0,i,1,0,0);
    
    solution(0,0,0);

    cout << result <<"\n";
    
    return 0;
}

