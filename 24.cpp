// Infix to postfix and prefix
#include <iostream>                         //for cin cout
#include <string>                           //for string expressions
#include <stack>                            //for LIFO approach
#include <cctype>                           //to use utility functions like isalnum() to test alphanumeric char
#include <algorithm>                        //to use reverse func
#include <cmath>                            //for pow() function

using namespace std;

bool isOperator(char c) {                   //helper function to check operator 
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {                   //helper function to return priority order of operator
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

// helper function to perform basic math operations
double applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    }
    return 0;
}

string infixToPostfix(const string &infix) {                //accepts an infix string and returns its postfix
    string postfix = "";
    stack<char> opStack;                                    //char type operator stack to temporarily hold operator and parenthesis

    for (char c : infix) {                                  //for loop to process input expression char by char from left to right
        if (isalnum(c)) {                                   //check whether char c is an operand                          
            postfix += c;                                   //operands pass to output string without entering stack
        } 
        else if (c == '(') {                                //to check opening parenthesis encountered or not
            opStack.push(c);                                //yes, then push to opStack(The temporary Operator stack to hold operators such as '+', '-')
        } 
        else if (c == ')') {                                //triggered when closing parenthesis reached
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty()) {
                opStack.pop();                              // Remove '('
            }
        } 
        else if (isOperator(c)) {
            // For right-associative '^', change >= to > if strict exponentiation handling is required
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

string infixToPrefix(const string &infix) {
    string reversedInfix = "";
    
    //Reverse string and swap parentheses
    for (int i = infix.length() - 1; i >= 0; i--) {            // i is the number of characters in string
        if (infix[i] == '(') {
            reversedInfix += ')';
        } else if (infix[i] == ')') {
            reversedInfix += '(';
        } else {
            reversedInfix += infix[i];
        }
    }

    //Convert modified infix to postfix with prefix precedence rules
    string reversedPostfix = "";
    stack<char> opStack;

    for (char c : reversedInfix) {
        if (isalnum(c)) {
            reversedPostfix += c;
        } 
        else if (c == '(') {
            opStack.push(c);
        } 
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                reversedPostfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty()) {
                opStack.pop(); // Remove '('
            }
        } 
        else if (isOperator(c)) {
            while (!opStack.empty() && opStack.top() != '(') {
                int p1 = precedence(opStack.top());
                int p2 = precedence(c);

                // For reversed prefix string:
                // Left-associative (+,-,*,/) use strictly >
                // Right-associative (^) uses >=
                if ((c == '^' && p1 >= p2) || (c != '^' && p1 > p2)) {
                    reversedPostfix += opStack.top();
                    opStack.pop();
                } else {
                    break;
                }
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        reversedPostfix += opStack.top();
        opStack.pop();
    }

    //Reverse postfix to get final prefix expression
    string prefix = reversedPostfix;
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

// evaluate postfix by scanning left to right
double evaluatePostfix(const string &postfix) {
    stack<double> st;                                       // stack to store numerical operands during evaluation

    for (char c : postfix) {                                // scan postfix string from left to right
        if (isdigit(c)) {
            st.push(c - '0');                               // convert char digit to integer and push to stack
        } else if (isOperator(c)) {
            double op2 = st.top(); st.pop();                // pop second operand
            double op1 = st.top(); st.pop();                // pop first operand
            st.push(applyOp(op1, op2, c));                  // evaluate op1 operator op2 and push result
        }
    }
    return st.top();
}

// evaluate prefix by scanning right to left
double evaluatePrefix(const string &prefix) {
    stack<double> st;                                       // stack to store numerical operands during evaluation

    for (int i = prefix.length() - 1; i >= 0; i--) {        // scan prefix string from right to left
        char c = prefix[i];
        if (isdigit(c)) {
            st.push(c - '0');                               // convert char digit to integer and push to stack
        } else if (isOperator(c)) {
            double op1 = st.top(); st.pop();                // pop first operand
            double op2 = st.top(); st.pop();                // pop second operand
            st.push(applyOp(op1, op2, c));                  // evaluate op1 operator op2 and push result
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);                                    //getline to read entire line of expression including spaces

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Prefix expression: " << prefix << endl;

    cout << "Postfix Evaluation result: " << evaluatePostfix(postfix) << endl;
    cout << "Prefix Evaluation result: " << evaluatePrefix(prefix) << endl;

    return 0;
}

// Works only with single digits or chars
// Both Postfix and Prefix expressions compute the same numerical result but their string representations and traversal orders are different.