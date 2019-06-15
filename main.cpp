// Tim Khal
// CS163 - Program #4
// Nov. 18th, 2018

#include "list.h"


int main()
{
	char response; // Variable used for the user to pick from the menu
	tree callFunction; // Creating member callFunction used to call the functions

	cout << "\nWelcome! Please choose from the following menu:";

	do {
		cout << "\n\n1) Add a bill\n";
		cout << "2) Display all information\n";
		cout << "3) Remove a company\n";
		cout << "4) Delete all bills older than six months\n";
		cout << "5) Display information about a specific company\n";
		cout << "6) Pay a bill\n";
		cout << "7) Exit\n\n";


		cin >> response;
		cin.ignore(100,'\n');

		switch (response)
		{
			case '1':
				{
					company info; // Creating member info of type company to hold user input

					// Buffer character pointer variables to hold user input:

					cout << "\nPlease enter the following bill information:\n\n";

					// Storing all user information in "input._______"

					cout << "Company name:\n";
					info.name = input(info.name);  //

					cout << "Company address:\n";
					info.address = input(info.address); //

					cout << "Company phone number:\n";
					info.number = input(info.number);

					cout << "How much are you paying?\n";
					info.payment = input(info.payment);

					cout << "How much was your last payment?\n";
					info.lastPayment = input(info.lastPayment);

					cout << "What was the date of your last payment?\n";
					info.dateLast = input(info.dateLast); //

					cout << "Is this account older than six months? (Y/N)\n";
					cin >> info.check;
					cin.ignore(100,'\n');

					info.check = tolower(info.check); // Making this a lowercase 'y' or 'n'

					callFunction.w_addBill(info); // Now, calling the wrapper function for addBill and passing through all the user entered in information

					delete [] info.name;
					delete [] info.address;
					delete [] info.number;
					delete [] info.payment;
					delete [] info.lastPayment;
					delete [] info.dateLast; 
					break;
				}

			case '2':
				{
					int count = callFunction.w_displayAll(); // Calling the wrapper function 'displayAll()' and outputting to the client how many bills we have
					if (count == 1)
						cout << "\nYou have " << count << " bill\n"; // Having this if statement to check if bill should be singular or plural

					else
						cout << "\n\nYou have " << count << " bills\n";
					break;
				}

			case '3':
				{
					char* response; // Variable used to hold users response of name

					cout << "Please enter the name of the company you'd like to remove:\n";
					response = input(response); // Dynamically allocating  variable, and copying user input in

					int i = callFunction.w_removeBill(response);
					if (i == 0)
						cout << "\nNo matching company name was in our list.\nPlease try again\n";


					delete [] response;
					break;
				}

			case '4':
				{
					int i = callFunction.w_removeOld(); // Remove any bill that is older than 6 months
					if (i == 1)
						cout << "\n\nAll bills older than 6 months have been deleted.\n";
					else
						cout << "There were no bills older than 6 months.\n";
					break;
				}

			case '5':
				{
					char* response; // Variable to hold users response of name

					cout << "Please enter in the name of the company you'd like to have all information displayed:\n";
					response = input(response); // Dynamically allocating variable, and copying user input in

					int i = callFunction.w_displayCompany(response);
					if (i == 0)
						cout << "\nNo matching company name was in our list.\nPlease try again\n";
						
					delete [] response;
					break;
				}
			case '6':
			{
				char* response; // Variable used to hold user's response;

				cout << "Please enter the name of the company you'd like to pay to:\n";
				response = input(response);

				int i = callFunction.w_payBill(response);

				if (i == 0)
					cout << "\nNo matching company has been found, we cannot pay the bill\n";
				else
					cout << "Bill has been payed!\n";

				delete [] response;
				break;
			}


			case '7':
				{
					// No function is called, we exit the program and the destructor deallocates all dynamic memory
					cout << "Program has been ended\n";
					return 0;
				}


			default:
				cout << "Invalid option. Please try again\n";
		}
	} while ((response) != '7');

	return 0;
}





