// Hamdi hmimy
//Dr keathly
// 4/11/2015
// This file will hold the functions for the Smallville Library system
#include "class6.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;

void transactions:: overdue()			// function to print out people with overdue books
{
	class transaction* temp1 = top;
	while(temp1 != NULL)
	{

		if(temp1->beg_seconds < temp1->end_seconds)
		{
			cout<<temp1->getperson()<< "Items are overdue"<<endl;
		} 	
		temp1 = temp1->getNext();
	}

}


void transactions:: timer2()
{
	class transaction *temp1;
	time_t end;
	temp1->end_seconds = time(&end);



}

void transactions::timer() 
{
	class transaction *temp1;
	time_t start;
	temp1->beg_seconds = time(&start); 
}



void load()			// load function for the saved library
{
	string read;
	ifstream myFile("LIBRARY.txt");
	if(myFile.is_open())
	{
		while(getline(myFile,read))
		{
			cout<<read<<'\n';
		}
		myFile.close();
	}
	else cout<<"Cant open file"<<endl;

}


void persons::save()				// save file for persons information
{
	ofstream myFile;
	myFile.open("library.txt");
	class person *temp1 =  top;
	while(temp1 != NULL)
	{
		myFile<<temp1->getnum()<<temp1->getName()<<temp1->getID();
		myFile<<temp1->getAdd()<<temp1->getfine();
		temp1 = temp1->getNext();
	}

	myFile.close();
}

void items::save()				// save function for books information
{
	ofstream myFile;
	myFile.open("library.txt");
	class item *temp1 = top;
	while(temp1 != NULL)
	{
		myFile<<temp1->getName()<<temp1->getID()<<temp1->getPrice()<<temp1->getSt();
		temp1 = temp1->getNext();
	}

	myFile.close();
}

void transactions::save()		// save function for transactions information
{
	ofstream myFile;
	myFile.open("library.txt");
	class transaction *temp1 = top;
	while(temp1 != NULL)
	{
		myFile<<temp1->getST()<<temp1->getid()<<temp1->getperson()<<temp1->getitem();
		temp1 = temp1->getNext();
	}

	myFile.close();
}




void persons::person_pay(int id)		// function to allow a member to pay for his/her fines
{
	int pay;
	class person* temp1 = top;
	while(temp1 != NULL)
	{
		if(temp1->getID() == id)
		{
			cout<<"How much would you like to pay to your fees: ";
			cin>> pay;
			temp1->fines= pay - temp1->getfine();
		}
		temp1 = temp1->getNext();
	}

}
void persons::person_edit()			// this function allows the user to edit a members information and add his/her fees/standing
{

	int id,pay = 0,fee,num,check;
	string nm,add,st;
	class person* temp1 = top;
	cout<<"Enter ID of person to Edit: ";
	cin>>check;

	if(temp1->getID() == check){
		cout<<"Enter a new name: ";
		cin.ignore();
		getline(cin,nm);
		cout<<"Enter a new address: ";
		getline(cin,add);
		cout<<"Enter a new ID: ";
		cin>>id;
		cout<<"Enter any fees: ";
		cin>>fee;
		cout<<"Enter a new Phone number: ";
		cin>>num;
		cout<<"Enter the new status of this person: ";
		cin>>st;
		cout<<"Payment for fees?: ";
		cin>>pay;
		temp1->name = nm;
		temp1->person_id = id;
		temp1->address = add;
		temp1->phone_number = num;
		temp1->status = st;
		if(pay > 0)
		{
			temp1->fines= pay - fee;
		}
		else
			temp1->fines = fee;
	}
	temp1 = temp1->getNext();
}




void persons::remove(person *x, int value)		// this function will check each node and delete a member with the corresponding ID
{

	if(x->getID() == value)
	{
		if(x == top)
		{
			top = x->getNext();
			delete x; 		
		}
		else if((x->getNext()->getID()) == value)
		{
			x->getNext() == x->getNext()->getNext();
			delete x;
		}

	}
	else
	{
		remove(x->next,value);
	}
}

void persons::addperson()     // this function will create a linked list of members for the library with input information
{
	string nm,add,st;
	cout<< now->getName();
	int id,num,fee = 0, i = 0;
	person *temp, *temp2;
	temp2 = top;

	cout<<"Enter Members name: ";
	cin.ignore();
	getline(cin,nm);
	cout<<"Enter Members ID: ";
	cin >> id;
	cout<<"Enter Members address: ";
	cin.ignore();
	getline(cin,add);
	cout<<"Enter Members Number: ";
	cin>> num; 
	st = "Good Standing";
	temp = new person(nm,id,add,num,fee,st);
	if( cnt == 0)
	{
		top = bottom = temp;
		temp->setNext(NULL);
		cnt++;
	}

	else
	{		
		bottom->setNext(temp);
		bottom = temp;
		temp->setNext(NULL);
		cnt++;
	}

}

void persons::mailing()     // this function will print out each members mailing address
{
	person *now = top;
	while(now!= NULL)
	{
		cout<<"Member "<<now->getID()<<" mailing address is "<<now->getAdd()<<endl;
		now = now->getNext();
	}

}
void persons::printList()		// this function will print out all the information of ever member
{
	person *now = top;
	while(now!= NULL)
	{
		cout<< "Members Name: " <<now->getName() <<endl;
		cout<< "Members ID: " <<now->getID() <<endl;
		cout<< "Members Address: "<<now->getAdd() << endl;
		cout<< "Members Phone Number: " << now->getnum()<<endl;
		cout<< "Members Fines: " << now->getfine()<<endl;
		cout<< "Members Standing: " <<now->getSt()<<endl<<endl;
		now = now->getNext();
	}
}

void persons::printFines()     // this function will print out all members that have fees
{
	person *now = top;
	while(now != NULL)
	{
		if(now->getfine() > 0)
		{
			cout<< "Person Name: " <<now->getName() <<endl;
			cout<< "Person ID: " <<now->getID() <<endl;
			cout<< "Person Address: "<<now->getAdd() << endl;
			cout<< "Person Phone Number: " << now->getnum()<<endl;
			cout<< "Fine Amount: "<<now->getfine()<<endl<<endl;
		}	
		now = now->getNext();
	}

}
void transactions::printTrans(int id)     // this function will print out which member ID has which Book
{
	transaction *now = top;
	while(now!= NULL)
	{
		if(id == now->person_id)
		{
			cout<<"Member "<< now->getperson();
			cout<< " is burrowing item " << now->getitem() <<endl;
		}
		now = now->getNext();
	}



}	
void transactions:: return_item(transaction *x,int id)   // this function will allow a member to return a book and end there transaction
{
	timer2();       // timer function to create a time stamp
	if(x->getperson() == id)
	{
		if(x == top)
		{
			top = x->getNext();
			delete x; 		
		}
		else if((x->getNext()->getperson()) == id)
		{
			x->getNext() == x->getNext()->getNext();
			delete x;
		}

	}
	else
	{
		return_item(x->next,id);
	}

}

void transactions::addtrans()     // this function allows a member to burrow a book as a transaction with the library
{	
	//timer();
	string st;
	int id,pid,tid, i = 0;
	transaction *temp, *temp2;
	temp2 = top;
	cout<<"Enter Transaction ID: ";
	cin>> id;
	cout<<"Enter Item ID: ";
	cin>>tid;
	cout<<"Enter Burrower ID: ";
	cin>>pid;
	st = "burrowed";


	temp = new transaction(id,pid,tid,st);
	if(tcnt == 0)
	{
		top = bottom = temp;
		bottom = temp;
		temp->setNext(NULL);
		tcnt++;
	}
	else
	{
		bottom->setNext(temp);
		bottom = temp;
		temp->setNext(NULL);
		tcnt++;
	}

}

void items::printLostItems()   // this function will print all books lost
{
	item *now = top;
	while(now!= NULL)
	{
		cout<< "Item Name: " <<now->getName() <<endl;
		cout<< "Item ID: " <<now->getID() <<endl;
		cout<< "Status" << now->getSt() <<endl<<endl;
		now = now->getNext();
	}


}

void items::itemstatus(int id,string st)   // this function initializes the books status
{
	item *now = top;						
	while(now!= NULL)
	{
		if(now->item_id == id)
		{	
			if(st == "burrowed")
				now->item_status = "burrowed";
			else if( st == "lost")
				now->item_status = "lost";
			else if(st == "available")
				now->item_status = "available";
		}
	}
}

void items::item_edit()		// this function allows for books to be edited by the user
{

	int check,id,pr;
	string nm,st;
	class item* temp1 = top;
	cout<<"Enter ID of Item to Edit: ";
	cin>>check;

	if(temp1->getID() == check){

		cout<<"Enter a new name: ";
		cin.ignore();
		getline(cin,nm);
		cout<<"Enter a new ID: ";
		cin>>id;
		cout<<"Enter a new Price: ";
		cin>>pr;
		cout<<"Is the book lost,available, or burrowed?: ";
		cin>>st;
		temp1->item_name = nm;
		temp1->item_id = id;
		temp1->item_price = pr;
		temp1->item_status = st;
	}
	temp1 = temp1->getNext();
}


void items::remove(item *x, int value)    // this function allows the user to remove a book from the library
{
	if(x->item_id == value)
	{
		if(x == top)
		{
			top = x->next;
			delete x; 		
		}
		else if((x->getNext()->getID()) == value)
		{
			x->getNext() == x->getNext()->getNext();
			delete x;
		}

	}
	else
	{
		remove(x->next,value);
	}
}



void items::additem(int x)   // this function allows the user to add a book with its information
{
	
	string nm, st, type;
	int id, pr, i = 0;
	item *temp, *temp2;
	temp2 = top;
	st = "available";						// change function to add different item types
	cout <<"Enter name: ";
	cin.ignore();
	getline(cin,nm);
	cout<< "Enter ID: ";
	cin>>id;
	cout<<"Enter price: ";
	cin>>pr;
	if(x == 1)
	temp = new book(nm,pr,id,st);
	else if(x ==2)
	temp = new reference(nm,pr,id,st);
	else if(x== 3)
	temp = new dvd(nm,pr,id,st);
	else if(x == 4)
	temp = new tape(nm,pr,id,st);
	if (bcnt == 0)
	{ 
		top = bottom = temp;
		temp->setNext(NULL);
		bcnt++;
	}
	else
	{
		bottom->setNext(temp);
		bottom = temp;
		temp->setNext(NULL);
		bcnt++;
	}

}
