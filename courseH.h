#pragma once
#include <iostream>
#include <stdbool.h>
using namespace std;

class Course {
public:
	Course();
	~Course();
	Course(string name);
	Course(Course*);
	void set_Course_Name(string);
	bool isSuitbleLenght(string);
	void set_Grade(int);
	void set_Grades_Arr(int*);
	string get_Course_Name() { return CourseName; }
	int get_Grade() { return grade; }
	int get_Grades_ByIndex(int);
	bool isThereScore();
	float get_average_Grade();
	bool isPassCourse();

private:
	char CourseName[30];
	int grades[3];
	int grade;
};


