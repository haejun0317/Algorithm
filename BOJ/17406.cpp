﻿/*
	BOJ 17406 - 배열돌리기4
	Created by haejun on 2020/04/09
*/
#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
const int MAX = 102;

int n, m, k;
int arr[MAX][MAX];
int map[MAX][MAX];
vector <int> dfsCnt;
int dfsCheck[10];
int result = 987987987;

struct coor {
	int r;
	int c;
	int s;
};
vector <coor> v;

// 배열 돌리기
void rotate(int r, int c, int s) {
	int temp;
	for (int z = s; z > 0; z--) {
		temp = arr[r - z][c - z];
		for (int i = r - z; i < r + z; i++) {
			arr[i][c - z] = arr[i + 1][c - z];
		}
		for (int i = c - z; i < c + z; i++) {
			arr[r + z][i] = arr[r + z][i + 1];
		}
		for (int i = r + z; i > r - z; i--) {
			arr[i][c + z] = arr[i - 1][c + z];
		}
		for (int i = c + z; i > c - z; i--) {
			arr[r - z][i] = arr[r - z][i - 1];
		}
		arr[r - z][c - z + 1] = temp;
	}
}

// 결과값 찾기
int ansFind() {
	int ans = 987987987;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cnt += arr[i][j];
		}
		if (cnt < ans) ans = cnt;
	}
	return ans;
}

// 순열
void dfs(int cnt) {
	if (cnt == k) {
		memcpy(arr, map, sizeof(map));
		for (int i = 0; i < dfsCnt.size(); i++) {
			rotate(v[dfsCnt[i]].r, v[dfsCnt[i]].c, v[dfsCnt[i]].s);
		}

		// 배열 결과 값 확인.
		int ans = ansFind();
		if (ans < result) result = ans;
		return;
	}
	for (int i = 0; i < k; i++) {
		if (dfsCheck[i] == 0) {
			dfsCheck[i] = 1;
			dfsCnt.push_back(i);
			dfs(cnt + 1);
			dfsCnt.pop_back();
			dfsCheck[i] = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// input 부분
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r - 1,c - 1,s });
	}
	dfs(0);

	cout << result << "\n";


	return 0;
}