class Teacher{
	private:
		char *name;
	public:
		Teacher();
		Teacher(char *name);
		~Teacher();
		void setName(char *name);
                char* getName();
};
