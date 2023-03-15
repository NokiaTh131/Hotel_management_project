#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Guest {
    string name;
    int roomNumber;
    int numNights;
    double roomRate;
    double advancePayment;
};

vector<Guest> guests;

void checkIn() {
    string name;
    int roomNumber;
    int numNights;
    double roomRate;
    double advancePayment;

    cout << "Enter guest name: ";
    getline(cin,name);
    cout << "Enter room number: ";
    cin >> roomNumber;
    cout << "Enter number of nights: ";
    cin >> numNights;
    cout << "Enter room rate: ";
    cin >> roomRate;
    cout << "Enter advance payment: ";
    cin >> advancePayment;

    guests.push_back({name, roomNumber, numNights, roomRate, advancePayment});

    cout << name << " has been checked in to room " << roomNumber << "." << endl;
}

void checkOut() {
    int roomNumber;
    bool found = false;

    cout << "Enter room number to check out: ";
    cin >> roomNumber;

    for (auto it = guests.begin(); it != guests.end(); ++it) {
        if (it->roomNumber == roomNumber) {
            cout << it->name << " has checked out of room " << roomNumber << "." << endl;

            double totalAmount = it->roomRate * it->numNights;
            double remainingAmount = totalAmount - it->advancePayment;
            if(remainingAmount <= 0){
                remainingAmount = 0;
                
            } 

            cout << "Total amount: " << totalAmount << endl;
            cout << "Advance payment: " << it->advancePayment << endl;
            cout << "Remaining amount: " << remainingAmount << endl;
            if(remainingAmount <= 0){
                double x = (-1)*(totalAmount - it->advancePayment);
                if(x==(-0)){
                    x = 0;
                }
                cout << "Return amount: " << x << endl;
            }

            guests.erase(it);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No guest found in room " << roomNumber << "." << endl;
    }
}

void displayGuests() {
    if (guests.empty()) {
        cout << "There are no guests currently checked in." << endl;
    } else {
        cout << "Guests currently checked in:" << endl;
        for (auto guest : guests) {
            cout << guest.name << " in room " << guest.roomNumber << endl;
        }
    }
}

void checkStatus() {
    int roomNumber;
    bool found = false;

    cout << "Enter room number to check status: ";
    cin >> roomNumber;

    for (auto guest : guests) {
        if (guest.roomNumber == roomNumber) {
            cout << guest.name << " is currently checked in to room " << roomNumber << "." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No guest found in room " << roomNumber << "." << endl;
    }
}

void searchGuest() {
    string name;
    bool found = false;

    cout << "Enter guest name to search: ";
    cin >> name;

    for (auto guest : guests) {
        if (guest.name == name) {
            cout << guest.name << " is currently checked in to room " << guest.roomNumber << "." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No guest found with name " << name << "." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Check in a guest" << endl;
        cout << "2. Check out a guest" << endl;
        cout << "3. Display guests currently checked in" << endl;
        cout << "4. Check guest status by room number" << endl;
        cout << "5. Check guest room number by guest name" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                checkIn();
                break;
            case 2:
                checkOut();
                break;
            case 3:
                displayGuests();
                break;
            case 4:
                checkStatus();
                break;
            case 5:
                searchGuest();
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}