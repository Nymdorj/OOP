#include <vector>
#include <string.h>
#include <iostream>
#include "Teacher.h"
#include "Student.h"
#include "Lesson.h"
#include "Registration.h"

using namespace std;

Registration::Registration(){
	setDate((char *)" ");	
	setState((char *)" ");
}

Registration::Registration(Lesson &lesson, Student &student, char *date, char *state){
	setLesson(lesson);
	setStudent(student);
	setDate(date);	
	setState(state);
}

Registration::~Registration(){
	delete[] date;
	delete[] state;
}

void Registration::setValues(Lesson &lesson, Student &student, char *date, char *state){
	setLesson(lesson);
	setStudent(student);
	setDate(date);	
	setState(state);
}

void Registration::show(){
	cout<<"Date: "<<this->date<<"\n"<<"Lesson: "<<this->lesson.getLessonId()<<"\n"<<
	      "Teacher: "<<this->lesson.getTeacher().getName()<<"\n"<<
	      "Student: "<<this->student.getName()<<"\n"<<"Status: "<<this->state<<"\n"<<"------\n";
}

void Registration::setDate(char *date){
	if(this->date != NULL){
		delete[] this->date;
	}
	this->date = new char[strlen(date) + 1];
	strcpy(this->date, date);
}

char* Registration::getDate(){
	return this->date;
}

void Registration::setState(char *state){
	if(this->state != NULL){
		delete[] this->state;
	}
	this->state = new char[strlen(state) + 1];
	strcpy(this->state, state);
}

char* Registration::getState(){
	return this->state;
}

void Registration::setLesson(Lesson &lesson){
	this->lesson = lesson;
}

Lesson Registration::getLesson(){
	return this->lesson;
}

void Registration::setStudent(Student &student){
	this->student = student;
}

Student Registration::getStudent(){
	return this->student;
}
