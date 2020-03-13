/*
	BOJ 2775 - 부녀회장이 될테야
	Created by haejun on 2020/03/13
*/
#include<iostream>
using namespace std;

int arr[15][15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 1; i < 15; i++) arr[0][i] = i;
	for (int i = 1; i < 15; i++) {
		int sum = 0;
		for (int j = 1; j < 15; j++) {
			arr[i][j] += sum + arr[i - 1][j];
			sum += arr[i - 1][j];
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k >> n;
		cout << arr[k][n] << "\n";
	}

	return 0;
}