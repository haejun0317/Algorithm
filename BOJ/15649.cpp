/*
	BOJ 15649 - N과 M(1)
	Created by haejun on 2020/03/16
*/
#include<iostream>
#include<vector>
using namespace std;
int n, m;
int check[10];
vector<int> v;


void dfs(int num) {
	if (num >= m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			v.push_back(i);
			dfs(num + 1);
			v.pop_back();
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	dfs(0);

	return 0;
}
