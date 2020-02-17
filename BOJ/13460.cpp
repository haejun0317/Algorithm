/*
	BOJ 13460 - 구슬 탈출2
	Created by haejun on 2020/02/17
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MAX = 12;
char arr[MAX][MAX];
int check[MAX][MAX][MAX][MAX];

int n, m;
int oy, ox, fry, frx, fby, fbx;
//반복문 수
int cnt = 0;
//결과 값 저장
int ans;

//큐에서 사용할 temp변수
int qry, qrx, qby, qbx;
int ry, rx, by, bx;
int nry, nrx, nby, nbx;

//구조체 생성
struct coor {
	int sry;
	int srx;
	int sby;
	int sbx;
};
//큐 생성
queue <coor> q;
//4방면
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void BFS() {
	while (!q.empty()) {
		int qlen = q.size();
		while (qlen--) {
			qry = q.front().sry;
			qrx = q.front().srx;
			qby = q.front().sby;
			qbx = q.front().sbx;
			q.pop();

			//O에 들어갔을 경우(레드만)
			if (arr[qry][qrx] == 'O' && arr[qby][qbx] != 'O') {
				ans = cnt;
				return;
			}

			for (int i = 0; i < 4; i++) {
				ry = qry;
				rx = qrx;
				by = qby;
				bx = qbx;
				//레드 이동
				while (1) {
					nry = ry + dy[i];
					nrx = rx + dx[i];
					if (arr[nry][nrx] == '#' || arr[ry][rx] == 'O') break;
					ry = nry;
					rx = nrx;
				}
				//블루 이동
				while (1) {
					nby = by + dy[i];
					nbx = bx + dx[i];
					if (arr[nby][nbx] == '#' || arr[by][bx] == 'O') break;
					by = nby;
					bx = nbx;
				}
				//겹쳤을 경우
				if (ry == by && rx == bx) {
					//둘다 들어갔을 경우
					if (arr[ry][rx] == 'O') continue;
					if (abs(qry - ry) + abs(qrx - rx) > abs(qby - by) + abs(qbx - bx)) {
						rx -= dx[i];
						ry -= dy[i];
					}
					else {
						bx -= dx[i];
						by -= dy[i];
					}
				}
				if (check[ry][rx][by][bx]) continue;
				check[ry][rx][by][bx] = 1;
				q.push({ ry,rx,by,bx });
			}
		}
		if (cnt == 10) {
			ans = -1;
			return;
		}
		cnt++;
	}
	ans = -1;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O') {
				oy = i;
				ox = j;
			}
			else if (arr[i][j] == 'R') {
				fry = i;
				frx = j;
			}
			else if (arr[i][j] == 'B') {
				fby = i;
				fbx = j;
			}
		}
	}

	q.push({ fry, frx, fby, fbx });
	BFS();

	cout << ans << endl;
}