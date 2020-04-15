﻿﻿/*
	BOJ 14889 - 스타트와 링크
	Created by haejun on 2020/04/15
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 20;
int n;
int arr[MAX][MAX];
int check[MAX];

int ans = 987987987;

void combination(int depth, int k) {
	if (depth == n / 2) {
		//실행할 곳

		vector<int> linkT, startT;

		for (int i = 0; i < n; i++) {
			if (check[i] == 1) startT.push_back(i);
			else linkT.push_back(i);
		}

		int startStat = 0, linkStat = 0;
		for (int i = 0; i < startT.size(); i++) {
			for (int j = i + 1; j < startT.size(); j++) {
				int sx = startT[i];
				int sy = startT[j];

				int lx = linkT[i];
				int ly = linkT[j];

				startStat += arr[sx][sy] + arr[sy][sx];
				linkStat += arr[lx][ly] + arr[ly][lx];
			}
		}

		ans = min(ans, abs(startStat - linkStat));

		return;
	}
	for (int i = k + 1; i < n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			combination(depth + 1, i);
			check[i] = 0;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	combination(0, 0);

	cout << ans << endl;
	//테스트 출력
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	*/

	return 0;
}