class Matrix {
	private:
		int **a;
		int rowSize, colSize;
	public:
		Matrix();
		Matrix(int, int);
		Matrix(const Matrix &);
		~Matrix();

		int getRowSize();
		int getColSize();
		void setRowSize(int sz);
		void setColSize(int sz);
		int getEl(int x, int y);
		void setEl(int x, int y, int v);
		void print()const;
		void read();

		Matrix operator ++();
		Matrix operator --();
		Matrix operator +(const Matrix &M);
		Matrix operator -(const Matrix &M);
		Matrix operator =(const Matrix &M);
		Matrix operator *(const Matrix &M);
		Matrix operator +=(const Matrix &M);
		Matrix operator -=(const Matrix &M);
		Matrix operator *=(const Matrix &M);
		Matrix operator ,(const Matrix &M);
};

