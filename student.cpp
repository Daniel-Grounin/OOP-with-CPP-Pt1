#include "studentH.h"
using namespace std;

Student::Student() {
	set_Name("Unknown");
	for (int i = 0; i < 10; i++) {
		id[i] = '0';
	}
	id[9] = '\0';
	numCourses = 0;
	CourseName = new Course*;
	CourseName = NULL;
}

Student::Student(Student* s1) {
	int lastIndex = 0;
	this->numCourses = s1->set_Num_Courses();
	string tempId = s1->get_Student_ID();
	for (int i = 0; i < 10; i++){
		this->id[i] = tempId[i];
		lastIndex = i;
	}
	this->id[lastIndex] = '\0';

	string tempName = s1->get_Student_Name();
	for (int i = 0; i < 30 && tempName[i]!='\0'; i++) {
		StudentName[i] = tempName[i];
		lastIndex = i;
	}
	this->StudentName[lastIndex+1] = '\0';

	CourseName = new Course*;
	CourseName[0] = new Course[this->numCourses];
	for (int i = 0; i < this->numCourses; i++) {
		this->CourseName[0][i] = s1->get_Course_by_index(i);
	}

}

Student::Student(string name, string idNum) {
	if (!isSuitbleLenght(name)) {
		set_Name("Unknown");
	}
	else
		set_Name(name);
	if (isSuitbleID(idNum)) {
		for (int i = 0; i < 9; i++) {
			id[i] = idNum[i];
		}
		id[9] = '\0';
	}
	else {
		for (int i = 0; i < 9; i++) {
			id[i] = '0';
		}
		id[9] = '\0';
	}
	numCourses = 0;
	CourseName = new Course*;
	CourseName = NULL;
}
void Student::set_Name(string name) {
	int i = 0;
	while (name[i] != '\0' && i < 30) { // set -> copy the name inputed char by char to the name of the student validating that input isnt longer than 30.
		StudentName[i] = name[i];
		i++;
	}
	StudentName[i] = '\0';
}
bool Student::isSuitbleID(string id) {
	if(id[0]!='0')
	for (int i = 0; i < 9; i++) {
		if (id[9] == '\0')
			return true;
	}
	return false;
}
bool Student::isSuitbleLenght(string name) {
	for (int i = 0; i < 30; i++) {
		if (name[i] == '\0')
			return true;
	}
	return false;
}
Course* Student::get_Course_by_index(int index) {
	return &CourseName[0][index];
}

void Student::set_Courses(Course* c1) {
	Course** cTemp = new Course*; //will get the current object courses and hold it.
	cTemp[0] = new Course[numCourses];
	for (int i = 0; i < numCourses; i++) { //copy all the courses to temp
		cTemp[0][i] = CourseName[0][i];
	}
	numCourses++;   // increase the courses for adding up the new course.
	delete[] CourseName; // release memory from old list.
	CourseName = new Course*;
	*CourseName = new Course[numCourses]; // allocate memory for new list(old+1)
	for (int i = 0; i < numCourses-1; i++) {
		 CourseName[0][i]= cTemp[0][i];  // copy from temp the courses.
	}
	CourseName[0][numCourses - 1] = c1; // adding the new course

		
}
float Student::get_average() {
	float avrg = 0;
	for (int i = 0; i < numCourses; i++) {
		avrg += get_Course_by_index(i)->get_average_Grade();
	}
	return (avrg / numCourses);
	
}

void Student::print_student_details() {
	cout << endl << "Student name: " << get_Student_Name() << ", ID: " << get_Student_ID() << ", Courses: ";
	for (int i = 0; i < numCourses; i++) {
		cout <<"{" <<get_Course_by_index(i)->get_Course_Name()<<","<< get_Course_by_index(i)->get_Grade()<<"} ";
		if (i < numCourses - 1)
			cout << ", ";
	}
	cout << "\n" << "Avg:" << get_average() << ", Outstanding: ";
	if (is_outstanding())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

bool Student::is_outstanding() { 
	int count = 0;
	for (int i = 0; i < numCourses; i++) {
		if(get_Course_by_index(i)->get_average_Grade()>85 && get_Course_by_index(i)->isPassCourse())
		count++;
	}
	if (count >= 3 && get_average() > 85)
		return true;
	else
		return false;
}
void Student:: add_course(string cName){
	Course cTemp = new Course(cName);
	set_Courses(&cTemp);
}

float Student::get_course_grade_by_name(string cName) {
	if (is_course_exist_by_name(cName)) {
		for (int i = 0; i < numCourses; i++) {
			if (get_Course_by_index(i)->get_Course_Name() == cName) {
				return get_Course_by_index(i)->get_Grade();
			}
		}
	}
	return -1;
}

bool Student::is_course_exist_by_name(string cName) {
	for (int i = 0; i < numCourses; i++) {
		if (get_Course_by_index(i)->get_Course_Name() == cName) {
			return true;
		}
	}
	return false;

}

void Student::update_course_grades(string cName, string* gradesNames, string testGrade) { // need to make delete course function. and use add course after we delete the current same named course.
	if (!is_course_exist_by_name(cName))
		return;
	
}
	Student::~Student() {
			delete[] CourseName;
	};

