#include <iostream>
using namespace std;

struct Node {
    int patientID;
    Node* next;
};

Node* createNode(int id) {
    Node* newNode = new Node;
    newNode->patientID = id;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int id) {
    Node* newNode = createNode(id);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Patient " << id << " added at the end.\n";
}

// Function to insert a node at the beginning (emergency)
void insertAtBeginning(Node*& head, int id) {
    Node* newNode = createNode(id);
    newNode->next = head;
    head = newNode;
    cout << "Patient " << id << " added at the beginning.\n";
}

// Function to display all nodes (patients)
void displayPatients(Node* head) {
    if (head == nullptr) {
        cout << "No patients currently.\n";
        return;
    }
    cout << "Current Patients: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->patientID << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Start with an empty list
    int choice, id;

    do {
        cout << "\n--- Hospital Patient Management ---\n";
        cout << "1. Add patient at end (regular check-in)\n";
        cout << "2. Add patient at beginning (emergency)\n";
        cout << "3. Display all patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                insertAtEnd(head, id);
                break;
            case 2:
                cout << "Enter Patient ID: ";
                cin >> id;
                insertAtBeginning(head, id);
                break;
            case 3:
                displayPatients(head);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 4);

    return 0;
}
