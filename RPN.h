#pragma once
#include "Stack.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T>
class RPN : public Stack<T>{
private:
    vector<string> v;

public:

    //This function displays intro.
    void intro() {
        cout << "************** This is RPN calculator ****************" << endl;
        cout << "************** You can enter q to quit ***************" << endl;
        cout << "<< Formula and answer will display after entering q >>" << endl;
        cout << "Please enter" << endl;
    }

    //This is function that put together all the functions to perform calculation.
    T rpn() {
        intro();
        auto* stack = new Stack<double>();

        string input;
        while(true) {
            cout << ">>";
            cin >> input;
            double num;
            if(istringstream(input) >> num) {
                stack->push(num);
                v.push_back(to_string(num));
            }
            else if(isOperator(input)) {
                if(stack->size() >= 2) {
                    v.push_back(input);
                }
                performOp(input, stack);
            }
            else if(input == "q" && isOperator(v.back())) {
                cout << print() << stack->peek() << endl;
                return 0;
            }

            else if(input == "q" && !isOperator(v.back())) {
                cout << "Can't end right now because it's invalid format. please enter at least one operator." << endl;
            }

            else {
                cout << "Invalid input" << endl;
            }
        }
    }

    //This function returns true if next element is among (-, +, *, /)
    bool isOperator(const string& input) {
        string ops[] = {"-", "+", "*", "/"};
        for(int i = 0; i < 4; i++) {
            if(input == ops[i]) {
                return true;
            }
        }
        return false;
    }

    //This function calculate RPN calculator.
    void performOp(const string& input, Stack<double>* stack) {
        double lVal, rVal, result;

        if(stack->size() >= 2) {
            rVal = stack->peek();
            stack->pop();

            lVal = stack->peek();
            stack->pop();
        }

        if(input == "-") {
            result = lVal - rVal;

        }

        else if(input == "+") {
            result = lVal + rVal;
        }

        else if(input == "*") {
            result = lVal * rVal;
        }

        else if(input == "/") {
            result = lVal / rVal;
        }

        //only push numbers to stack and if stack has less than two numbers, it tells to enter number.
        if(result == result) {
            cout << "The answer so far is: " << result << "     if you want to quit, enter q, if you want to continue keep entering." << endl;
            stack->push(result);
        }else {
            cout << "Wrong format, you need to enter number, the operator you just entered will be ignored." <<endl;
        }
    }

    //This function get rid of 0s caused by to_string function.
    string trimmedString(string st) {
        reverse(st.begin(), st.end());
        int num;
        for(int i = 0; i < st.size(); ++i) {
            if(st[i] == '.') {
                reverse(st.begin(), st.end());
                return st.substr(0, st.find("."));
            }

            else if(st[i] != '.' && st[i] != '0') {
                num = st.size() - i;
                break;
            }
        }
        reverse(st.begin(), st.end());
        string trimmedSt = st.substr(0, num);
        return trimmedSt;
    }

    //This function prints whole RPN formula + answer
    string print() {
        string ans = "[ ";
        for(auto c : v) {
            ans += trimmedString(c) + " ";
        }
        ans += "] = ";

        return ans;
    }
};

