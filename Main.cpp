// CS210 Project 3
// Travis Erwin
// Cemal Tepe
// 08/10/2025

#include <iostream> // for input and output
#include <string>	// for string manipulation
#include <map>		// for storing grocery items and their frequencies
#include <iomanip>  // for formatting output
#include <fstream>  // for file input/output
#include <algorithm>  // for transforming strings to lowercase
#include "GroceryItem.h" // for the GroceryItem class


using namespace std;

map<string, GroceryItem> groceryItemFrequencies; // Map to store grocery item names and their frequencies	


string tolowerCase(const string& str) {    // Function to convert a string to lowercase to keep it case insensitive for the user.
	string lower = str;						// copys the input string		
	transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return tolower(c); });  // Changes characters to lowercase
	return lower;							//returns a lowercase string
}
// Function to read grocery items from a file and populate the map
void ReadItemsFromFile(const string& filename) {
	ifstream file(filename);							//opens the file
	if (!file.is_open()) {								// error handler if file doesn't open
		cerr << "Error reading file: " << filename << endl;
		return;
	}

	string itemName;
	while (getline(file, itemName)) {		//reads each line from the txt file
		if (!itemName.empty()) {			// skips empty lines	
			string lookupKey = tolowerCase(itemName);	// reads lines as lowercase to help in case user inputs all lowercase.

			auto it = groceryItemFrequencies.find(lookupKey); // Checks if the item already exists
			if (it != groceryItemFrequencies.end()) {
				it->second.incrementQuantity();  // increments the quantity if it exists already on the list. 
			}
			else {
				groceryItemFrequencies[lookupKey] = GroceryItem(itemName);  // if its not on the list it adds the new grocery item to the list. 
			}
		}
	}
	file.close();  //closes the file
}


//this function prints the menu and reads the user input
int PrintMenu() {

	int choice = 0;
	cout << "\nCorner Grocer" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "1. Display frequency for a specific item" << endl;
	cout << "2. Display a list of all items and their frequencies" << endl;
	cout << "3. Display histogram of all  items" << endl;
	cout << "4. Exit Application" << endl;
	cout << "Please enter your selection as a number 1-4:" << endl;

	if (!(cin >> choice) || choice < 1 || choice > 4) { // Input validation, ensures the input is a number between 1 and 4
		cout << "Invalid input. Please enter a number between 1 and 4." << endl; 
		cin.clear();					//clears flags	
		cin.ignore(999999, '\n');		//discards invalid input
	}

	return (choice);  //returns valid choice
}

void SpecificItemFrequency() {				// This function prompts the user for an item and displays its frequency
	string searchItem;
	cout << "What item are you looking for? ";
	cin >> searchItem;						//reads user input for item they are searching for

	string lookupKey = tolowerCase(searchItem);  //converts to lowercase for looking up items

	auto it = groceryItemFrequencies.find(lookupKey); //searches through the map
	//if the searched item is found, displays its name as it appears in the txt file and its frequency
	if (it != groceryItemFrequencies.end()) {
		cout << it->second.getName() << " is on the list " << it->second.getQuantity() << " times" << endl;
	}
	// if its not found, prints a message to the user
	else {
		cout << "That item isn't on the list." << endl;
	}
}


void ListOfAllItemsAndFrequencies() {						// This function displays a list of all items and their frequencies
	cout << "All items and their frequencies" << endl;
	cout << "--------------------------------" << endl;
	cout << setw(20) << left << "Item" << setw(10) << "Frequency" << endl;
	cout << "--------------------------------" << endl;
	for (const auto& item : groceryItemFrequencies) {  // iterates through the map, prints the items and their counts.
		cout << setw(20) << left << item.second.getName() << setw(10) << item.second.getQuantity() << endl;
	}
}


void HistogramOfAllItems() {						// This function displays a histogram of all items
	cout << "Histogram of all items" << endl;
	cout << "--------------------------------" << endl;
	cout << setw(20) << left << "Item" << setw(10) << "Frequency" << endl;
	cout << "--------------------------------" << endl;
	for (const auto& item : groceryItemFrequencies) {   // iterates through the map
		cout << setw(20) << left << item.second.getName(); // prints the item name
		for (int i = 0; i < item.second.getQuantity(); ++i) {   // prints asterisks based on the frequency of the item
			cout << "*";
		}
		cout << endl;  // prints a new line after each item
	}
}

void WriteListToFile(const string& filename) {  // Function to write the list of items and their frequencies to a file
	ofstream file(filename);				// opens the file for writing
	if (!file.is_open()) {					// error handler if file doesn't open
		cerr << "Error writing to file: " << filename << endl;
		return;
	}
	for (const auto& item : groceryItemFrequencies) {  // iterates through the map and writes each item and its frequency to the file
		file << item.second.getName() << ": " << item.second.getQuantity() << endl;
	}
	file.close();  // closes the file
}

	

int main() {										//Main function to run the application
	ReadItemsFromFile("GroceryList.txt");			// uses the readitemsfromfile function to read from grocerylist.txt

	int choice;										// Variable to store user choice
	do {											// Loop until the user chooses to exit
		choice = PrintMenu();						// Prints the menu and gets user input
		switch (choice) {							// Switch case to handle user choices
		case 1:										// call to display frequency for a specific item
				SpecificItemFrequency();
				break;
			case 2:									// displays all items and their frequencies
				ListOfAllItemsAndFrequencies();
				break;
			case 3:									// displays histogram of all items
				HistogramOfAllItems();
				break;
			case 4:									// Exits the application
				cout << "Exiting application." << endl;
				WriteListToFile("frequency.dat"); // writes the list to frequency.dat before exiting
				break;
			default:								// Invalid choice
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 4);  // Loop until the user chooses to exit

	return 0;				// Returns 0 to indicate successful execution
}