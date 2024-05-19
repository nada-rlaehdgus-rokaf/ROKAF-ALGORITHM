#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> save;
int arr[9];
int visited[9];
int index = 0;
void print(int k, int idx){
    if(k==m){
       
      
        for(int i=0; i<n ;i++){
            if(visited[i] == 1)
            {   
                cout << save[i] <<" ";
            }
        }
        cout <<"\n";
        
        return;
    }
    
    
    for(int i=idx; i<n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            print(k+1,i);
            visited[i] = 0;
        }
    }
    
 
 
}


int main()
{
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        save.push_back(a);
    }
    sort(save.begin(),save.end());
    
   
    print(0,0);
 

    return 0;
}
