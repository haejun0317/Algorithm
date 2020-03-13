/*
	BOJ 3046 - R2
	Created by haejun on 2020/03/14
*/
#include<iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int r1, r2, s;
	cin >> r2 >> s;
	r1 = (s * 2) - r2;
	cout << r1;

	return 0;
}