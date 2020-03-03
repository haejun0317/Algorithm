/*
	BOJ 3055 - 탈출
	Created by haejun on 2020/03/03
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
char arr[MAX][MAX];
int check[MAX][MAX];

int r, c;
int sy, sx, ey, ex;

int ans = 0;

struct coor {
	int y;
	int x;
	int cnt;
};
queue <coor> q;

bool inside(int y, int x) {
	return y >= 0 && y < r && x >= 0 && x < c;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
void BFS() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		check[y][x] = 1;

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && arr[ny][nx] == 'D' && cnt != -1) {
				ans = cnt + 1;
				return;
			}
			if (inside(ny, nx) && check[ny][nx] == 0 && arr[ny][nx] == '.' && cnt == -1) {
				check[ny][nx] = 1;
				q.push({ ny,nx,-1 });
			}
			else if (inside(ny, nx) && check[ny][nx] == 0 && arr[ny][nx] == '.' && cnt != -1) {
				check[ny][nx] = 1;
				q.push({ ny,nx,cnt + 1 });
			}
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'D') {
				ey = i;
				ex = j;
			}
			else if (arr[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (arr[i][j] == '*') {
				q.push({ i,j,-1 });
			}
		}
	}
	q.push({ sy,sx,0 });
	BFS();

	if (ans == 0) {
		cout << "KAKTUS" << endl;
	}
	else {
		cout << ans << endl;
	}

	return 0;
}
