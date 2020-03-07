/*
	BOJ 1992 - 쿼드트리
	Created by haejun on 2020/03/07
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;
const int MAX = 150;
int n;
int arr[MAX][MAX];


void dc(int sy, int sx, int ey, int ex) {

	int check = arr[sy][sx];

	for (int i = sy; i < ey; i++) {
		for (int j = sx; j < ex; j++) {
			if (check == 0 && arr[i][j] == 1) check = 2;
			else if (check == 1 && arr[i][j] == 0) check = 2;

			if (check == 2) {
				cout << "(";
				dc(sy, sx, (sy + ey) / 2, (sx + ex) / 2);
				dc(sy, (sx + ex) / 2, (sy + ey) / 2, ex);
				dc((sy + ey) / 2, sx, ey, (sx + ex) / 2);
				dc((sy + ey) / 2, (sx + ex) / 2, ey, ex);
				cout << ")";
				return;
			}
		}
	}

	if (check == 0) cout << 0;
	else if (check == 1) cout << 1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	dc(0, 0, n, n);
	cout << endl;

	return 0;
}