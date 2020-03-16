/*
	BOJ 15652 - N과 M(4)
	Created by haejun on 2020/03/16
*/
#include<iostream>
#include<vector>
using namespace std;
int n, m;
int check[10];
vector<int> v;


void dfs(int num, int a) {
	if (num >= m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = a; i <= n; i++) {
		v.push_back(i);
		dfs(num + 1, i);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	dfs(0,1);

	return 0;
}
