#include <iostream>
#include <string>
using namespace std;

struct student {
	int id;
	string name;
	int age;
	student *next;
};

student *head = NULL; // Declare head globally

student *createNode() {
	student *st = new student;
	cout << "Enter student name:\n";
	cin >> st->name;
	cout << "Enter age: ";
	cin >> st->age;
	cout << "Enter ID: ";
	cin >> st->id;
	st->next = NULL;

	return st;
}

void insert_atfrist() {
	student *st = createNode();
	if (head == NULL)
		head = st;
	else {
		st->next = head;
		head = st;
	}
}

void insert_last() {
	student *st = createNode();
	if (head == NULL)
		head = st;
	else if (head->next == NULL)
		head->next = st;
	else {
		student *temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = st;
	}
}

void deletefrist() {
	if (head == NULL)
		cout << "No data found to delete!\n";
	else {
		student *temp = head;
		head = head->next;
		cout << "Successfully deleted!\n";
		delete temp;
	}
}

void delete_end() {
	if (head == NULL)
		cout << "No data to be deleted!\n";
	else if (head->next == NULL) {
		delete head;
		head = NULL;
	} else {
		student *temp = head, *t2;
		while (temp->next != NULL) {
			t2 = temp;
			temp = temp->next;
		}
		t2->next = NULL;
		delete temp;
	}
}

void disply() {
	if (head == NULL)
		cout << "No data available!\n";
	else {
		student *temp = head;
		while (temp != NULL) {
			cout << "Name: " << temp->name << endl;
			cout << "ID: " << temp->id << endl;
			cout << "Age: " << temp->age << endl;
			temp = temp->next;
		}
	}
}

int main() {
	int choice;

	do {
		cout << "\n1: Display\n";
		cout << "2: Insert at first\n";
		cout << "3: Insert at last\n";
		cout << "4: Delete at first\n";
		cout << "5: Delete at last\n";
		cout << "6: Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				disply();
				break;
			case 2:
				insert_atfrist();
				break;
			case 3:
				insert_last();
				break;
			case 4:
				deletefrist();
				break;
			case 5:
				delete_end();
				break;
			case 6:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice!\n";
		}
	} while (choice != 6);

	return 0;
}