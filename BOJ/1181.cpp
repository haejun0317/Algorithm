/*
	BOJ 1181 - 단어 정렬
	Created by haejun on 2020/03/13
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n;
vector<string> v;
string s;

bool comp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (find(v.begin(), v.end(), s) == v.end()) v.push_back(s);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";

	return 0;
}