//+----------------------+
//|Nama : Catur Rahmat   | 
//|NIM  : 124180026      |
//+----------------------+
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
using namespace std;
typedef int noAntrian;
struct data{
	noAntrian no;
	char name[30];
	char kepentingan[30];
};
typedef struct queue *typeptr;
struct queue{
	data dataSave;
	typeptr next;
	typeptr prev;
};
typeptr first, top; // PONITER QUEUE

typedef struct history *pointer;
struct history{
	data historySave;
	pointer next;
	pointer prev;	
};
pointer begin, last;// PONITER HISTORY
//MAIN METHOD
void createQueue();
void createHistory();
int isEmptyQueue();
int isEmptyHistory();
void enqueue(data newData);
int checkingData(data checkingData);
void enqueueHistory(data newHistory);
void dequeue();
void printQueue();
void printHistory();
int pilih;
enum pilih{
	ENQUEUE = 1,
	DEQUEUE,
	LIST,
	HISTORY,
	EXIT
};
int main(){
	createQueue();
	createHistory();
		do{
		cout << "+============================+\n";
        cout << "|            QUEUE           |\n";
        cout << "+============================+\n";
        cout << "| 1. ENQUEUE                 |\n";
        cout << "| 2. DEQUEUE                 |\n";
        cout << "| 3. LIST                    |\n";
        cout << "| 4. HISTORY                 |\n";
        cout << "| 5. Keluar                  |\n";
        cout << "+============================+\n";
        cout << " Pilih : ";
        cin >> pilih;
        system("CLS");
        switch(pilih){
        	case ENQUEUE : 
			{
			data newData;
			if(isEmptyQueue()){
				newData.no = 0;
			}
			cout << "+============================+\n";
            cout << "|            PUSH            |\n";
            cout << "+============================+\n";
            cout << "|ID        : "<< ++newData.no <<endl;
            cout << "|NAMA      : ";
            cin >> newData.name;
            cout << "|KEPERLUAN : ";
            cin >> newData.kepentingan;
            cout << "+============================+\n";
            enqueue(newData); //mengirim struct ke dalam stack
            system("CLS");
				break;
			}
			case DEQUEUE : 
			{
				dequeue();
				break;
			}
			case LIST : 
			{
				printQueue();
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
	}while(pilih == DEQUEUE || pilih == ENQUEUE || pilih == LIST || pilih == HISTORY || pilih > 5 );
	
}
void createQueue(){
	typeptr NewQueue;
	NewQueue = (queue*)malloc(sizeof(queue));
	NewQueue = NULL;
	first = NewQueue;
	top   = NewQueue;
}//OK
void createHistory(){
	pointer History;
	History = (history*)malloc(sizeof(history));
	History = NULL;
	begin = History;
	last  = History;
}//OK
int isEmptyQueue(){
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

void enqueue(data NewData){
	typeptr inputData;
	inputData = (queue *)malloc(sizeof(queue));
	inputData -> dataSave = NewData;
	inputData -> next = NULL;
	inputData -> prev = NULL;
	if(isEmptyQueue()){
		first = inputData;
		top   = first;
		system("PAUSE");
	}else{
		top -> next = inputData;
		inputData -> prev = top;
		top = inputData;
	}	
}//PUSH DATA
void dequeue(){
	if(isEmptyQueue()){
		cout << "DATA NOT FOUND!!!\n";
		system("PAUSE");
		system("CLS");
	}else{
	cout << "                        INFO DEQUEUE\n";
    cout << "+=======+====================+===========================+\n";
    cout << "|  ID   |        NAMA        |          KEPERLUAN        |\n";
    cout << "+=======+====================+===========================+\n";
	typeptr help;
	if(top == first){
		enqueueHistory(top -> dataSave);
    	cout <<"|" << setw(5) << first -> dataSave.no <<setw(3)<<"|"<< setw(12) << first -> dataSave.name << setw(9)<<"|";
        cout << setw(18) << first -> dataSave.kepentingan <<setw(10)<<"|"<<endl;
		free(first);
		first = NULL;
		top   = first;
		cout << "ALL DATA DELETED!!!\n";
		system("PAUSE");
		system("CLS");
	}else{
		help = first -> next;
		enqueueHistory(first -> dataSave);
		cout <<"|" << setw(5) << first -> dataSave.no <<setw(3)<<"|"<< setw(12) << first -> dataSave.name << setw(9)<<"|";
        cout << setw(18) << first -> dataSave.kepentingan <<setw(10)<<"|"<<endl;
		free(first);
		first = help;
		first -> prev = NULL;
		first -> next = help -> next;
	}
}
    cout << "+=======+====================+===========================+\n";
system("PAUSE");
system("CLS");
}//POP

void enqueueHistory(data newHistory ){
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
void printQueue(){
	if(isEmptyQueue()){
				cout <<"DATA NOT FOUND!!!";
	}else{
	cout << "                           QUEUE\n";
    cout << "+=======+====================+===========================+\n";
    cout << "|  ID   |        NAMA        |          KEPERLUAN        |\n";
    cout << "+=======+====================+===========================+\n";
    if(first == top){
    	cout <<"|" << setw(5) << first -> dataSave.no <<setw(3)<<"|"<< setw(12) << first -> dataSave.name << setw(9)<<"|";
            cout << setw(18) << first -> dataSave.kepentingan <<setw(10)<<"|"<<endl;
	}else{
	typeptr help;
	help = first;
	do{
		    cout <<"|" << setw(5) << help -> dataSave.no <<setw(3)<<"|"<< setw(12) << help -> dataSave.name << setw(9)<<"|";
            cout << setw(18) << help -> dataSave.kepentingan <<setw(10)<<"|"<<endl;
            help = help -> next;
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
    	    cout <<"|" << setw(5) << begin -> historySave.no <<setw(3)<<"|"<< setw(12) << begin -> historySave.name << setw(9)<<"|";
            cout << setw(18) << begin -> historySave.kepentingan <<setw(10)<<"|"<<endl;
	}else{
		    pointer helpHistory;
    helpHistory = begin;
	do{
		    cout <<"|" << setw(7) << helpHistory -> historySave.no <<setw(3)<<"|"<< setw(12) << helpHistory -> historySave.name << setw(9)<<"|";
            cout << setw(18) << helpHistory -> historySave.kepentingan <<setw(10)<<"|"<<endl;
            helpHistory = helpHistory -> next;
	}while(helpHistory != NULL);	
	}
}
    cout << "+=======+====================+===========================+\n";
		system("PAUSE");
		system("CLS");
}
