//HW1: Postfix Conversion
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

////////////////////////////
//Code for Stack
////////////////////////////

template <class T>
void ChangeSize1D(T*&a, const int oldSize, const int newSize)
{//Change size of 1-dimensional array.
    if (newSize < 0) throw "New length must be >= 0";
    T*temp = new T[newSize];              //new array
    int number = min(oldSize, newSize);   //number to copy
    copy(a, a + number, temp);
    delete [] a;                          //deallocate old memory (array)
    a = temp;
}

template <class T>
class Stack
{//A finite ordered list with zero or more elements.
public:
    Stack(int stackCapacity = 1000);
    //Create empty stack with initial capacity of 1000
    
    ~Stack();
    
    bool IsEmpty() const;
    //If number of elements in stack is 0, return true, else return false
    
    T& Top() const;
    //Return the top element
    
    void Push(const T& item);
    //Insert item into the top of stack
    
    void Pop();
    //Delete the top element of the stack
    
private:
    T*stack;        //array for stack elements
    int top;        //array position of top element, init. value = -1
    int capacity;   //capacity of stack array
};

template <class T>
Stack<T>::Stack(int stackCapacity):capacity(stackCapacity)
{
    if(capacity < 1) throw "Stack capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template <class T>
Stack<T>::~Stack(){
    delete[] stack;
}

template <class T>
inline bool Stack<T>::IsEmpty() const {return top == -1;}

template <class T>
inline T& Stack<T>::Top() const
{
    if(IsEmpty()) throw "Stack is empty";
    return stack[top];
}

template <class T>
void Stack<T>::Push(const T&x)
{//Add x to stack.
    if(top == capacity - 1)
    {
        ChangeSize1D(stack, capacity, 2*capacity);
        capacity *= 2;
    }
    stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{//Delete top element from stack.
    if(IsEmpty()) throw "Stack is empty. Cannot delete.";
    top--;
    //stack[top--].~T(); //Delete the element
}

////////////////////////////
//Code for Evaluation
////////////////////////////

bool IsNumber(char C)
{//Verify whether a character is numeric digit.
    if(C >= '0' && C <= '9') return true;
    return false;
}

bool IsOperator(char C)
{//Verify whether a character is operator symbol or not.
    if(C == '+' || C == '-' || C == '*' || C == '/') return true;
    return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{//Perform an operation and return output.
    if(operation == '+') return operand1 + operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;
    
    else cout << "Unexpected Error \n";
    return -1;
}

int Evaluate(string expression)
{//Evaluate postfix expression.
    Stack<int> S;
    
    for(int i = 0;i< expression.length();i++){
        //Scanning each character from left.
        //If character is operator, pop two elements from stack, perform operation and push the result back.
        if(IsOperator(expression[i])) {
            //If stack is empty, abort
            if(S.IsEmpty()) return -1;
            //Pop an operand.
            int operand2 = S.Top(); S.Pop();
            //If stack is empty, abort
            if(S.IsEmpty()) return -1;
            //Pop second operand.
            int operand1 = S.Top(); S.Pop();
            //Perform operation
            int result = PerformOperation(expression[i], operand1, operand2);
            //Push back result of operation on stack.
            S.Push(result);
        }
        else if(IsNumber(expression[i])){
            //Extract the numeric operand from the string
            int operand = expression[i] - '0';
            //Push operand on stack.
            S.Push(operand);
        }
    }
    int value = 0;
    value = S.Top(); S.Pop();
    //If expression is correct, stack is empty, output final value.
    if(S.IsEmpty()) return value;
    //If stack any elements left, then postfix expression is incorrect
    return -1;
}

////////////////////////////
//Code for Conversion
////////////////////////////

int OperatorLevel(char C)
{//Return level of operator for ParanthesesCheck.
    if (C == '+' || C == '-') return 1;
    else if (C == '*' || C == '/') return 2;
    else return 0;
}

bool ParanthesesCheck(char current, char next)
{//Check if parantheses are necessary.
    int current_lvl = OperatorLevel(current);
    int next_lvl = OperatorLevel(next);
    if(next_lvl > current_lvl) return true;
    return false;
}

char FutureOperator(string expression, int current_i)
{//Look for next operator. If found within next two characters, return operator. If not, return non-operator.
    if(IsOperator(expression[current_i+1])){
        return expression[current_i+1];
    }
    else if(IsOperator(expression[current_i+2])){
        return expression[current_i+2];
    }
    else{
        return 'n';
    }
}

int ParanCor(string expression, int i, bool right)
{//Find the corresponding operator for this layer of parantheses.
    char op_char = 'e';
    int paran_count = 0;
    //Reading from right to left.
    if(right == false){
        int j = i - 1;
        while(j >= 0){
            if(expression[j] == ')'){
                paran_count++;
                j--;
            }
            else if(expression[j] == '('){
                paran_count--;
                j--;
            }
            else if(IsOperator(expression[j]) && paran_count == 0){
                op_char = expression[j];
                goto found_op;
            }
            else j--;
        }
    }
    //Reading from left to right.
    else{
        int j = i + 1;
        while(j < expression.length()){
            if(expression[j] == '('){
                paran_count++;
                j++;
            }
            else if(expression[j] == ')'){
                paran_count--;
                j++;
            }
            else if(IsOperator(expression[j]) && paran_count == 0){
                op_char = expression[j];
                goto found_op;
            }
            else j++;
        }
    }
found_op:
    return op_char;
}

int OtherParan(string expression, int i, bool right)
{//Find the corresponding operator for this layer of parantheses.
    int paran_loc = 0;
    int paran_count = 0;
    //Reading from right to left.
    if(right == false){
        int j = i - 1;
        while(j >= 0){
            if(expression[j] == ')'){
                paran_count++;
                j--;
            }
            else if(expression[j] == '('){
                if(paran_count == 0){
                    paran_loc = j;
                    goto found_paran;
                }
                else{
                    paran_count--;
                    j--;
                }
            }
            else j--;
        }
    }
    //Reading from left to right.
    else{
        int j = i + 1;
        while(j < expression.length()){
            if(expression[j] == '('){
                paran_count++;
                j++;
            }
            else if(expression[j] == ')'){
                if(paran_count == 0){
                    paran_loc = j;
                    goto found_paran;
                }
                else{
                    paran_count--;
                    j++;
                }
            }
            else j++;
        }
    }
found_paran:
    return paran_loc;
}

string DelParan(string expression)
{//Delete unnecessary parantheses from infix expression.
    //Create stack for paranthesis locations that should be deleted.
    Stack<int> Sdel;
    //First and last parantheses should always be deleted.
    Sdel.Push(0);
    Sdel.Push(expression.length()-1);
    //Check each paranthesis and determine if it should be deleted.
    for(int i = 1; i < expression.length(); i++){
        if(expression[i] == ')' && expression[i+1] == '+'){
            Sdel.Push(i);
            Sdel.Push(OtherParan(expression, i, false));
        }
        else if(expression[i] == ')' && expression[i+1] == '-'){
            Sdel.Push(i);
            Sdel.Push(OtherParan(expression, i, false));
        }
        else if(expression[i] == ')' && expression[i+1] == '*'){
            if(ParanCor(expression, i, false) == '*' || ParanCor(expression, i, false) == '/'){
                Sdel.Push(i);
                Sdel.Push(OtherParan(expression, i, false));
            }
        }
        else if(expression[i] == ')' && expression[i+1] == '/'){
            if(ParanCor(expression, i, false) == '*' || ParanCor(expression, i, false) == '/'){
                Sdel.Push(i);
                Sdel.Push(OtherParan(expression, i, false));
            }
        }
        else if(expression[i] == '(' && expression[i-1] == '+'){
            Sdel.Push(i);
            Sdel.Push(OtherParan(expression, i, true));
        }
        else if(expression[i] == '(' && expression[i-1] == '-'){
            if(ParanCor(expression, i, true) == '*' || ParanCor(expression, i, true) == '/'){
                Sdel.Push(i);
                Sdel.Push(OtherParan(expression, i, true));
            }
        }
        else if(expression[i] == '(' && expression[i-1] == '*'){
            if(ParanCor(expression, i, true) == '*' || ParanCor(expression, i, true) == '/'){
                Sdel.Push(i);
                Sdel.Push(OtherParan(expression, i, true));
            }
        }
    }
    string infix = expression;
    //Sort Sdel first, then delete from largest to smallest.
    Stack<int> Stemp;
    Stack<int> Ssort;
    while(Sdel.IsEmpty() == false){
        while(Ssort.IsEmpty() == false && Sdel.Top() < Ssort.Top()){
            Stemp.Push(Ssort.Top());
            Ssort.Pop();
        }
        Ssort.Push(Sdel.Top());
        Sdel.Pop();
        while(Stemp.IsEmpty() == false){
            Ssort.Push(Stemp.Top());
            Stemp.Pop();
        }
    }
    //Deletion process.
    while(Ssort.IsEmpty() == false){
        infix.erase(Ssort.Top(),1);
        Ssort.Pop();
    }
    return infix;
}

string Postfix2Infix(string expression)
{//Convert postfix to infix expression, with necessary parantheses.
    Stack<string> S;
    //Scanning each character from left.
    for(int i = 0;i < expression.length();i++)
    {
        //If character is operator, pop two elements from stack, perform operation and push the result back.
        if(IsOperator(expression[i]))
        {
            //Pop two operands.
            string operand2 = S.Top(); S.Pop();
            string operand1 = S.Top(); S.Pop();
            //New string with parantheses.
            string result = '(' + operand1 + expression[i] + operand2 + ')';
            //Push back result on stack.
            S.Push(result);
        }
        else if(IsNumber(expression[i])){
            string number;
            number = expression[i];
            //Push operand on stack.
            S.Push(number);
        }
    }
    string infix_paran = S.Top();
    string infix = DelParan(infix_paran);
    return infix;
}

string Infix2Prefix(string expression)
{
    //Create stack for prefix expression (backwards).
    Stack<char> Spr;
    //Create stack for operators.
    Stack<char> Sop;
    //Read expression from right to left.
    for(int i = expression.length() - 1; i >= 0; i--){
        //Push numbers to Spr stack.
        if(IsNumber(expression[i])) Spr.Push(expression[i]);
        //When operators, including '(' and ')', are encountered:
        else if(IsOperator(expression[i]) || expression[i] == '(' || expression[i] == ')'){
            //Push operator into Sop stack.
            Sop.Push(expression[i]);
            //If top element is ')', jump out of while loop.
            if(Sop.Top() == ')') continue;
            //If top element is '(', push operators to Spr until ')' is encountered.
            else if(Sop.Top() == '('){
                Sop.Pop();  //Pop '('
                while(Sop.Top() != ')'){
                    Spr.Push(Sop.Top());
                    Sop.Pop();
                }
                Sop.Pop();  //Pop ')'
                continue;
            }
            //If top element is low level operator '+' or '-':
            else if(Sop.Top() == '+' || Sop.Top() == '-'){
                //Pop the '+' or '-' to be put back in later.
                Sop.Pop();
                if(Sop.IsEmpty() == false){
                    //Push all higher level operators into Spr stack.
                    while(Sop.Top() == '*' || Sop.Top() == '/'){
                        Spr.Push(Sop.Top());
                        Sop.Pop();
                        if(Sop.IsEmpty()) goto empty;
                    }
                }
            empty:
                //Push the '+' or '-' back into Sop stack.
                Sop.Push(expression[i]);
            }
        }
    }
    //Pop Sop operators into a string, and then reverse the order.
    string remaining_operators = "";
    while(Sop.IsEmpty() == false){
        remaining_operators += Sop.Top();
        Sop.Pop();
    }
    reverse(remaining_operators.begin(), remaining_operators.end());
    //Pop Spr elements into the prefix string right after remaining operators.
    string prefix = remaining_operators;
    while(Spr.IsEmpty() == false){
        prefix += Spr.Top();
        Spr.Pop();
    }
    return prefix;
}


int main(int argc, char **argv)
{
    string expression;
    cout<<"Enter Postfix Expression\n";
    while(getline(cin,expression)){
        //Evaluate postfix expression, and get value if expression is correct
        int result = Evaluate(expression);
        //If the format of the postfix expression is wrong, output False.
        if(result == -1)
        {
            cout << "False";
        }
        else{
            //Otherwise, output three lines:
            //First line: the corresponding infix expression
            string infix = Postfix2Infix(expression);
            cout << infix << endl;
            //Second line: the corresponding prefix expression
            string prefix = Infix2Prefix(infix);
            cout << prefix << endl;
            //Third line: the evaluated value. NO endl behind value. Result from initial evaluation.
            cout << result;
        }
    }
    return 0;
}
