#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> s;
vector<int> res;

void transform(vector<int> &s, vector<int> &res) {
	int sz = s.size();
	int sum = 0;
	for(int i = 0; i < sz; i++) {
		sum += (pow(10, sz-i-1) * s[i]);
	}
	res.push_back(sum);
	s.pop_back();
}

void recur(int n, int len) {
	if(n > 0) {
		for(int i = 0; i <= 9; i++) {
			s.push_back(i);
			if(s.size() == len) {
				transform(s, res);
			}
			recur(n-1, len);
		}
		s.pop_back();
	}
}

vector<int> numbersByRecursion(int n) {
	recur(n, n);
	return res;
}

int main() {
	int n=3;
	vector<int> ans;
	ans = numbersByRecursion(n);
	for(auto i : ans) 
		printf("%d\n", i);
	printf("end test case\n");
	return 0;
}
