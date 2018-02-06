#ifndef PE04_H
#define PE04_H
#define MAX_LEN 80

/* 
 Complete the deifnition of structure "Student" below this line.
 This stucture has 6 fields, we have defined 2 of them for you.   
 Complete the remaining 4 fields: major, year, enrollment, and age.
 You may want to look at the database.txt file to find out the data type
 of these fields.
 You should assume the maximum length of the string is MAX_LEN
*/
typedef struct {
	int id;//field one id number is integer
	char name[MAX_LEN];//field two student name is string
	char major[MAX_LEN];//field three major is string
	char year[MAX_LEN];//field four year is string
	char enrollment[MAX_LEN];//field five enrollment is string
	int age;//field six age is integer
} Student;

/* Do not change code below this line */
typedef struct {
	int number; // Total number of students in the database.txt
	Student **students; // Array of pointers to Student objects
} StudentDatabase;

StudentDatabase * Connect(char * filename);
Student * SearchByName(StudentDatabase * studb, char * name);
void Close(StudentDatabase * studb);
void PrintDatabase(StudentDatabase * studb);
void PrintStudent(Student * stu);
#endif
