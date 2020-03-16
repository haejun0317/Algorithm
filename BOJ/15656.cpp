/*
	BOJ 15656 - N과 M(7)
	Created by haejun on 2020/03/16
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int check[10];
int arr[10];
vector<int> v;


void dfs(int num) {
	if (num >= m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
			v.push_back(arr[i]);
			dfs(num + 1);
			v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0);

	return 0;
}
