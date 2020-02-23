/*
	BOJ 5557 - 1학년
	Created by haejun on 2020/02/23
	DP
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<string>
using namespace std;
const int MAX = 1000001;

int n;
int arr[110];
long long int dp[110][30];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a;
	cin >> n >> a;
	dp[1][a] = 1;
	for (int i = 2; i < n; i++) {
		cin >> a;
		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j]) {
				if (j + a < 21) dp[i][j + a] += dp[i - 1][j];
				if (j - a >= 0) dp[i][j - a] += dp[i - 1][j];
			}
		}
	}
	cin >> a;
	cout << dp[n - 1][a] << "\n";

	return 0;
}