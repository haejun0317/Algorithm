﻿/*
	BOJ 2522 - 별 찍기12
	Created by haejun on 2020/04/11
*/
#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int space;
	int star;

	for (int i = 1; i <= n; i++) {
		space = n - i;
		for (int j = 0; j < space; j++) {
			cout << " ";
		}
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		star = n - i;
		for (int j = 0; j < star; j++) {
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}