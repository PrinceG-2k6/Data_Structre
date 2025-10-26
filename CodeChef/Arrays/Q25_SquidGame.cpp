#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int sum = 0;
		int smallest_element = 1e6;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
			smallest_element = min(smallest_element, v[i]);
		}
		cout << sum - smallest_element << "\n";
	}
	return 0;
}