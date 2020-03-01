/*
	BOJ 5565 - 영수증
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

int arr[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int res;
	int a;
	int sum = 0;

	cin >> res;
	for (int i = 0; i < 9; i++) {
		cin >> a;
		sum += a;
	}

	cout << res - sum << "\n";


	return 0;
}