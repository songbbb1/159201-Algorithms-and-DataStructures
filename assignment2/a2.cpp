// Bai Song 
// Test all passed

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>

using namespace std;

/* implement your stack here */
struct Node {
  float data;
  Node *next;
};

class Stack {
private:                         //the data differs from the array
  Node *listpointer;
public:                          //the functions (methods) are identical
  Stack();
  ~Stack();
  void Push(float newthing);
  void Pop();
  float Top();
  bool isEmpty();
};

Stack::Stack() {
// constructor
  listpointer = NULL;
}

Stack::~Stack() {
// destructor

}

void Stack::Push(float newthing) {
// place the new thing on top of the stack
Node *temp;
  temp = new Node;             //same as add node to front of linked-list
  temp->data = newthing;
  temp->next = listpointer;    //NOTE: no overflow problem
  listpointer = temp;
}
void Stack::Pop() {
// remove top item from the stack
Node *p;
  p = listpointer;
  if (listpointer != NULL) {     //        check to avoid underflow
     listpointer = listpointer->next;
     delete p;                //always delete a TEMPORARY variable
  }
}

float Stack::Top() {
// return the value of the top item
  return listpointer->data;  //WARNING: what if listpointer is NULL?
}

bool Stack::isEmpty() {
// returns true if the stack is empty
  if (listpointer == NULL) {
     return true;
  }
  return false;
}



int main( int argc, char** argv ){//get arguments from command line, i.e., yourexec filename
	Stack A;
	int result, op1,op2,number,i,final;
	char oper;
	string expression;
	ifstream input_file;
	if(argc==2) input_file.open(argv[1]);
	else { cout<< "cannot read file " << argv[1] << endl; exit(0);}
	while(!input_file.eof()){
		getline(input_file,expression);
		if(isdigit(expression[0])){
		  stringstream line(expression);
		  line >> number;
		  cout << "reading number " << number << endl;
		  //modify here to deal with the Stack
		  //PUSH number
		  A.Push(number);
		}
		else {
		  if(expression[0]=='+' || expression[0]=='-'|| expression[0]=='/'||expression[0]=='*') {
		    stringstream line(expression);
		    line >> oper;
		    cout << "reading operator " << oper << endl;

		    if( !A.isEmpty()) {
				op2 =  A.Top();  
				A.Pop();    // op2 is  before op1 here
			}
			else{
				cout << "too many operators"<<endl;
				exit(0);
			}
			if( !A.isEmpty()) {
				op1 = A.Top();  
				A.Pop();
			}
			else {
				cout << "too many operators"<<endl;
				exit(0);
			}
			//calculate
			if(oper=='+'){
				result =  op1 + op2;
			}else if(oper=='-'){
				result =  op1 - op2;
			}else if(oper=='*'){
				result =  op1 * op2;
			}else if(oper=='/'){
				result =  op1 / op2;
			}
			
			A.Push(result);
		  }
		}
}
	//finalanswer = TOP
	
	final = A.Top();
	//cout<<"The result is " << final << endl;
	//the last element of the stack should be the final answer...
	A.Pop();
	if (!A.isEmpty()) 
	{
		cout<< "too many numbers"<<endl;
	}
	else{
		cout<<"The result is " << final << endl;
	}
	A.~Stack();
}
