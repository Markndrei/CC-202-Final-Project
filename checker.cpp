#include <iostream>
using namespace std
template <typename T>
int main ()
{
	T forceInputType_T ()
	{
		T acctNo;
		bool check = false;
		string temp;
		while (check == false)
		{
			cin >> temp;
			stringstream stream (temp);
			if (stream >> number)
			{
				check = true;
			}
			else // (check!= true)
			{
				cout << Invalid Account Number. Try again! << endl;
			}
		}
		return acctNo
	}
}
