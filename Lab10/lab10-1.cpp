#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class shape{
	protected:
		int lenght;
	public:
		void set_lenght(int k){
			lenght=k;
		}
		shape(){}
		shape(int xlenght){
            		lenght=xlenght;
		}
		virtual float primeter()=0;
};

class twodimensionalshape:public shape{
	public:
		int *x;
		int *y;
		twodimensionalshape(){}
		twodimensionalshape(int data, int datay, int i){
			x[i]=data;
			y[i]=datay;
		}
		virtual float talbai()=0;
		void set_point(int data, int datay, int i){
			x[i]=data;
			y[i]=datay;
		}

		int get_x(int i){
			return x[i];
		}

		int get_y(int i){
			return y[i];
		}

		int get_lenght(){
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
		circle(int r){
		    lenght=r;
		    x=new int [1];
		    y=new int [1];
		}
		float talbai();
		float primeter();
};

float circle::talbai(){
	int r=get_lenght();
	return 3.14*r*r;
}

float circle::primeter(){
	int r=get_lenght();
	return 2*3.14*r;
}

class kvadrat:public twodimensionalshape{
	public:
		kvadrat(){
			x=new int [4];
			y=new int [4];
		}
		kvadrat(int l){
		    lenght=l;
		    x=new int [4];
		    y=new int [4];
		}
		float talbai();
		float primeter();
		void otherpoints();
};

void kvadrat::otherpoints(){
	for(int i=0; i<4; i++){
		if(i==0){
			x[i]=get_x(i);
			y[i]=get_y(i);
		}
		else if(i==1){
			x[i]=x[i-1]+get_lenght();
			y[i]=y[i-1];
		}
		else if(i==2){
			x[i]=x[i-1];
			y[i]=y[i-1]-get_lenght();
		}
		else if(i==3){
			x[i]=x[i-1]-get_lenght();
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
	int a=get_lenght();
	return a*a;
}

float kvadrat::primeter(){
	int a=get_lenght();
	return 4*a;
}

class triangle:public twodimensionalshape{
	public:
		triangle(){
			x=new int [3];
			y=new int [3];
		}
		triangle(int l){
		    lenght=l;
		    x=new int[3];
		    y=new int[3];
		}
		float talbai();
		float primeter();
		void otherpoints();
};

void triangle::otherpoints(){
	float tal=(float)get_lenght()/(float)2;
	for(int i=0; i<3; i++){
		if(i==0){
			x[i]=get_x(i);
			y[i]=get_y(i);
		}
		else if(i==1){
			x[i]=x[i-1]+tal;
			y[i]=y[i-1]-get_lenght();
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
	int a=get_lenght();
	float b=a/2;
	float h=sqrt((a*a)-(b*b));
	return 0.5*h*a;
}

float triangle::primeter(){
	int a=get_lenght();
	return 3*a;
}

int main(){
	int a,x,y;
	circle c;
	kvadrat k;
	triangle t;

	cout<<"Circle"<<endl;
	c.set_point(1,1,0);
	c.set_lenght(3);
	cout<<"Toirgiin tov: "<<c.get_x(0)<<" "<<c.get_y(0)<<endl;
	cout<<"Radius: "<<c.get_lenght()<<endl;
	cout<<"Talbai: "<<c.talbai()<<endl;
	cout<<"Toirgiin urt: "<<c.primeter()<<endl<<" "<<endl;

	cout<<"Kvadrat"<<endl;
	k.set_point(2,2,0);
	k.set_lenght(4);
	cout<<"Urt: "<<k.get_lenght()<<endl;
	cout<<"A point: "<<"x="<<k.get_x(0)<<" y="<<k.get_y(0)<<endl;
	k.otherpoints();
	cout<<"Talbai: "<<k.talbai()<<endl;
	cout<<"Primeter: "<<k.primeter()<<endl<<" "<<endl;

	cout<<"Zov gurvaljin"<<endl;
	t.set_point(4,4,0);
	t.set_lenght(3);
	cout<<"Urt: "<<t.get_lenght()<<endl;
	cout<<"A point: "<<"x="<<t.get_x(0)<<" y="<<t.get_y(0)<<endl;
	t.otherpoints();
	cout<<"Talbai: "<<t.talbai()<<endl;
	cout<<"Primeter: "<<t.primeter()<<endl<<" "<<endl;

	twodimensionalshape *twoDshape[6];
	twoDshape[1]=new circle(5);
	twoDshape[2]=new triangle(3);
	twoDshape[3]=new circle(5);
	twoDshape[4]=new kvadrat(6);
	twoDshape[5]=new kvadrat(1);
	twoDshape[6]=new circle(10);
	cout<<"Talbaigaar ni erembleh"<<endl;
	cout<<"Eremblehiin omno"<<endl;
        for(int j=1; j<=6; j++){
		cout<<twoDshape[j]->talbai()<<endl;
        }
	for(int i=1; i<=6; i++){
		for(int j=1; j<=(6-i); j++){
		    if(twoDshape[j]->talbai()>twoDshape[j+1]->talbai()){
		        twodimensionalshape *temp=twoDshape[j];
		        twoDshape[j]=twoDshape[j+1];
		        twoDshape[j+1]=temp;
		    }
		}
    	}
    	cout<<endl;
	cout<<"Eremblesenii daraa"<<endl;
    	for(int j=1; j<=6; j++){
		cout<<twoDshape[j]->talbai()<<endl;
    	}
}
