/*
	BOJ 1018 - 체스판 다시 칠하기
	Created by haejun on 2020/03/13
*/
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int MAX = 52;

char arr[MAX][MAX];
int n, m;
int ans = 987987987;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			int wcnt = 0;
			int bcnt = 0;
			for (int a = i; a < i + 8; a++) {
				for (int b = j; b < j + 8; b++) {
					if ((a+b)%2 == 0) {
						if (arr[a][b] == 'B') wcnt++;
						else bcnt++;
					}
					else {
						if (arr[a][b] == 'B') bcnt++;
						else wcnt++;
					}
				}
			}

			ans = min(ans, wcnt);
			ans = min(ans, bcnt);

		}
	}
	
	cout << ans << "\n";


	return 0;
}