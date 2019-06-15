// Tim Khal
// CS163 - Program #4
// Nov. 18th, 2018

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Functions not related to class
char* input(char* array); // Function that takes in users response and dynamically allocates memory for it, then copies the response into new variable

struct company // Struct to hold values for company
{
	char* name; // Name of company
	char* address; // Mailing address of company
	char* number; // Phone number of company
	char check; // Check if the company is older or less than 6 months old
	char* payment; // Amount currently being paid
	char* lastPayment; // Amount of last payment
	char* dateLast; // Date of last payment
};
// ___________________________________________________________________________________________________________________________________________

struct node // Struct node to traverse the tree
{
	company data; // Each node is going to have the members name, address, number, payment, lastPayment, and dateLast

	node* left; // Each node is going to have a left child pointer
	node* right; // Each node is going to have a right child pointer
};
// ___________________________________________________________________________________________________________________________________________

class tree
{
	public:
		tree(); // Constructor to initialize variables and set values to NULL or 0
		~tree(); // Destructor to deallocate all dynamic memory

		int w_addBill(const company & info); // Function to add a bill to the tree
		int w_displayAll(); // Function to display all data in each node
		int w_displayCompany(char* response); // Function to display all data in a specific company
		int w_removeBill(char* response); // Function to remove a bill
		int w_removeOld(); // Function to remove all bills older than 6 months
		int w_payBill(char* response); // Pay a bill

		int displayCompany(); // Display all data about a specific company

		node* copy(const company & info);

	private:
		node* root; // The root of the Binary Search Tree

		// Recursive functions wth matching wrapper function
		int addBill(node* & root, node* & temp);
		int displayAll(node* root); // Display all informatinon
		int displayCompany(node* root, char* response);
		int removeBill(node* & root, char* response);
		int removeOld(node* & root, bool flag);
		int payBill(node* & root, char* response); // Pay a bill

		// Recursive function with no matching wrapper function
		int deleteAll(node* & root);
};


