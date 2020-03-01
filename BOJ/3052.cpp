/*
	BOJ 3052 - 나머지
	Created by haejun on 2020/03/01
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int check[1002];
int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a;
	for (int i = 0; i < 10; i++) {
		cin >> a;
		if (check[a % 42] == 0) {
			check[a % 42] = 1;
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}