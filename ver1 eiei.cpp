#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Guest {
    string name;
    int roomNumber;
};

vector<Guest> guests;

void checkIn() {
    string name;
    int roomNumber;
    cout << "Enter guest name: ";
    cin >> name;
    cout << "Enter room number: ";
    cin >> roomNumber;
    guests.push_back({name, roomNumber});
    cout << name << " has been checked in to room " << roomNumber << "." << endl;
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

int main() {
    int choice;
    do {
        cout << "1. Check in a guest" << endl;
        cout << "2. Display guests currently checked in" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkIn();
                break;
            case 2:
                displayGuests();
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}