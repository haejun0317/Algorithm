﻿/*
	BOJ 2164 - 카드2
	Created by haejun on 2020/03/27
*/
#include<iostream>
#include<queue>
using namespace std;

int n;
queue <int> q;


int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (true) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}

		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}


	return 0;
}