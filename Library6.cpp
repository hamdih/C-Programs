// Hamdi Hmimy
// Dr Keathly
// 4/7/15
// This program will imitate a library database, with patrons that will have
// saved information and can check in and check out books
#include "class6.h" 
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	int x= 0;
	persons peeps;  		// initialize classes in main
	transactions trans;
	items library;

	string name;
	int pick;
	int id;
	string add;
	int num = 0;
	int choose = 0;
	cout<<endl;
	cout<<"Name: Hamdi Hmimy\tCourse: CSE 1040-Dr. Keathly\tDate: 4/16/2015"<<'\n';
	cout<<"\t\tProgram: Homework 5: C++\t"<<endl<<endl;
	while(num == 0)
	{
		cout<<"Welcome to the Smallville Library"<<'\n'; // menu options for the user to choose what to do
		cout<<"Here are options, please choose one"<<'\n';
		cout<<"1: Add a member"<<'\n';
		cout<<"2: Edit a members info"<<'\n';
		cout<<"3: Remove a member"<<'\n';
		cout<<"4: Print a list of members"<<'\n';
		cout<<"5: Print a list of all the members with fines"<<'\n';
		cout<<"6: Add a new item"<<'\n';	// opens different menu for type of items
		cout<<"7: Edit a item"<<'\n';		// opens different menu for type of items to edit
		cout<<"8: Remove a item"<<'\n';		// opens different menu for type of items to remove
		cout<<"9: Print lost items"<<'\n';	// opens different menu to print type of items
		cout<<"10: Member wants to burrow an item"<<'\n';	// open menu to choose which menu to burrow
		cout<<"11: Print members and burrowed items"<<'\n';	// open menu to print certain items
		cout<<"12: Member wants to return an item"<<'\n';	// open menu to return an item
		cout<<"13: Member wants to pay toward fees"<<'\n';	
		cout<<"14: Print all overdue items, and who has them"<<'\n';// open menu to choose which item are overdue to print
		cout<<"15: Print address mailing labels"<<'\n';
		cout<<"16: Save to Library database"<<'\n';
		cout<<"17: Load Library database"<<'\n';
		cout<<"18: Exit"<<endl;
		cin>>choose;

		switch(choose)					// switch statement to enter corresponding choice for the function
		{
			case 1: peeps.addperson(); 
				break;
			case 2: peeps.person_edit();
				break;
			case 3:	
				{
					int check = 0;// in main
					cout<<"Enter ID of person to remove: ";//before remove
					cin>> check;// inside main
					peeps.remove(peeps.top,check);
				}
				break;
			case 4: peeps.printList();
				break;   
			case 5:peeps.printFines();
			       break;
			case 6: 	
				cout<<"What kind of Item do you want to add:"<<endl;
				cout<<"1.Book"<<endl;
				cout<<"2.DVD"<<endl;
				cout<<"3.Reference"<<endl;
				cout<<"4.Book-Tape"<<endl;
				cin>>pick;
				switch(pick)
				{
					case 1:library.additem(1);
					break;
					case 2:library.additem(3);
					break;
					case 3:library.additem(2);
					break;
					case 4:library.additem(4);
					break;
				}
				//library.additem();
				break;

			case 7:library.item_edit();
			       break;
			case 8:
			       {
				       int check;
				       cout<<"Enter ID of book to remove: ";
				       cin>>check;
				       library.remove(library.top,check);
			       }
			       break;
			case 9:library.printLostItems();
			       break;
			case 10:trans.addtrans();
				break;
			case 11:
				{
					int check;
					cout<<"Enter ID of Member with books: ";
					cin>>check;
					trans.printTrans(check);
				}
				break;
			case 12:
				{
					int check;
					cout<<"Enter ID of member returning book: ";
					cin>>check;
					trans.return_item(trans.top,check);
				}
				break;
			case 13:

				{
					int check;
					cout<<"Enter ID of member paying fees: ";
					cin>>check;
					peeps.person_pay(check);	
				}
				break;
			case 14:trans.overdue();
				break;
			case 15:peeps.mailing();
				break;
			case 16:peeps.save();
				library.save();
				trans.save();
				break;
			case 17:load();
				break;
			case 18:num = 1;
				break;
		}
	}
	return 0;
}
