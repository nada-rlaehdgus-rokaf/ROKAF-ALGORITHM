#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> save;
int n,m;
int arr[8];
//int visited[8];
void print(int k){
    if(k == m){
        for(int i=0; i<m; i++)
        {
            cout << arr[i] << " ";
        }        
        cout <<"\n";
        return;
    }
    for(int i=0; i<n; i++){
        //if(visited[i] == 1){
            //visited[i] = 1;
            arr[k] = save[i];
            print(k+1);
            //visited[i] = 0 ;
       // }
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
 
    print(0);

    return 0;
}
