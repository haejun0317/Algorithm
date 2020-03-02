/*
	BOJ 2587 - 대표값2
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

int arr[5];
int sum, avg;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	avg = sum / 5;
	sort(arr, arr + 5);
	cout << avg << "\n" << arr[2] << "\n";


	return 0;
}