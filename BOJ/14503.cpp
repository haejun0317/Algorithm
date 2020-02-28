/*
	BOJ 14503 - 로봇 청소기
	Created by haejun on 2020/02/28
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int MAX = 52;

int n, m;
int arr[MAX][MAX];

struct coor {
	int y;
	int x;
	int dir;
};
queue <coor> q;

int ry, rx, rd;
// 청소한 벽
int ans;

//inside
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}
//북동남서
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void func() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().dir;
		q.pop();

		if (arr[y][x] == 0) {
			arr[y][x] = 2;
			ans++;
		}

		bool flag = false;
		int ny, nx, nd;
		for (int i = 0; i < 4; i++) {
			nd = (d + (3- i)) % 4;
			ny = y + dy[nd];
			nx = x + dx[nd];
			if (inside(ny, nx) && arr[ny][nx] == 0) {
				q.push({ ny,nx,nd });
				flag = true;
				break;
			}
		}

		if (flag == true) continue;

		ny = y - dy[d];
		nx = x - dx[d];
		if (inside(ny, nx) && arr[ny][nx] != 1) {
			q.push({ ny,nx,d });
		}
		else break;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 1. input
	cin >> n >> m;
	cin >> ry >> rx >> rd;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];

	q.push({ ry,rx,rd });
	
	func();

	cout << ans << "\n";


	return 0;
}