﻿/*
	BOJ 7576 - 토마토
	Created by haejun on 2020/04/07
*/
#include<iostream>
#include<queue>
using namespace std;

const int MAX = 1005;

int arr[MAX][MAX];
int check[MAX][MAX];

int n, m;

int globalCnt = 0;

//구조체 생성
typedef struct coor {
	int y;
	int x;
	int cnt;
	coor() {};
	coor(int _y, int _x, int _cnt) : y(_y), x(_x), cnt(_cnt) {};
}coor;

//큐 생성
queue <coor> q;

//inside check
bool inside(int y, int x) {
	return (y >= 0 && y < n) && (x >= 0 && x < m);
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void BFS() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		arr[y][x] = cnt;
		if (cnt > globalCnt) globalCnt = cnt;
		q.pop();

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && arr[ny][nx] == 0) {
				arr[ny][nx] = cnt + 1;
				q.push(coor(ny, nx, cnt + 1));
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push(coor(i, j, 1));
		}
	}

	BFS();

	//flag ==0 이면 모두 익은것
	// 1 이면 모두 다 안익은것
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				flag = 1;
				break;
			}
		}
	}

	if (flag == 1) cout << -1 << endl;
	else cout << globalCnt - 1 << endl;

	//테스트 출력
	/*
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	*/


	return 0;
}