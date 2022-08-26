//Name - Ratnakar Dhruv Vats
//Roll number - 2010990579
//Set number - 5
//Question 1

#include <bits/stdc++.h>
using namespace std;


int longlen(int arr[],int n,int target)
{

	unordered_map<int, int> um;
	int s = 0, a = 0;

	for (int i = 0; i < n; i++) {

		s += arr[i];

		if (s == target)
			a = i + 1;

		if (um.find(s) == um.end())
			um[s] = i;

		if (um.find(s - target) != um.end()) {

			if (a < (i - um[s - target]))
				a = i - um[s - target];
		}
	}


	return a;
}


int main()
{
	int arr[] = {5,6,-5,5,3,5,3,-2,0};
    
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 8;
	cout << "longest subarray have length of = "
		<< longlen(arr, n, target);
	return 0;
}
