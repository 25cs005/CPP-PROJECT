#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For formatting the output

using namespace std;

// Structure to store item details
struct Item {
    string name;
    int quantity;
    double price;
    double total;
};

int main() {
    // Project Header with your details from the list 
    cout << "-------------------------------------------" << endl;
    cout << "Student Name: CHODVADIYA AYUSHKUMAR RAKESHBHAI" << endl;
    cout << "Student ID: 25CS005" << endl;
    cout << "Project: Digital Bill Generator" << endl;
    cout << "-------------------------------------------" << endl << endl;

    vector<Item> billItems;
    char choice;
    double grandTotal = 0.0;

    cout << "--- Digital Sales & Invoice System ---" << endl;

    // Loop to add multiple items
    do {
        Item newItem;
        cout << "\nEnter Item Name: ";
        cin.ignore(); // Clear buffer
        getline(cin, newItem.name);
        
        cout << "Enter Quantity: ";
        cin >> newItem.quantity;
        
        cout << "Enter Unit Price: ";
        cin >> newItem.price;

        // Calculate total for this specific item
        newItem.total = newItem.quantity * newItem.price;
        
        // Add item to our list
        billItems.push_back(newItem);
        grandTotal += newItem.total;

        cout << "Add another item? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // --- Generate Formatted Receipt ---
    cout << "\n\n================ RECEIPT ================" << endl;
    cout << left << setw(15) << "Item" 
         << setw(10) << "Qty" 
         << setw(10) << "Price" 
         << setw(10) << "Total" << endl;
    cout << "-----------------------------------------" << endl;

    for (const auto& item : billItems) {
        cout << left << setw(15) << item.name 
             << setw(10) << item.quantity 
             << setw(10) << fixed << setprecision(2) << item.price 
             << setw(10) << item.total << endl;
    }

    cout << "-----------------------------------------" << endl;
    
    // Calculate a mock Tax (e.g., 5%)
    double tax = grandTotal * 0.05;
    double finalAmount = grandTotal + tax;

    cout << right << setw(35) << "Subtotal: " << fixed << setprecision(2) << grandTotal << endl;
    cout << right << setw(35) << "Tax (5%): " << tax << endl;
    cout << "=========================================" << endl;
    cout << right << setw(35) << "GRAND TOTAL: " << finalAmount << endl;
    cout << "=========================================" << endl;
    cout << "\nThank you for shopping with us!" << endl;

    return 0;
}