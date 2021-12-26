#include "Class.h"
#pragma region functions
List::List()
{
	head = NULL;
}

List::~List()
{
	if (head != NULL)
		while (head != NULL)
		{
			Node* next = head->getNext();
			delete head;
			head = next;
		}
}

void List::push_back(string item)
{
	Node* current = head;
	while (current->getNext() != NULL)
	{
		current = current->getNext();
	}

	Node* temp = new Node(item);
	current->setNext(temp);
	current = temp;
}

void List::push_front(string item)
{
	Node* temp = new Node(item);
	temp->setNext(head);
	head = temp;
}

void List::pop_back()
{
	Node* current = head;
	Node* previous = NULL;
	while (current->getNext() != NULL)
	{
		previous = current;
		current = current->getNext();
	}
	previous->setNext(current->getNext());
}

void List::pop_front()
{
	Node* current = head;
	head = current->getNext();
}

void List::insert(string item, int index)
{
	if (index < 0) { cout << "Incorrect index" << endl; }
	else
	{
		Node* current = head; int i = 1;
		while (current->getNext() != NULL)
		{
			if (i + 1 == index) break;
			i++;
			current = current->getNext();
		}
		if (i + 1 != index) { cout << "Insertion at the end, since the specified index is larger than the actual size of the list"; }
		Node* temp = new Node(item);
		temp->setNext(current->getNext());

		current->setNext(temp);
		current = temp;
	}
}

string List::at(int index)
{
	if (index < 0) { cout << "output of the first element" << endl; return head->getData(); }
	else
	{
		Node* current = head;
		int i = 1;
		while (i != index)
		{
			current = current->getNext();
			i++;
			if (current->getNext() == NULL) { cout << "Output of the last element " << endl; break; }
		}
		return current->getData();
	}
}

void List::remove(int index)
{
	if (index < 0) { cout << "Incorrect index" << endl; }
	else
	{
		Node* current = head; int i = 1;
		Node* previous = NULL;
		bool found = false;
		while (!found)
		{
			if (i == index) found = true;
			else
			{
				previous = current;
				current = current->getNext();
				if (current->getNext() == NULL) { cout << "deleting the last element" << endl; break; }
			}
			i++;
		}
		if (previous == NULL) head = current->getNext();
		else previous->setNext(current->getNext());
	}
}

int List::size_t()
{
	Node* current = head;
	int count = 0;

	while (current != NULL)
	{
		count++;
		current = current->getNext();
	}

	return count;
}

void List::clear()
{
	Node* current;
	while (head != NULL)
	{
		current = head->getNext();
		delete head;
		head = current;
	}
}

void List::set(string item, int index)
{
	if (index < 0) { cout << "Incorrect index" << endl; }
	else
	{
		Node* current = head; int i = 1;
		Node* previous = NULL;
		bool found = false;
		while (!found)
		{
			if (i == index) found = true;
			else
			{
				previous = current;
				current = current->getNext();
				if (current->getNext() == NULL) { cout << "replacing the last element" << endl; break; }
			}
			i++;
		}
		if (previous == NULL) head = current->getNext();
		else previous->setNext(current->getNext());

		Node* temp = new Node(item);
		temp->setNext(previous->getNext());

		previous->setNext(temp);
		previous = temp;
	}
}

bool List::isEmpty() { return head == NULL; }

ostream& operator<< (ostream& out, const List& list)
{
	Node* current = list.head;
	int i = 1;
	if (current == NULL)
	{
		out << "List is Empty!\n";
		return(out);
	}
	else
	{
		while (current != NULL)
		{
			out << i++ << ")" << current->getData() << " ";
			current = current->getNext();
		}
		out << " \n";
		return(out);
	}
}

bool List::contains(List& side_list)
{
	Node* current = head; int i = 1; int entry_count;
	int index = side_list.size_t();
	bool entry = false, complete_passage = false;
	while (current != NULL)
	{
		if (current->getData() == side_list.at(1))
		{
			entry = true;
			entry_count = i;
			current = current->getNext();
			if (current->getNext() == NULL) break;
			i++;
			int j = 2;
			while (j < index)
			{
				if (current->getData() == side_list.at(j)) complete_passage = true;
				else { complete_passage = false; }
				current = current->getNext();
				i++; j++;
				if (current->getNext() == NULL) break;
			}
			if (entry == true && complete_passage == true)
			{
               break;
			}
		}
		else
		{
			current = current->getNext(); i++;
		}
	}
	return complete_passage;
}

#pragma endregion

