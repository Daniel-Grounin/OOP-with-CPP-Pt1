#include <iostream>
#include "courseH.h"
#include "studentH.h"
using namespace std;

int main() {
	Course c1 = new Course();
	cout << c1.get_Course_Name();
	cout << endl << c1.get_Grade();
	cout << endl << c1.get_Grades_ByIndex(0) << endl << endl;

	Course c2 = new Course("Test and Grades");
	cout << c2.get_Course_Name();
	cout << endl << c2.get_Grade();
	cout << endl << c2.get_Grades_ByIndex(2) << endl << endl;
	c2.set_Grade(70);
	int arr[3] = { 60,56,60 };
	c2.set_Grades_Arr(arr);
	cout << c2.get_Course_Name();
	cout << endl << c2.get_Grade();
	cout << endl << c2.get_Grades_ByIndex(2) << endl << endl;

	Course c3 = new Course(&c2);
	cout << c3.get_Course_Name();
	cout << endl << c3.get_Grade();
	cout << endl << c3.get_Grades_ByIndex(2) << endl << endl;

	Course c4 = new Course("CPP");
	int cpp[3] = { 100,90,80 };
	c4.set_Grades_Arr(cpp);
	c4.set_Grade(84);
	cout << c4.get_average_Grade();
	cout << endl << c4.isPassCourse();

	Course c5 = new Course("Logic");
	int Logic[3] = { 100,80,80 };
	c5.set_Grades_Arr(Logic);
	c5.set_Grade(84);
	cout << c5.get_average_Grade() << endl;
	cout << endl << c5.isPassCourse() <<endl;

	Course c6 = new Course("Arhi");
	int Arhi[3] = { 90,80,80 };
	c6.set_Grades_Arr(Arhi);
	c6.set_Grade(80);
	cout << c6.get_average_Grade() << endl;
	cout << endl << c6.isPassCourse() << endl;
	cout << endl << "--------------------------------------------------" << endl;

	Course** CourseName;
	CourseName = new Course*;
	CourseName[0] = new Course[2];
	CourseName[0][0] = new Course("Arhi");
	CourseName[0][1] = new Course("Logic");
	CourseName[0][0].set_Grade(90);
	CourseName[0][0].set_Grades_Arr(arr);
	CourseName[0][1].set_Grade(95);
	CourseName[0][1].set_Grades_Arr(arr);

	cout << CourseName[0][0].get_Course_Name() << " " << CourseName[0][0].get_average_Grade() << endl;
	cout << CourseName[0][1].get_Course_Name() << " " << CourseName[0][1].get_average_Grade() << endl;

	Student s1 = new Student("Daniel Grounin","319191680");
	s1.set_Courses(&c4);
	Course cTest = new Course;
	cTest = s1.get_Course_by_index(0);
	cout << cTest.get_Course_Name() << " " << cTest.get_Grade() << endl;

	Student s2 = new Student(&s1);
	Course cTest1 = new Course;
	cTest1 = s2.get_Course_by_index(0);
	cout << cTest1.get_Course_Name() << " " << cTest1.get_average_Grade() << endl;
	s2.set_Courses(&c6);
	s2.set_Courses(&c5);
	cout << s2.get_Course_by_index(1)->get_Course_Name() << " " << s2.get_Course_by_index(1)->get_average_Grade() << endl;
	cout << s2.get_average()<<endl;
	s2.print_student_details();

	system("pause>0");
}

