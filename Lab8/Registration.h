class Registration{
	private:
		Lesson lesson;
		Student student;
		char *date;
		char *state;
	public:
		Registration();
		Registration(Lesson &lesson, Student &student, char *date, char *state);
		~Registration();
		void setValues(Lesson &lesson, Student &student, char *date, char *state);
		void show();		
		void setLesson(Lesson &lesson);
		void setStudent(Student &student);
		void setDate(char *date);
		void setState(char *state);
		Lesson getLesson();
                Student getStudent();
		char* getDate();
                char* getState();
};
