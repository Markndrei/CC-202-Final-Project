//Loading Bar for CPP Project

// C++ program to create loading bar
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

// Function to creating loading bar
void loadingBar()
{

	// Initialize char for printing
	// loading bar
	char a = 177, b = 219;

	cout << "\n\n\n\n\n\n\n";
	cout <<"\n\n\n\n\t\t\t\t\t\t    Creating Account...\n\n";
	cout << "\t\t\t\t\t         ";

	// Print initial loading bar
	for (int i = 0; i < 25; i++)
		cout << a;

	// Set the cursor again starting
	// point of loading bar
	cout << "\r";
	cout << "\t\t\t\t\t         ";

	// Print loading bar progress
	for (int i = 0; i < 25; i++) {
		cout << b;

		// Sleep for 1 second
		Sleep(1000);
	}
}

// Driver Code
int main()
{
	// Function Call
	loadingBar();
	system ("CLS");
	return 0;
}

