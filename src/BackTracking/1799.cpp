#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int board[11][11];
vector<pair<int,int>> visited_black;
vector<pair<int,int>> visited_white;
// vector<pair<int,int>> can_pos;
// 검은 색과 흰색을 기준으로 2개 분할 backtracking 해볼 것 
int pos_count = 0;
int n;
int white_result = 0;
int black_result = 0;
bool check_white(int y,int x){
    for(int i=0; i<visited_white.size(); i++){
        if(abs(y-visited_white[i].first) == abs(x-visited_white[i].second)){
            return false;
        }
    }
    return true;
}
bool check_black(int y,int x){
    for(int i=0; i<visited_black.size(); i++){
        if(abs(y-visited_black[i].first) == abs(x-visited_black[i].second)){
            return false;
        }
    }
    return true;
}

void solve_white(int k,int count,int y,int x){ // 0,0 시작
 /*   if(k==n*n){
        result = max(result,count);
        return;
    }
    int index = k;
    for(int i=k; i<n*n; i++){
        if(board[i/n][i%n] == 0){
            index+=1;
            continue;
        }
        if(check(i/n,i%n)){
            visited.push_back({i/n,i%n});
            solve(index+1,count+1);
            visited.pop_back();
        }
        else{
            index+=1;
        }
    }*/
  /*  if(k== pos_count){
        result = max(result,count);
        return;
    }*/
/*    int index = k;
    for(int i = k; i<white_count; i++){
        if(check(can_pos[i].first,can_pos[i].second)){
            visited.push_back({white[i].first,white[i].second});
            solve(index+1,count+1);
            visited.pop_back();
        }
        else{
            index+=1;
        }
    }*/
    if(k == n){
        white_result = max(white_result,count);
        return;
    }
    if(board[y][x] == 1){
        if(check_white(y,x))
        {
            visited_white.push_back({y,x});
            solve_white(k , count+1, y,x);
        }
        
    }
    
    
}
void sovle_black(int k,int count,int y,int x){ // 0,1 시작
    if(k == n){
        black_result = max(black_result,count);
        return;    
    }
    
    
    
}

int main()
{
   cin >> n;
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           int a;
           cin >> a;
           board[i][j] = a;
       }
   }

    // for(int i=0; i<visited.size(); i++){
    //     cout <<visited[i].first <<" "<<visited[i].second<<'\n';
    // }
    solve_white(0,0,0,0);
    sovle_black(0,0,0,1);
    cout << white_result+black_result <<'\n';
    return 0;
}
