#include <vector>
#include <string.h>
#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Lesson.h"

using namespace std;

Lesson::Lesson(){
	setTopic((char *)" ");	
	setLessonId(0);
}

Lesson::Lesson(int id, char *topic, Teacher &teacher, Student &student){
	setLessonId(id);
	setTopic(topic);
	setTeacher(teacher);	
	setStudent(student);
}

Lesson::~Lesson(){
	delete[] topic;
}

void Lesson::setValues(int id, char *topic, Teacher &teacher, Student &student){
	setLessonId(id);
	setTopic(topic);
	setTeacher(teacher);	
	setStudent(student);
}

void Lesson::show(){
	cout<<"Lesson Id: "<<this->lessonId<<"\n"<<"Topic: "<<this->topic<<"\n"<<
	      "Teacher: "<<this->teacher.getName()<<"\n";

	for(int i=0; i < students.size(); i++)
	      cout<<"Student["<<i+1<<"]: "<<this->students.at(i).getName()<<"\n";
}

void Lesson::setLessonId(int id){
	this->lessonId = id;
}

int Lesson::getLessonId(){
	return this->lessonId;
}

void Lesson::setTopic(char *topic){
	if(this->topic != NULL){
		delete[] this->topic;
	}
	this->topic = new char[strlen(topic) + 1];
	strcpy(this->topic, topic);
}

char* Lesson::getTopic(){
	return this->topic;
}

void Lesson::setTeacher(Teacher &teacher){
	this->teacher = teacher;
}

Teacher Lesson::getTeacher(){
	return this->teacher;
}

void Lesson::setStudent(Student &student){
	students.push_back(student);
}

vector<Student> Lesson::getStudent(){
	return students;
}

