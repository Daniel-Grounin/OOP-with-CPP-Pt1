#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "courseH.h"
using namespace std;

Course::Course() {
	set_Course_Name("Unknown");// I used set function in order to input 'unknown' into the courseName var.
	grades[0] = -1;
	grades[1] = -1;
	grades[2] = -1;
	grade = 0;
}
Course::Course(string name) {
	if (!isSuitbleLenght(name)) {
		set_Course_Name("Unknown");
	}
	else
		set_Course_Name(name);
	grades[0] = -1;
	grades[1] = -1;
	grades[2] = -1;
	grade = 0;
}
Course::Course(Course* c1) { // cpy constructor (takes an object and copies its field into This object).
	this->grade = c1->get_Grade(); // take the grade from obj and copy to "This"
	for (int i = 0; i < 3; i++) {
		this->grades[i] = c1->get_Grades_ByIndex(i);
	}
	this->set_Course_Name(c1->get_Course_Name());// takes the name from c1 obj and copy it to the "This" obj.(using the set function)
}
void Course::set_Course_Name(string name) {
	int i = 0;
	while (name[i] != '\0' && i < 30) { // set -> copy the name inputed char by char to the name of the course, validating that input isnt longer than 30.
		CourseName[i] = name[i];
		i++;
	}
	CourseName[i] = '\0';
}
bool Course::isSuitbleLenght(string name) {
	for (int i = 0; i < 30; i++) {
		if (name[i] == '\0')
			return true;
	}
	return false;
}
void Course::set_Grade(int num) {
	grade = num;
}
void Course::set_Grades_Arr(int* arr) {
	grades[0] = arr[0];
	grades[1] = arr[1];
	grades[2] = arr[2];
}
int Course::get_Grades_ByIndex(int index) {
	if (index > 2) {
		cout << "Index out of boundries" << endl;
		return -1;
	}
	return grades[index];
}
bool Course::isThereScore() {
	if (grade != -1) {
		return true;
	}
	return false;
}
float Course::get_average_Grade() {
	if (!isThereScore()) {
		return 0;
	}
	return ((grades[0] + grades[1] + grades[2]) / 3) * 0.3 + 0.7 * grade;
}
bool Course::isPassCourse() {
	if (!isThereScore())
		return false;
	if (get_average_Grade() > 55)
		return true;
	return false;
}
Course::~Course() {

}
