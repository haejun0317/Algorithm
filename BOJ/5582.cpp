/*
	BOJ 5582 - 공통 부분 문자열
	Created by haejun on 2020/02/13

	DP (다이나믹 프로그래밍)
*/

#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<algorithm>
#include<math.h>
#include<memory.h>
typedef long long ll;
using namespace std;
const int INF = 987987987;
const int MAX = 4005;

string c1;
string c2;
int dp[MAX][MAX];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> c1 >> c2;
	int ans = 0;
	for (int i = 0; i < c1.size(); i++) {
		for (int j = 0; j < c2.size(); j++) {
			if (c1[i] == c2[j]) {
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			if (dp[i][j] > ans) ans = dp[i][j];
		}
	}
	cout << ans << "\n";



	return 0;
}