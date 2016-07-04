//hamdi hmimy
//4/22/2015
// Dr. keathly
// This program will create employees, print employees, and find employees using hierachy and polymorphism

#include <iostream>
using namespace std;
#include <string>



class Employee{
	string name; 
	long salary;
	public:
	Employee(string s,long pay){name = s,salary = pay;} // initialize private member to string name 's'
	//constructors
	// virtual function

	string getName(){return name;} // get the private member name
	long getSalary(){return salary;}

	virtual void show_info (){	// function to print out employee name// virtual knows to be replaced by spicific class functions
		cout<< "Employee: " <<getName()<<" Salary: "<<getSalary()<< endl;}

};

class Manager : public Employee
{
	protected: string degree;
	public: Manager(string s,long pay,string position) : Employee(s,pay) // take in parameter and create base class employee
		{degree = position;}

		void show_info(){
			cout<<"Employee: " <<getName()<< " Salary: "<< getSalary()<<" Degree: "<< degree <<endl;// because its virtual the function will skip and look to use this functin for this class
		}
};

class Worker : public Employee
{
	protected: string position;
	public: Worker(string s,long pay,string pos) : Employee(s,pay) // create Worker class of employee
		{position = pos;}
		void show_info(){
			cout<<"Employee: " << getName()<<" Salary: "<< getSalary()<<" Position: "<< position<<endl;	// worker class prints out position of sub classes, why we use virtual to ksip the first base function
		}
};

class Officer : public Worker
{
	public: Officer(string s,long pay,string pos) : Worker(s,pay,pos) //create officer class of employee // goes to worker
		{}
};

class Technician : public Worker		// create technician class of employee	// goes to worker
{
	public: Technician(string s,long pay,string pos) : Worker(s,pay,pos)
		{}
};



int main()
{	
	string nm;
	string place;
	long money;
	int cnt = 0;
	int x = 0;
	int choose;
	Employee *EmployeeList[cnt];		//declare and initialize employee array and other needed variables
	while(x == 0)
	{
		cout<<"WHat type of employee would you like to add? "<<endl;		// print out menu
		cout<<"1.Manager"<<endl;
		cout<<"2.Officer"<<endl;
		cout<<"3.Technician"<<endl;
		cout<<"4.Print out all Employees added"<<endl;
		cout<<"5. Find an employee"<<endl;
		cout<<"6. Exit"<<endl;
		cin>>choose;
		switch(choose)								// switch statement for options
		{
			case 1:cout<<"Please Enter Name,Salary, and Degree in that order:";		// create a manager
			       cin>>nm;
			       cin>>money;
			       cin>>place;
			       EmployeeList[cnt]= new Manager(nm,money,place);
			       cnt +=1;
			       break;
			case 2: cout<<"Please Enter Name,Salary, and Position in that order:";		// create a officer
				cin>>nm;
				cin>>money;
				cin>>place;
				EmployeeList[cnt]= new Officer(nm,money,place);
				cnt+=1;
				break;
			case 3:cout<<"Please Enter Name,Salary, and Position in that order:";		// create a technician
			       cin>>nm;
			       cin>>money;
			       cin>>place;
			       EmployeeList[cnt]= new Technician(nm,money,place);
			       cnt+=1;
			       break;

			case 4:
			       for(int i =0; i <cnt;i++)					// print out all employees
				       EmployeeList[i]->show_info();
			       break;
			case 5:
			       cout<<"Enter Name of Employee you want to find: ";		// find a employee by name and print information
			       cin >> nm;
			       for(int z = 0;z <cnt; z++)
			       {
				       if(EmployeeList[z]->getName() == nm)
				       {
					       cout<<nm<< " was found"<<endl;
					       EmployeeList[z]->show_info();
					       cout<<'\n';
				       }			
			       }
			       break;
			case 6: x = 1;							// exit loop
				break;
		}
	}


	/*	Employee* EmployeeList[NUM_EMPLOYEE]; // keeping this because it helps me understand conceptually and logically

		EmployeeList[0] = new Manager("Carla Garcia", 35000, "Economist");
		EmployeeList[1] = new Manager("Juan Perez", 38000, "Engineer");
		EmployeeList[2] = new Officer("Pedro Egia", 18000, "Officer 1");
		EmployeeList[3] = new Officer("Luisa Penia", 15000, "Officer 2");
		EmployeeList[4] = new Technician("Javier Ramos", 19500, "Welder");
		EmployeeList[5] = new Technician("Amaia Bilbao", 12000, "Electricist");

		for(int i =0; i <NUM_EMPLOYEE;i++)
		EmployeeList[i]->show_info();
	 */

	return 0;
}
