
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>


using namespace std;

#define DIRTY 1
#define CLEAN 0
#define OBSTACLE -1
#define INT_MAX 987654321

int dy[]{ 0,0,1,-1 };
int dx[]{ 1,-1,0,0 };


int boards[21][21];

int trashToTrashLength[21][21];
int visited[21][21];
int startToTrash[21];

int w, h;
char c;


// 해당 지점 쓰레기 위치에서 다른 위치 까지 거리 구하기
void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	fill(&visited[0][0], &visited[0][0] + 21 * 21, INT_MAX);
	visited[y][x] = 0;

	while (!q.empty()) {

		int sy = q.front().first;
		int sx = q.front().second;
		int nCost = visited[sy][sx]+1;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = sy + dy[d];
			int nx = sx + dx[d];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w || visited[ny][nx] <= nCost || boards[ny][nx]==OBSTACLE) {
				continue;
			}

			visited[ny][nx] = nCost;
			q.push({ ny,nx });

		}

	}


}

// 시작점에서 쓰레기 줍는 최단 거리 구하기
int findMinPath(int y, int x, vector<pair<int, int>> &dirtyPoint) {
	vector<int> trashOrder;
	int result = INT_MAX;

	// 시작점에서 쓰레기 까지 위치 구하기
	bfs(y, x);

	for (int j = 0; j < dirtyPoint.size(); j++) {
		startToTrash[j] = visited[dirtyPoint[j].first][dirtyPoint[j].second];
	}

	// 각 쓰레기에서 다른 쓰레기 까지 위치 구하기
	for (int i = 0; i < dirtyPoint.size(); i++) {
		bfs(dirtyPoint[i].first, dirtyPoint[i].second);

		for (int j = 0; j < dirtyPoint.size(); j++) {
			if (i == j) {
				continue;
			}
			trashToTrashLength[i][j] = visited[dirtyPoint[j].first][dirtyPoint[j].second];
		}
		trashOrder.push_back(i);
	}

	// 쓰레기 줍는 모든 순서 살펴보기
	do {
		int lengthSum = startToTrash[trashOrder[0]];
		
		for (int i = 0; i < trashOrder.size()-1; i++) {
			if (trashToTrashLength[trashOrder[i]][trashOrder[i+1]]==INT_MAX) {
				lengthSum = -1;
				break;
			}
			lengthSum += trashToTrashLength[trashOrder[i]][trashOrder[i+1]];
		}
		if (lengthSum == -1) {
			continue;
		}
		result = min(result, lengthSum);

	} while (next_permutation(trashOrder.begin(), trashOrder.end()));

	// 갈 수 없는 경로가 있는 경우
	if (result == INT_MAX) {
		result = -1;
	}

	return result;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int startY, startX;

	cin >> w >> h;

	while (w != 0 && h != 0) {

		fill(&boards[0][0], &boards[0][0] + 21 * 21, 0);
		fill(&trashToTrashLength[0][0], &trashToTrashLength[0][0] + 21 * 21, 0);

		vector<pair<int, int>> dirtyPoint;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> c;
				if (c == '*') {
					boards[i][j] = DIRTY;
					dirtyPoint.push_back({ i,j });
				}
				else if (c == 'x'){
					boards[i][j] = OBSTACLE;
				}
				else if (c == 'o') {
					startY = i;
					startX = j;
					
				}
			}
		}
		cout << findMinPath(startY, startX, dirtyPoint) << endl;

		cin >> w >> h;


	}


	return 0;
}