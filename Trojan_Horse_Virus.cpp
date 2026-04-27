#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void calculator() {
    double a, b;
    char op;
    cout << "=== Simple Calculator ===" << endl;
    cout << "Enter expression (e.g. 5 + 3): ";
    cin >> a >> op >> b;

    cout << "Result: ";
    if (op == '+') cout << a + b;
    else if (op == '-') cout << a - b;
    else if (op == '*') cout << a * b;
    else if (op == '/' && b != 0) cout << a / b;
    else cout << "Invalid operation";
    cout << endl;
}

void maliciousPayload() {
   
    ofstream logFile("trojan_payload.txt");
    if (logFile.is_open()) {
        logFile << "*** TROJAN HORSE SIMULATION ***\n";
        logFile << "This file was secretly created by the Trojan payload made by Mandip.\n";
        logFile.close();
    }

}

int main() {
    char again;

    do {
        cout << "Trojan Horse / Virus Simulation\n\n";
        calculator();

        maliciousPayload();

        cout << "\n A payload file 'trojan_payload.txt' was secretly created!\n";
        cout << "\nDo you want to continue? (y/n): ";
        cin >> again;
        cout << "\n";

    } while (again == 'y' || again == 'Y');

    cout << "----------------------------------\n";
    cout << "Lab No.: 19\n";
    cout << "Name: Mandip Shrestha\n";
    cout << "Roll No.: 20800625 (Section: 'A')\n";
    cout << "----------------------------------\n";

    return 0;
}
