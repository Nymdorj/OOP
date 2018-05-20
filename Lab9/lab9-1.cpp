#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class shape{
	protected:
		int lenght;
	public:
		void setLenght(int k);
};

void shape::setLenght(int k){
	lenght=k;
}
		
class twodimensionalshape:public shape{
	public:
		int *x;
		int *y;
		void setPoint(int datax, int datay, int i){
			x[i]=datax;
			y[i]=datay;
		}
		
		int getX(int i){
			return x[i];
		}
		
		int getY(int i){
			return y[i];
		}
		
		int getLenght(){
			return lenght;
		}
		
		~twodimensionalshape(){
			delete[] x;
			delete[] y;
		}
};  

class circle:public twodimensionalshape{		
	public:
		circle(){
			x=new int[1];
			y=new int[1];
		}
		float talbai();
		float toirgiinUrt();
};

float circle::talbai(){
	int r=getLenght();
	return 3.14*r*r;
}

float circle::toirgiinUrt(){
	int r=getLenght();
	return 2*3.14*r;
}

class kvadrat:public twodimensionalshape{
	public:
		kvadrat(){
			x=new int [4];
			y=new int [4];
		}
		float talbai();
		float primeter();
		void otherPoints();
};

void kvadrat::otherPoints(){
	for(int i=0; i<4; i++){
		if(i==0){
			x[i]=getX(i);
			y[i]=getY(i);
		}
		else if(i==1){
			x[i]=x[i-1]+getLenght();
			y[i]=y[i-1];
		}
		else if(i==2){
			x[i]=x[i-1];
			y[i]=y[i-1]-getLenght();
		}
		else if(i==3){
			x[i]=x[i-1]-getLenght();
			y[i]=y[i-1];
		}
	}
	for(int i=1; i<4; i++){
		if(i==1){
			cout<<"B point: ";
		}
		else if(i==2){
			cout<<"C point: ";
		}	
		else if(i==3){
			cout<<"D point: ";
		}
		cout<<"x="<<x[i]<<" y="<<y[i]<<endl;
	}
}

float kvadrat::talbai(){
	int a=getLenght();
	return a*a;
}

float kvadrat::primeter(){
	int a=getLenght();
	return 4*a;
}

class triangle:public twodimensionalshape{
	public:
		triangle(){
			x=new int [3];
			y=new int [3];
		}
		float talbai();
		float primeter();
		void otherPoints();
};

void triangle::otherPoints(){
	float tal=(float)getLenght()/(float)2;
	for(int i=0; i<3; i++){
		if(i==0){
			x[i]=getX(i);
			y[i]=getY(i);
		}
		else if(i==1){
			x[i]=x[i-1]+tal;
			y[i]=y[i-1]-getLenght();
		}
		else if(i==2){
			x[i]=x[i-2]-tal;
			y[i]=y[i-1];
		}
	}
	for(int i=1; i<3; i++){
		if(i==1){
			cout<<"B point: ";
		}
		else if(i==2){
			cout<<"C point: ";
		}
		cout<<"x="<<x[i]<<" y="<<y[i]<<endl;
	}
}

float triangle::talbai(){
	int a=getLenght();
	float b=a/2;
	float h=sqrt((a*a)-(b*b));
	return 0.5*h*a;
}

float triangle::primeter(){
	int a=getLenght();
	return 3*a;
}
		
class threedimensionalshape:public shape{
	public:
		int *x;
		int *y;
		int *z;
		void setPoint(int datax, int datay, int dataz, int i){
			x[i]=datax;
			y[i]=datay;
			z[i]=dataz;
		}
		
		int getX(int i){
			return x[i];
		}
		
		int getY(int i){
			return y[i];
		}
		
		int getZ(int i){
			return z[i];
		}
		
		int getLenght(){
			return lenght;
		}
		
		~threedimensionalshape(){
			delete[] x;
			delete[] y;
			delete[] z;
		}
};  

class circle3d:public threedimensionalshape{		
	public:
		circle3d(){
			x=new int[1];
			y=new int[1];
			z=new int[1];
		}
		float talbai();
		float toirgiinUrt();
};

float circle3d::talbai(){
	int r=getLenght();
	return 3.14*r*r;
}

float circle3d::toirgiinUrt(){
	int r=getLenght();
	return 2*3.14*r;
}

class kvadrat3d:public threedimensionalshape{
	public:
		kvadrat3d(){
			x=new int [4];
			y=new int [4];
			z=new int [4];
		}
		float talbai();
		float primeter();
		void otherPoints();
};

void kvadrat3d::otherPoints(){
	for(int i=0; i<4; i++){
		if(i==0){
			x[i]=getX(i);
			y[i]=getY(i);
			z[i]=getZ(i);
		}
		else if(i==1){
			x[i]=x[i-1]+getLenght();
			y[i]=y[i-1];
			z[i]=z[i-1]+getLenght();
		}
		else if(i==2){
			x[i]=x[i-1];
			y[i]=y[i-1]-getLenght();
			z[i]=z[i-1];
		}
		else if(i==3){
			x[i]=x[i-1]-getLenght();
			y[i]=y[i-1];
			z[i]=z[i-1]-getLenght();
		}
	}
	for(int i=1; i<4; i++){
		if(i==1){
			cout<<"B point: ";
		}
		else if(i==2){
			cout<<"C point: ";
		}	
		else if(i==3){
			cout<<"D point: ";
		}
		cout<<"x="<<x[i]<<" y="<<y[i]<<" z="<<z[i]<<endl;
	}
}

float kvadrat3d::talbai(){
	int a=getLenght();
	return 6*a;
}

float kvadrat3d::primeter(){
	int a=getLenght();
	return 4*a;
}

class triangle3d:public threedimensionalshape{
	public:
		triangle3d(){
			x=new int [3];
			y=new int [3];
			z=new int [3];
		}
		float talbai();
		float primeter();
		void otherPoints();
};

void triangle3d::otherPoints(){
	float tal=(float)getLenght()/(float)2;
	for(int i=0; i<3; i++){
		if(i==0){
			x[i]=getX(i);
			y[i]=getY(i);
			z[i]=getZ(i);
		}
		else if(i==1){
			x[i]=x[i-1]+tal;
			y[i]=y[i-1]-getLenght();
			z[i]=z[i-1];
		}
		else if(i==2){
			x[i]=x[i-2]-tal;
			y[i]=y[i-1];
			z[i]=z[i-1];
		}
	}
	for(int i=1; i<3; i++){
		if(i==1){
			cout<<"B point: ";
		}
		else if(i==2){
			cout<<"C point: ";
		}
		cout<<"x="<<x[i]<<" y="<<y[i]<<" z="<<z[i]<<endl;
	}
}

float triangle3d::talbai(){
	int a=getLenght();
	float b=a/2;
	float h=sqrt((a*a)-(b*b));
	return 0.5*h*a;
}

float triangle3d::primeter(){
	int a=getLenght();
	return 3*a;
}

int main(){
	int a,x,y;
	circle c;
	kvadrat k;
	triangle t;
	circle3d c1;
	kvadrat3d k1;
	triangle3d t1;
	
	cout<<"----------------2D----------------"<<endl;
	cout<<"Circle"<<endl;
	c.setPoint(1,1,0);
	c.setLenght(3);
	cout<<"Toirgiin tov: "<<c.getX(0)<<" "<<c.getY(0)<<endl;
	cout<<"Radius: "<<c.getLenght()<<endl;
	cout<<"Talbai: "<<c.talbai()<<endl;
	cout<<"Toirgiin urt: "<<c.toirgiinUrt()<<endl;
	
	cout<<"Kvadrat"<<endl;
	k.setPoint(2,2,0);
	k.setLenght(4);
	cout<<"Urt: "<<k.getLenght()<<endl;
	cout<<"A point: "<<"x="<<k.getX(0)<<" y="<<k.getY(0)<<endl;
	k.otherPoints();
	cout<<"Talbai: "<<k.talbai()<<endl;
	cout<<"Primeter: "<<k.primeter()<<endl;
	
	cout<<"Zov gurvaljin"<<endl;
	t.setPoint(4,4,0);
	t.setLenght(3);
	cout<<"Urt: "<<t.getLenght()<<endl;
	cout<<"A point: "<<"x="<<t.getX(0)<<" y="<<t.getY(0)<<endl;
	t.otherPoints();
	cout<<"Talbai: "<<t.talbai()<<endl;
	cout<<"Primeter: "<<t.primeter()<<endl;

	/*cout<<"----------------3D----------------"<<endl;
	cout<<"Circle"<<endl;
	c1.setPoint(1,1,1,0);
	c1.setLenght(3);
	cout<<"Toirgiin tov: "<<c1.getX(0)<<" "<<c1.getY(0)<<" "<<c1.getZ(0)<<endl;
	cout<<"Radius: "<<c1.getLenght()<<endl;
	cout<<"Talbai: "<<c1.talbai()<<endl;
	cout<<"Toirgiin urt: "<<c1.toirgiinUrt()<<endl;
	
	cout<<"Kvadrat"<<endl;
	k1.setPoint(2,2,2,0);
	k1.setLenght(4);
	cout<<"Urt: "<<k1.getLenght()<<endl;
	cout<<"A point: "<<"x="<<k1.getX(0)<<" y="<<k1.getY(0)<<" z="<<k1.getZ(0)<<endl;
	k1.otherPoints();
	cout<<"Talbai: "<<k1.talbai()<<endl;
	cout<<"Primeter: "<<k1.primeter()<<endl;
	
	cout<<"Zov gurvaljin"<<endl;
	t1.setPoint(4,4,4,0);
	t1.setLenght(3);
	cout<<"Urt: "<<t1.getLenght()<<endl;
	cout<<"A point: "<<"x="<<t1.getX(0)<<" y="<<t1.getY(0)<<" z="<<t1.getZ(0)<<endl;
	t1.otherPoints();
	cout<<"Talbai: "<<t1.talbai()<<endl;
	cout<<"Primeter: "<<t1.primeter()<<endl;*/
}
