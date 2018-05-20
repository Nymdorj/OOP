class Student{
	private:
		char *studentId;
		char *name;
	public:
		Student();
		Student(const Student &s);
		Student(char *id, char *name);
		~Student();
		void setStudentId(char *id);
		void setName(char *n);
		char* getStudentId();
                char* getName();
};
