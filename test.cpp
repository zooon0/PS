#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n = 6;
	list<int> numlist(0, 0);
	list<int>::iterator a, b;
	for(int i = 0; i < n; i++)
		numlist.push_back(i);

		
	for (list<int>::iterator i = numlist.begin(); i != numlist.end(); ++i)
		for (list<int>::iterator j = i; j != numlist.end(); ++j)
		{
			if (i == j)	
				continue;

			else
			{
				int tempI = *i;
				int tempJ = *j;

				j = numlist.erase(j);
				i = numlist.erase(i);

				for(auto &k : numlist)	
					cout << k << " ";
				cout << endl << endl;	
				

				i = numlist.insert(i, tempI);
				j = numlist.insert(j, tempJ);

				cout << "i,j = " << *i << " " << *j << endl;

			}
		}

		
	return 0;
}
