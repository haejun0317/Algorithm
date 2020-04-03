/*
	Programmers 42626 - 더 맵게
	Created by haejun on 2020/04/04
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	// 1. pq에 vector값 넣기
	for (int i = 0; i < scoville.size(); i++) pq.push(scoville[i]);

	// 2. 만약 첫번째 값이 K이상이면 종료.
	if (pq.top() >= K) return answer;

	while (1) {
		if (pq.top() >= K) return answer;
		if (pq.size() == 1 && pq.top() < K) return -1;
		else if (pq.size() == 1 && pq.top() >= K) return answer;

		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		pq.push(a + (b * 2));
		answer++;
	}

	return answer;
}