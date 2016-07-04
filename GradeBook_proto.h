/*Name: Hamdi Hmimy
  Email: hh0240@my.unt.edu
  Professor: Dr. keathly
  Date: 2/3/2015
  Program" My program will represent a gradebook
  with students and grades, there will be a menu with options
  that the user can choose from.
*/

void add_course(courses *stuff);     /*Prototype function to add new course*/
void add_student(students *kids);   /*Prototype function to add new student */
void Student_Course(enrollment *stuff); /*Prototype function to add a student to the course*/
void Grades(enrollment *stuff,students *kid,courses *classes);         /*Prototype function to add grades in a course*/
void print_grades(enrollment *print,students *kid);  /*Prototype function to print the list of grades*/
void print_students(students * cs); /*Prototype function to print list of students*/
void avg(enrollment *stuff,students *kid);            /*Prototype function to calculate the average and print*/
void all_courses(courses *print);    /*Prototype function to print all courses*/
void print_stud_crse(enrollment *print,students *kid); /*Prototype function to print all students*/
/*void avg_course(); */    /*Prototype function to compute the average of a course*/
void store(FILE *file,students *stuff);  /* prototype to store the file info/ gradebook*/
void load(FILE *file);   /* prototype to loat a gradebook*/
