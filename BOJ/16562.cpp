/*
	BOJ 16562 - 친구비
	Created by haejun on 2020/03/24
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 10003;

int n, m, k;
int ans;
int v[MAX];
//비용
int w[MAX];
int c[MAX];

int find(int x) {
	if (v[x] == x) return x;
	return v[x] = find(v[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	else v[a] = b;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		v[i] = i;
	}
	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		merge(temp1 - 1, temp2 - 1);
	}
	fill(c, c + n, 1e9);
	for (int i = 0; i < n; i++) {
		c[find(i)] = min(c[find(i)], w[i]);
	}

	for (int i = 0; i < n; i++) {
		if (c[i] >= 1e9) continue;
		ans += c[i];
	}
	if (ans <= k) cout << ans << "\n";
	else cout << "Oh no\n";

	return 0;
}