class Lesson{
	private:
		int lessonId;
		char *topic;
		Teacher teacher;
		std::vector<Student> students;
	public:
		Lesson();
		Lesson(int id, char *topic, Teacher &teacher, Student &student);
		~Lesson();
		void setValues(int id, char *topic, Teacher &teacher, Student &student);
		void show();
		int getLessonId();
		void setLessonId(int id);
		char* getTopic();
		void setTopic(char *topic);
		Teacher getTeacher();
		void setTeacher(Teacher &teacher);
		std::vector<Student> getStudent();
		void setStudent(Student &student);
};
