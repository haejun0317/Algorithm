﻿/*
	BOJ 14888 - 연산자 끼워넣기
	Created by haejun on 2020/04/08
*/
#include<iostream>
using namespace std;

const int MAX = 12;
int n;
int num[MAX];
int arr[4];

int maximum = -1000000001;
int minimum = 1000000001;

void permutation(int depth, int sum) {
	if (depth == n) {
		if (sum > maximum) maximum = sum;
		if (sum < minimum) minimum = sum;
		return;
	}

	if (arr[0] > 0) {
		arr[0] -= 1;
		permutation(depth + 1, sum + num[depth]);
		arr[0] += 1;
	}
	if (arr[1] > 0) {
		arr[1] -= 1;
		permutation(depth + 1, sum - num[depth]);
		arr[1] += 1;
	}
	if (arr[2] > 0) {
		arr[2] -= 1;
		permutation(depth + 1, sum * num[depth]);
		arr[2] += 1;
	}
	if (arr[3] > 0) {
		arr[3] -= 1;
		permutation(depth + 1, sum / num[depth]);
		arr[3] += 1;
	}

}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}

	permutation(1, num[0]);

	cout << maximum << endl;
	cout << minimum << endl;

	return 0;
}