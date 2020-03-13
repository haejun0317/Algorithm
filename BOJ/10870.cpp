/*
	BOJ 10870 - 피보나치 수 5
	Created by haejun on 2020/03/14
*/
#include<iostream>
using namespace std;

int n;
int arr[22];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= 20; i++) arr[i] = arr[i - 1] + arr[i - 2];
	cout << arr[n];

	return 0;
}