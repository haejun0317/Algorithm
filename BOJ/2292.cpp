/*
	BOJ 2292 - 벌집
	Created by haejun on 2020/03/13
*/
#include<iostream>
using namespace std;

int n, sum=2, lv;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	if (n == 1) cout << 1;
	else {
		while (n >= sum) {
			sum += 6 * lv;
			lv++;
		}
		cout << lv;
	}



	return 0;
}