#include <iostream>

using namespace std;  

// Function declarations
void ChangeCustomerChoice();
void CheckUserPermissionAccess();
void DisplayInfo();
int GetInfo();  
int ProcessData(int info);  
int FormatData(int info);  
int DisplayData(int info);  

int main() {
    cout << "Created by Edgar Carrillo" << endl;  // Output statement

    int userChoice;

    while (true) {
        cout << "Enter a number: "; // SECURITY FIX: PROMPTS USER FOR INPUT
        
        if (!(cin >> userChoice)) { 
            // SECURITY VULNERABILITY: NO INPUT VALIDATION
            // THE PROGRAM DOESN'T CHECK IF THE USER ENTERS A NON-NUMBER, WHICH CAN CAUSE ERRORS
            // IF A USER TYPES LETTERS, THE PROGRAM MIGHT GET STUCK IN A LOOP OR CRASH

            // SECURITY FIX: PREVENTS NON-NUMERIC INPUT FROM BREAKING THE PROGRAM
            cout << "Invalid input! Please enter a number.\n";
            cin.clear(); // CLEAR ERROR FLAG
            cin.ignore(10000, '\n'); // DISCARD BAD INPUT
            continue;

            // ADDED cin.clear() TO REMOVE ERROR FLAGS AND cin.ignore() TO DISCARD INVALID INPUT.
            // THIS MAKES SURE THAT THE PROGRAM DOES NOT GET STUCK IN A LOOP IF THE USER ENTERS NON-NUMERIC INPUT.
        }

        // SECURITY VULNERABILITY: NO CHECK FOR INVALID NUMBERS
        // IF THE USER ENTERS A NUMBER THAT ISN'T 1, 2, 3, OR 0, NOTHING HAPPENS
        // THE PROGRAM SHOULD GIVE A WARNING OR PROMPT THE USER TO ENTER A VALID NUMBER

        // SECURITY FIX: CHECK FOR VALID NUMBER RANGE
        if (userChoice == 1) {
            ChangeCustomerChoice();
        } 
        else if (userChoice == 2) {
            CheckUserPermissionAccess();
        } 
        else if (userChoice == 3) {
            DisplayInfo();
        } 
        else if (userChoice == 0) {
            cout << "Exiting program.\n"; // SECURITY FIX: CONFIRM EXIT TO USER
            break;

            // ADDED A MESSAGE TO NOTIFY THE USER THAT THE PROGRAM IS EXITING.
            // THIS PROVIDES A CLEAR INDICATION THAT THE PROGRAM IS CLOSING AS INTENDED.
        } 
        else {
            // SECURITY FIX: HANDLE INVALID NUMBER INPUT
            cout << "Invalid choice! Please enter 1, 2, 3, or 0.\n";

            // ADDED A WARNING MESSAGE FOR INVALID INPUT.
            // THIS MAKES SURE THAT THE USER UNDERSTANDS THEY MUST ENTER A VALID CHOICE.
        }
    }

    return 0;
}


// Function: ChangeCustomerChoice
// Purpose: Prompts the user to select a customer option (1–5) and validates the input
void ChangeCustomerChoice() {
    int choice;

    // Prompt the user with clear instructions
    cout << "Select a customer option (1-5): ";

    // Validate input until it is a number between 1 and 5
    while (!(cin >> choice) || choice < 1 || choice > 5) {
        cout << "Invalid input! Please enter a number between 1 and 5.\n";
        cin.clear();               // Clear error flag
        cin.ignore(10000, '\n');   // Discard bad input
        cout << "Try again: ";
    }

    // Confirm the user selection
    cout << "You selected option " << choice << ".\n";
}

// Function: CheckUserPermissionAccess
// Purpose: Simulates a basic permission check by asking for a username and password
void CheckUserPermissionAccess() {
    string username;
    string password;

    // Ask for username and password input
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Check Credentials 
    if (username == "admin" && password == "pass123") {
        cout << "Access granted. Permission level: Admin\n";
    } else {
        cout << "Access denied. Invalid credentials.\n";
    }
}

// Function: DisplayInfo
// Purpose: Retrieves, processes, formats, and displays customer data
void DisplayInfo() {
    int info = GetInfo(); // Step 1: Get the customer ID

    if (info < 0) {
      // Handle the case where GetInfo() failed due to invalid input
        cout << "Error: Failed to retrieve valid data.\n";
        return;
    }

    int processed = ProcessData(info); // Step 2: Process the customer ID
    int formatted = FormatData(processed); // Step 3: Format the processed data

    // Step 4: Display the final result and handle errors
    if (DisplayData(formatted) == -1) {
        cout << "Error displaying data.\n";
    } else {
        cout << "Data displayed successfully.\n";
    }
}

// Function: GetInfo
// Purpose: Prompts the user to enter a customer ID and validates it
int GetInfo() {
    int data;
    cout << "Enter customer ID (positive number): ";
    cin >> data;

    // Validate input to ensure it's a positive number
    if (cin.fail() || data <= 0) {
        cin.clear();              //clear error flag
        cin.ignore(10000, '\n'); //Discard invalid input
        return -1;              // Return error signal
    }

    return data; // Return validated customer ID
}

// Function: ProcessData
// Purpose: Simulates processing logic by multiplying the ID
int ProcessData(int info) {
    
    return info * 10;  
}

// Function: FormatData
// Purpose: Simulates formatting logic by rounding to the nearest 100
int FormatData(int info) {
    // Round to nearest 100
    return (info + 50) / 100 * 100;
}

// Function: DisplayData
// Purpose: Displays the formatted customer data
int DisplayData(int info) {
    if (info < 0) {
        return -1;   // Signal error if data is invalid
    }

    // Output the final customer data
    cout << "Customer Data: " << info << endl;
    return 0;
}