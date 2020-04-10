﻿/*
	BOJ 1904 - 01타일
	Created by haejun on 2020/04/10
*/
#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long int arr[1000001];

int main() {


	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 2] + arr[i - 1]) % 15746;

	}
	cout << arr[n];

	return 0;
}