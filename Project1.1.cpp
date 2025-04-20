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

void ChangeCustomerChoice() {
    int choice;  // Store user's input

    cin >> choice;  // Get user input

    // SECURITY VULNERABILITY: NO INPUT VALIDATION FOR CHOICE
    // THE PROGRAM ACCEPTS ANY INPUT WITHOUT CHECKING IF IT'S A VALID OPTION
    // THIS CAN CAUSE UNEXPECTED BEHAVIOR OR LOGIC ERRORS

    // Check the user's choice and store the same value back
    if (choice == 1) {
        choice = 1;  
    } 
    else if (choice == 2) {
        choice = 2;  
    } 
    else if (choice == 3) {
        choice = 3;  
    } 
    else if (choice == 4) {
        choice = 4;  
    } 
    else if (choice == 5) {
        choice = 5;  
    }
    // SECURITY VULNERABILITY: UNNECESSARY ASSIGNMENT
    // EACH "IF" STATEMENT JUST ASSIGNS THE SAME VALUE BACK TO CHOICE

    return;  // End function
}

void CheckUserPermissionAccess() {
    int permission = 0;  // Initialize permission level to 0

    // SECURITY VULNERABILITY: HARDCODED PERMISSION CHECK
    // THE PERMISSION VALUE IS ALWAYS 0 AT THE START, WHICH MEANS IT NEVER CHANGES
    // THIS MAKES THE PERMISSION CHECK USELESS AND MAY CREATE A SECURITY RISK

    // If permission is not 0, set it to 2; otherwise, set it to 1
    if (permission != 0) {  
        permission = 2;  
    } 
    else {
        permission = 1;  
    }
    // SECURITY VULNERABILITY: NO PROPER PERMISSION VALIDATION
    // THERE IS NO CHECK TO CONFIRM IF THE USER ACTUALLY HAS PERMISSION TO ACCESS THIS FUNCTION
    // THIS MEANS ANY USER CAN CALL THIS FUNCTION WITHOUT AUTHENTICATION

    return;  // Function ends here
}

void DisplayInfo() {
    int info;  // Stores the retrieved information

    info = GetInfo();  // Retrieve the data
    info = ProcessData(info);  // Process the retrieved data
    info = FormatData(info);  // Format the data for display
    info = DisplayData(info);  // Output the final formatted data

    // SECURITY VULNERABILITY: NO ERROR HANDLING FOR DATA RETRIEVAL
    // IF GetInfo() OR ANY OTHER FUNCTION RETURNS INVALID DATA, THE PROGRAM DOESN'T HANDLE IT
    // THIS CAN RESULT IN INCORRECT OR UNRELIABLE OUTPUT

    return;  // End the function
}

// *** Placeholder Functions ***
int GetInfo() {
    return 0;  // Placeholder return value

   // SECURITY VULNERABILITY: PLACEHOLDER FUNCTION DOES NOTHING
    // THIS FUNCTION IS EXPECTED TO RETRIEVE DATA, BUT IT ALWAYS RETURNS 0
    // IT SHOULD BE IMPLEMENTED PROPERLY OR REMOVED IF NOT USED 
}

int ProcessData(int info) {
    return info;  // Return the same value as a placeholder

    // SECURITY VULNERABILITY: PROCESSDATA FUNCTION DOESN'T ACTUALLY PROCESS ANYTHING
    // THIS FUNCTION JUST RETURNS THE INPUT WITHOUT MAKING CHANGES
    // IT SHOULD HAVE PROPER LOGIC TO PROCESS THE DATA AS EXPECTED
}

int FormatData(int info) {
    return info;  // Return the same value as a placeholder

    // SECURITY VULNERABILITY: FORMATTING FUNCTION DOESN'T ACTUALLY FORMAT
    // IT JUST RETURNS THE SAME DATA WITHOUT DOING ANY FORMATTING
    // THIS SHOULD HAVE LOGIC TO CONVERT DATA INTO A SPECIFIC FORMAT
}

int DisplayData(int info) {
    return info;  // Return the same value as a placeholder

    // SECURITY VULNERABILITY: DISPLAYDATA FUNCTION DOESN'T HANDLE ERRORS
    // IT JUST RETURNS THE SAME DATA WITHOUT CHECKING IF THE DATA IS VALID OR USEFUL
    // THERE SHOULD BE ERROR HANDLING TO PREVENT BAD OUTPUT
}