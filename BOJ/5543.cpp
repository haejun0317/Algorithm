/*
	BOJ 5543 - 상근날드
	Created by haejun on 2020/03/13
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int f,s;
	cin >> f;
	cin >> s;
	f = min(f, s);
	cin >> s;
	f = min(f, s);

	int c, d;
	cin >> c >> d;
	c = min(c, d);

	cout << f + c-50;
	
	

	return 0;
}