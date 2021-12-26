#include "pch.h"
#include "CppUnitTest.h"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class Node
{
private:
	string data;
	Node* next;

public:
	Node(string initdata)
	{
		data = initdata;
		next = NULL;
	}

	string getData()
	{
		return data;
	}

	Node* getNext() { return next; }

	void SetData(string newData)
	{
		data = newData;
	}

	void setNext(Node* newnext) { next = newnext; }

};

class List
{
private:
	Node* head;

public:
	List();
	~List();
	void push_back(string);
	void push_front(string);
	void pop_back();
	void pop_front();
	void insert(string, int);
	string at(int);
	void remove(int);
	int size_t();
	void clear();
	void set(string, int);
	bool isEmpty();
	friend ostream& operator<< (ostream& out, const List& new_List);

	//int find_first(List&);
	bool contains(List&);
};

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
	Node* current = head; int i = 1;
	while (current->getNext() != NULL)
	{
		if (i + 1 == index) break;
		i++;
		current = current->getNext();
	}
	Node* temp = new Node(item);
	temp->setNext(current->getNext());

	current->setNext(temp);
	current = temp;
}

string List::at(int index)
{
	Node* current = head;
	int i = 1;
	while (i != index)
	{
		current = current->getNext();
		i++;
	}
	return current->getData();
}

void List::remove(int index)
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
		}
		i++;
	}
	if (previous == NULL) head = current->getNext();
	else previous->setNext(current->getNext());
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


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(test_isEmpty)
		{
			List test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");

			Assert::IsTrue(test.isEmpty() == false);
		}

		TEST_METHOD(test_push_back)
		{
			List test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");

			test.push_back("back");

			Assert::IsTrue(test.at(4) == "back");
		}

		TEST_METHOD(test_pop_front)
		{
			List test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");

			test.pop_front();

			Assert::IsTrue(test.at(1) == "second");
		}

		TEST_METHOD(test_pop_back)
		{
			List test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");

			test.pop_back();

			Assert::IsTrue(test.size_t() == 2);
		}

		TEST_METHOD(test_insert)
		{
			List test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");

			test.insert("mid", 2);

			Assert::IsTrue(test.at(2) == "mid");
		}

		TEST_METHOD(test_remove)
		{
			List test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");

			test.remove(2);

			Assert::IsTrue(test.at(2) == "first");
		}

		TEST_METHOD(test_set)
		{
			List test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");

			test.set("fifth", 3);

			Assert::IsTrue(test.at(3) == "fifth");
		}

		TEST_METHOD(test_clear)
		{
			List test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");

			test.clear();

			Assert::IsTrue(test.isEmpty() == true);
		}

		TEST_METHOD(test_contains)
		{
			List test, tmp_test; int a = 0;
			test.push_front("first");
			test.push_front("second");
			test.push_front("first");
			test.push_front("second");
			test.push_front("third");
			test.push_front("fifth");

			tmp_test.push_front("first");
			tmp_test.push_front("second");
			tmp_test.push_front("third");

			Assert::IsTrue(test.contains(tmp_test) == true);
		}
	};
}
