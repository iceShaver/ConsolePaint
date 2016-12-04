#include "List.h"
#include <cstdlib>


Element::Element()
{
	Table = NULL;
	Previous = NULL;
	Next = NULL;
	Index = NULL;
}

void List::AddLast(short** tab)
{
	auto tmp = new Element();
	tmp->Index = counter;
	tmp->Table = tab;
	if (this->counter == 0)
	{
		initialized = true;
		tmp->Previous = NULL;
		tmp->Next = NULL;
		last = tmp;
		first = tmp;
	}
	else
	{
		tmp->Previous = last;
		tmp->Next = NULL;
	}
	last = tmp;
	counter++;
	//delete tmp;
}

void List::RemoveLast()
{
	Element* tmp = last->Previous;
	//delete last;
	last = tmp;
	last->Next = NULL;
	//delete tmp;
	counter--;
}

short** List::GetLast()
{
	short** tmp = this->last->Table;
	//RemoveLast();
	return tmp;

}

List::List()
{
	this->counter = 0;
	this->first = NULL;
	this->last = NULL;
	this->initialized = false;
}


List::~List()
{
}
