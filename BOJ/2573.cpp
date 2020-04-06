﻿/*
	BOJ 2573 - 빙산
	Created by haejun on 2020/04/06
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;

//초기 입력 변수
const int MAX = 505;
int n, m;

//맵 배열 생성, 방문 체크 배열 생성
int arr[MAX][MAX];
int check[MAX][MAX];
//빙하 배열
int ice[MAX][MAX];

//좌표를 저장하는 구조체
typedef struct coor {
	int x;
	int y;
	coor() {};
	coor(int _x, int _y) : x(_x), y(_y) {};
}coor;

//coor 구조체를 이용한 queue생성
queue <coor> q;

//4방면 확인 배열 및 함수
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool inside(int x, int y) {
	if ((x >= 0 && x < n) && (y >= 0 && y < m)) return true;
	else return false;
}

//덩어리 확인하는 BFS 
void groupCheckBFS() {
	if (q.empty()) return;
	int x = q.front().x;
	int y = q.front().y;
	q.pop();

	check[x][y] = 1;

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (inside(nx, ny) && arr[nx][ny] != 0 && check[nx][ny] == 0) {
			check[nx][ny] = 1;
			q.push(coor(nx, ny));
		}
	}
	if (!q.empty()) groupCheckBFS();

}

//몇 덩어리가 있는지 확인
int groupCheckCnt = 0;

void groupCheck() {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (arr[i][j] != 0 && check[i][j] == 0) {
				groupCheckCnt++;
				q.push(coor(i, j));
				groupCheckBFS();
			}
		}
	}
}

//check 배열 초기화
void resetCheck() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = 0;
		}
	}
}

//빙하의 주변 0을 확인하고 -1하는 BFS;
void iceBFS() {
	if (q.empty()) return;
	int x = q.front().x;
	int y = q.front().y;
	q.pop();

	check[x][y] = 1;

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (inside(nx, ny) && arr[nx][ny] == 0) {
			ice[x][y] += 1;
			//cout<<x<<","<<y<<","<<arr[x][y]<<",X:"<<nx<<",Y:"<<ny<<"   "<<check[x][y]<<endl;
		}
		else if (inside(nx, ny) && arr[nx][ny] != 0 && check[nx][ny] == 0) {
			check[nx][ny] = 1;
			q.push(coor(nx, ny));
		}
	}
	if (!q.empty()) iceBFS();
}

//빙하 있는 곳 체크
void iceCheck() {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (arr[i][j] != 0 && check[i][j] == 0) {
				q.push(coor(i, j));
				iceBFS();
			}
		}
	}
}


//빙하 값들을 본래 arr 함수에 합치기.
void iceArrSum() {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			arr[i][j] -= ice[i][j];
			if (arr[i][j] < 0) {
				arr[i][j] = 0;
			}
		}
	}
}

//모든 빙하가 0인지 확인
bool zeroCheck() {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (arr[i][j] != 0) return false;
		}
	}
	return true;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	bool zeroC = 0;

	while (true) {
		//빙하가 나누어져 있는지 확인.
		groupCheckCnt = 0;
		groupCheck();
		if (groupCheckCnt >= 2) break;

		//모두 0인지 확인
		zeroC = zeroCheck();
		if (zeroC == true) {
			cnt = 0;
			break;
		}

		memset(check, 0, sizeof(check));

		//빙하를 찾고 그 BFS를 통해 그 주변에 바다있는지 확인
		iceCheck();

		//ice배열을 기존arr배열에 넣기
		iceArrSum();

		memset(check, 0, sizeof(check));
		memset(ice, 0, sizeof(ice));
		cnt++;
	}

	cout << cnt << endl;

	return 0;
}









