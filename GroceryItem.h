#pragma once
#include <string>

class GroceryItem {
public:
	GroceryItem();											// Default constructor
	GroceryItem(const std::string& name);					// Constructor with name only
	GroceryItem(const std::string& name, int quantity);   // Constructor with name and quantity

	std::string getName() const; // Returns the name of the grocery item
	int getQuantity() const;		// Returns the quantity of the grocery item
	void incrementQuantity();



	bool operator<(const GroceryItem& other) const; // Overloaded less than operator for sorting

private:
	std::string name; // Name of the grocery item
	int quantity;		// Quantity of the grocery item, default is 1	
};

