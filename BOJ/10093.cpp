﻿﻿/*
	BOJ 10093 - 숫자
	Created by haejun on 2020/04/17
*/
#include <iostream>
#include <algorithm>
#define N 100000

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B;

	cin >> A >> B;

	if (A > B) {
		swap(A, B);
	}

	if (A != B) {
		cout << B - A - 1 << "\n";
		for (long long i = A + 1; i < B; i++) {
			cout << i << " ";
		}
	}
	else {
		cout << 0;
	}

}
