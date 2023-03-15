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
    cin >> name;
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

            cout << "Total amount: " << totalAmount << endl;
            cout << "Advance payment: " << it->advancePayment << endl;
            cout << "Remaining amount: " << remainingAmount << endl;

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

int main() {
    int choice;

    do {
        cout << "1. Check in a guest" << endl;
        cout << "2. Check out a guest" << endl;
        cout << "3. Display guests currently checked in" << endl;
        cout << "4. Check guest status by room number" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}