class Student{
	private:
		char *id;
		float gpa;
		static int number;
	public:
		int kurs;
		char *name;
		Student();
		Student(Student &s);
		Student(char [], char [], int, float);
		~Student();
		void set_id(char []);
		void set_name(char []);
		void set_kurs(int);
		void set_gpa(float);
		char* get_id();
		char* get_name();
		int get_kurs();
		float get_gpa();
		void stdcopy(Student &);
		bool greatThan(Student &);
		bool lessThan(Student &);
		bool isEqual(Student &);
		bool before(Student &);
		bool after(Student &);
		void printNumber();
};
