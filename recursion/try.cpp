// C++ program to find the sum
// of Array using accumulate() in STL

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Get the vector
	vector<int> a = { 1, 2 };

	cout << "\nSum = "
		<< accumulate(a.begin(), a.end(), 4);
	return 0;
}
