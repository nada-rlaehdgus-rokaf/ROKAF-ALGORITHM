#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
// vector<pair<int,int>> save;
vector<int> save;
vector<int> last;
int visited[9];
int arr[10];

void print(int k){
    
    if(k==m){

 
        for(int i=0; i<m; i++){
            cout << arr[i] <<" ";
        }
        
        cout <<"\n";
        
        return;
    }
    int index = 0;
    for(int i=0; i<n; i++){
        if(visited[i] == 0 && save[i] !=index){
            arr[k] = save[i];
            index = arr[k];
            visited[i] = 1;
            print(k+1);
            visited[i] = 0;
        }
        
    }
    // for(int i=0 ; i< n; i++){
    //     if(visited[i] == 0){
          
    //         visited[i] = 1;
    //         arr[k] = save[i];
    //         print(k+1);
    //         visited[i] = 0;
    //     }
      
    // }
    // for(int i=0; i<n; i++){
    //     if(visited[i] == 0 ){
    //         if(save[i].second ==0)
    //         {
    //             visited[i] = 1;
    //             arr[k] = save[i];
    //             print(k+1);
    //             visited[i] = 0;
    //         }
    //         else{
    //             if(k!=0 && save[i] != arr[k-1]){
    //                 visited[i] = 1;
    //                 arr[k] = save[i].first;
    //                 print(k+1);
    //                 visited[i] = 0;
    //             }
    //         }
    //     }
    // }
    return;
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
    
    // for(int i=0; i<n; i++){
    //     if(i != 0){
    //         if(save[i].first == save[i-1].first){
    //             save[i].second = save[i-1].second + 1;   
    //         }
    //     }
    // }
    
    print(0);
    //cout<<"Hello World";

    return 0;
}






