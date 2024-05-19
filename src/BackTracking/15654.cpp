#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> arr;
int visited[9];
int save[9];
void print(int k){
    if(k == m){
        for(int i= 0 ; i<m; i++){
            cout << save[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0 ; i<n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            save[k] = arr[i];
            print(k+1);
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
       arr.push_back(a);
   }
   sort(arr.begin(),arr.end());
   
   print(0);

    return 0;
}
