/*
	BOJ 15663 - N과 M(9)
	Created by haejun on 2020/03/16
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 100000;

int n, m;
int arr[MAX];
bool check[MAX];

vector<int> v;

void dfs(int cnt) {
	if (cnt >= m) {
		for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
		cout << "\n";
		return;
	}

	bool check2[MAX] = { 0, };
	for (int i = 0; i < n; i++) {
		if (check[i] == true || check2[arr[i]] == true) continue;
		check[i] = true;
		check2[arr[i]] = true;
		v.push_back(arr[i]);
		dfs(cnt + 1);
		check[i] = false;
		v.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	dfs(0);

	return 0;
}