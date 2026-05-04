#include <iostream>
#include <string>
#include <cctype>
using namespace std;

unsigned long simpleHash(const string &s) {
    unsigned long hash = 5381;
    for (char c : s)
        hash = ((hash << 5) + hash) + (unsigned char)c;
    return hash;
}

const string STORED_USER = "Unish";
unsigned long storedHash = 0;

bool isStrongPassword(const string &pass) {
    if (pass.length() < 8) return false;
    bool hasUpper=false, hasLower=false, hasDigit=false, hasSpecial=false;
    for (char c : pass) {
        if (isupper(c))   hasUpper = true;
        if (islower(c))   hasLower = true;
        if (isdigit(c))   hasDigit = true;
        if (ispunct(c))   hasSpecial = true;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

void registerUser() {
    char again;
    do {
        cout << "\n--- Register ---\n";
        string pass;
        cout << "Set password for user '" << STORED_USER << "': ";
        cin >> pass;

        if (!isStrongPassword(pass)) {
            cout << "[!] Weak password! Must be 8+ chars with upper, lower, digit, and special char.\n";
            cout << "Try again? (y/n): ";
            cin >> again;
            cout << "\n";
        } else {
            storedHash = simpleHash(pass);
            cout << "[Registration SUCCESS] Password stored as hash: " << storedHash << "\n";
            again = 'n';
        }
    } while (again == 'y' || again == 'Y');
}

void loginUser() {
    if (storedHash == 0) {
        cout << "\n[!] No registered user. Please register first.\n";
        return;
    }

    cout << "\n--- Login ---\n";
    string username, password;
    int maxAttempts = 3;

    for (int attempt = 1; attempt <= maxAttempts; attempt++) {
        cout << "Attempt " << attempt << "/" << maxAttempts << "\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == STORED_USER && simpleHash(password) == storedHash) {
            cout << "\n[LOGIN SUCCESS] Welcome, " << username << "!\n";
            return;
        } else {
            cout << "[FAILED] Incorrect username or password.\n\n";
        }
    }
    cout << "\n[LOCKOUT] Too many failed attempts.\n";
}

int main() {
    cout << "=== Password-Based Authentication System ===\n\n";

    int choice;

    do {
        cout << "1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice;
        cout << "\n";

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n";

    } while (choice != 3);



    return 0;
}