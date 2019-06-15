// Tim Khal
// CS163 - Program #4
// Nov. 18th, 2018

#include "list.h"

// ___________________________________________________________________________________________________________________________________________

int tree::w_addBill(const company & info)
{
	node* temp = copy(info); // The node that was being returned from copy function is being placed in temp

	return addBill(root, temp); // Call our addBill function, and pass in root and the new node

}

 
int tree::addBill(node* & root, node* & temp)
{
	// In main, have the user enter in all the data they'd like to store
	if (!root)
	{
		root = temp;

		root -> left = NULL;
		root -> right = NULL;

		return 1; // Always returns success, because with this function we're always adding
	}

	if (strcmp(temp -> data.name, root -> data.name) < 0)
		return addBill(root -> left, temp);

	else
		return addBill(root -> right, temp);
}

// ___________________________________________________________________________________________________________________________________________

int tree::w_displayAll() // Wrapper function to display all data in each node
{
	return displayAll(root);  // Calls out displayAll function and passes in 'root' 

}

int tree::displayAll(node* root) // Function to display all data in each node
{
	if (!root)
		return 0;
	int i = displayAll(root -> left) + 1;

	cout << "\nName: " << root -> data.name << endl;
	cout << "Address: " << root -> data.address << '\n';
	cout << "Number: " << root -> data.number << '\n';
	cout << "Payment: " << root -> data.payment << '\n';
	cout << "Last payment: " << root -> data.lastPayment << '\n';
	cout << "Date of last payment: " << root -> data.dateLast << '\n';

	return displayAll(root -> right) + i; // Displaying all information in a node, then going to the next one
}

// ___________________________________________________________________________________________________________________________________________

int tree::w_displayCompany(char* response) // Wrapper function to call display company, and pass in a response
{
	return displayCompany(root, response);

}

int tree::displayCompany(node* root, char* response) // Go through and display all data in a selected company
{
	if (!root)
		return 0;


	if (strcmp(response, root -> data.name) == 0) // Is there a match?
	{ // We found a match

		cout << "\n\nCompany Information:\n\n";
		cout << "Name: " << root -> data.name << endl;
		cout << "Address: " << root -> data.address << '\n';
		cout << "Phone number: " << root -> data.number << '\n';
		cout << "Payment: " << root -> data.payment << '\n';
		cout << "Last payment: " << root -> data.lastPayment << '\n';
		cout << "Date of last payment: " << root -> data.dateLast << "\n\n";

		return 1;
	}


	else if (strcmp(response, root -> data.name) < 0)
	{ // Go left
		return displayCompany(root -> left, response);
	}

	else
		return displayCompany(root -> right, response);
}

// ___________________________________________________________________________________________________________________________________________

int tree::w_removeOld()
{
	bool flag = false;
	return removeOld(root, flag);
}

int tree::removeOld(node* & root, bool flag)
{
	if (!root)
	{ // We have gone through the tree. If we have not deleted any old nodes, flag should return false
		if (flag == false)
			return 0; // For failure
		else
			return 1; // For success
	}

	removeOld(root -> left, flag); // Go left

	removeOld(root -> right, flag); // Then go right

	if (root -> data.check == 'y')  // Is the node older than 6 months?
	{ // Yes
		if (root -> left && root -> right)  // If the node has 2 children
		{ // Find IOS
			node* current = root;
			node* prev = root;
			// Go left, then all the way right
			current = current -> left;

			while (current -> right) 
			{
				prev = current;
				current = current -> right;
			}

			// Delete contents of root, but NOT root itself
			delete [] root -> data.name;
			delete [] root -> data.number;
			delete [] root -> data.address;
			delete [] root -> data.payment;
			delete [] root -> data.lastPayment;
			delete [] root -> data.dateLast;

			root -> data = current -> data;

			if (prev = root)
				prev -> left = current -> left;

			else
				prev -> right = current -> left;

			delete current;

			flag = true; // Return for success

		}

		else if (root -> left && !root -> right) // If there's a left child but no right
		{
			node* temp = root;

			root = root -> left;

			delete [] temp -> data.name;
			delete [] temp -> data.number;
			delete [] temp -> data.address;
			delete [] temp -> data.payment;
			delete [] temp -> data.lastPayment;
			delete [] temp -> data.dateLast;
			delete temp;

			flag = true;
		}

		else if (root -> right && !root -> left) // If there's a right child but no left
		{
			node* temp = root;

			root = root -> right;

			delete [] temp -> data.name;
			delete [] temp -> data.number;
			delete [] temp -> data.address;
			delete [] temp -> data.payment;
			delete [] temp -> data.lastPayment;
			delete [] temp -> data.dateLast;
			delete temp;

			flag = true;
		}

		else
		{
			delete [] root -> data.name;
			delete [] root -> data.number;
			delete [] root -> data.address;
			delete [] root -> data.payment;
			delete [] root -> data.lastPayment;
			delete [] root -> data.dateLast;

			delete root;
			root = NULL;

			flag = true;;


		}
	}



}

// ___________________________________________________________________________________________________________________________________________

int tree::w_removeBill(char* response) // Wrapper function used to call removeBill | Using a wrapper function here so we do not violate laws of data abstraction
{
	return removeBill(root, response); // Returning value to main to indicate success or failure

}

int tree::removeBill(node* & root, char* response) // Function to remove a bill from the tree. If there is a match, we remove and reconnect the tree
{
	if (!root)
		return 0; // If there is no tree, return failure

	if (strcmp(response, root -> data.name) == 0) // Do we have a match?
	{ // Yes!
		if (root -> left && root -> right) // Check if the current node has a left child and right child
		{ // It does, now find IOS

			node* current = root; // Setting current to root to traverse
			node* prev = root; // Use 'prev' to stay one step behind current

			// To find roots IOS, we need to traverse left once then all the way right.
			current = current -> left;

			while (current -> right) 
			{
				prev = current;
				current = current -> right;
			}

			// Now we're at the IOS, so delete all data and replace root -> data with current -> data
			delete [] root -> data.name;
			delete [] root -> data.number;
			delete [] root -> data.address;
			delete [] root -> data.payment;
			delete [] root -> data.lastPayment;
			delete [] root -> data.dateLast;

			root -> data = current -> data;

			if (prev == root)
				prev -> left = current -> left;

			else
				prev -> right = current -> left;

			delete current;

			return 1; // Return for success

		}

		else if (root -> left && !root -> right)
		{
			node* temp = root;

			root = root -> left;

			delete [] temp -> data.name;
			delete [] temp -> data.number;
			delete [] temp -> data.address;
			delete [] temp -> data.payment;
			delete [] temp -> data.lastPayment;
			delete [] temp -> data.dateLast;
			delete temp;

			return 1;
		}

		else if (root -> right && !root -> left)
		{
			node* temp = root;

			root = root -> right;

			delete [] temp -> data.name;
			delete [] temp -> data.number;
			delete [] temp -> data.address;
			delete [] temp -> data.payment;
			delete [] temp -> data.lastPayment;
			delete [] temp -> data.dateLast;
			delete temp;

			return 1;
		}

		else 
		{
			delete [] root -> data.name;
			delete [] root -> data.number;
			delete [] root -> data.address;
			delete [] root -> data.payment;
			delete [] root -> data.lastPayment;
			delete [] root -> data.dateLast;

			delete root;
			root = NULL;

			return 1;
		}
	}


		else if (strcmp(response, root -> data.name) < 0)
		{ // Go left
			return removeBill(root -> left, response);
		}

		else
			return removeBill(root -> right, response);
}

// ___________________________________________________________________________________________________________________________________________

	
int tree::w_payBill(char* response) // Wrapper function used to call payBill | Using a wrapper function here so we do not violate laws of data abstraction
{
	return payBill(root, response); // Returning value to main to indicate success or failure

}

int tree::payBill(node* & root, char* response) // Function to remove a bill from the tree. If there is a match, we remove and reconnect the tree
{
	if (!root)
		return 0; // If there is no tree, return failure

	if (strcmp(response, root -> data.name) == 0) // Do we have a match?
	{ // Yes!
		if (root -> left && root -> right) // Check if the current node has a left child and right child
		{ // It does, now find IOS

			node* current = root; // Setting current to root to traverse
			node* prev = root; // Use 'prev' to stay one step behind current

			// To find roots IOS, we need to traverse left once then all the way right.
			current = current -> left;

			while (current -> right) 
			{
				prev = current;
				current = current -> right;
			}

			// Now we're at the IOS, so delete all data and replace root -> data with current -> data
			delete [] root -> data.name;
			delete [] root -> data.number;
			delete [] root -> data.address;
			delete [] root -> data.payment;
			delete [] root -> data.lastPayment;
			delete [] root -> data.dateLast;

			root -> data = current -> data;

			if (prev == root)
				prev -> left = current -> left;

			else
				prev -> right = current -> left;

			delete current;

			return 1; // Return for success

		}

		else if (root -> left && !root -> right)
		{
			node* temp = root;

			root = root -> left;

			delete [] temp -> data.name;
			delete [] temp -> data.number;
			delete [] temp -> data.address;
			delete [] temp -> data.payment;
			delete [] temp -> data.lastPayment;
			delete [] temp -> data.dateLast;
			delete temp;

			return 1;
		}

		else if (root -> right && !root -> left)
		{
			node* temp = root;

			root = root -> right;

			delete [] temp -> data.name;
			delete [] temp -> data.number;
			delete [] temp -> data.address;
			delete [] temp -> data.payment;
			delete [] temp -> data.lastPayment;
			delete [] temp -> data.dateLast;
			delete temp;

			return 1;
		}

		else 
		{
			delete [] root -> data.name;
			delete [] root -> data.number;
			delete [] root -> data.address;
			delete [] root -> data.payment;
			delete [] root -> data.lastPayment;
			delete [] root -> data.dateLast;

			delete root;
			root = NULL;

			return 1;
		}
	}


		else if (strcmp(response, root -> data.name) < 0)
		{ // Go left
			return payBill(root -> left, response);
		}

		else
			return payBill(root -> right, response);
}

	


	

	


