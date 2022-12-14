/*
Program Title: Banking Management System
Submitted by: Cherilyn Marie Deocampo and Mark Andrei Encanto
Program Description: the progam functions similarly to how bank procedures work it allows users to
					Establish an Account, Check Account Details, Check List of Accounts Recorded
					Deposit Cash, Withdraw Cash, Modify Account Details, and Terminate Accounts from Record
*/


#include <iostream>
#include <fstream>
#include <ctime>
#include <cctype>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;

class bankAccount // DECLARATION OF CLASS
{
    // ATTRIBUTES DECLARATION:
	int accountNum;
    char fullname[99];
    int minimumDep;
    char type;

public: // ACCESS SPECIFIER [PUBLIC]
 
	// PUBLIC METHODS PROTOTYPES:
    void createAccount();    			  //function to get data from user
    void showAccount() const; 			  //function to show data on screen
    void modifyDetails();                //function to add new data
    void depositCash(int);            	 //function to accept amount and add to balance amount
    void withdrawCash(int);          	  //function to accept amount and subtract from balance amount
    void accountDetails() const;     	  //function to show data in tabular format
    int retaccountNum() const;      	 //function to return account number
    int retminimumDep() const;   	    //function to return balance amount
    char rettype() const;     		    //function to return type of account
};                           	

//-------------------------------------------------------------------------------------------------------------------------//
	//FILE READING FUNCTION PROTOTYPES FOR PRELIMINARIES
	void mainMenu(ifstream& in_s);    // function prototype for mainmenu.
	void drawing(ifstream& in_s);     // function prototype for drawing
	void closing(ifstream& in_s);     // function prototype for closing
	void loadingBar(string);		  //function to loading bar for processing
	
//-------------------------------------------------------------------------------------------------------------------------//


// FUNCTION DEFINITION FOR ESTABLISHING ACCOUNT
void bankAccount::createAccount()
{
	char lines;
	ifstream in_s; // declaration of the stream of type input
	drawing (in_s); // function for file input
	while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
			{
			cout.put(lines);
			}
	cout << "\n\t\t\t_____________________________________________________________________________\n";
	// prompts user to input account number
    cout << "\t\t\tInput Account Number : ";
    cin >> accountNum; 
    // prompts user to input account holder name
    cout << "\n\t\t\tInput Name of the Account Holder : ";
    cin.ignore(35); // ignores characters given the delimiter
    cin.getline(fullname, 99); // allows string input
    // prompts user to input account type
    cout << "\n\t\t\tInput Type of The account [C = Current; S = Savings] : ";
    cin >> type;
    type = toupper(type); // converts characters to uppercases
    cout << "\n\t\t\tInput Minimum Deposit [C = 5000 < Initial; S = 2000 < Initial]: ";
    cin >> minimumDep;
    if  ((minimumDep < 2000 && type == 'S') || (type == 'S'&&minimumDep < 5000))
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t INSUFFICIENT MINIMUM DEPOSIT";
    else
    cout << "\nCommence Processing";
                
}
//									END OF CREATING ACCOUNT FUNCTION DEFINITION
//---------------------------------------------------------------------------------------------------------------------------//



// FUNCTION DEFINITION FOR SHOWING ACCOUNT DETAILS
void bankAccount::showAccount() const
{
	
	cout << "\n\t\t\t_____________________________________________________________________________\n";
	cout << "\t\t\tAccount Number : " << accountNum;
    cout << "\n\t\t\tAccount Holder Name : " << fullname;
    cout << "\n\t\t\tType of Account : " << type;
    cout << "\n\t\t\tAccount Balance : " << minimumDep;
    cout << "\n\t\t\t_____________________________________________________________________________\n";
}

// 			END OF SHOWING OF ACCOUNT DETAILS FUNCTION DEFINITION
//-----------------------------------------------------------------------------------------------------------------------//


// FUNCTION DEFINITION FOR MODIFYING ACCOUNT DETAILS
void bankAccount::modifyDetails()
{
    cout << "\n\t\t\t_____________________________________________________________________________\n";
	cout << "\t\t\t\t\t\t\tMODIFICATION";
    cout << "\n\t\t\t_____________________________________________________________________________\n";
	cout << "\n\t\t\tAccount No. : " << accountNum;
    cout << "\n\t\t\tAccount Holder Name : ";
    cin.ignore(); // takes number of characters name as arguments for vivid record
    cin.getline(fullname, 99); // allows the progam to acquire multiple characters
    cout << "\n\t\t\tType of Account : ";
    cin >> type; // prompts type of account input
    type = toupper(type); // converts character inputs to uppercases
    cout << "\n\t\t\tBalance amount : ";
    cin >> minimumDep; // prompts minimum deposit input
}

// 			END OF MODIFYING ACCOUNT FUNCTION DEFINITION
//--------------------------------------------------------------------------------------------------------------------//


// FUNCTION DEFINITION FOR CASH DEPOSIT
void bankAccount::depositCash(int x)
{
    minimumDep += x; // short notation for deposit
}
//-------------------------------------------------------------------------------------------------------------------//


// FUNCTION DEFINITION FOR CASH WITHDRAWAL
void bankAccount::withdrawCash(int x)
{
    if (minimumDep < x)
    		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t INSUFFICIENT BALANCE";
    else
    	minimumDep -= x; // short notation for withdraw
                    system ("CLS");
      				loadingBar("WITHDRAWING CASH");
					system ("CLS");
					cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tCASH WITHDRAWAL SUCCESSFUL";
}
//				END OF CASH WITHDRAWAL FUNCTION PROTOTYPE
// -----------------------------------------------------------------------------------------------------------------//



// FUNCTION DEFINITION FOR DISPLAYING ACCOUNT DETAILS
void bankAccount::accountDetails() const
{
    std::cout << "\t\t\t" << setw (10) << accountNum << setw(35) << fullname << setw(10)<< type << setw(15) << minimumDep << endl;
		//DISPLAYS ALL ACCOUNT DETAILS IN A LIST
		// setw - sets the minimum number of characters in an input
}
// 		END OF SHOW ACCOUNT LIST
// ------------------------------------------------------------------------------------------------------------//


// FUNCTION DEFINTIONS FOR CONVETING USER INPUTS TO CONSTANTS

int bankAccount::retaccountNum() const // returns account number
{
    return accountNum;
}

int bankAccount::retminimumDep() const // returns minimum deposits
{
    return minimumDep;
}

char bankAccount::rettype() const // returns type
{
    return type;
}

// END OF  CONVERSION FUNCTION DEFINITIONS
//-------------------------------------------------------------------------------------------------------------------------//




// FUNCTION DECLARATIONS:
void writeAccount();            //function to write record in binary file
void displayDetails(int);            //function to display account details given by user
void modifyAccount(int);        //function to modify record of file
void deleteAccount(int);        //function to delete record of file
void displayList();              //function to display all account details
void deposit_withdraw(int, int); //function to desposit/withdraw amount for given account

//-----------------------------------------------------------------------------------------------------------------------//


// MAIN FUNCTION OF THE PROGRAM
int main()
{
    // declaration of variables
	char choice, lines;
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
		time_t now = time (0); // current time and date based on the system
	 	char* dt = ctime (&now); // converts time and date to a string
	 	cout << "\t\t\t\t   " << dt; // displays time and date
		
		
		
		// MAIN MENU
		ifstream in_s; // declaration of the stream of type input
		mainMenu(in_s); // function for file input
		while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
			{
			cout.put(lines); // display lines
			}
	in_s.close( ); // Close the connection (close the file)
        cout << "\t\t\tSELECT OPTION: "; // prompts user to select an option
		cin >> choice;
        system("CLS"); // clear screen
        
    // ------------------------------------------------------------------------------------------------------------------//
    
        // SWITCH CASE FOR EACH OPTION
        switch (choice) // choice as expression
        {
        case '1': // CASE FOR ESTABLISHING ACCOUNT
            writeAccount(); // function call for class method
            system ("CLS"); // clear screen
      		loadingBar("CREATING ACCOUNT"); // function call for loading bar
			system ("CLS"); // clear screen
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ACCOUNT ESTABLISHED";
            break;
            
    //-------------------------------------------------------------------------------------------------------------------//       
        case '2':// CASE FOR CASH DEPOSIT
        	char lines;
			drawing (in_s); // function for file input
			while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
					{
					cout.put(lines); // diplay lines
					}
			cout << "\n\t\t\t_____________________________________________________________________________\n";
			// prompts ser to input account number
            cout << "\n\t\t\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 1); // function call for deposit ( 1 = deposit)
            break;
            
        //--------------------------------------------------------------------------------------------------------------//
        
        case '3': // CASE FOR CASH WITHDRAW
			drawing (in_s); // function for file input
			while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
					{
					cout.put(lines); // display lines
					}
			cout << "\n\t\t\t_____________________________________________________________________________\n";
			// prompts user to input account number
            cout << "\t\t\tEnter The account No. : ";
            cin >> num;
            deposit_withdraw(num, 2); // function call for withdraw  2 = withdraw)
            break;
        
        //------------------------------------------------------------------------------------------------------------//
        
        case '4': // CASE FOR ACCOUNT DETAILS
			drawing (in_s); // function for file input
			while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
					{
					cout.put(lines); // display lines
					}
			cout << "\n\t\t\t_____________________________________________________________________________\n";
			// prompts user to input account number
            cout << "\n\t\t\tEnter The account No. : ";
            cin >> num;
            system ("CLS"); // clear screen
      		loadingBar("LOCATING ACCOUNT"); // function call for loading bar
			system ("CLS"); // clear screen
            displayDetails(num); // function call for displaying account details
            break;
            
        //--------------------------------------------------------------------------------------------------------------//
        
        case '5': // CASE FOR ACCOUNT LIST
			drawing (in_s); // function for file input
			while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
					{
					cout.put(lines); // display lines
					}
			cout << "\n\t\t\t_____________________________________________________________________________\n";
            displayList(); // function call to display all accounts record
            break;
        
        //--------------------------------------------------------------------------------------------------------------//
        
        case '6': // CASE FOR TERMINATE ACCOUNT
			drawing (in_s); // function for file input
			while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
					{
					cout.put(lines);
					}
			cout << "\n\t\t\t_____________________________________________________________________________\n";
			// prompts users for account number input
            cout << "\n\t\t\tEnter The account No. : ";
            cin >> num;
            deleteAccount(num);// function call for deleting account
            break;
            
         //--------------------------------------------------------------------------------------------------------------//
        
        case '7': // CASE FOR MODIFY ACCOUNT
			drawing (in_s); // function for file input
			while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
					{
					cout.put(lines); // display lines
					}
			cout << "\n\t\t\t_____________________________________________________________________________\n";
            // prompts user to input account number
			cout << "\n\t\t\tInput Account Number for Modification : ";
            cin >> num;
            modifyAccount(num); // function call for modifying account
            break;
            
         //--------------------------------------------------------------------------------------------------------------//
         
         
        case '8': // CASE FOR EXIT
			closing (in_s); // function for file input
			while(in_s.get(lines)) // Read all numbers one-by-one to the end of the file.
					{
					cout.put(lines);
					}
					
		 //--------------------------------------------------------------------------------------------------------------//
		
		
        default:
            cout << "\a"; // produces a sound to notify wrong input
        }
        cin.ignore(2); // ignores exceeding characters given the delimiter
        cin.get(); // reads whitespaces
    } while (choice != '8'); // return if wrong input
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------//

//FUNCTION TO LOADING BAR TO ALL FUNCTIONS
void loadingBar (string loadingText)
{

	// Initialize char for printing
	// loading bar
	char a = 177, b = 219;

	cout << "\n\n\n\n";
	cout <<"\n\n\n\n\t\t\t\t\t         " + loadingText + "...\n\n"; // calls specific strings depending on the case
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
	getch (); // pauses system until any key is pressed
}

//--------------------------------------------------------------------------------------------------------------------//

void mainMenu(ifstream& in_s) // function header for main menu file reading
	{
	 in_s.open("MAINMENU.txt"); //Connect to the input file and test
	 
	 if(in_s.fail( )) // condition if there's an error with opening the file.
	 	{
	 	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Input file opening failed. \n";
	 	exit(1); // if we couldn't open the file to read from we exit
		}
	}
	
//--------------------------------------------------------------------------------------------------------------------//

void closing(ifstream& in_s) // function header for exit file reading
	{
	 in_s.open("CLOSING.txt"); //Connect to the input file and test
	 
	 if(in_s.fail( )) // condition if there's an error with opening the file.
	 	{
	 	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Input file opening failed. \n";
	 	exit(1); // if we couldn't open the file to read from we exit
		}
	}
	
//-----------------------------------------------------------------------------------------------------------------------//

void drawing(ifstream& in_s) // function header for bank drawing file reading
	{
	 in_s.open("drawing.txt"); //Connect to the input file and test
	 
	 if(in_s.fail( )) // condition if there's an error with opening the file.
	 	{
	 	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Input file opening failed. \n";
	 	exit(1); // if we couldn't open the file to read from we exit
		}
	}

//--------------------------------------------------------------------------------------------------------------------//
//FUNCTION TO WRITE A FILE 

void writeAccount()
{
    bankAccount ac; // declares class
    ofstream outFile; // stream to write to files
    outFile.open("deonto.cpp", ios::binary | ios::app); // open file and avoid overwriting inputs
    ac.createAccount(); //calls create Account function
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(bankAccount));//cast structure pointer to const char* and write data
    																  // as expected by the write () function
    outFile.close(); // close file
}

//----------------------------------------------------------------------------------------------------------------------//
//FUNCTION TO READ SPECIFIC RECORD FROM A FILE
void displayDetails(int n)
{
    bankAccount ac; // declares class
    bool flag = false; // boolean expreassion
    ifstream inFile; // stream to read files
    inFile.open("deonto.cpp", ios::binary); // open file and avoid overwriting inputs
    if (!inFile) // if file not found
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t File location Not Found ! Press any Key...";
        return;
    }
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(bankAccount))) // if file is located
    {
        if (ac.retaccountNum() == n) // checker if the user input is similar to the recorded accounts
        {
        	cout << "\n\t\t\t\t\t\t BALANCE DETAILS\n";
        	flag = true;// if account number input match the records
            ac.showAccount(); // function call to show account details
        }
    }
    inFile.close();
    if (flag == false) // if account number input does not match the records
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t ACCOUNT NUMBER DOES NOT EXISTS";
}

//------------------------------------------------------------------------------------------------------------//

//FUNCTION TO MODIFY AN ACCOUNT

void modifyAccount(int n)
{
    bool found = false; 
    bankAccount ac; // function calls
    fstream File; // 
    File.open("deonto.cpp", ios::binary | ios::in | ios::out); // open file location
    if (!File) // if file is not found
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t File location Not Found! Press any Key...";
        return;
    }
    while (!File.eof() && found == false) // condition if file is found
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(bankAccount));//cast structure pointer to const char* and write data
    																  // as expected by the write () function
        if (ac.retaccountNum() == n) // checker if the account number is similar to the input
        {
            ac.showAccount(); // function call to show account details
            cout << "\n\t\t\t\t\t\tPROVIDE REPLACEMENT DETAILS" << endl;
            ac.modifyDetails(); // function to initiate modifying account details
            int pos = (-1) * static_cast<int>(sizeof(bankAccount));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(bankAccount));
            system ("CLS");
      		loadingBar("MODIFYING ACCOUNT");
      		system ("CLS");
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ACCOUNT MODIFIED";
            found = true;
        }
    }
    File.close();
    if (found == false)
    	system ("CLS");
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t RECORD NOT FOUND ";
}

//FUNCTION TO DELETE RECORD ACCOUNT

void deleteAccount(int n)
{
    bankAccount ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("deonto.cpp", ios::binary);
    if (!inFile)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t File location Not Found! Press any Key...";
        return;
    }
    outFile.open("Temp.dat", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(bankAccount)))
    {
        if (ac.retaccountNum() != n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(bankAccount));
        }
    }
    inFile.close();
    outFile.close();
    remove("deonto.cpp");
    rename("Temp.dat", "deonto.cpp");
     		system ("CLS");
      		loadingBar("TERMINATING ACCOUNT");
			system ("CLS");
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t ACCOUNT TERMINATED";
}

// FUNCTION TO DISPLAY ALL ACCOUNTS DEPOSIT LIST
void displayList()
{
    bankAccount ac;
    ifstream inFile;
    inFile.open("deonto.cpp", ios::binary);
    if (!inFile)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t File location Not Found ! Press any Key...";
        return;
    }
     		system ("CLS");
      		loadingBar ("GATHERING ALL ACCOUNTS");
			system ("CLS");
    cout << "\n\n\t\t\t\t\t\tACCOUNT HOLDER LIST\n\n";
    cout << "\t\t\t=========================================================================\n";
    cout << "\t\t\t=  ACCT NO                  NAME                    TYPE      BALANCE   =\n";
    cout << "\t\t\t=========================================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(bankAccount)))
    {
        ac.accountDetails();
    }
    inFile.close();
}

//FUNCTION TO WITHRDRAW OR DEPOSIST AMOUNT 

void deposit_withdraw(int n, int option)
{
    int cash;
    bool found = false;
    bankAccount ac;
    fstream File;
    File.open("deonto.cpp", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t File location Not Found ! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(bankAccount));
        if (ac.retaccountNum() == n)
        {
            ac.showAccount();
            if (option == 1)
            {
                cout << "\n\t\t\t\t''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
				cout << "\t\t\t\t''\t\t\tCASH DEPOSIT PANEL                    ''";
				cout << "\n\t\t\t\t''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n";
                cout << "\t\t\t\tEnter The amount to be deposited: ";
                cin >> cash;
                system ("cls");
                loadingBar("DEPOSITING CASH");
                system ("cls");
                cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tCASH DEPOSIT SUCCESSFUL";
                ac.depositCash(cash);
            }
            if (option == 2)
            {
                cout << "\n\t\t\t\t================================================================\n";
				cout << "\t\t\t\t=\t\t\tCASH WITHDRAW PANEL                    =";
				cout << "\n\t\t\t\t================================================================\n";
                cout << "\t\t\t\tEnter The amount to be withdrawn: ";
                cin >> cash;
                int bal = ac.retminimumDep() - cash;
                	if ((bal < 2000 && ac.rettype() == 'S') || (bal < 5000 && ac.rettype() == 'C'))
                    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tINSUFFICIENT BALANCE";
                else
                 ac.withdrawCash(cash);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(bankAccount));
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t RECORD NOT FOUND ";
}

// END OF PROJECT