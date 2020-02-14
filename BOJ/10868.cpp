/*
	BOJ 10868 - 최솟값
	Created by haejun on 2020/02/14

	세그먼트 트리
*/
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<climits>
typedef long long ll;
using namespace std;
const int MAX = 100005;

int n, m;
ll arr[MAX];
ll d[1000000];
ll dd[1000000];

ll h, low;

ll init(int node, int s, int e, int mode) {
	if (s == e) {
		if (mode == 1) return d[node] = arr[s];
		else return dd[node] = arr[s];
	}
	int m = (s + e) / 2;
	if (mode == 1)	return d[node] = max(init(node * 2, s, m, 1), init(node * 2 + 1, m + 1, e, 1));
	else return dd[node] = min(init(node * 2, s, m, 2), init(node * 2 + 1, m + 1, e, 2));
}


void query(int node, int s, int e, int l, int r) {
	if (l > e || s > r) return;
	if (l <= s && e <= r) {
		//여기서 시행
		if (dd[node] < low) low = dd[node];
		if (d[node] > h) h = d[node];
		return;
	}
	int m = (s + e) / 2;
	query(node * 2, s, m, l, r);
	query(node * 2 + 1, m + 1, e, l, r);
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n, 1);
	init(1, 1, n, 2);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		h = 0;
		low = LONG_MAX;
		query(1, 1, n, a, b);
		cout << low << "\n";
	}


}