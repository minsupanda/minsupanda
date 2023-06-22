#include"Person.h"
#include"Student.h"

void main()
{
	Person PersonList[10];
	for (Person person : PersonList)
		person.PrintPerson();

	Student StudentList[10];

	for (Student student : StudentList)
		student.PrintStudent();
}