#include<iostream>
#include<stdio.h>

using namespace std;

/*
	Холбоост жагсаалтыг хэрэгжүүлэхдээ link нь өөрийн арын блокын хаягийг зааж байхаар хэрэгжүүлэв.
	Хэрвээ ард нь блок байхгүй бол NULL-г заана.
	Тэхээр блокын хаяг NULL байвал хамгийн арын блок гэсэн үг.
	Head хаяган хувьсагч нь хамгийн эхний блокын хаягийг заана.
	while(head != NULL) head=head->link; давталтаар жагсаалтын хамгийн эхний блокоос хамгийн сүүлийн блок хүртэл давтана.
*/

template <class T>
class Node{
	public:
		T data;
		Node* link;
};

template <class T>
class List{
	private:
		Node<T> *head = NULL;
	public:
		void print();
		void insert(T t, int index);
		void remove(int index);
		void add(T t);
		T get(int index);
		int lenght();      
};
                                                                                                                                                                                                                                             
template <class T>
void List<T>::add(T t){
	Node<T> *temp = new Node<T>();
	temp->data = t;
	temp->link = NULL;	
	if(head == NULL){
		temp->link = head;
		head = temp;
		return;
	}
	Node<T> *temp1 = head;
	while(temp1->link != NULL){
		temp1 = temp1->link;
	}
	temp->link = temp1->link;
	temp1->link = temp;
}

template <class T>
void List<T>::insert(T t, int index){
	Node<T> *temp = new Node<T>();
	temp->data = t;
	temp->link = NULL;	
	if(index == 1){
		temp->link = head;
		head = temp;
		return;
	}
	Node<T> *temp1 = head;
	for(int i = 0; i < index-2; i++){
		temp1 = temp1->link;
	}
	temp->link = temp1->link;
	temp1->link = temp;
	
}

template <class T>
void List<T>::remove(int index){
	Node<T> *temp = head;
	if(temp == NULL){
		cout<<"Jagsaalt hooson bn"<<endl;
		return;
	}
	if(index == 1){
		head = temp->link;
		delete temp;
		return;
	}
	for(int i = 0; i < index-2; i++){
		temp = temp->link;
	}
	Node<T> *temp1 = temp->link;
	temp->link = temp1->link;
	delete temp1;
}

template <class T>
int List<T>::lenght(){
	Node<T> *temp = head;
	int c = 0;
	while(temp != NULL){
		temp=temp->link;
		c++;
	}	
	return c;
}

template <class T>
T List<T>::get(int index){
	Node<T> *temp = head;
	int c = 1;
	while(temp != NULL){
		if(c == index){		
			cout<<temp->data<<" "<<endl;
		}
		temp=temp->link;
		c++;
	}	
}

template <class T>
void List<T>::print(){
	Node<T> *temp = head;
	cout<<("Jagsaalt: ");
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->link;
	}	
	cout<<endl;
}

int main() { 
	int n,a,b;

        List<char> list;
	list.add('X');
	list.add('Y');
	list.add('G');
	list.add('F');
        list.insert('b', 2);
        list.insert('q', 6);
        list.insert('c', 4);
        list.insert('d', 5);
	list.add('O');        
	list.print();
	cout << list.get(2);
	cout << list.lenght()<<endl;
	list.remove(2);
	list.print();
	cout << list.get(2);
	cout << list.lenght()<<endl;
}
