/*
	BOJ 2851 - 슈퍼 마리오
	Created by haejun on 2020/02/27
*/
#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

int arr[10];
int sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 10; i++) cin >> arr[i];

	for (int i = 0; i < 10; i++) {
		if (abs(sum + arr[i] - 100) <= abs(sum - 100)) sum += arr[i];
		else break;
	}

	cout << sum << "\n";

	return 0;
}
