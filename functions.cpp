// Tim Khal
// CS163 - Program #4
// Nov. 18th, 2018

#include "list.h"

// ___________________________________________________________________________________________________________________________________________

tree::tree() // Constructor used to initialze the tree
{
	root = NULL;
}


tree::~tree() // Destructor used to only call my deleteAll function
{
	deleteAll(root);
}

// ___________________________________________________________________________________________________________________________________________

int tree::deleteAll(node* & root) // Function that will use an inOrder method to go through and delete data
{
	// Go through each node and delete data
	if (!root)
		return 1;

	deleteAll(root -> left);	

	delete [] root -> data.name;
	delete [] root -> data.address;
	delete [] root -> data.number;
	delete [] root -> data.payment;
	delete [] root -> data.lastPayment;
	delete [] root -> data.dateLast;

	deleteAll(root -> right);

	delete root;
}
// ___________________________________________________________________________________________________________________________________________

char* input(char* array) // Function that takes in users response and dynamically allocates memory for it
{
        char temp[101];

        cin.get(temp, 101, '\n');
        cin.ignore(101,'\n');

        array = new char[strlen(temp) + 1]; 
        strcpy(array, temp);

        return array;
}
// ___________________________________________________________________________________________________________________________________________

node* tree::copy(const company & info) // Function used to dynamically allocate memory and copy information over
{
	node* ptr = new node; // Creating a new node to hold information to copy user input and return it into the node we're adding into the BST

	if (!info.name) // Checking if there's any info in the first field
		return 0;

        (ptr -> data.name) = new char[strlen(info.name) + 1]; // Copying the data that the user entered in main (in info._____) over to our new temp node
        strcpy((ptr -> data.name), info.name);

        (ptr -> data.address) = new char[strlen(info.address) + 1];
        strcpy((ptr -> data.address), info.address);

        (ptr -> data.number) = new char[strlen(info.number) + 1];
        strcpy((ptr -> data.number), info.number);

        (ptr -> data.payment) = new char[strlen(info.payment) + 1];
        strcpy((ptr -> data.payment), info.payment);

	(ptr -> data.lastPayment) = new char[strlen(info.lastPayment) + 1];
	strcpy((ptr -> data.lastPayment), info.lastPayment);

	(ptr -> data.dateLast) = new char[strlen(info.dateLast) + 1];
	strcpy((ptr -> data.dateLast), info.dateLast);

	ptr -> data.check = info.check;

	// Now that we have our temporary node filled up, return it to our function

	return ptr; // We copied over all the information, 
}

// ___________________________________________________________________________________________________________________________________________






