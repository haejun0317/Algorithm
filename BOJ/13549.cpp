/*
	BOJ 13549 - 숨바꼭질3
	Created by haejun on 2020/02/25
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<algorithm>
using namespace std;
const int MAX = 100005;

int n, k;
bool check[MAX];

struct coor {
	int num;
	int cnt;
};
/*
struct compare {
	bool operator()(coor& a, coor& b) {
		if (a.cnt != b.cnt) return a.cnt > b.cnt;
		return a.num > b.num;
	}
};
priority_queue <coor, vector<coor>, compare> q;
*/
queue <coor> q;

int bfs() {
	int maxCnt;
	while (!q.empty()) {
		int a = q.front().num;
		int cnt = q.front().cnt;
		q.pop();

		if (a == k) {
			maxCnt = cnt;
			return maxCnt;
		}

		if (a != 0 && a * 2 < 100001 && check[a * 2] == 0) {
			check[a * 2] = 1;
			q.push({ a * 2, cnt });
		}
		if (a - 1 >= 0 && check[a - 1] == 0) {
			check[a - 1] = 1;
			q.push({ a - 1,cnt + 1 });
		}
		if (a + 1 < 100001 && check[a + 1] == 0) {
			check[a + 1] = 1;
			q.push({ a + 1,cnt + 1 });
		}
		
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	check[n] = 1;
	q.push({ n,0 });
	
	cout << bfs() << "\n";



	return 0;
}