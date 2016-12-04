#pragma once
class Element
{
private:

public:
	Element getPrevious();
	Element getNext();
	short ** Table;
	Element* Previous;
	Element* Next;
	int Index;
	Element();

};

class List
{
public:
	void AddLast(short** tab);
	void AddFirst();
	void RemoveLast();
	void RemoveFirst();
	short ** GetLast();
	short ** GetFirst();
	List();
	~List();
private:
	int counter;
	Element* last;
	Element* first;
	bool initialized;

};
