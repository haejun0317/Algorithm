/*
	BOJ 17142 - 연구소3
	Created by haejun on 2020/02/21
*/
#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

const int MAX = 52;
int arr[MAX][MAX];
int temp[MAX][MAX];
int check[MAX][MAX];

int n, m;

int ans = 987987987;
int k = 0;

//구조체
struct coor {
	int y;
	int x;
};
queue <coor> q;

//inside check
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void BFS() {
	int inf = 0, times = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;

		q.pop();

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && check[ny][nx] == -1 && arr[ny][nx] != 1) {
				q.push({ ny,nx });
				check[ny][nx] = check[y][x] + 1;
				if (arr[ny][nx] == 0) {
					times = check[ny][nx];
					inf++;
				}
			}

		}
	}
	if (inf == k && ans > times) ans = times;
}


void pickDFS(int count, int sy, int sx) {
	if (count == m) {
		//실행할 곳
		memset(check, -1, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == -1) {
					q.push({ i,j });
					check[i][j] = 0;
				}
			}
		}
		BFS();

		return;
	}

	for (int y = sy; y < n; y++) {
		for (int x = sx; x < n; x++) {
			if (arr[y][x] == 2) {
				arr[y][x] = -1;
				pickDFS(count + 1, y, x);
				arr[y][x] = 2;
			}
		}
		sx = 0;
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) k++;
		}
	}

	pickDFS(0, 0, 0);

	if (ans == 987987987) {
		cout << "-1" << endl;
	}
	else {
		cout << ans << endl;
	}

	return 0;
}