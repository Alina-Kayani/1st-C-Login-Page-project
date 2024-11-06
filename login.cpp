#include<iostream>
#include<fstream>
using namespace std;

// Define a class 'temp' to handle user registration, login, and password retrieval
class temp {
    // Private member variables for storing user details and search queries
    string userName, Email, password;
    string searchName, searchPass, searchEmail;  // Variables for searching user data
    fstream file;

    public:
        // Functions for various operations
        void login();   // Login function
        void signUP();  // Sign-Up function
        void forgot();  // Forgot Password function
} obj; // Instantiate an object of class 'temp'

// Main function to display menu and handle user choice
int main() {
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice :: ";
    cin >> choice;

    // Switch-case to handle different options
    switch(choice) {
        case '1':
            cin.ignore(); // Ignore newline character left in buffer
            obj.login();  // Call login function
            break;
        case '2':
            cin.ignore();
            obj.signUP(); // Call sign-up function
            break;
        case '3':
            cin.ignore();
            obj.forgot(); // Call forgot password function
            break;
        case '4':
            return 0;     // Exit program
        default:
            cout << "Invalid Selection...!";
    }
}

// Sign-up function to register a new user
void temp::signUP() {
    cout << "\nEnter Your User Name :: ";
    getline(cin, userName);
    cout << "Enter Your Email Address :: ";
    getline(cin, Email);
    cout << "Enter Your Password :: ";
    getline(cin, password);

    // Open the file in append mode to add new user data
    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

// Login function to authenticate existing users
void temp::login() {
    cout << "----------LOGIN---------\n";
    cout << "Enter Your User Name :: ";
    getline(cin, searchName);
    cout << "Enter Your Password :: ";
    getline(cin, searchPass);

    // Open the file in read mode to verify login credentials
    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');

    // Check if entered credentials match any stored record
    while(!file.eof()) {
        if(userName == searchName) {
            if(password == searchPass) {
                cout << "\nAccount Login Successful...!";
                cout << "\nUsername :: " << userName << endl;
                cout << "\nEmail :: " << Email << endl;
                break;
            } else {
                cout << "Password is Incorrect...!";
                break;
            }
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    file.close();
}

// Forgot password function to retrieve user's password
void temp::forgot() {
    cout << "\nEnter Your UserName :: ";
    getline(cin, searchName);
    cout << "\nEnter Your Email Address :: ";
    getline(cin, searchEmail);

    // Open the file in read mode to search for the user's account
    file.open("loginData.txt", ios::in);
    getline(file, userName, '*');
    getline(file, Email, '*');
    getline(file, password, '\n');

    // Loop through file to find the account with matching username and email
    while(!file.eof()) {
        if(userName == searchName && Email == searchEmail) {
            cout << "\nAccount Found...!";
            cout << "Your Password :: " << password << endl;
            break;
        }
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
    }
    file.close();
}
