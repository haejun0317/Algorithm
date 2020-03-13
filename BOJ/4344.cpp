/*
	BOJ 4344 - 평균은 넘겠지
	Created by haejun on 2020/03/14
*/
#include<iostream>
#include<algorithm>
using namespace std;

int arr[1002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a;
		cin >> a;
		double sum = 0;
		for (int i = 0; i < a; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		sum = sum / (double)a;
		int cnt = 0;
		for (int i = 0; i < a; i++) {
			if (arr[i] > sum) cnt++;
		}

		double ans = (double)cnt / a * 100;
		cout.precision(3);
		cout << fixed << ans << "%\n";
		
	}

	return 0;
}