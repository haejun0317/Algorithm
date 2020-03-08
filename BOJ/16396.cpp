/*
	BOJ 16396 - 선 그리기
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

int arr[10002];
int n;
int m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (b > m) m = b;
		for (int j = a; j < b; j++) arr[j] = 1;
	}

	int ans = 0;
	for (int i = 0; i <= m; i++) if (arr[i] == 1) ans++;

	cout << ans << "\n";


	return 0;
}