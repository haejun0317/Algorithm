/*
	BOJ 1764 - 듣보잡
	Created by haejun on 2020/03/09
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int n, m;
vector <string> v;
vector <string> r;

bool func(int s, int e, string a) {
	if (s > e) return false;
	else {
		int mid = (s + e) / 2;
		if (v[mid]==a) return true;
		else if (v[mid] > a) return func(s, mid - 1, a);
		else return func(mid+1, e, a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (func(0, v.size() - 1, s)) r.push_back(s);
	}

	sort(r.begin(), r.end());

	cout << r.size() << "\n";
	for (int i = 0; i < r.size(); i++) cout << r[i] << "\n";

	return 0;
}