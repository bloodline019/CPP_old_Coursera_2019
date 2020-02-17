#include <string>
using namespace std;
struct Specialization {
	string value;
explicit Specialization(const string& new_value) {
	value = new_value; 
	}
};
struct Course {
	string value;
explicit	Course(const string& new_value) {
		value = new_value;
	}
};
struct Week {
	string value;
explicit	Week(const string& new_value) {
		value = new_value;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization new_spec, Course new_course, Week new_week) {
		course = new_course.value;
		week = new_week.value;
		specialization = new_spec.value;
		
	}
};