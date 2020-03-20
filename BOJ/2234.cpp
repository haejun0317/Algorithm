/*
	BOJ 2234 - 성곽
	Created by haejun on 2020/03/20
*/
#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
const int MAX = 52;

int arr[MAX][MAX];
int check[MAX][MAX];
int gro[MAX * MAX];

int n, m;

int g = 1;
struct Coor {
	int y;
	int x;
};
queue <Coor> q;

//inside check
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int BFS() {
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		check[y][x] = g;
		q.pop();
		cnt++;
		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (!inside(ny, nx)) continue;
			if (i == 0 && (arr[y][x] == 2 || arr[y][x] == 3 || arr[y][x] == 6 || arr[y][x] == 7 || arr[y][x] == 10 || arr[y][x] == 11 || arr[y][x] == 14 || arr[y][x] == 15)) continue;
			if (i == 1 && (arr[y][x] == 8 || arr[y][x] == 9 || arr[y][x] == 10 || arr[y][x] == 11 || arr[y][x] == 12 || arr[y][x] == 13 || arr[y][x] == 14 || arr[y][x] == 15))continue;
			if (i == 2 && (arr[y][x] == 1 || arr[y][x] == 3 || arr[y][x] == 5 || arr[y][x] == 7 || arr[y][x] == 9 || arr[y][x] == 11 || arr[y][x] == 13 || arr[y][x] == 15))continue;
			if (i == 3 && (arr[y][x] == 4 || arr[y][x] == 5 || arr[y][x] == 6 || arr[y][x] == 7 || arr[y][x] == 12 || arr[y][x] == 13 || arr[y][x] == 14 || arr[y][x] == 15)) continue;
			if (check[ny][nx] != 0) continue;
			check[ny][nx] = g;
			q.push({ ny,nx });
		}
	}
	return cnt;
}

void oneTwo() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0) {
				check[i][j] = g;
				q.push({ i,j });
				gro[g] = BFS();
				g++;
			}
		}
	}
	int max = 0;
	for (int i = 1; i < g; i++) {
		if (gro[i] > max) max = gro[i];
	}
	cout << g - 1 << endl;
	cout << max << endl;
}

//해당 수의 4방면을 확인
//4방면 중의 그룹이, 자신의 그룹과 다르면
//자신의 그룹과 다른 그룹의 갯수를 더함!
//그리고 큰 수를 max에 저장.
void three() {
	int max = 0;
	int ny, nx;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int z = 0; z < 4; z++) {
				ny = i + dy[z];
				nx = j + dx[z];
				if (inside(ny, nx) && check[i][j] != check[ny][nx]) {
					if (gro[check[i][j]] + gro[check[ny][nx]] > max) max = gro[check[i][j]] + gro[check[ny][nx]];
				}
			}
		}
	}
	cout << max << endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	//1,2번 답을 얻기 위한 BFS();
	oneTwo();
	//3번 답을 얻기 위해서 check 배열에 각기 다른 그룹이라면 더하기해서 MAX값 구하기;
	three();

	/*
	cout << endl;
	for (int i = 1; i < g; i++) {
		cout << gro[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}