/*
	BOJ 3197 - 백조의 호수
	Created by haejun on 2020/02/26
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
const int MAX = 1502;

int n, m;
char arr[MAX][MAX];
bool check[MAX][MAX];

struct coor {
	int y;
	int x;
};

// 백조
coor duck[2];

//0번 백조에 대한 큐, 물에 대한 큐
queue<coor> q; queue <coor> wq;

//inside check
bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int now = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'L') {
				duck[now].y = i;
				duck[now].x = j;
				now++;
				wq.push({ i,j });
			}
			else if (arr[i][j] == '.') {
				wq.push({ i,j });
			}
		}
	}

	q.push({ duck[0].y, duck[0].x });

	int ans = 0;
	while (1) {
		bool flag = false;
		queue<coor> nq;
		//0번 백조 돌기.
		while (!q.empty()) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			if (y == duck[1].y && x == duck[1].x) {
				flag = true;
				break;
			}

			int ny, nx;
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (inside(ny, nx) && check[ny][nx] == 0 && arr[ny][nx] != 'X') {
					q.push({ ny,nx });
					check[ny][nx] = 1;
				}
				else if (inside(ny, nx) && check[ny][nx] == 0 && arr[ny][nx] == 'X') {
					nq.push({ ny,nx });
					check[ny][nx] = 1;
				}
			}
			if (flag == true) break;
		}

		if (flag == true) break;

		q = nq;

		// 얼음 뿌수기
		int s = wq.size();
		while (s--) {
			int y = wq.front().y;
			int x = wq.front().x;
			wq.pop();

			int ny, nx;
			for (int i = 0; i < 4; i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if (inside(ny, nx) && arr[ny][nx] == 'X') {
					wq.push({ ny,nx });
					arr[ny][nx] = '.';
				}
			}
		}

		//디버깅
		/*
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		ans++;
	}
	cout << ans << "\n";

	return 0;
}