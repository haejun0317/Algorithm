/*
	BOJ 9997 - 폰트
	Created by haejun on 2020/03/22
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<memory.h>
#include<cstring>
using namespace std;

int check[30];
char a[102];
int n, com;
long long dab;


void dfs(int d, int sum) {
	if (d >= n) {
		// 기저 조건
		if (sum == com) {
			dab++;
		}
		return;
	}

	dfs(d + 1, sum | check[d]);
	dfs(d + 1, sum);
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < 26; i++) com |= 1 << i;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < strlen(a); j++) {
			check[i] |= (1 << (a[j] - 'a'));
		}
	}

	dfs(0, 0);

	cout << dab << "\n";


	return 0;
}
