/*
	BOJ 18229 - 내가 살게, 아냐 내가 살게
	Created by haejun on 2020/04/01
*/
#include<iostream>
using namespace std;
const int MAX = 102;

int arr[MAX][MAX];
int n, m, k;
int man, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (j != 0) arr[i][j] += arr[i][j - 1];
		}
	}

	bool flag = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j][i] >= k) {
				man = j+1;
				ans = i+1;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}

	cout << man << " " << ans;


	return 0;
}