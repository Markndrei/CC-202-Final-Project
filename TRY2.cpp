#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <windows.h>
using namespace std;
class bankAccounts // Class
{
	// DECLARATION OF OBJECTS
    char fullname[50];
    int accountCash, passcode;
    char type;
    string address, phoneNumber, nationality, civilStatus;

public:
	// CLASS FUNCTION PROTOTYPES: 
    void createAccount();     			  //function to get data from user
    void showAccount() const; 			  //function to show data on screen
    void modifyDetail();    			  //function to add new data
    void changePasscode (int);        //function to change passcode
    void depositation(int);            	//function to accept amount and add to balance amount
    void withdrawal(int);                //function to accept amount and subtract from balance amount
    void report() const;      		    //function to show data in tabular format
    int retaccountCash() const;         //function to return balance amount
    char rettype() const;              //function to return type of account
    string retaddress () const;        //function to return address
    string retphoneNumber () const;    //function to return phone number
    int retpasscode () const;      //function to return phone number
    string retnationality () const;    //function to return nationality
    string retcivilStatus () const;     //function to return civil status
};                                     //class ends here

void bankAccounts::createAccount()
{
    cout << "Input Fullname : [FIRSTNAME MIDDLENAME SURNAME]\n ";
    cout << "FULL NAME: ";
    cin.ignore();
    cin.getline(fullname, 50);
    cout << "Input Full Address : [House Number, Street Number, Town, City, Country, Zipcode]\n ";
    cout << "FULL ADDRESS: ";
    cin.ignore();
    cin.getline(fullname, 50);
    cout << "Enter Type of account : [Checking Account = C / Savings Account = S ] \n";
    cout << "ACCOUNT TYPE: ";
    cin >> type;
    type = toupper(type); // converts lowercase to uppercase
    cout << "Input Civil Status : [Single / Married / Widowed / Divorced] \n";
    cout << "CIVIL STATUS: ";
    cin >> civilStatus;
    cout << "Input Nationality : [Full Word] \n";
    cout << "NATIONALITY: ";
    cin >> nationality;
    cout << "Input Phone Number : \n";
    cout << "PHONE NUMBER: ";
    cin >> phoneNumber;
    cout << "Enter The Initial amount[>=500 for Saving and >=1000 for current]: ";
    cout << "MINIMUM DEPOSIT: ";
    cin >> accountCash;
    cout << "Passcode of the account : [ENTER A FIVE (5) DIGIT PASSCODE] ";
    cout << " FIVE DIGIT PASSCODE: ";
    cin >> passcode;
}

void bankAccounts::showAccount() const
{
	cout << "Fullname : \n" << fullname;
    cout << "Permanent Address : \n" << address;
    cout << "Type of Account : \n" << type;
    cout << "Civil Status : \n" <<civilStatus;
    cout << "Nationality : \n" << nationality;
    cout << "Phone Number : \n" << phoneNumber;
    cout << "\nBalance amount : " << accountCash;
    cout << "Account Passcode : " << passcode;
    
}
void bankAccounts::modifyDetail ()
{
    cout << "Modify Fullname : [FIRSTNAME MIDDLENAME SURNAME]\n ";
    cout << " FULL NAME: ";
    cin.ignore();
    cin.getline(fullname, 50);
    cout << "Modify Full Address : [House Number, Street Number, Town, City, Country, Zipcode]\n ";
    cout << " FULL ADDRESS: ";
    cin.ignore();
    cin.getline(fullname, 50);
    cout << "Modify Type of account : [Checking Account = C / Savings Account = S ] \n";
    cout << " ACCOUNT TYPE: ";
    cin >> type;
    type = toupper(type); // converts lowercase to uppercase
    cout << "Modify Civil Status : [Single / Married / Widowed / Divorced] \n";
    cout << " CIVIL STATUS: ";
    cin >> civilStatus;
    cout << "Modify Nationality : [Full Word] \n";
    cout << " NATIONALITY: ";
    cin >> nationality;
    cout << "Modify Phone Number : \n";
    cout << " PHONE NUMBER: ";
    cin >> phoneNumber;
    cout << " Enter The Initial amount[>=500 for Saving and >=1000 for current]: ";
    cout << " MINIMUM DEPOSIT: ";
    cin >> accountCash;  
}

void bankAccounts::changePasscode(int passcode)
{
	int newCode, prevCode;
	int index = 0;
	int attempts = 1+index;
	cout << "You are about to change your Pass Code \n ";
	cout << "Enter your Previous Passcode: ";
	cin >> prevCode;
		while (prevCode != passcode, index<3)
		{
			cout << "Attempt # " << attempts << endl;
			cout << "Enter your Previous Passcode: \n";
			cin >> prevCode;
			index++;
			attempts++;
		}
			if (prevCode !=passcode)
			{
				cout << "Incorrect Passcode, Try Again!" << endl;
			}
			else 
			{
				prevCode = passcode; index=3 ;
			}
				if (prevCode == passcode)
				{
					cout <<	"Password Correct, Proceed!" << endl;
					cout << "You can now change your password" << endl;
					cin >> newCode;
					newCode=passcode;
				}
				else //(prevCode != passcode);
				{
					cout << "Sorry, Try again later!";
				}
}

// CALCULATIONS OF CLASS OBJECTS:
void bankAccounts::depositation(int x)
{
    accountCash += x;
}

void bankAccounts::withdrawal(int x)
{
    accountCash -= x;
}

// CONVERSION OF CLASS OBJECTS:
void bankAccounts::report() const
{
    cout << retpasscode () << setw(10) << " " << fullname << setw(10) << " " << type << setw(6) << " " << accountCash << setw (10) << endl;
}

int bankAccounts::retaccountCash() const
{
    return accountCash;
}

char bankAccounts::rettype() const
{
    return type;
}

string bankAccounts::retaddress() const
{
    return address;
}

string bankAccounts::retnationality() const
{
    return nationality;
}

string bankAccounts::retcivilStatus() const
{
    return civilStatus;
}

string bankAccounts::retphoneNumber () const
{
	return phoneNumber;
}

int bankAccounts::retpasscode () const
{
	return passcode;
}

// FUNCTION PROTOTYPES:
void writeAccount();            //function to write record in binary file
void displayDetails(int);         //function to display account details given by user
void modifyAccount(int);        //function to modify record of file
void deleteAccount(int);        //function to delete record of file
void displayList();              //function to display all account details
void deposit_withdraw(int, int); //function to desposit/withdraw amount for given account
void loadingBar();				 //function to loading bar in creating acount

// MAIN FUNCTION OF THE PROGRAM

int main ()
{
	 char choice;
    int num;
	do 
	{
		time_t now = time (0);
	 	char* dt = ctime (&now);
	 	cout << "======================================================================\n";
	 	cout << "\t\t   Welcome to Deonto Bank Corporation!\n";
		cout << "\t\t\t" << dt;
		cout << "======================================================================\n";
	 	cout << "\t\t\t   M A I N  M E N U \n";
	 	cout << "======================================================================\n";
        cout << "\t01. ESTABLISH AN ACCOUNT";
        cout << "\n\t02. DEPOSIT CASH";
        cout << "\n\t03. WITHDRAW CASH";
        cout << "\n\t04. BALANCE INQUIRY";
        cout << "\n\t05. ACCOUNT LIST";
        cout << "\n\t06. TERMINATE AN ACCOUNT";
        cout << "\n\t07. MODIFY AN ACCOUNT";
        cout << "\n\t08. EXIT";
        cout << "\n======================================================================\n";
        cout << "\n\tSelect Your Choice : [1-8] \n";
        cout << "\tChoice : ";
        cin >> choice;
        system("CLS");
	cout << "======================================================================\n";
        switch (choice)
        {
        case '1':
            writeAccount();
            system ("CLS");
      		loadingBar();
			system ("CLS");
			cout << "\n\n\t Account created...";
            break;
        case '2':
            cout << "\n\n\tEnter Account Pincode : ";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout << "\n\n\tEnter  Account Pincode : ";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            cout << "\n\n\t  Account Pincode : ";
            cin >> num;
            displayDetails(num);
            break;
        case '5':
            displayList();
            break;
        case '6':
            cout << "\n\n Account Pincode : ";
            cin >> num;
            deleteAccount(num);
            break;
        case '7':
            cout << "\n\n\t Account Pincode : ";
            cin >> num;
            modifyAccount(num);
            break;
        case '8':
            cout << "\n\n\tThanks for using bank managemnt system";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } 
	while (choice != '8');
    return 0;
}

//FUNCTION TO WRITE A FILE 

void writeAccount()
{
    bankAccounts pass;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    pass.createAccount();
    outFile.write(reinterpret_cast<char *>(&pass), sizeof(bankAccounts));
    outFile.close();
}

// 									MAIN USER DEFINED FUNCTIONS:		
//FUNCTION TO READ SPECIFIC RECORD FROM A FILE
void displayDetails (int n)
{
    bankAccounts pass;
    bool flag = false;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\nBALANCE DETAILS\n";

    while (inFile.read(reinterpret_cast<char *>(&pass), sizeof(bankAccounts)))
    {
        if (pass.retpasscode() == n)
        {
            pass.showAccount();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nAccount number does not exist";
}


//FUNCTION TO MODIFY AN ACCOUNT

void modifyAccount(int n)
{
    bool found = false;
    bankAccounts pass;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&pass), sizeof(bankAccounts));
        if (pass.retpasscode() == n)
        {
            pass.showAccount();
            cout << "\n\nEnter The New Details of account" << endl;
            pass.modifyDetail();
            int pos = (-1) * static_cast<int>(sizeof(bankAccounts));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&pass), sizeof(bankAccounts));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}


//FUNCTION TO DELETE RECORD ACCOUNT

void deleteAccount(int n)
{
    bankAccounts pass;
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
    while (inFile.read(reinterpret_cast<char *>(&pass), sizeof(bankAccounts)))
    {
        if (pass.retpasscode() != n)
        {
            outFile.write(reinterpret_cast<char *>(&pass), sizeof(bankAccounts));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    cout << "\n\n\tRecord Deleted ..";
}


// FUNCTION TO DISPLAY ALL ACCOUNTS DEPOSIT LIST
void displayList()
{
    bankAccounts pass;
    ifstream inFile;
    inFile.open("account.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "A/c no.      NAME           Type  Balance\n";
    cout << "====================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&pass), sizeof(bankAccounts)))
    {
        pass.report();
    }
    inFile.close();
}


//FUNCTION TO WITHRDRAW OR DEPOSIST AMOUNT 

void deposit_withdraw(int n, int option)
{
    int amount;
    bool found = false;
    bankAccounts pass;
    fstream File;
    File.open("account.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&pass), sizeof(bankAccounts));
        if (pass.retpasscode() == n)
        {
            pass.showAccount();
            if (option == 1)
            {
                cout << "\n\n\tTO DEPOSIT AMOUNT ";
                cout << "\n\nEnter The amount to be deposited";
                cin >> amount;
                pass.depositation(amount);
            }
            if (option == 2)
            {
                cout << "\n\n\tTO WITHDRAW AMOUNT ";
                cout << "\n\nEnter The amount to be withdrawn";
                cin >> amount;
                int bal = pass.retaccountCash() - amount;
                if ((bal < 500 && pass.rettype() == 'S') || (bal < 1000 && pass.rettype() == 'C'))
                    cout << "Insufficient balance";
                else
                    pass.withdrawal(amount);
            }
            int pos = (-1) * static_cast<int>(sizeof(pass));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&pass), sizeof(bankAccounts));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}



// 											UTILITY FUNCTIONS:


 
//FUNCTION FOR LOADING BAR WHEN CREATING AN ACCOUNT
void loadingBar()
{

	// Initialize char for printing
	// loading bar
	char a = 177, b = 219;

	cout << "\n\n\n\n";
	cout <<"\n\n\n\n\t\t\t\t\t    Creating Account...\n\n";
	cout << "\t\t\t\t\t";

	// Print initial loading bar
	for (int i = 0; i < 25; i++)
		cout << a;

	// Set the cursor again starting
	// point of loading bar
	cout << "\r";
	cout << "\t\t\t\t\t";

	// Print loading bar progress
	for (int i = 0; i < 25; i++) {
		cout << b;

		// Sleep for 250 milliseconds
		Sleep(250);
	}
}
