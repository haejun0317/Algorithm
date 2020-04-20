/* 
	SWEA 2477 - [모의 SW 역량테스트] 차량 정비소 
	Created by haejun on 2020/04/20 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;

struct Man {
	// 접수 창고, 정비 창고
	int f1;
	int f2;
	// 도착 시간
	int time;
};
Man man[1002];
int k;
int n, m, a, b;

//접수 창고, 창고 이용 고객, 창고 별 걸리는 시간
int n1[11];
int nm[11];
int nt[11];

//정비 창고, 창고 이용 고객, 창고 별 걸리는 시간
int m1[11];
int mm[11];
int mt[11];


// 접수 창고 기다리는 큐
queue <int> q;
// 정비 창고 기다리는 큐
queue <int> q2;

void func() {
	int t = 0;

	// 나간 사람
	int out = 0;
	memset(n1, -1, sizeof(n1));
	memset(m1, -1, sizeof(m1));

	while (true) {

		// 1. 도착한 사람 큐에 넣기
		for (int i = 1; i <= k; i++) if (man[i].time == t) q.push(i);

		// 2. 접수 창고에 시간 다 된 사람 내보내기.
		for (int i = 1; i <= n; i++) {
			if (n1[i] == t) {
				n1[i] = -1;
				q2.push(nm[i]);
			}
		}

		// 3. 접수 창고 비였으면 도착한 사람 넣기
		for (int i = 1; i <= n; i++) {
			if (q.empty()) break;
			if (n1[i] == -1) {
				n1[i] = nt[i] + t;
				nm[i] = q.front();
				man[q.front()].f1 = i;
				q.pop();
			}
		}

		// 4. 정비 창고에 시간 다 된 사람 내보내기.
		for (int i = 1; i <= m; i++) {
			if (m1[i] == t) {
				m1[i] = -1;
				out++;
			}
		}

		// 5. 정비 창고 비였으면 도착한 사람 넣기
		for (int i = 1; i <= m; i++) {
			if (q2.empty()) break;
			if (m1[i] == -1) {
				m1[i] = mt[i] + t;
				mm[i] = q2.front();
				man[q2.front()].f2 = i;
				q2.pop();
			}
		}

		// 6. 만약 나간 사람이 사람 총합과 같다면 끝
		if (out == k) break;

		t++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for (int o = 1; o <= t; o++) {
		cin >> n >> m >> k >> a >> b;
		for (int i = 1; i <= n; i++) cin >> nt[i];
		for (int i = 1; i <= m; i++) cin >> mt[i];
		for (int i = 1; i <= k; i++) cin >> man[i].time;
		func();

		int ans = 0;
		for (int i = 1; i <= k; i++) {
			if (man[i].f1 == a && man[i].f2 == b) ans += i;
		}
		if (ans == 0) cout << "#" << o << " " << -1 << "\n";
		else cout << "#" << o << " " << ans << "\n";
	}


	return 0;
}
