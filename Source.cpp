#include<iostream>
#include<string>
using namespace std;
typedef struct
{
	int id;
}song;
typedef song* ptrsong;
typedef struct list_node_tag
{
	ptrsong Song;
	list_node_tag *next;
}list_node;
typedef struct
{
	list_node first;
	int count;
}list;

// Function defin
void initlist(list*);
void append(list*, song*);
list_node* sort(list_node*, int);

void main()
{
	list List;
	int numArr[5] = {0,69,428,86,-5};

	// init the list
	initlist(&List);

	// Insert arr to the list
	for (size_t i = 0; i < 5; i++)
	{
		song *temp = new song;
		temp->id = numArr[i];
		append(&List, temp);
	}

	// send to sort function the first place in the list
	List.first.next=sort((List.first.next),5);
	cout << "";

}

void initlist(list *ptrlist)
{
	ptrlist->first.next = NULL;
	ptrlist->first.Song = NULL;
	ptrlist->count = 0;
}

void append(list *ptrlist, song *Song)
{
	list_node *index;

	// insert the lest pleca in list to index
	for (index = &(ptrlist->first); index->next != NULL; index = index->next);
	
	// create new place in the list and insret to ther the struct 
	index->next = new list_node;

	// move the index to the new ptag in the list
	index = index->next;
	index->next = NULL;
	index->Song = Song;
	ptrlist->count++;
}

// recursion merge sort
list_node* sort(list_node *index, int len)
{
	list_node *midel = index;

	// Stop conditions
	if (len <= 1)
	{
		index->next = NULL;
		return(index);
	}

	// Run to the middle of the list
	for (size_t i = 0; i < len / 2; i++)
	{
		midel = midel->next;
	}

	//Cross the list recursion
	list_node *first = sort(index, len / 2);
	list_node *scond = sort(midel, len / 2 + (len % 2 != 0));
	list_node *Index;

	// Inserts to first the list where the first position is smaller 
	if (first->Song->id>scond->Song->id)
	{
		list_node *temp;
		temp = first;
		first = scond;
		scond = temp;
	}
	
	// Runs on the second list and puts the values in their proper place on the first list
	while (scond)
	{
		list_node *temp = first;

		// Puts into temp the pointer of largest place in the first list 
		// that is smaller than the number given in the second list
		while ((temp->next) && (temp->next->Song->id<scond->Song->id))
		{
			temp = temp->next;
		}

		Index = scond->next;
		scond->next = temp->next;
		temp->next = scond;
		scond = Index;

	}
	return (first);
}