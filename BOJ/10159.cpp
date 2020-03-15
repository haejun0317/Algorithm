/*
	BOJ 10159 - 저울
	Created by haejun on 2020/03/15
	플로이드 와샬
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
const int MAX = 105;

int n, m, k;
int arr[MAX][MAX];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	memset(arr, -1, sizeof(arr));

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == -1) arr[i][j] = INF;
		}
	}

	//거쳐가는 노드
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (arr[i][j] == INF && arr[j][i] == INF) sum++;
		}
		cout << sum << "\n";
	}

	return 0;
}