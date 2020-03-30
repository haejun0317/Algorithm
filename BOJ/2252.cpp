/*
	BOJ 2252 - 줄 세우기
	Created by haejun on 2020/03/30
*/
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
using namespace std;
const int MAX = 32005;
int n, m;

vector<int> v[MAX];
int arr[MAX];

queue <int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}

	for (int i = 1; i <= n; i++) if (!arr[i]) q.push(i);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << " ";
		for (int i = 0; i < v[node].size(); i++) {
			arr[v[node][i]]--;
			if (!arr[v[node][i]]) q.push(v[node][i]);
		}
	}




	return 0;
}