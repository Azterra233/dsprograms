/*
Print and display
Insertion: Beginning, Position, End
Deletion: Beginning, Position, End
Traversing linked list
Linear search - iterative and recursive(ineffieciency why learn)
Sorting
Linked list Reversal - Iterative and Recursive 
Searching Sorted list
Doubly linked list
Insertion operations Doubly linked list
Deletion operations Doubly linked list
Circular linked list
Doubly circular linked list
XOR linked list
Stack
Queue
Postfix prefix infix operation expression notation
*/

/*
Polish prefix
Reverse polish notation postfix
Operators ka priority order, rules, etc.
When more ops come use associativity rule: usually left to right but not at all times.
*/

/*
Infix to postfix conversion
----------------------------
1. print operands as they arrive
2. if the stack is empty or contains a left parenthesis on top,  push the incoming operator on to the stack.
3. If the incoming symbol is "(" push it onto stack.
4. If the incoming symbol is ")", pop the stack and print the operator until left parenthesis is found.
5. if incoming symbol is highest precedance than to top of stack, push it on the stack.
6. if incoming symbol has lower precedence than top of stack, pop and print the top, then test the incoming operator against the new top of the stack.
7. if the incoming operator has equal precedence with top of the stack use associative rule. 
    i)  At the end of expression pop and print all operators of the stack. 
    ii) If associativity is left to right then pop and print the top of stack and then push the incoming operator.
    iii) if associativity is right to left then push the incoming operator.
*/

/*
Without using stack - 
eqn: 1. A+B/C
           = A + BC/
           = ABC/+





*/

