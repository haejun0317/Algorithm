/*
	BOJ 17837 - 새로운 게임2
	Created by haejun on 2020/02/12

	삼성 2019 하반기 오전 기출 (시뮬레이션)
*/

#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<algorithm>
#include<math.h>
#include<memory.h>
typedef long long ll;
using namespace std;
const int INF = 987987987;
const int MAX = 13;

// 말 구조체
struct Mal {
	int y;
	int x;
	int d;
	int num;
};

// Input List
int n, k;
int arr[MAX][MAX];
vector <int> v[MAX][MAX];
Mal mal[MAX];

// inside check
bool inside(int y, int x) { return y >= 1 && y <= n && x >= 1 && x <= n; }
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };

void move(int MAL, int y, int x, int d, int ny, int nx, int map) {
	int num = mal[MAL].num;
	int arriveSize = v[ny][nx].size();
	int cnt = 0;

	if (map == 0) {
		for (int i = num; i < v[y][x].size(); i++) {
			int temp = v[y][x][i];
			mal[temp].num = cnt++;
			mal[temp].num += arriveSize;
			mal[temp].y = ny;
			mal[temp].x = nx;
			v[ny][nx].push_back(temp);
		}
		v[y][x].erase(v[y][x].begin() + num, v[y][x].end());
	}
	else if (map == 1) {
		for (int i = v[y][x].size() - 1; i >= num; i--) {
			int temp = v[y][x][i];
			mal[temp].num = cnt++;
			mal[temp].num += arriveSize;
			mal[temp].y = ny;
			mal[temp].x = nx;
			v[ny][nx].push_back(temp);
			v[y][x].pop_back();
		}
	}
	else if (map == 2) {
		if (d == 1) mal[MAL].d = 2;
		else if (d == 2)mal[MAL].d = 1;
		else if (d == 3)mal[MAL].d = 4;
		else if (d == 4)mal[MAL].d = 3;

		d = mal[MAL].d;

		ny = y + dy[d];
		nx = x + dx[d];
		if (arr[ny][nx] == 2 || !inside(ny, nx)) return;

		move(MAL, y, x, d, ny, nx, arr[ny][nx]);
	}
}

int func() {
	int cnt = 0;
	while (++cnt < 1000) {
		// 3. 1번 말 부터 이동
		for (int i = 1; i <= k; i++) {
			int y = mal[i].y;
			int x = mal[i].x;
			int d = mal[i].d;

			int ny = y + dy[d];
			int nx = x + dx[d];

			if (!inside(ny, nx)) {
				move(i, y, x, d, ny, nx, 2);
			}
			else {
				move(i, y, x, d, ny, nx, arr[ny][nx]);
			}

			// 4. 체크
			for (int z = 1; z <= n; z++) {
				for (int j = 1; j <= n; j++) {
					if (v[z][j].size() >= 4) return cnt;
				}
			}

		}

	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 1. input
	// n, k, 맵 arr, 말 정보
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> arr[i][j];

	for (int i = 1; i <= k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mal[i].y = a;	mal[i].x = b;	mal[i].d = c; mal[i].num = 0;
		v[a][b].push_back(i);
	}

	// 2. 1000번 반복
	// 1000번 반복문 종료시킬 플래그와 카운트 변수
	cout << func() << "\n";

	return 0;
}