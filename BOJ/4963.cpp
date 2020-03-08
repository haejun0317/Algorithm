/*
	BOJ 4963 - 섬의 개수
	Created by haejun on 2020/03/08
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

const int MAX = 52;
int n, m;
int arr[MAX][MAX];
bool check[MAX][MAX];

struct coor {
	int y;
	int x;
};
queue <coor> q;
int dy[8] = { -1,1,0,0,-1,-1,1,1 };
int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
int gNum = 0;

bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		int ny, nx;
		for (int i = 0; i < 8; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && arr[ny][nx] == 1 && check[ny][nx] == 0) {
				q.push({ ny,nx });
				check[ny][nx] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> m >> n;
		if (n == 0 && m == 0) break;

		memset(check, 0, sizeof(check));
		gNum = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1 && check[i][j] == 0) {
					check[i][j] = 1;
					q.push({ i,j });
					gNum++;
					bfs();
				}
			}
		}

		cout << gNum << "\n";
	}

	return 0;
}