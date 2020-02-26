/*
	BOJ 1912 - 연속 합
	Created by haejun on 2020/02/26
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

int arr[100002];
int dp[100002];
int n;
int m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {
		dp[i] = arr[i] + dp[i - 1];
		if (dp[i] < 0) dp[i] = 0;
		if (dp[i] > m) m = dp[i];
	}

	cout << m << "\n";

	return 0;
}