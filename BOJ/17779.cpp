/*
	BOJ 17779 - 게리맨더링2
	Created by haejun on 2020/02/20
*/
#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;
const int MAX = 52;

int n;
int arr[MAX][MAX];
int map[MAX][MAX];

int ans = 987987987;

bool inside(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}

void check(int y, int x, int d1, int d2) {
	memset(arr, 0, sizeof(arr));
	// (위,) 왼쪽, 아래, 오른쪽
	int ly, lx, by, bx, ry, rx;
	ly = y + d1;
	lx = x - d1;
	if (!inside(ly, lx)) return;

	by = y + d1 + d2;
	bx = x - d1 + d2;
	if (!inside(by, bx)) return;

	ry = y + d2;
	rx = x + d2;
	if (!inside(ry, rx)) return;

	for (int i = 1; i < d1; i++) {
		arr[y + 1 * i][x - 1 * i] = 5;
		arr[ry + 1 * i][rx - 1 * i] = 5;
	}
	for (int i = 1; i < d2; i++) {
		arr[y + 1 * i][x + 1 * i] = 5;
		arr[ly + 1 * i][lx + 1 * i] = 5;
	}

	arr[y][x] = 5;
	arr[by][bx] = 5;
	arr[ly][lx] = 5;
	arr[ry][rx] = 5;
	
	//1번구역
	for (int i = 0; i < ly; i++) {
		for (int j = 0; j <= x; j++) {
			if (arr[i][j] == 5) break;
			arr[i][j] = 1;
		}
	}

	//2번구역
	for (int i = 0; i <= ry; i++) {
		for (int j = n - 1; j > x; j--) {
			if (arr[i][j] == 5) break;
			arr[i][j] = 2;
		}
	}
	
	//3번구역
	for (int i = ly; i < n; i++) {
		for (int j = 0; j < bx; j++) {
			if (arr[i][j] == 5) break;
			arr[i][j] = 3;
		}
	}

	//4번구역
	for (int i = n - 1; i > ry; i--) {
		for (int j = n - 1; j >= bx; j--) {
			if (arr[i][j] == 5) break;
			arr[i][j] = 4;
		}
	}

	int cnt[5] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 || arr[i][j] == 5) cnt[0] += map[i][j];
			else if (arr[i][j] == 1) cnt[1] += map[i][j];
			else if (arr[i][j] == 2) cnt[2] += map[i][j];
			else if (arr[i][j] == 3) cnt[3] += map[i][j];
			else if (arr[i][j] == 4) cnt[4] += map[i][j];
		}
	}

	sort(cnt, cnt + 5);
	int temp = cnt[4] - cnt[0];
	if (temp < ans) ans = temp;

	/*
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << "\n";
	}
	*/
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> map[i][j];

	for (int i = 0; i < n - 2; i++)
		for (int j = 1; j < n - 1; j++)
			for (int d1 = 1; d1 <= j; d1++)
				for (int d2 = 1; d2 <= n - j; d2++)
					check(i, j, d1, d2);


	cout << ans << "\n";

	return 0;
}