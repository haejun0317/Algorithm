/*
	BOJ 2475 - 검증수
	Created by haejun on 2020/03/09
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, sum=0;

	for (int i = 0; i < 5; i++) {
		cin >> a;
		sum += a * a;
	}
	cout << sum % 10 << "\n";

	return 0;
}