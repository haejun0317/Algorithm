/*
	BOJ 10824 - 네 수
	Created by haejun on 2020/03/08
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

string a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c >> d;
	a = a + b;
	c = c + d;
	long long int num1 = stoll(a.c_str());
	long long int num2 = stoll(c.c_str());
	long long int sum = num1 + num2;
	cout << sum << "\n";
	

	return 0;
}