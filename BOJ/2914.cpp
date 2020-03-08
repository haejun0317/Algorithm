/*
	BOJ 2914 - 저작권
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

	int a, b;
	cin >> a >> b;
	cout << a * (b - 1) + 1 << "\n";

	return 0;
}