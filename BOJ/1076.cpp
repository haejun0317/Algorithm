/*
	BOJ 1076 - 저항
	Created by haejun on 2020/02/29
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int check(string s) {
	if (s == "black") return 0;
	else if (s == "brown") return 1;
	else if (s == "red") return 2;
	else if (s == "orange") return 3;
	else if (s == "yellow") return 4;
	else if (s == "green") return 5;
	else if (s == "blue") return 6;
	else if (s == "violet") return 7;
	else if (s == "grey") return 8;
	else if (s == "white") return 9;
}

void print(int a) {
	for (int i = 0; i < a; i++) cout << 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	long long int ans = 0;
	int arr[3];

	for (int i = 0; i < 3; i++) {
		cin >> s;
		arr[i] = check(s);
	}

	if (arr[0] == 0 && arr[1] == 0) {
		cout << 0 << "\n";
		return 0;
	}
	else if (arr[0] == 0 && arr[1] != 0) {
		cout << arr[1];
		print(arr[2]);
	}
	else {
		cout << arr[0] << arr[1];
		print(arr[2]);
	}
	cout << "\n";

	return 0;
}