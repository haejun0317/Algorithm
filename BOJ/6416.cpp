﻿﻿/*
	BOJ 6416 - 트리인가?
	Created by haejun on 2020/04/16
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
typedef long long ll;
using namespace std;

map<long long int, long long int> m, degree;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 0;
	while (1) {
		// 초기화
		bool ans = true;
		ll a, b;
		ll edgeCnt = 0;
		ll nodeCnt = 0;
		m.clear();
		degree.clear();

		while ((cin >> a >> b), (a || b)) {
			if (a == -1 && b == -1) return 0;
			edgeCnt++;
			if (m.find(a) == m.end()) m.insert({ a, nodeCnt++ });
			if (m.find(b) == m.end()) m.insert({ b, nodeCnt++ });
			if (degree.find(b) == degree.end()) degree.insert({ b,0 });
			else ans = false;
		}
		if (edgeCnt > 0 && m.size() != edgeCnt + 1) ans = false;
		if (ans) cout << "Case " << t + 1 << " is a tree.\n";
		else cout << "Case " << t + 1 << " is not a tree.\n";
		t++;
	}

	return 0;
}