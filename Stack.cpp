//+----------------------+
//|Nama : Catur Rahmat   | 
//|NIM  : 124180026      |
//+----------------------+
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
using namespace std;
struct data{
	char id[10];
	char name[30];
	char kepentingan[30];
};
typedef struct stack *typeptr;
struct stack{
	data dataSave;
	typeptr next;
	typeptr prev;
};
typeptr first, top;

typedef struct history *pointer;
struct history{
	data historySave;
	pointer next;
	pointer prev;	
};
pointer begin, last;
void createStack();
void createHistory();
int isEmptyStack();
int isEmptyHistory();
void push(data newData);
int checkingData(data checkingData);
void pushHistory(data newHistory);
void pop();
void printStack();
void printHistory();
int pilih;
enum pilih{
	PUSH = 1,
	POP,
	LIST,
	HISTORY,
	EXIT
};
int main(){
	createStack();
	createHistory();
		do{
		cout << "+============================+\n";
        cout << "|             STACK          |\n";
        cout << "+============================+\n";
        cout << "| 1. PUSH                    |\n";
        cout << "| 2. POP                     |\n";
        cout << "| 3. LIST                    |\n";
        cout << "| 4. HISTORY                 |\n";
        cout << "| 5. Keluar                  |\n";
        cout << "+============================+\n";
        cout << " Pilih : ";
        cin >> pilih;
        system("CLS");
        switch(pilih){
        	case PUSH : 
			{
			data newData;
			cout << "+============================+\n";
            cout << "|            PUSH            |\n";
            cout << "+============================+\n";
            cout << "|ID        : ";
            cin >> newData.id;
            cout << "|NAMA      : ";
            cin >> newData.name;
            cout << "|KEPERLUAN : ";
            cin >> newData.kepentingan;
            cout << "+============================+\n";
            push(newData); //mengirim struct ke dalam stack
            system("CLS");
				break;
			}
			case POP : 
			{
				pop();
				break;
			}
			case LIST : 
			{
				printStack();
				break;
			}
			case HISTORY :{
				printHistory();
				break;
			}
			case EXIT :
			{
				exit(0);
			}
			default :
			{
				cout << "MENU NOT FOUND!!!\n";
				system("PAUSE");
				system("CLS");		
			}
        	
		}
	}while(pilih == PUSH || pilih == POP || pilih == LIST || pilih == HISTORY || pilih > 5 );
	
}
void createStack(){
	typeptr NewStack;
	NewStack = (stack*)malloc(sizeof(stack));
	NewStack = NULL;
	first = NewStack;
	top   = NewStack;
}//OK
void createHistory(){
	pointer History;
	History = (history*)malloc(sizeof(history));
	History = NULL;
	begin = History;
	last  = History;
}//OK
int isEmptyStack(){
	if(first == NULL){
			return true;
	}else{
		return false;
	}
}//KOSONG
int isEmptyHistory(){
	if(begin == NULL){
			return true;
	}else{
		return false;
	}
}//KOSONG
int checkingData(data checkingData){
	if(first == NULL && top == NULL){
		return true;
	}else{
		typeptr help;
		help = first;
		do{
		if(strcmp(help -> dataSave.id, checkingData.id)!=0){
			return true;	
		}else{
			return false;
			cout << "CANT SAVE DATA, BECAUSE THE DATA ALREADY IN STACK!!!\n";
			system("PAUSE");
			system("CLS");
			
		}
		help = help -> next;
	}while(help -> next != NULL);	
	}
}//Checking Data
void push(data NewData){
	if(checkingData(NewData)){
	typeptr inputData;
	inputData = (stack *)malloc(sizeof(stack));
	inputData -> dataSave = NewData;
	inputData -> next = NULL;
	inputData -> prev = NULL;
	if(isEmptyStack()){
		first = inputData;
		top   = first;
	}else{
		top -> next = inputData;
		inputData -> prev = top;
		top = inputData;
	}	
	}else{
		cout << "CANT INPUT DATA\n";
	}
}//PUSH DATA
void pop(){
	if(isEmptyStack()){
		cout << "DATA NOT FOUND!!!\n";
		system("PAUSE");
		system("CLS");
	}else{
	typeptr help;
	if(top == first){
		pushHistory(top -> dataSave);
		free(top);
		first = NULL;
		top   = NULL;
		cout << "ALL DATA DELETED!!!\n";
		system("PAUSE");
		system("CLS");
	}else{
		help = top -> prev;
		pushHistory(top -> dataSave);
		free(top);
		top = help;
		top -> next = NULL;
		top -> prev = help -> prev;
	}
}
}//POP

void pushHistory(data newHistory ){
	pointer inputHistory;
	inputHistory = (history *)malloc(sizeof(history));
	inputHistory -> historySave = newHistory;
	inputHistory -> next = NULL;
	inputHistory -> prev = NULL;
	if(isEmptyHistory()){
		begin  = inputHistory;
		last   = begin;
	}else{
		last -> next = inputHistory;
		inputHistory -> prev = last;
		last = inputHistory;
	}
}//PUSH HISTORY
void printStack(){
	if(isEmptyStack()){
				cout <<"DATA NOT FOUND!!!";
	}else{
	cout << "                           STACK\n";
    cout << "+=======+====================+===========================+\n";
    cout << "|  ID   |        NAMA        |          KEPERLUAN        |\n";
    cout << "+=======+====================+===========================+\n";
    if(first == top){
    	cout <<"|" << setw(5) << first -> dataSave.id <<setw(3)<<"|"<< setw(12) << first -> dataSave.name << setw(9)<<"|";
            cout << setw(18) << first -> dataSave.kepentingan <<setw(10)<<"|"<<endl;
	}else{
	typeptr help;
	help = top;
	do{
		    cout <<"|" << setw(5) << help -> dataSave.id <<setw(3)<<"|"<< setw(12) << help -> dataSave.name << setw(9)<<"|";
            cout << setw(18) << help -> dataSave.kepentingan <<setw(10)<<"|"<<endl;
            help = help -> prev;
	}while(help != NULL);	
	}
}
    cout << "+=======+====================+===========================+\n";
		system("PAUSE");
		system("CLS");
}
void printHistory(){
	if(isEmptyHistory()){
		cout <<"DATA NOT FOUND!!!";
	}else{
	cout << "                          HISTORY\n";
    cout << "+=======+====================+===========================+\n";
    cout << "|  ID   |        NAMA        |          KEPERLUAN        |\n";
    cout << "+=======+====================+===========================+\n";
    if(begin == last){
    	    cout <<"|" << setw(5) << begin -> historySave.id <<setw(3)<<"|"<< setw(12) << begin -> historySave.name << setw(9)<<"|";
            cout << setw(18) << begin -> historySave.kepentingan <<setw(10)<<"|"<<endl;
	}else{
		    pointer helpHistory;
    helpHistory = last;
	do{
		    cout <<"|" << setw(7) << helpHistory -> historySave.id <<setw(3)<<"|"<< setw(12) << helpHistory -> historySave.name << setw(9)<<"|";
            cout << setw(18) << helpHistory -> historySave.kepentingan <<setw(10)<<"|"<<endl;
            helpHistory = helpHistory -> prev;
	}while(helpHistory != NULL);	
	}
}
    cout << "+=======+====================+===========================+\n";
		system("PAUSE");
		system("CLS");
}
