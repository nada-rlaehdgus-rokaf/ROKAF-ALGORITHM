#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
vector<int> save;
int visited[9];
int arr[9];
void print(int k,int idx){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout <<"\n";
        return;
    }
    int index = 0;
    
    for(int i=idx; i<n; i++){
        if(visited[i] == 0 && index != save[i]){
            visited[i] = 1;
            arr[k] = save[i];
            index = arr[k];
            print(k+1, i);
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
    //cout<<"Hello World";

    return 0;
}

