#include <iostream>
#include <string>
#include "Stack.h"
#include "RPN.h"

using namespace std;


int main() {
    RPN<double>* rpn = new RPN<double>();
    rpn->rpn();
}
