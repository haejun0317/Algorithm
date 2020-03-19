/*
	BOJ 1600 - 말이 되고픈 원숭이
	Created by haejun on 2020/03/19
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 202;
int n, m, k;
int ans = 0;
int anscnt = 0;

int arr[MAX][MAX];
bool check[MAX][MAX][31];

struct coor {
	int y;
	int x;
	int cnt;
	int jump;
};
queue <coor> q;

//inside check
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
//대각선
int ddy[8] = { -2,-2,-1,-1,1,1,2,2 };
int ddx[8] = { -1,1,-2,2,-2,2,-1,1 };

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int jump = q.front().jump;
		q.pop();

		if (y == n - 1 && x == m - 1) {
			ans = 1;
			anscnt = cnt;
			break;
		}

		int ny, nx;
		if (jump < k) {
			for (int i = 0; i < 8; i++) {
				ny = y + ddy[i];
				nx = x + ddx[i];
				if (inside(ny, nx) && check[ny][nx][jump + 1] == 0 && arr[ny][nx] == 0) {
					check[ny][nx][jump + 1] = 1;
					q.push({ ny,nx,cnt + 1,jump + 1 });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && check[ny][nx][jump] == 0 && arr[ny][nx] == 0) {
				check[ny][nx][jump] = 1;
				q.push({ ny,nx,cnt + 1,jump });
			}
		}


	}
	while (!q.empty()) q.pop();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	q.push({ 0,0,0,0 });
	bfs();

	if (ans == 1) {
		cout << anscnt << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}