/*
	BOJ 10872 - 팩토리얼
	Created by haejun on 2020/03/14
*/
#include<iostream>
using namespace std;

int n;
int func(int a) {
	if (a == 0) return 1;
	return a * func(a - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cout << func(n);

	return 0;
}