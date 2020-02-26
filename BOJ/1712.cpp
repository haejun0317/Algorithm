/*
	BOJ 1712 - 손익분기점
	Created by haejun on 2020/02/27
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define ll long long int

ll a, b, c;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c;
	if (b >= c) {
		cout << -1 << "\n";
		return 0;
	}

	ll ans = a / (c - b) + 1;
	cout << ans << "\n";

	return 0;
}