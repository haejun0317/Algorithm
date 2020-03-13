/*
	BOJ 1297 - TV 크기
	Created by haejun on 2020/03/14
*/
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	double a, b, c;
	cin >> a >> b >> c;
	cout <<(int)sqrt((a*a*b*b/(b*b+c*c))) <<' ' << (int)sqrt((a * a * c * c / (b * b + c * c))) << '\n';

	return 0;
}