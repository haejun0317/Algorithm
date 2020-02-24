/*
	BOJ 1926 - 그림
	Created by haejun on 2020/02/24
*/
#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
const int MAX = 502;

int arr[MAX][MAX];
int check[MAX][MAX];
int n, m;

struct coor {
	int y;
	int x;
};
int group;
int cnt;
int maxCnt;

queue <coor> q;

//inside check, dir
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}
int dy[4] = {-1,1,0,0};
int dx[4] = { 0,0,-1,1 };

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && arr[ny][nx] == 1 && check[ny][nx] == 0) {
				check[ny][nx] = 1;
				cnt++;
				if (cnt > maxCnt) maxCnt = cnt;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && check[i][j]==0) {
				check[i][j] = 1;
				group++;
				cnt = 0;
				cnt++;
				q.push({ i,j });
				bfs();
			}
		}
	}

	if (group == 0) {
		cout << "0\n0";
	}
	else {
		cout << group << "\n";
		cout << maxCnt << "\n";
	}



	return 0;
}