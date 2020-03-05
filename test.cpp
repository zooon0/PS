#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[])
{
	int n = 5;
	int temp;
	list<int> a(0, 0);
	list<int>::iterator iter;
	for (int i = 0; i < n; i++) {
		a.push_back(i);
	}


	iter = a.begin();

	temp = *iter;
	
	iter = a.erase(iter);
	
	cout << "iter points: " << *iter << endl;

	a.insert(iter, temp);

	cout << "iter points: "<< *iter<<endl;
	iter--;
	cout << "Now iter points: "<< *iter<<endl;

	return 0;
}
