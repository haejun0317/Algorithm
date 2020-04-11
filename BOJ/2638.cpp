﻿/*
	BOJ 2638 - 치즈
	Created by haejun on 2020/04/11
*/
#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

const int MAX = 102;
int arr[MAX][MAX];
bool check[MAX][MAX];
int n, m;

//반복 플래그
int flag = 0;
int ansTime = 0;

//구조체
struct coor {
	int y;
	int x;
};
queue <coor> q;

//4방면
bool inside(int y, int x) {
	return y >= 0 && y <= n + 1 && x >= 0 && x <= m + 1;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		check[y][x] = 1;

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && check[ny][nx] == 0 && arr[ny][nx] == 0) {
				check[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
}

void solution() {
	ansTime = 0;
	while (true) {
		// 1. BFS로 공기확산
		q.push({ 0,0 });
		bfs();

		flag = 1;

		// 2. 치즈가 있는 곳을 확인하며 주변에 공기 2면이 있으면 치즈 삭제
		int cnt = 0, ny, nx;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				if (arr[i][j] == 1) {
					flag = 0;
					cnt = 0;
					for (int p = 0; p < 4; p++) {
						ny = i + dy[p];
						nx = j + dx[p];
						if (check[ny][nx] == 1) cnt++;
					}
					if (cnt >= 2) arr[i][j] = 0;
				}
			}
		}

		memset(check, 0, sizeof(check));

		if (flag == 1) break;
		else ansTime += 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	solution();

	cout << ansTime << endl;

	return 0;
}