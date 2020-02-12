/*
	BOJ 1956 - 운동
	Created by haejun on 2020/02/12

	플로이드 와샬 알고리즘
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
const int MAX = 405;

int n, m;
int arr[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int a, b, c;
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == -1) arr[i][j] = INF;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	int ans = 987987987;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (arr[i][j] == INF || arr[j][i] == INF) continue;
			int sum = 0;
			sum = arr[i][j] + arr[j][i];
			if (sum < ans) ans = sum;
		}
	}

	if (ans == 987987987) cout << -1 << "\n";
	else cout << ans << "\n";


	return 0;
}