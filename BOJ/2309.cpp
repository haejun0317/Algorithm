/*
	BOJ 2309 - 일곱 난쟁이
	Created by haejun on 2020/02/26
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;

int arr[9];

bool check[9];
vector <int> v;

bool flag;

void dfs(int n, int cnt) {
	if (n == 7) {
		if (flag == true) return;
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += arr[v[i]];
		}
		if (sum == 100) {
			flag = true;
			for (int i = 0; i < v.size(); i++) {
				cout << arr[v[i]] << "\n";
			}
		}
		return;
	}
	for (int i = cnt; i < 9; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			v.push_back(i);
			dfs(n + 1, i);
			check[i] = 0;
			v.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) cin >> arr[i];
	sort(arr, arr + 9);

	dfs(0, 0);

	return 0;
}