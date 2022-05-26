#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> m = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

template <typename T>
class Stack{
    private:
    T *stack;
    int top = -1;
    int size;

    public:
    Stack(int size) {
        this->size = size;
        stack = new T[size];
    }

    inline bool isEmpty() const{
        return top == - 1 ? true : false;
    }

    inline T peekTop() const{
        return stack[top];
    }

    inline bool isFull() const{
        return top == size - 1 ? true : false;
    }

    void push(T x) {
        if (this->isFull()) cout<<"The stack is full\n";
        else {
            stack[++top] = x;
            cout << x << " added to the stack" << endl;
        }
    }

    T pop() {
        if (this->isEmpty()) cout<<"The stack is empty.\n";
        else {
            cout << stack[top]  << " popped from the stack" << endl;
            return stack[top--];
        }
    }
};

string infixToPostfix(string inf){
    int n = inf.length();
    Stack<char> s(n);
    int i = 0;
    string post;
    while(i<n){
        if(isalpha(inf[i])){
            post.append(inf.substr(i,1));
        }else{
            if(inf[i] == '('){
                s.push(inf[i]);
            }else if(inf[i]==')'){
                while(true){
                    char temp = s.pop();
                    if(temp == '(') break;
                    post += temp;
                }
            }else{
                while(!s.isEmpty() and m[inf[i]] <= m[s.peekTop()]){
                    char temp = s.pop();
                    post += temp;
                }
                s.push(inf[i]);
            }
        }
        i++;
    }
    while(!s.isEmpty()){
        char temp = s.pop();
        post += temp;
    }
    return post;
}

int postfixToInfix(string post){
    int n = post.length();
    Stack<int> s(n);
    int i = 0;
    while(i<n){
        if(isdigit(post[i])){
            int temp = post[i] - '0';
            s.push(temp);
        }else{
            int a = s.pop();
            int b = s.pop();
            int temp;
            switch(post[i]) {
                case '+': temp = b + a; break;
                case '-': temp = b - a; break;
                case '*': temp = b * a; break;
                case '/': temp = b / a; break;
            }
            s.push(temp);
        }
        i++;
    }
    return s.pop();
}

int main() {
    string inf;
    cout<<"Enter the infix operation\n> ";
    getline(cin, inf);
    string post = infixToPostfix(inf);
    cout<<"Postfix expression is: "<<post<<endl;

    string postf;
    cout<<"Enter the postfix expression\n> ";
    getline(cin, postf);
    int eval = postfixToInfix(postf);
    cout<<"Evaluation of Postfix expression is: "<<eval<<endl;
    return 0;
}