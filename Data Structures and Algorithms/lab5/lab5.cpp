/**************************************************/
/*                                                */
/*  Lab 2 Starter file                            */
/*                                                */
/*  Name:Michael                                  */
/*  Student number:143152189                      */
/*                                                */
/**************************************************/
#include <string>
#include "stack.h"
bool bracketCheck(const std::string& s){
    Stack<char> stack;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '(':
        case '{':
        case '[':
            stack.push(s[i]);
            break;
        case ')':
            if (stack.isEmpty() || stack.top() != '(')
                return false;
            stack.pop();
            break;
        case '}':
            if (stack.isEmpty() || stack.top() != '{')
                return false;
            stack.pop();
            break;
        case ']':
            if (stack.isEmpty() || stack.top() != '[')
                return false;
            stack.pop();
            break;
        }
    }
    return stack.isEmpty();
}