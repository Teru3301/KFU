#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string num1;
	string num2;

	cin >> num1 >> num2;

	int* n1 = new int[num1.length()];
	int* n2 = new int[num2.length()];

	for (int i = 0; i < num1.length(); i++)
		n1[i] = num1[i];

	for (int i = 0; i < num2.length(); i++)
		n2[i] = num2[i];

	sort(n1, (n1 + num1.length()));
	sort(n2, (n2 + num2.length()));

	if (num1.length() == num2.length())
	{
		bool y = true;
		for (int i = 0; i < num1.length(); i++)
		{
			if (n1[i] != n2[i])
			{
				cout << "NO";
				y = !y;
				break;
			}
		}
		if (y) cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
