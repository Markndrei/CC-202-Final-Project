// PIN GENERATOR FOR FINAL PROJ
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    srand(time(0));
    cout<<"Pin Code Generated: \n";
    for(int i = 0; i < 5; i++)
    cout << alphanum[rand() % 66];
    return 0;
	
}
