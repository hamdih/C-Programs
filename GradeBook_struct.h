/*Name: Hamdi Hmimy
  Email: hh0240@my.unt.edu
  Professor: Dr. keathly
  Date: 2/3/2015
  Program" My program will represent a gradebook
  with students and grades, there will be a menu with options
  that the user can choose from.
*/
typedef struct        /* student structure*/
{
 int sid;
 char fname[10];
}student;

typedef struct 
{          /* enrollment structure*/
 int enroll_id;
 int student_id;
 int course_id;
 int grade_cnt;
 int *grades;
}enroll;
/*Create a structure for course*/
typedef struct 
{
 int cid;
 char cname[10];
}course;

/*Structure for students*/
typedef struct
{
 int student_cnt;
 int stud_cap;
 student *stud_list;
}students;

/* structure for group of courses*/
typedef struct
{
 int course_cap;
 int course_cnt;
 course *course_list;
}courses;
/* structure for group of enrollments*/
typedef struct
{
int enroll_cnt;
int enroll_cap;
enroll *enroll_list;
}enrollment;
