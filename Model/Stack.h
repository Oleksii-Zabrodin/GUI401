/*
 * Stack.h
 *
 *  Created on: Mar 25, 2025
 *      Author: lex
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

template <typename T, size_t N>
class Stack {
public:
    void push(T value) { if (top < N - 1) data[++top] = value; }
    void pop() { if (top >= 0) --top; }
    T topValue() const { return (top >= 0) ? data[top] : T{}; }
    bool empty() const { return top == -1; }
    bool full() const { return top == N - 1; }

private:
	T data[N];
	int top = -1;
};

#endif /* STACK_H_ */
