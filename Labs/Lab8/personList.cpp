/**********************************
* Alexander Wise, 002907473
* Jason Lei, 002113242
**********************************/

#include <iostream>
#include <string>
using namespace std;

// Linked List Management Code
struct Person
{
	// Unique identifier for the person
	int id;
	// Information about person
	string name;
	int age;
	// Pointer to next person in list
	Person *next;
};

struct List
{
	// First person in the list. A value equal to NULL indicates that the
	// list is empty.
	Person *head;
	// Current person in the list. A value equal to NULL indicates a
	// past-the-end position.
	Person *current;
	// Pointer to the element appearing before 'current'. It can be NULL if
	// 'current' is NULL, or if 'current' is the first element in the list.
	Person *previous;
	// Number of persons in the list
	int count;
};

// Give an initial value to all the fields in the list.
void ListInitialize(List *list)
{
	list->head = NULL;
	list->current = NULL;
	list->previous = NULL;
	list->count = 0;
}
// Move the current position in the list one element forward. If last element
// is exceeded, the current position is set to a special past-the-end value.
void ListNext(List *list)
{
	if (list->current)
	{
		list->previous = list->current;
		list->current = list->current->next;
	}
}
// Move the current position to the first element in the list.
void ListHead(List *list)
{
	list->previous = NULL;
	list->current = list->head;
}
// Get the element at the current position, or NULL if the current position is
// past-the-end.
Person *ListGet(List *list)
{
	return list->current;
}
// Set the current position to the person with the given id. If no person
// exists with that id, the current position is set to past-the-end.
void ListFind(List *list, int id)
{
	ListHead(list);
	while (list->current && list->current->id != id)
		ListNext(list);
}
// Insert a person before the element at the current position in the list. If
// the current position is past-the-end, the person is inserted at the end of
// the list. The new person is made the new current element in the list.
void ListInsert(List *list, Person *person)
{
	// Set 'next' pointer of current element
	person->next = list->current;
	// Set 'next' pointer of previous element. Treat the special case where
	// the current element was the head of the list.
	if (list->current == list->head)
		list->head = person;
	else
		list->previous->next = person;
	// Set the current element to the new person
	list->current = person;
}
// Remove the current element in the list. The new current element will be the
// element that appeared right after the removed element.
void ListRemove(List *list)
{
	// Ignore if current element is past-the-end
	if (!list->current)
		return;
	// Remove element. Consider special case where the current element is
	// in the head of the list.
	if (list->current == list->head)
		list->head = list->current->next;
	else
		list->previous->next = list->current->next;
	// Free element, but save pointer to next element first.
	Person *next = list->current->next;
	delete list->current;
	// Set new current element
	list->current = next;
}
void PrintPerson(Person *person)
{
	cout << "Person with ID: " << person->id << endl;
	cout << "\tName: " << person->name << endl;
	cout << "\tAge: " << person->age << endl << endl;;
}

/** main function: Will create and process a linked list
 */
int main() {
	List list;				// Create the main list
	ListInitialize(&list);			// Initialize the list
//*************** PUT THE REST OF YOUR CODE HERE  *****************
	// Initiate variables
	bool exit = false;
	int id = 0;
	while(!exit){
		// Prompt user with menu for option selection
		int option;
		cout << "Select Option From Menu:\n\t1. Add a person\n\t2. Find a person\n\t3. Remove a person\n\t4. Print the list\n\t5. Exit" << endl;
		cin >> option;
		cout << "You selected ";

		// Switch statement to process option selection
		switch(option){
			case 1: 
				// Creates a new person and sets its id
        		Person *np;
        		np = new Person;
        		np->id = id;
        		id++;

				// Prompts user for age and name and then assigns values
				cout << "\"Add a person\"\n";
        		cout << "\nEnter name: ";
        		cin >> np->name;
        
       			cout << "Enter age: ";
        		cin >> np->age;

				// Sets pointer to the next person = NULL
        		np->next = NULL;
				// Updates pointers to the Persons that have been created
        		ListInsert(&list, np);

				break;
			case 2:
				int searchID;
				// Prompts user for the search ID
				cout << "\"Find a person\"\n";
			
				cout << "Enter person's ID: ";
				cin >> searchID;

				// Sets list->current = memory address of the ID's location
				ListFind(&list, searchID);
				// Returns an error if it doesn't exist
				if(ListGet(&list) == NULL) 
					cout << "Error. Invalid ID\n";
				else
					// Prints the person located at list-> current
					PrintPerson(ListGet(&list));
        
				break;
			case 3:
        		int removeID;
				// Prompts user for ID to search for
				cout << "\"Remove a person\"\n";

				cout << "Enter person's ID: ";
				cin >> removeID;
				
				// Works the same as the search function
				ListFind(&list, removeID);

				if(ListGet(&list) == NULL) 
					cout << "Error. Invalid ID\n";
				else
					// Calls the remove function to remove the Person at list->current
					ListRemove(&list);
				break;
			case 4:
				cout << "\"Print the list\"\n";
				// Sets current = head
				ListHead(&list);
				// Iterates through each item until it reaches current = NULL
				while(ListGet(&list) != NULL) {
					// Prints person at list->current
					PrintPerson(ListGet(&list));
					// Moves list->current to Person->next
					ListNext(&list);
				}
				// Resets current to the head
				ListHead(&list);
				break;
			case 5:
				// Breaks out of the loop when called
				cout << "\"Exit\"\n";
				exit = true;

				break;
			default:
				// Error if invalid input
				cout << "Error\nNot a valid selection\n";
				break;
		}
	}
} //end main
