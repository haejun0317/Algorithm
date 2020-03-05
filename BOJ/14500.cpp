/*
	BOJ 14500 - 테트로미노
	Created by haejun on 2020/03/05
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;
const int MAX = 500;
int arr[MAX][MAX];
int n, m;
int ans = 0;
void blockL1(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y + 1][x];
	sum += arr[y + 2][x];
	sum += arr[y + 2][x + 1];
	if (sum > ans) ans = sum;
}
void blockL2(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y + 1][x];
	sum += arr[y][x + 1];
	sum += arr[y][x + 2];
	if (sum > ans) ans = sum;
}
void blockL3(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y + 1][x + 1];
	sum += arr[y + 2][x + 1];
	if (sum > ans) ans = sum;
}
void blockL4(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y][x + 2];
	sum += arr[y - 1][x + 2];
	if (sum > ans) ans = sum;
}
void blockL5(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y - 1][x + 1];
	sum += arr[y - 2][x + 1];
	if (sum > ans) ans = sum;
}
void blockL6(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y + 1][x];
	sum += arr[y + 1][x + 1];
	sum += arr[y + 1][x + 2];
	if (sum > ans) ans = sum;
}
void blockL7(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y + 1][x];
	sum += arr[y + 2][x];
	if (sum > ans) ans = sum;
}
void blockL8(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y][x + 2];
	sum += arr[y + 1][x + 2];
	if (sum > ans) ans = sum;
}
void blockZ1(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y + 1][x];
	sum += arr[y + 1][x + 1];
	sum += arr[y + 2][x + 1];
	if (sum > ans) ans = sum;
}
void blockZ2(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y - 1][x + 1];
	sum += arr[y - 1][x + 2];
	if (sum > ans) ans = sum;
}
void blockZ3(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y - 1][x + 1];
	sum += arr[y + 1][x];
	if (sum > ans) ans = sum;
}
void blockZ4(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y + 1][x + 1];
	sum += arr[y + 1][x + 2];
	if (sum > ans) ans = sum;
}
void blockD(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y + 1][x];
	sum += arr[y + 1][x + 1];
	if (sum > ans) ans = sum;
}
void blockI2(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y + 1][x];
	sum += arr[y + 2][x];
	sum += arr[y + 3][x];
	if (sum > ans) ans = sum;
}
void blockI1(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y][x + 2];
	sum += arr[y][x + 3];
	if (sum > ans) ans = sum;
}
void blockT1(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y - 1][x + 1];
	sum += arr[y][x + 2];
	if (sum > ans) ans = sum;
}
void blockT2(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y + 1][x + 1];
	sum += arr[y][x + 2];
	if (sum > ans) ans = sum;
}
void blockT3(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y][x + 1];
	sum += arr[y - 1][x + 1];
	sum += arr[y + 1][x + 1];
	if (sum > ans) ans = sum;
}
void blockT4(int y, int x) {
	int sum = 0;
	sum += arr[y][x];
	sum += arr[y + 1][x];
	sum += arr[y + 1][x + 1];
	sum += arr[y + 2][x];
	if (sum > ans) ans = sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i < n - 2 && j < m - 1) {
				blockL1(i, j);
				blockL3(i, j);
				blockL7(i, j);
				blockZ1(i, j);
				blockT4(i, j);
			}
			if (i < n - 1 && j < m - 2) {
				blockL2(i, j);
				blockT2(i, j);
				blockL6(i, j);
				blockL8(i, j);
				blockZ4(i, j);
			}
			if (i > 0 && j < m - 2) {
				blockL4(i, j);
				blockZ2(i, j);
				blockT1(i, j);
			}
			if (i > 0 && i < n - 1 && j < m - 1) {
				blockT3(i, j);
				blockZ3(i, j);
			}
			if (j < m - 3) {
				blockI1(i, j);
			}
			if (i < n - 3) {
				blockI2(i, j);
			}
			if (i < n - 1 && j < m - 1) {
				blockD(i, j);
			}
			if (i > 1 && j < m - 1) {
				blockL5(i, j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}