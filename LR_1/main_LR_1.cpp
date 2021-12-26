#include <iostream>
#include <fstream>
#include "Sup_f.h"

using namespace std;

int main()
{
	  setlocale(LC_ALL, "Russian");

	  cout << "LR_1 Касаткин Андрей. гр 0309. Вариант 9." << endl << endl;

	//variables
#pragma region variables
	List newList;
	List side_List;
	int i=0;
#pragma endregion

	//filling in the main list
	completion(newList,1);
	//checking for emptiness
	cout << "main list: ";
	if (newList.isEmpty() == true) cout << "Empty" << endl;
	else cout << "Not empty" << endl;
	cout << "List contents: " << endl;
	cout << newList;
	cout << "its size: ";
	cout << newList.size_t() << endl << endl;

	//adding to the end of the list
	newList.push_back("back");
	cout << "The contents of the list, after pasting to the end: " << endl;
	cout << newList << endl;

	//adding to the top of the list
	newList.push_front("front");
	cout << "The contents of the list, after pasting to the beginning: " << endl;
	cout << newList << endl;

	//deleting the last element
	newList.pop_back();
	cout << "The contents of the list, after deleting the last item: " << endl;
	cout << newList << endl;

	//deleting the first element
	newList.pop_front();
	cout << "The contents of the list, after deleting the first item: " << endl;
	cout << newList << endl;
	
	//adding an item by index
	newList.insert("mid", 10);
	cout << "The contents of the list, after insertion to the tenth position: " << endl;
	cout << newList << endl;

	//getting an item by index
	string tmp = newList.at(10);
	cout << "Contents of the tenth element: " << tmp << endl << endl;
	
	//deleting an item by index
    newList.remove(10);
	cout << "The contents of the list, after deleting the tenth element: " << endl;
	cout << newList << endl;

	//deleting an item by index
	newList.set("set",10);
	cout << "The contents of the list, after replacing the tenth element: " << endl;
	cout << newList << endl;

	//filling in the side list
	completion(side_List, 2);

	//checking for emptiness
	cout << "side list: ";
	if (side_List.isEmpty() == true) cout << "Empty" << endl;
	else cout << "Not empty" << endl;
	cout << "List contents: " << endl;
	cout << side_List;
	cout << "its size: ";
	cout << side_List.size_t()<< endl;

	newList.push_back("back");
	cout << "The contents of the list, after pasting to the end: " << endl;
	cout << newList << endl;
	
	i = newList.contains(side_List);
	if(i==0) cout << "There was no full entry";
	else cout << "The first full entry of the side list into the main one occurs in " << i << " element" << endl << endl;

	//deleting a list
    newList.clear();
	cout << "The contents of the list, after deleting it: " << endl;
	cout << newList << endl;
	side_List.~List();
	newList.~List();

}