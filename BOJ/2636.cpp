/*
	BOJ 2636 - 치즈
	Created by haejun on 2020/03/23
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//좌표 구조체
typedef struct coor {
	int x;
	int y;
	coor() {};
	coor(int _x, int _y) : x(_x), y(_y) {};
}coor;

//맵 생성
const int MAX = 105;
int arr[MAX][MAX];
int n, m;
int chz[1000] = { 0, };

//큐 생성
queue <coor> q;

//4방면 변수
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool inside(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < m);
}
//치즈 갯수 저장
void countNum(int cnt) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				chz[cnt]++;
			}
		}
	}
}

//맵 초기화
void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) {
				arr[i][j] = 0;
			}
		}
	}
}

//맵 확인할 때 치즈 개수
int cheez = 0;

//맵 확인
bool checking() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				cheez++;
			}
		}
	}
	if (cheez == 0) {
		return true;
	}
	else {
		cheez = 0;
		return false;
	}
}

void BFS() {
	if (q.empty()) return;

	int x = q.front().x;
	int y = q.front().y;

	q.pop();

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (inside(nx, ny) && arr[nx][ny] == 0) {
			arr[nx][ny] = 2;
			q.push(coor(nx, ny));
		}
		else if (inside(nx, ny) && arr[nx][ny] == 1) {
			arr[nx][ny] = 2;
		}
	}

	if (!q.empty()) BFS();
	else return;
}

int main() {

	cin >> n >> m;
	int start = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				start++;
			}
		}
	}

	bool check = false;
	int cnt = 0;

	if (start != 0) {
		while (true) {
			cnt++;
			q.push(coor(0, 0));

			countNum(cnt);

			BFS();
			reset();
			check = checking();
			if (check == true) {
				break;
			}
		}
	}
	else {
		cnt = 0;
	}

	cout << cnt << endl << chz[cnt];


	return 0;
}