//LATIHAN RESPONSI
//NAME  = CATUR RAHMAT
//NIM   = 124180026

#include <iostream>
#define MAX 30
using namespace std;
int TOP = 0;
int IP = 0;
int stack[MAX];
void createStack();
int isEmpty();
int isFull();
void push(int newData);
void add();
void sub();
void mpy();
void div();
void result();
void createStack(){
	stack[TOP] = 0;
}
int isEmpty(){
	if(TOP == 0){
		return true;
	}else{
		return false;
	}
}
int isFull(){
	if(TOP ==MAX){
		return true;
	}else{
		return false;
	}
}
void push(int newData){
	if(isFull()){
		cout << "Sorry, Stack is Full!!!\n";
	}else{
		TOP++;
		stack[TOP] = newData;
		stack[0] = TOP;
	}	
}
void result(){
	if(isEmpty()){
		cout << "Sorry, Stack is Empty!!!\n";
	}else{
		IP = stack[TOP];
		cout << "Y = (6+(2*3))/(4-1) : "<<IP<<endl;
		TOP--;
		stack[0] = TOP;
	}
}
void add(){
	IP = stack[TOP];
	TOP--;
	stack[0] = TOP;
	stack[TOP] = stack[TOP] + IP;	
}
void sub(){
	IP = stack[TOP];
	TOP--;
	stack[0] = TOP;
	stack[TOP] = stack[TOP] - IP;
}
void mpy(){
	IP = stack[TOP];
	TOP--;
	stack[0] = TOP;
	stack[TOP] = stack[TOP] * IP;
}
void div(){
	IP = stack[TOP];
	TOP--;
	stack[0] = TOP;
	stack[TOP] = stack[TOP] / IP;
}
int main(){
	//Y = (6+(2*3))/(4-1)
	push(6);
	push(2);
	push(3);
	mpy();
	add();
	push(4);
	push(1);
	sub();
	div();
	result();
	
}
