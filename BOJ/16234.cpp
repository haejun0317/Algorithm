/*
	BOJ 16234 - 인구 이동
	Created by haejun on 2020/02/12
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
const int MAX = 52;

int n, L, R;
int arr[MAX][MAX];
int check[MAX][MAX];
int ans;

// 나라 값, 나라 수;
int sum;
int cnt;

int checkCnt;

bool flag = true;

struct coor {
	int y;
	int x;
};
queue <coor> q;
int num[3000];

// inside check
bool inside(int y, int x) { return y >= 0 && y < n && x >= 0 && x < n; }
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs() {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		int ny, nx;
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];

			if (inside(ny, nx) && check[ny][nx] == 0) {
				// 인원 조건 확인
				int a = abs(arr[y][x] - arr[ny][nx]);
				if (a >= L && a <= R) {
					check[ny][nx] = checkCnt;
					sum += arr[ny][nx];
					cnt += 1;
					q.push({ ny,nx });
					flag = false;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> L >> R;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];


	while (1) {
		// 방문 체크, 체크 카운트, 플래그 초기화
		/*
		  방문 체크 : check 배열
		  체크 카운트 : 1부터 시작.
		  플래그 : while문이 한바퀴 돌았는데, 아무런 변화가 없을 경우 true;
		*/
		memset(check, 0, sizeof(check));
		checkCnt = 1;
		flag = true;

		// (0,0) 부터 탐색
		// 큐에 넣고 BFS 실행, 방문 체크에 체크 카운트 넣기..
		// 체크 카운트 ++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0) {
					check[i][j] = checkCnt;
					sum = arr[i][j];
					cnt = 1;
					q.push({ i,j });
					bfs();

					num[checkCnt] = sum / cnt;
					checkCnt++;
				}
			}
		}

		// 방문 체크의 수에 따른 계산 값으로 변경
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = num[check[i][j]];
			}
		}

		if (flag == true) break;
		ans++;

	}

	cout << ans << "\n";


	return 0;
}