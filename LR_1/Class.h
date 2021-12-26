#pragma once
#include <iostream>

using namespace std;

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
	void push_back(string);  //Adding to the end
	void push_front(string);
	void pop_back();
	void pop_front();
	void insert(string, int);
	string at(int);
	void remove(int);
	int size_t();  //Output List siz
	void clear();
	void set(string, int);
	bool isEmpty();  //Checking for emptiness
	friend ostream& operator<< (ostream& out, const List& new_List);

	//int find_first(List&); 
	bool contains(List&);
};

