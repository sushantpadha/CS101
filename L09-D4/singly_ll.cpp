#include <iostream>
#include <string>
using namespace std;

// Structure to represent a Train Bogie
struct TrainBogie {
    string name;       // Name of the bogie
    TrainBogie *next;  // Pointer to the next bogie
};

// Function prototypes
TrainBogie *createBogie(const string &bogieName);
TrainBogie *insertAtBeginning(TrainBogie *head, const string &bogieName);
TrainBogie *insertAtEnd(TrainBogie *head, const string &bogieName);
TrainBogie *deleteAtBeginning(TrainBogie *head);
TrainBogie *deleteAtEnd(TrainBogie *head);
void searchAndAddAfter(TrainBogie *head, const string &existingBogieName,
                       const string &newBogieName);
void searchAndDelete(TrainBogie *head, const string &bogieName);
void printList(TrainBogie *head);
TrainBogie *deleteEntireList(TrainBogie *head);

int main() {
    int n;
    cin >> n;                    // Number of operations to perform
    TrainBogie *head = nullptr;  // Initialize head pointer to null

    for (int i = 0; i < n; ++i) {
        int operation;
        string bogieName1, bogieName2;
        cin >> operation;  // Read operation type

        // Perform operations based on user input
        if (operation == 1) {  // Insert at the Beginning
            cin >> bogieName1;
            head = insertAtBeginning(head, bogieName1);
        } else if (operation == 2) {  // Insert at the End
            cin >> bogieName1;
            head = insertAtEnd(head, bogieName1);
        } else if (operation == 3) {  // Delete at the Beginning
            head = deleteAtBeginning(head);
        } else if (operation == 4) {  // Delete at the End
            head = deleteAtEnd(head);
        } else if (operation == 5) {  // Search and Add After
            cin >> bogieName1 >> bogieName2;
            searchAndAddAfter(head, bogieName1, bogieName2);
        } else if (operation == 6) {  // Search and Delete
            cin >> bogieName1;
            searchAndDelete(head, bogieName1);
        } else if (operation == 7) {  // Print the Entire List
            printList(head);
        } else if (operation == 8) {  // Delete the Entire List
            head = deleteEntireList(head);
        }
    }

    return 0;  // End of program
}

// Function to create a new TrainBogie node
TrainBogie *createBogie(const string &bogieName) {
    TrainBogie *newBogie = new TrainBogie;  // Allocate memory for new bogie
    newBogie->name = bogieName;             // Set the bogie name
    newBogie->next = nullptr;               // Initialize next to null
    return newBogie;                        // Return the new bogie
}

// Function to insert a bogie at the beginning of the list
TrainBogie *insertAtBeginning(TrainBogie *head, const string &bogieName) {
    TrainBogie *newBogie = createBogie(bogieName);  // Create a new bogie
    newBogie->next = head;  // Point new bogie's next to current head
    return newBogie;        // Return new head
}

// Function to insert a bogie at the end of the list
TrainBogie *insertAtEnd(TrainBogie *head, const string &bogieName) {
    if (!head) {
        return createBogie(bogieName);
    }

    TrainBogie *temp = head;

    while (temp->next) temp = temp->next;

    TrainBogie *newBogie = createBogie(bogieName);

    temp->next = newBogie;

    return head;
}

// Function to delete a bogie at the beginning of the list
TrainBogie *deleteAtBeginning(TrainBogie *head) {
    if (!head) {
        cerr << "Train is empty!\n";
        return nullptr;
    }

    TrainBogie *temp = head;
    head = head->next;

    delete temp;

    return head;
}

// Function to delete a bogie at the end of the list
TrainBogie *deleteAtEnd(TrainBogie *head) {
    if (!head)
        return nullptr;  // If the list is empty, return null
    if (!head->next) {   // If there's only one bogie
        delete head;     // Delete the head
        return nullptr;  // List is now empty
    }
    TrainBogie *temp = head;    // Temporary pointer to traverse the list
    while (temp->next->next) {  // Traverse to the second-to-last bogie
        temp = temp->next;
    }
    delete temp->next;     // Delete the last bogie
    temp->next = nullptr;  // Set the next of second-to-last bogie to null
    return head;           // Return original head
}

// Function to search for a bogie and add a new bogie after it
void searchAndAddAfter(TrainBogie *head, const string &existingBogieName,
                       const string &newBogieName) {
    while (!head || head->next->name == existingBogieName) head = head->next;

    if (!head) {
        cerr << "Bogie with name '" << existingBogieName << "' was not found!\n";
        return;
    }

    TrainBogie *newBogie = createBogie(newBogieName);

    newBogie->next = head->next;
    head->next = newBogie;

    return;
}

// Function to search for a bogie and delete it
void searchAndDelete(TrainBogie *head, const string &bogieName) {
    if (!head)
        return;  // If the list is empty, exit

    if (head->name == bogieName) {       // If the head bogie matches
        head = deleteAtBeginning(head);  // Delete the head and update it
        return;                          // Exit after deletion
    }

    TrainBogie *temp = head;                  // Temporary pointer to traverse the list
    while (temp->next) {                      // Traverse the list
        if (temp->next->name == bogieName) {  // If the bogie to delete is found
            TrainBogie *toDelete = temp->next;  // Store the bogie to delete
            temp->next = temp->next->next;      // Link previous bogie to next bogie
            delete toDelete;                    // Delete the bogie
            return;                             // Exit after deletion
        }
        temp = temp->next;  // Move to the next bogie
    }
}

// Function to print the entire list
void printList(TrainBogie *head) {
    if (!head) {
        cout << "-1" << endl;  // Print -1 if the list is empty
        return;
    }
    TrainBogie *temp = head;  // Temporary pointer to traverse the list
    while (temp) {            // While there are bogies in the list
        cout << temp->name;   // Print the bogie name
        if (temp->next) {
            cout << " > ";  // Print separator if not the last bogie
        }
        temp = temp->next;  // Move to the next bogie
    }
    cout << endl;  // New line after printing the list
}

// Function to delete the entire list
TrainBogie *deleteEntireList(TrainBogie *head) {
    if (!head) {
        cerr << "Train is empty!\n";
        return nullptr;
    }

    TrainBogie *temp = nullptr;
    while (head->next) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return nullptr;
}
