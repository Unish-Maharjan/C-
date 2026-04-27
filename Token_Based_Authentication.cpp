#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

const string STORED_USER = "mandip";
const string STORED_PASS = "pass123";

string generateToken(const string &username) {
    srand(time(0));
    ostringstream oss;
    oss << username << "_";
    for (int i = 0; i < 16; i++)
        oss << hex << setw(1) << (rand() % 16);
    return oss.str();
}

int main() {
    cout << "=== Token-Based Authentication System ===\n\n";

    string username, password;
    string sessionToken = "";

    // Login Phase
    cout << "--- Login ---\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == STORED_USER && password == STORED_PASS) {
        sessionToken = generateToken(username);
        cout << "\n[LOGIN SUCCESS]\n";
        cout << "Session Token Issued: " << sessionToken << "\n";
    } else {
        cout << "\n[LOGIN FAILED] Invalid credentials. No token issued.\n";
        return 1;
    }


    cout << "\n--- Token Verification ---\n";
    cout << "Enter token to access protected resource: ";
    string inputToken;
    cin >> inputToken;

    if (inputToken == sessionToken) {
        cout << "\n[TOKEN VALID] Access GRANTED to protected resource.\n";
        cout << "Welcome, " << username << "! Here is your protected data.\n";
    } else {
        cout << "\n[TOKEN INVALID] Access DENIED.\n";
    }

    cout << "\n----------------------------------\n";
    cout << "Lab No.: 24\n";
    cout << "Name: Mandip Shrestha\n";
    cout << "Roll No.: 20800625 (Section: 'A')\n";
    cout << "----------------------------------\n";

    return 0;
}
