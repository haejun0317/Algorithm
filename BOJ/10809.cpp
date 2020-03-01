/*
	BOJ 10809 - 알파벳 찾기
	Created by haejun on 2020/03/01
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int arr[30];
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s;
	memset(arr, -1, sizeof(arr));
	for (int i = 0; i < s.size(); i++) {
		if(arr[s[i] - 'a']==-1) arr[s[i]-'a']=i;
	}
	for (int i = 0; i < 26; i++) cout << arr[i] << " ";


	return 0;
}