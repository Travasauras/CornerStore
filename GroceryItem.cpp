#include "GroceryItem.h"
using namespace std;

GroceryItem::GroceryItem() : name(""), quantity(0) {}		// Default constructor 

GroceryItem::GroceryItem(const string& name) {		// Constructor with name only
	this->name = name;
	this->quantity = 1;
}

GroceryItem::GroceryItem(const string& name, int quantity) {  // Constructor with name and quantity
	this->name = name;
	this->quantity = quantity;
}

string GroceryItem::getName() const {   // Returns the name of the grocery item
	return name;
}


int GroceryItem::getQuantity() const {		// Returns the quantity of the grocery item
	return quantity;
}

void GroceryItem::incrementQuantity() {		// Increments the count of the grocery item for the final list.
	++quantity;
}

bool GroceryItem::operator<(const GroceryItem& other) const {			// Overloaded less than operator for sorting
	return name < other.name;
}
