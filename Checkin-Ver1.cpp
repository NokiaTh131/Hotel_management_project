#include <iostream>
#include <string>

using namespace std;

int main() {
    string name, checkinDate, checkoutDate;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your check-in date (YYYY-MM-DD): ";
    getline(cin, checkinDate);

    cout << "Enter your check-out date (YYYY-MM-DD): ";
    getline(cin, checkoutDate);

    cout << "Thank you, " << name << ". You have successfully checked in from " << checkinDate << " to " << checkoutDate << "." << endl;

    return 0;
}