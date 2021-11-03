#pragma once
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include "courseH.h"
using namespace std;

class Student {
public:
	Student();
	Student(Student*);
	~Student();
	Student(string name, string id);
	void set_Name(string name);
	bool isSuitbleID(string id);
	bool isSuitbleLenght(string name);
	void set_id(string num);
	string get_Student_Name() { return StudentName; }
	string get_Student_ID() { return id; }
	void set_Num_Courses(int num);
	void set_Courses(Course*);
	int set_Num_Courses() {	return numCourses;}
	Course* get_Course_by_index(int);
	float get_average();
	void print_student_details();
	bool is_outstanding();
	void add_course(string);
	float get_course_grade_by_name(string);
	bool is_course_exist_by_name(string);
	void update_course_grades(string,string*,string);

private:
	char StudentName[30];
	char id[30];
	Course** CourseName;
	int numCourses;
};

