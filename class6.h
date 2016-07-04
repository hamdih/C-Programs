//Hamdi Hmimy
//Dr keathly
// 4/9/2015
// The classes for homework5 of the library database will be saved here
#include <iostream>
using namespace std;
void load(); 	// prototype function for load function
class person{		// information for individual person
	friend class persons;
	private:						
	string name;
	int person_id;
	string address;
	int phone_number;
	int fines;
	string status;
	person *next;
	public:


	person(string nm, int id, string add, int num,int fee, string st)
	{
		fines = fee;
		status = st;
		name = nm;
		person_id = id;
		address = add;
		phone_number = num;
	}

	// functions that return a memebrs information
	int getnum(){return phone_number;}
	string getName(){ return name;}
	int getID(){return person_id;}
	string getAdd(){return address;}
	int getfine(){return fines;}
	string getSt(){return status;}

	void setNext(person *n) {next = n;}				// pointers to link the linked list
	person *getNext() {return next;}
};

class persons{   // class to keep count of each person
	private:	
		int cnt;
	public:
		person *top;
		person *bottom;

		persons()
		{
			cnt = 0;
			top = bottom = NULL;
		}

		void save();				// functions of persons for person
		void person_pay(int id); 	
		void mailing();		
		void person_edit();
		void remove(person *x, int value);
		void addperson();
		void printList();
		void printFines();
};

class transaction{ // class to keep information for each transaction
	friend class transactions;
	private:
	int trans_id;
	int person_id;
	int item_id;		// change to item of the parent class
	string status;
	transaction *next;
	double beg_seconds;
	double end_seconds;
	public:

	transaction(int id,int pid,int tid,string st)
	{
		trans_id = id;
		person_id = pid;
		item_id = tid;
		status = st;
	}
	// functions to return information of a transaction
	string getST(){return status;}
	int getid(){return trans_id;}
	int getperson(){return person_id;}
	int getitem(){return item_id;}	


	// pointers to create the linked list
	void setNext(transaction *n) {next = n;}
	transaction *getNext(){return next;}
};

class transactions{ // class to keep track of transactions
	private:
		int tcnt;
	public:
		transaction* top;
		transaction* bottom;

		transactions()
		{ 
			tcnt = 0;
			top = bottom = NULL;
		}

		~transactions()
		{
			transaction *now = top;
			while(now!= bottom)
			{
				transaction * next = now->getNext();
				delete now;
				now = next;
			}
		}
		void overdue();
		void timer2();
		void timer();
		void save();						// functions of transactions for a transaction
		void return_item(transaction *x,int id);
		void printTrans(int id);
		void addtrans();
};

class item{ // class to keep information of individual books
	friend class items;			// becomes item parent class
	string item_name;
	int item_price;
	int item_id;
	string item_status;
	public:
	item *next;

	item(string nm,int pr, int id,string st)
	{
		item_name = nm;
		item_price = pr;
		item_id = id;
		item_status = st;
	}
	// functions to recieve information of a book
	string getName(){return item_name;}
	int getID() {return item_id;}
	int getPrice() {return item_price;}
	string getSt(){return item_status;}

	void setNext(item*n){next = n;}					// pointers to link the linked list of books
	item *getNext(){return next;}

};

class items{ // class to keep track of each book
	private:
		int bcnt;
	public:
		item *top;
		item *bottom;
		items()
		{
			bcnt = 0;
			top = bottom = NULL;
		}	
		virtual void save();							// functions for books
		virtual void item_edit();
		virtual void printLostItems();
		virtual void itemstatus(int id,string st);
		virtual void remove(item *x, int value);
		virtual void additem(int x);
};


// child functions of class item
class reference : public item
{	
	
	public: reference(string nm,int pr,int id,string st) : item(nm,pr,id,st)
	{}
	void additem();						//reference is a subclass of Item
};
class dvd : public item
{
	public: dvd(string nm,int pr,int id,string st) : item(nm,pr,id,st)
	{}
	void additem();						// dvd is child class of item class
};
class book : public item
{
	public: book(string nm,int pr,int id,string st) : item(nm,pr,id,st)
	{}
	void additem();						// book is child class of item class
};
class tape : public item
{
	public: tape(string nm,int pr,int id,string st) : item(nm,pr,id,st)
	{}
	void additem();						// tape is child class of item class
};



