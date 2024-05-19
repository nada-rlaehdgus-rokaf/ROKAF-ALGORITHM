#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int arr[9];
int visited[9];
vector<int> save;
void print(int k, int idx){
    if(k== m ){
        
        for(int i=0; i<m; i++){
            
            cout << arr[i] <<" ";
           
        }
        cout << "\n";
        
        return;
    }
    
    for(int i=idx; i<n; i++){
      
        arr[k] = save[i];
        print(k+1, i);
     
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
    
    //cout<<"Hello World";

    return 0;
}
