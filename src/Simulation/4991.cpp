#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int w, h;
char map[21][21];

#define INF 987654321

vector<int> anss;

void solution() {

    pair<int, int> start;         // y, x
    vector<pair<int, int>> dirty; // y, x
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
        if (map[i][j] == 'o') {
            start = {i, j};
        } else if (map[i][j] == '*') {
            dirty.push_back({i, j});
        }
        }
    }
    // for (int i = 0; i < dirty.size(); i++) {
    //   cout << dirty[i].first << " " << dirty[i].second << endl;
    // }

    int ans = INF;

    int dirty_dist[11][11] = {
        0,
    };
    int start_to_dirty[11] = {0};
    int start_to_dist[21][21];
    vector<int> dirty_order;
    for (int i = 0; i < dirty.size(); i++) {
        
        int dist[21][21];
        for (int a = 0; a < h; a++) {
            for (int b = 0; b < w; b++) {
                dist[a][b] = INF;
            }
        }

        for (int j = 0; j < dirty.size(); j++) {
            if (i == j)
                continue;
            //cout << " i : " << i << " j :" << j << endl;
            queue<pair<int, int>> q;
            dist[dirty[i].first][dirty[i].second] = 0;
            q.push(dirty[i]);
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                //cout << cur.first << " " << cur.second << "\n";
                q.pop();
                if (cur == dirty[j]) {

                    dirty_dist[i][j] = dist[cur.first][cur.second];
                    break;
                }
                for (int k = 0; k < 4; k++) {
                    int ny = cur.first + dy[k];
                    int nx = cur.second + dx[k];
                    if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                        continue;
                    if (map[ny][nx] == 'x')
                        continue;
                    if (dist[ny][nx] == INF) {
                        dist[ny][nx] = dist[cur.first][cur.second] + 1;
                        q.push({ny, nx});
                    } else if (dist[ny][nx] >= dist[cur.first][cur.second] + 1) {
                        dist[ny][nx] = dist[cur.first][cur.second] + 1;
                        q.push({ny, nx});
                    }
                }
            }
            for (int a = 0; a < h; a++) {
                for (int b = 0; b < w; b++) {
                dist[a][b] = INF;
                }
            }

        }
        dirty_order.push_back(i);
    }


  // 시작 지점에서 각 더러운 곳 까지 거리

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        start_to_dist[i][j] = INF;
      }
    }
    for (int i = 0; i < dirty.size(); i++) {
      queue<pair<int, int>> q;
      q.push({dirty[i].first, dirty[i].second});
      start_to_dist[dirty[i].first][dirty[i].second] = 0;
      while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur == start) {
          start_to_dirty[i] = start_to_dist[cur.first][cur.second];
          break;
        }
        for (int k = 0; k < 4; k++) {
          int ny = cur.first + dy[k];
          int nx = cur.second + dx[k];
          if (nx < 0 || nx >= w || ny < 0 || ny >= h)
            continue;
          if (map[ny][nx] == 'x')
            continue;
          if (start_to_dist[ny][nx] == INF) {
            start_to_dist[ny][nx] = start_to_dist[cur.first][cur.second] + 1;
            q.push({ny, nx});
          } else if (start_to_dist[ny][nx] >=
                     start_to_dist[cur.first][cur.second] + 1) {
            start_to_dist[ny][nx] = start_to_dist[cur.first][cur.second] + 1;
            q.push({ny, nx});
          }
        }
      }
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          start_to_dist[i][j] = INF;
        }
      }
    }


    
//   for (int i = 0; i < dirty.size(); i++) {
//     for (int j = 0; j < dirty.size(); j++) {
//       cout << dirty_dist[i][j] << " ";
//     }
//     cout << "\n";
//   }
//   for (int i = 0; i < dirty.size(); i++) {
//     cout << start_to_dirty[i] << " ";
//   }
//   cout << "\n";

  // 답을 어떻게
  // 4 2 6  -> 시작점에서 더러운 곳 까지 거리
  // 0 6 2
  // 6 0 4
  // 2 4 0
    //cout << "dirty_order : " <<dirty_order.size() << "\n";
    do{ 
        int sum = start_to_dirty[dirty_order[0]];
        for(int i = 0; i < dirty_order.size() - 1; i++){
            if(dirty_dist[dirty_order[i]][dirty_order[i+1]] == INF){
                sum = -1;
                break;
            }
            sum += dirty_dist[dirty_order[i]][dirty_order[i+1]];
        }
        if(sum == - 1)
        {
            continue;
        }
        ans = min(ans, sum);
    }while(next_permutation(dirty_order.begin(), dirty_order.end()));

    if (ans == INF || ans == 0 )
    {
        anss.push_back(-1);
    }
    else
    {
        anss.push_back(ans);
    }

}

int main() {
    cin >> w >> h;
  for (;;) {
    if (w == 0 && h == 0)
      break;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        char c;
        cin >> c;
        map[i][j] = c;
      }
    }
    // for (int i = 0; i < h; i++) {
    //   for (int j = 0; j < w; j++) {
    //     cout << map[i][j] << " ";
    //   }
    //   cout << "\n";
    // }

    solution();

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        map[i][j] = ' ';
      }
    }

    cin >> w >> h;
  }

  for(int i = 0 ;i < anss.size(); i++){
      cout << anss[i] << "\n";
  } 

  return 0;
}