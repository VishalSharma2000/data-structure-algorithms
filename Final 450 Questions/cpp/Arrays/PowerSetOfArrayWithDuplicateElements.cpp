#include <bits/stdc++.h>
using namespace std;

void findPowerSet(vector<int> &ans, vector<vector<int> > &ans, int index, vector<int> &subset) {
	ans.push_back(subset);

	for(int i=index; i<arr.size(); i++) {
		if(i > start && arr[i] == arr[i-1]) continue;

		// include the elemnt
		subset.push_back(arr[i]);
		findPowerSet(ans, ans, i+1, subset);
		subset.pop_back();
	}
}

vector<vector<int> > powerSet(vector<int> &arr) {
	sort(arr.begin(), arr.end());
	vector<vector<int> > ans;
	vector<int> subset;
	int index = 0;

	findPowerSet(arr, ans, index, subset);
	return ans;
}

int main() {
	int n; cin >> n;
	vector<int> arr(n, 0);

	int no;
	for(int i=0; i<n && cin >> no; i++) arr[i] = no;

	cout << powerSet(arr) << endl;
}