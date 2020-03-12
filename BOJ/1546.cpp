/*
	BOJ 1546 - 평균
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<string>
using namespace std;

int n;
double arr[1002];
double m;
double ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > m) m = arr[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / m * 100.0;
		ans += arr[i];
	}
	
	ans = ans / (double)n;
	cout << ans;

	return 0;
}