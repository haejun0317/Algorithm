/*
	BOJ 1964 - 오각형, 오각형, 오각형
	Created by haejun on 2020/03/14
*/
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int ans = 5;
	for (int i = 1; i < n; i++) ans = (ans + (i + 2) * 3 - 2) % 45678;

	cout << ans;

	return 0;
}