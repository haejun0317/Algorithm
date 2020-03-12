/*
	BOJ 10250 - ACM 호텔
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<memory.h>
using namespace std;

int t;
int arr[102][102];
int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		int num = 1;
		int sum = 0;
		bool flag = false;
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = (j * 100) + num;
				sum++;
				if (sum == k) {
					flag = true;
					ans = arr[i][j];
					break;
				}
			}
			if (flag == true) break;
			num++;
		}
		cout << ans << "\n";
	}

	return 0;
}