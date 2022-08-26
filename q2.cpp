//Name - Ratnakar Dhruv Vats
//Roll number - 2010990579
//Set number - 5
//Question 2


#include <bits/stdc++.h>
using namespace std;


vector< pair<int, int> > subarray(int arr[], int n)
{
	unordered_map<int, vector<int> > map;

	vector <pair<int, int>> out;

	int s = 0;

	for (int i = 0; i < n; i++)
	{
		s += arr[i];

		if (s == 0)
			out.push_back(make_pair(0, i));

		if (map.find(s) != map.end())
		{
			vector<int> vc = map[s];
			for (auto it = vc.begin(); it != vc.end(); it++)
				out.push_back(make_pair(*it + 1, i));
		}

		map[s].push_back(i);
	}

	return out;
}

void print(vector<pair<int, int>> out)
{
	for (auto it = out.begin(); it != out.end(); it++)
		cout << "Subarray found from Index " <<
			it->first << " to " << it->second << endl;
}

// Driver code
int main()
{
	int arr[] = {3,4,-7,3,1,3,1,-4,-2,-2};
	int n = sizeof(arr)/sizeof(arr[0]);

	vector<pair<int, int> > out = subarray(arr, n);

	if (out.size() == 0)
		cout << "No subarray exists";
	else
		print(out);

	return 0;
}
