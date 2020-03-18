/*
	BOJ 10026 - 적록색약
	Created by haejun on 2020/03/18
*/
#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;
const int MAX = 102;
int n;
char arr[MAX][MAX];
bool check[MAX][MAX];
//그룹
int gNum;
struct coor {
	int y;
	int x;
	int rgb;
};
queue<coor> q;
// inside check
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
void bfs(int flag) {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		char c = q.front().rgb;
		q.pop();
		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (inside(ny, nx) && check[ny][nx] == 0) {
				if (flag == 1) {
					if ((c == 'R' || c == 'G') && (arr[ny][nx] == 'R' || arr[ny][nx] == 'G')) {
						check[ny][nx] = 1;
						q.push({ ny,nx,'R' });
					}
					else {
						if (c == arr[ny][nx]) {
							check[ny][nx] = 1;
							q.push({ ny,nx,c });
						}
					}
				}
				else {
					if (c == arr[ny][nx]) {
						check[ny][nx] = 1;
						q.push({ ny,nx,c });
					}
				}

			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	//정상인 사람이 볼 때,
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				check[i][j] = 1;
				q.push({ i,j,arr[i][j] });
				bfs(0);
				gNum++;
			}
		}
	}
	cout << gNum << "\n";
	//적록색약인 사람이 볼 때,
	memset(check, 0, sizeof(check));
	gNum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				check[i][j] = 1;
				q.push({ i,j,arr[i][j] });
				bfs(1);
				gNum++;
			}
		}
	}
	cout << gNum << "\n";


	return 0;
}