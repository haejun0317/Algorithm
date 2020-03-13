/*
	BOJ 2530 - 인공지능 시계
	Created by haejun on 2020/03/14
*/
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	c += d;
	b += c / 60;
	c %= 60;
	a += b / 60;
	b %= 60;
	a %= 24;
	cout << a<<" " << b <<" "<< c;

	return 0;
}