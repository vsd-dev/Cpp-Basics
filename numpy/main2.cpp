#include <iostream>
#include <list>
using namespace std;

//function to display the list
void dispList(list<int> L)
{
	//declaring iterator to the list
	list<int>::iterator l_iter;
	for (l_iter = L.begin(); l_iter != L.end(); l_iter++)
		cout<< *l_iter<< " ";
	cout<<endl;
}

int main()
{
	//list1 declaration
	list<int> list1;
	//array declaration
	int arr[]={10, 20, 30, 40, 50};

	//displaying list1
	cout<<"Before assign... "<<endl;
	cout<<"Size of list1: "<<list1.size()<<endl;
	cout<<"Elements of list1: ";
	dispList(list1);

	//assigning array Elements to the list
	list1.assign(arr+0, arr+5);

	//displaying list1
	cout<<"After assigning... "<<endl;
	cout<<"Size of list1: "<<list1.size()<<endl;
	cout<<"Elements of list1: ";
	dispList(list1);

	return 0;
}