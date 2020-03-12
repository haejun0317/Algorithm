/*
	BOJ 1085 - 직사각형에서 탈출
	Created by haejun on 2020/03/13
*/
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int y, x, h, w;
int arr[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y >> w >> h;
	int ans = min(w - x, x);
	ans = min(ans, min(h - y, y));
	cout << ans;

	return 0;
}