#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void newMonth(vector < pair < int, string > >& v);
vector < int > month;
int index = 0;
int main()
{
	// ifstream cin("input.txt");
	month.push_back(31);
	month.push_back(28);
	month.push_back(31);
	month.push_back(30);
	month.push_back(31);
	month.push_back(30);
	month.push_back(31);
	month.push_back(31);
	month.push_back(30);
	month.push_back(31);
	month.push_back(30);
	month.push_back(31);
	int n;
	cin >> n;
	vector < pair < int, string > > a;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "NEXT")
		{
			newMonth(a);
			++index;
			index %= 12;
		}
		if (s == "ADD")
		{
			int k;
			string ss;
			cin >> k >> ss;
			a.push_back({ k , ss });
		}
		if (s == "DUMP")
		{
			int k;
			cin >> k;
			int p = 0;
			bool f = false;
			for (int i = 0; i < a.size(); i++)
			{
				if (a[i].first == k)
				{
					f = true;
					p++;
				}
			}
			if (p > 0)
			{
				cout << p << " ";
				for (int i = 0; i < a.size(); i++)
				{
					if (a[i].first == k)
					{
						f = true;
						cout << a[i].second << " ";
					}
				}
				cout << endl;
			}
			if (f == false)
			{
				cout << "0" << endl;
			}
		}
	}
	return 0;
}
void newMonth(vector < pair < int, string > >& v)
{
	if (month[index % 12] >= month[(index + 1) % 12])
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].first > month[(index + 1) % 12])
				v[i].first = month[(index + 1) % 12];
		}
	}
}