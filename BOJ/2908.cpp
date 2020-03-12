/*
	BOJ 2908 - 상수
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<string>
using namespace std;

string a, b;
string aa, bb;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	for (int i = a.size()-1; i >=0; i--) aa += a[i];
	for (int i = b.size() - 1; i >= 0; i--) bb += b[i];

	int an = atoi(aa.c_str());
	int bn = atoi(bb.c_str());

	if (an > bn) cout << an;
	else cout << bn;

	return 0;
}