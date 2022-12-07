#include <iostream>
#include <fstream>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;

class account
{
    int acno;
    char name[50];
    int deposit;
    char type;

public:
    void create_account();     //function to get data from user
    void show_account() const; //function to show data on screen
    void modify();             //function to add new data
    void dep(int);             //function to accept amount and add to balance amount
    void draw(int);            //function to accept amount and subtract from balance amount
    void report() const;       //function to show data in tabular format
    int retacno() const;       //function to return account number
    int retdeposit() const;    //function to return balance amount
    char rettype() const;      //function to return type of account
};                             //class ends here

//PRELIMS FUNCTIONS
void mainMenu(ifstream& in_s);    // function prototype for mainmenu.
void drawing(ifstream& in_s);     // function header
void account::create_account()
{
	char lines;
	ifstream in_s; // declaration of the stream of type input
	drawing (in_s); // function for file input
	while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
			{
			cout.put(lines);
			}
	cout << "\n\t\t\t_____________________________________________________________________________\n";
    cout << "\t\t\tEnter Account Number : ";
    cin >> acno; 
    cout << "\n\t\t\tEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\n\t\t\tEnter Type of The account [C = Current; S = Savings) : ";
    cin >> type;
    type = toupper(type);
    cout << "\n\t\t\tEnter Minimum Deposit [>=2000 for Saving and >=5000 for Current ]: ";
    cin >> deposit;
}

void account::show_account() const
{
    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Holder Name : " << name;
    cout << "\nType of Account : " << type;
    cout << "\nBalance amount : " << deposit;
}

void account::modify()
{
    cout << "\nAccount No. : " << acno;
    cout << "\nModify Account Holder Name : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nModify Type of Account : ";
    cin >> type;
    type = toupper(type);
    cout << "\nModify Balance amount : ";
    cin >> deposit;
}

void account::dep(int x)
{
    deposit += x;
}

void account::draw(int x)
{
    deposit -= x;
}

void account::report() const
{
    std::cout << "\t\t\t" << setw (10) << acno << setw(15) << name << setw(10)<< type << setw(15) << deposit << endl;
}

int account::retacno() const
{
    return acno;
}

int account::retdeposit() const
{
    return deposit;
}

char account::rettype() const
{
    return type;
}

// FUNCTION DECLARATION
void write_account();            //function to write record in binary file
void display_sp(int);            //function to display account details given by user
void modify_account(int);        //function to modify record of file
void delete_account(int);        //function to delete record of file
void display_all();              //function to display all account details
void deposit_withdraw(int, int); //function to desposit/withdraw amount for given account
void loadingBar(string);		  //function to loading bar in creating acount
// MAIN FUNCTION OF THE PROGRAM
int main()
{
    // declaration of variables
	char ch, lines;
    int num;
    do
    {
		
		system("cls");
		//PRELIMS:
		// INTRODUCTION
		cout << "\n\n\n\n";
		cout << "\n\t\t\t+++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "\t\t\t   WELCOME TO DEONTO UNIBANK INCORPORTION!   \n";
		// TIME AND DATE display
		time_t now = time (0);
	 	char* dt = ctime (&now);
	 	cout << "\t\t\t\t   " << dt;
		// MAIN MENU
		ifstream in_s; // declaration of the stream of type input
		mainMenu(in_s); // function for file input
		while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
			{
			cout.put(lines);
			}
	in_s.close( ); // Close the connection (close the file)
        cout << "\t\t\tSELECT OPTION: ";
		cin >> ch;
        system("CLS");
        switch (ch)
        {
        case '1':
            write_account();
            system ("CLS");
      		loadingBar("CREATING ACCOUNT");
			system ("CLS");
			cout << "\n\n\t Account established...";
            break;
        case '2':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            system ("CLS");
      		loadingBar("LOCATING ACCOUNT");
			system ("CLS");
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            delete_account(num);
            break;
        case '7':
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            modify_account(num);
            break;
        case '8':
            cout << "\n\n\tThanks for using bank managemnt system";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}


//FUNCTION TO LOADING BAR TO ALL FUNCTIONS
void loadingBar (string loadingText)
{

	// Initialize char for printing
	// loading bar
	char a = 177, b = 219;

	cout << "\n\n\n\n";
	cout <<"\n\n\n\n\t\t\t\t\t         " + loadingText + "...\n\n";
	cout << "\t\t\t\t";

	// Print initial loading bar
	for (int i = 0; i < 50; i++)
		cout << a;
	cout << "\r";

	// Set the cursor again starting
	// point of loading bar
	cout << "\r";
	cout << "\t\t\t\t";

	// Print loading bar progress
	for (int i = 0; i < 50; i++) {
		cout << b;

		// Sleep for 200 milliseconds
		Sleep(100);
	}
	cout << "\n\t\t\t\t   Processing done. Press any key to continue...";
	getch ();
}
void mainMenu(ifstream& in_s) // function header
	{
	 in_s.open("MAINMENU.txt"); //Connect to the input file and test
	 
	 if(in_s.fail( )) // condition if there's an error with opening the file.
	 	{
	 	cout << "Input file opening failed. \n";
	 	exit(1); // if we couldn't open the file to read from we exit
		}
	}
	
void drawing(ifstream& in_s) // function header
	{
	 in_s.open("drawing.txt"); //Connect to the input file and test
	 
	 if(in_s.fail( )) // condition if there's an error with opening the file.
	 	{
	 	cout << "Input file opening failed. \n";
	 	exit(1); // if we couldn't open the file to read from we exit
		}
	}

//FUNCTION TO WRITE A FILE 

void write_account()
{
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
    outFile.close();
}

//FUNCTION TO READ SPECIFIC RECORD FROM A FILE
void display_sp(int n)
{
    account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\nBALANCE DETAILS\n";

    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() == n)
        {
            ac.show_account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nAccount number does not exist";
}

//FUNCTION TO MODIFY AN ACCOUNT

void modify_account(int n)
{
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            cout << "\n\nEnter The New Details of account" << endl;
            ac.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            system ("CLS");
      		loadingBar("MODIFYING ACCOUNT");
			system ("CLS");
            cout << "\n\n\t Account Modified";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}

//FUNCTION TO DELETE RECORD ACCOUNT

void delete_account(int n)
{
    account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        if (ac.retacno() != n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
     		system ("CLS");
      		loadingBar("TERMINATING ACCOUNT");
			system ("CLS");
    cout << "\n\n\t Account Deleted..";
}

// FUNCTION TO DISPLAY ALL ACCOUNTS DEPOSIT LIST
void display_all()
{
    account ac;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
     		system ("CLS");
      		loadingBar ("GATHERING ALL ACCOUNTS");
			system ("CLS");
    cout << "\n\n\t\t\t\t\tACCOUNT HOLDER LIST\n\n";
    cout << "\t\t\t=======================================================\n";
    cout << "\t\t\t   ACCT NO        NAME           TYPE      BALANCE\n";
    cout << "\t\t\t=======================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
    {
        ac.report();
    }
    inFile.close();
}

//FUNCTION TO WITHRDRAW OR DEPOSIST AMOUNT 

void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    account ac;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if (ac.retacno() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                cout << "\n\n\tTO DEPOSIT AMOUNT ";
                cout << "\n\nEnter The amount to be deposited: ";
                cin >> amt;
                system ("cls");
                loadingBar("DEPOSITING CASH");
                system ("cls");
                cout << "\n\n\t Cash Deposited...";
                ac.dep(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                cout << "\n\nEnter The amount to be withdrawn: ";
                cin >> amt;
                int bal = ac.retdeposit() - amt;
                if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
                    cout << "Insufficient balance";
                else
                    ac.draw(amt);
                    system ("CLS");
      				loadingBar("WITHDRAWING CASH");
					system ("CLS");
					cout << "\n\n\t Cash Withdrawn...";
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(account));
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}

// END OF PROJECT
