#include <iostream>
#include <vector>

using namespace std;

//vector<int> save;
//int arr[]
vector<vector<int>> save;
int visited[14];
int arr[7];
void print(int k,int save_num,int idx){
    if(k == 6 ){
        for(int i= 0; i<6; i++ ){
            cout << arr[i] <<" ";
        }
        cout <<"\n";
        return;
    }
    
    
    for(int i=idx; i<save[save_num].size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            arr[k] = save[save_num][i];
            print(k+1, save_num,i);
            visited[i] = 0;
        }
    }

}


int main()
{
    //int count = 0;
    while(true){
        int a;
        cin >> a; 
        if(a == 0)
            break;
        vector<int> karr(a,0);
        for(int i=0; i<a; i++)
        {
            int x;
            cin >> x;
            karr[i] = x;
        }
        save.push_back(karr);
    }
    
    // for(int i=0; i<save.size(); i++){
    //     for(int j=0; j<save[i].size(); j++)
    //     {
    //         cout<< save[i][j] << " ";
    //     }
    //     cout <<"\n";
    // }
    
    
    
    //cout<<"Hello World";
    for(int i=0; i<save.size(); i++){
        print(0,i,0);
        cout <<"\n";
    }

    return 0;
}
