#include "Teacher.h"
#include <string.h>
#include <iostream>

using namespace std;

Teacher::Teacher(){
	setName((char *)" ");	
}

Teacher::Teacher(char *name){
	setName(name);	
}

Teacher::~Teacher(){
	delete[] name;
}

void Teacher::setName(char *name){
	if(this->name != NULL){
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

char* Teacher::getName(){
	return this->name;
}
