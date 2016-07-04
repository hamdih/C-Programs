/*Name: Hamdi Hmimy
  Email: hh0240@my.unt.edu
  Professor: Dr. keathly
  Date: 2/3/2015
  Program" My program will represent a gradebook
  with students and grades, there will be a menu with options
  that the user can choose from.
*/
#include <stdlib.h>
#include <stdio.h>
#include "GradeBook_struct.h"
#include "GradeBook_proto.h"
#define MAX_STUD 100   /*Max number of students 100*/                           
#define MAX_CRSE 25    /*Max number of courses 25*/
#define MAX_CSTUD 4    /*Max number of courses per students 4*/
#define MAX_GRADE 10     /*Max number of grades per student per course 10*/
#define MAX_STUDC 20   /*Max number of students per course 20*/
#define CHUNKSIZE 2

void add_course(courses *stuff)
{  /* add course function*/
int id;
if ( stuff->course_cnt == stuff->course_cap) /*Realloc more memory*/
 {
  course *temp;
  temp = (course*) realloc(stuff->course_list,sizeof(course)*(stuff->course_cap +CHUNKSIZE));
  stuff->course_cap += CHUNKSIZE;
  stuff->course_list = temp;
 }
 
printf("Enter new course ID:  ");
scanf("%d%*c",&(stuff->course_list[stuff->course_cnt].cid));  /* this will create Courses with IDs and Names*/
printf("Enter Name of Course:  ");
fgets(stuff->course_list[stuff->course_cnt].cname,15,stdin);
stuff->course_cnt +=1;
}

void add_student(students *kids)
{
int id; char temp [10];
if ( kids->student_cnt == kids->stud_cap)  //realloc more memory
 {
  student *temp;
  temp = (student*) realloc(kids->stud_list,sizeof(student)*(kids->stud_cap +CHUNKSIZE));
  kids->stud_cap += CHUNKSIZE;
  kids->stud_list = temp;
 }
 
printf("Enter Student ID:  ");
scanf("%d%*c",&(kids->stud_list[kids->student_cnt].sid)); /* this function will add students with name and SID*/
printf("Enter Name:  ");
fgets(kids->stud_list[kids->student_cnt].fname,10,stdin);
kids->student_cnt+=1;
}

void Student_Course(enrollment *stuff)
{
	int id; int cs; int iid;
 	if ( stuff->enroll_cnt == stuff->enroll_cap)// realloc more memory
 	{
  	enroll *temp;
  	temp = (enroll*) realloc(stuff->enroll_list,sizeof(enroll)*(stuff->enroll_cap +CHUNKSIZE));
  	stuff->enroll_cap += CHUNKSIZE;
  	stuff->enroll_list = temp;
 	}
	printf("Enter new Enrollment ID:  "); /* this function will create enrollments which hold student and course information as a whole*/
	scanf("%d%*c", &(stuff->enroll_list[stuff->enroll_cnt].enroll_id));
	printf("Enter Student ID for enrollment: ");
	scanf("%d%*c", &(stuff->enroll_list[stuff->enroll_cnt].student_id));
	printf("Enter course ID for enrollment: ");
	scanf("%d%*c",&(stuff->enroll_list[stuff->enroll_cnt].course_id));
	stuff->enroll_cnt +=1;
}

void print_stud_crse(enrollment *cs,students *kid)
{
 	int i;int temp;int x;int change = -1; /* this function will search for a course ID*/

 	printf("Please Enter the Course ID to print the students: ");
 	scanf("%d%*c",&temp);
 	for ( i = 0; i <cs->enroll_cnt;i++)
 	{
  	if (temp == cs->enroll_list[i].course_id)  /* then with that course ID each enrollment will find the corresponding student IDs*/
   		printf("Student Name: %sStudent ID: %d",kid->stud_list[i].fname,cs->enroll_list[i].student_id); 
 	}
}

void Grades(enrollment *stuff, students *kid, courses *class)
{
	int temp;int e;int z;int x;int y;int choose;int r;
	printf("Enter Student ID:  ");
	scanf("%d%*c",&temp);
   	for (x= 0;x <stuff->enroll_cnt;x++) /* This function will search for an enrollment id*/
   	{
     	  if(temp == stuff->enroll_list[x].student_id && temp == kid->stud_list[x].sid )    /*Then will enter 10 grades for the corrsepding student and course*/
     	  {	
	   printf("Courses for %s\n",kid->stud_list[x].fname);		
		for(y=0; y<stuff->enroll_cnt;y++)
		 {
		 if(stuff->enroll_list[y].course_id == class->course_list[y].cid) 
                 printf("%s   %d\n",class->course_list[y].cname,class->course_list[y].cid);	 
     		 }
   	   }
	printf("Which course do you want to input grades for(Class ID)?:\n");
        scanf("%d",&choose);
       		for(e =0;e<stuff->enroll_cnt;e++)
		{
        		if(choose == stuff->enroll_list[e].course_id && temp == stuff->enroll_list[e].student_id)
			{
		  	printf("How many grades are you entering?\n");
        	  	scanf("%d",&z);
				for(r = 0; r < z;r++)
				{	
 		  		stuff->enroll_list[e].grades = (int*)malloc(sizeof(int)*z); // malloc memory for grades
				printf("Enter Grade #%d: ",r+1);
		  		scanf("%d",&stuff->enroll_list[e].grades[r]);
				}
	
			}	
	  	}
	
	 }
     z = stuff->enroll_list[e].grade_cnt;
}
void print_grades(enrollment *print,students *kid)
{
	 int x;int temp;int y;     /* this function will search for the student entered and print all grades*/
 	printf("Enter Student ID to print their grades: ");
 	scanf("%d%*c",&temp);
    	for (x = 0; x <print->enroll_cnt;x++)
    	{ 
     	if (temp == (print->enroll_list[x].student_id) && temp == kid->stud_list[x].sid)
      	  {
       		 for(y = 0;y < print->enroll_list[x].grade_cnt ;y++)
      	    	{
      	 		printf("Grade #%d: %d\n",y+1,print->enroll_list[x].grades[y]);
             	}
      	  } 
	}
}


void avg(enrollment *stuff,students *kid)
{
 int x;int temp;int y;int avg;
 printf("Enter Student ID to print their average: ");/* this function will find the entered student and then print the AVERAGE of the students grades*/
 scanf("%d%*c",&temp);
    for (x = 0; x <stuff->enroll_cnt;x++)
    { 
     if (temp == (stuff->enroll_list[x].student_id) && temp == kid->stud_list[x].sid)
        {
       		for(y=0;y < stuff->enroll_list[x].grade_cnt;y++)
		{
		avg = stuff->enroll_list[x].grades[y] +avg;
		}
     	}
   }
	 	avg = avg/stuff->enroll_list[x].grade_cnt;
		printf("Average of this student is %d",avg);
}


void all_courses(courses *print)
{
	int i;                    /* this function will print all courses created in the gradebook*/
	for ( i = 0; i <print->course_cnt;i++)
 	{
  	printf("Course id: %d Name: %s\n",print->course_list[i].cid,print->course_list[i].cname);
 	}
}

void print_students(students *cs)
{
	int i; /* this function will print out all students created in the gradebook*/
	for ( i = 0; i <cs->student_cnt;i++)
 	{
  	printf("Student id: %d Name: %s\n",cs->stud_list[i].sid,cs->stud_list[i].fname);
 	}
}	

void avg_course(enrollment *stuff)
{
 int i;int temp;int x;int avg;/* by entering the course ID, this function will search for all corresponding grade arrays in enrollment and find the average*/
 printf("Enter the Course ID, that you would like to know the average of: ");
 scanf("%d%*c",&temp);
 for(i = 0; i < stuff->enroll_cnt;i++)
 {
  if(temp == stuff->enroll_list[i].course_id)
        for(x = 0;x < stuff->enroll_list[i].grade_cnt;x++)
        {
         avg = avg + (stuff->enroll_list[i].grades[x]);
        }
 }
 printf("The average of this course is: %d\n",avg/stuff->enroll_list[i].grade_cnt);
}

void store(FILE *file,students *stuff)  /* this function will create a saved database of the gradebook*/
{
 int scnt; 
 for(scnt = 0; scnt !=0;scnt++)
{
 fwrite(&scnt,sizeof(int),1,file); 
 fwrite(stuff,sizeof(students),scnt,file);
 fclose(file);
}
}


/*void load(FILE *file, enroll *print)*/ /* this function will load a saved database/gradebook*/
/*{
 int x;  */  /* very diffucult part if i uncomment it doesnt work, this is all i could get*/
 /*file = fopen("Gradebook1.txt","w+");
 for(x=0;x<100;x++)
 {
 puts(print->grades,x);
 }
 fclose(file);


}

*/

