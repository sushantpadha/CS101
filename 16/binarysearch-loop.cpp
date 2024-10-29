#include <iostream>
#include <cassert>
using std::cout; using std::cin; using std::cerr;
using std::endl; using std::flush;

int srch_loop (const float sortA[], const float& target, int n) {
	int left = 0, right = n-1, mid;
	while (right >= left && target != sortA[mid=(left+right)/2]) {
		if(target < sortA[mid]) right = mid-1;
		else left = mid+1;
	}
	return (right < left) ? -1 : mid;
}

int srch (const float sortA[], const float& target, int left, int right) {
	if (right < left)
		return -1;
	int mid = (left+right)/2;
	if (target < sortA[mid])
		return srch(sortA,target,left,mid-1);
	else if (sortA[mid] < target)
		return srch(sortA,target,mid+1,right);
	else // target == sortA[mid]
		return mid;
}
int main() {
	float S[5] = {11, 21.1, 114.7, 803.9, 1161.24};
	float t = 21.1;
	int i = srch_loop(S,t,5), j = srch(S,t,0,4);
	assert(i==j);
	cout << i << endl;
}
