/*
	BOJ 2875 - 대회 or 인턴
	Created by haejun on 2020/03/02
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int a, b, k, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> k;
	while (k--) {
		int aa;
		if (a == 0 || a == 1) aa = a;
		else aa = a / 2;

		if (aa >= b) a--;
		else b--;
		//cout << a << " " << b << " " << k << "\n";
	}
	if (a == 0 || a == 1) cout << 0 << "\n";
	else cout << min(a / 2, b) << "\n";


	return 0;
}