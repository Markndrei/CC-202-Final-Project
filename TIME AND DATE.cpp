// DATE AND TIME

#include <iostream>
#include <ctime>
using namespace std;
 int main ()
 {
 	time_t now = time (0);
 	char* dt = ctime (&now);
 	cout << "Current Time and Date : " << dt << endl;
 }
