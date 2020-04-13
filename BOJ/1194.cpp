﻿﻿/*
	BOJ 1194 - 달이 차오른다, 가자.
	Created by haejun on 2020/04/13
*/
#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
const int MAX = 51;
char arr[MAX][MAX];
bool check[MAX][MAX][1 << 6];

int n, m;
int moving = 0;

//inside check
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

//struct
struct coor {
	int y;
	int x;
	int cnt;
	int key;
};
queue <coor> q;

int sy, sx;

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int key = q.front().key;
		q.pop();


		if (arr[y][x] == '1') {
			moving = cnt;
			break;
		}

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && check[ny][nx][key] == 0) {
				if (arr[ny][nx] == '.' || arr[ny][nx] == '1') {
					check[ny][nx][key] = 1;
					q.push({ ny,nx,cnt + 1, key });
				}
				else if (arr[ny][nx] >= 'a' && arr[ny][nx] <= 'f') {
					int tempkey = key | (1 << (int(arr[ny][nx]) - 'a'));
					check[ny][nx][tempkey] = 1;
					q.push({ ny,nx,cnt + 1, tempkey });
				}
				else if (arr[ny][nx] >= 'A' && arr[ny][nx] <= 'F') {
					int tempkey = key & (1 << (int(arr[ny][nx]) - 'A'));
					if (tempkey != 0) {
						check[ny][nx][key] = 1;
						q.push({ ny,nx,cnt + 1,key });
					}
				}
			}
		}
	}
	while (!q.empty()) q.pop();
}

void solution() {
	check[sy][sx][0] = 1;
	q.push({ sy,sx,0,0 });
	bfs();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				sy = i;
				sx = j;
				arr[i][j] = '.';
			}
		}
	}
	solution();

	if (moving == 0) cout << -1 << endl;
	else cout << moving << endl;


	return 0;
}