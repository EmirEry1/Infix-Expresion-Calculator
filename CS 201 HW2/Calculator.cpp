#include "Calculator.h"

Calculator::Calculator(string infixExpression) {

	
	this->infixExpression = infixExpression;
	stack = new Stack();
	string token;
	istringstream iss(infixExpression);
	while (token.compare(";") != 0) {

		iss >> token;
		if (token == ";") {
			break;
		}
		if (token.compare("*") != 0 && token.compare("+") != 0 && token.compare("/") != 0 && token.compare("-") != 0) {

			if (token.compare("(")!=0 && token.compare(")")!=0) {
				postfixExpression += token + " ";
				
				
			}
			else if(token.compare("(")==0){
				stack->push(new StackItem(token));
			}
			else {
				while (stack->top()->toString() != "(") {
					postfixExpression += stack->top()->toString() + " ";
					
					stack->pop();

				};
				stack->pop();
			}

		}
		else if (token.compare("+") == 0 || token.compare("-")==0) {
			
			if (stack->top() != NULL) {
				while (stack->top()->toString() == "*" || stack->top()->toString() == "/" || stack->top()->toString() == "+" || stack->top()->toString() == "-") {

					postfixExpression += stack->top()->toString() + " ";
					
					stack->pop();
					if (stack->top() == NULL) {
						break;
					}
				}
			}
								
			
			stack->push(new StackItem(token));
			

		}
		else {
			stack->push(new StackItem(token));
		}

	}
	while (stack->top()!= NULL) {
		postfixExpression+=stack->top()->toString()+" ";
		
		stack->pop();
	}
	
	postfixExpression += ";";
	
}
string Calculator::getPostfix() {
	return this->postfixExpression;
}

int Calculator::calculate() {
	string token1;
	istringstream iss(postfixExpression);
	
	
	while (token1.compare(";") != 0) {
		
		
		iss >> token1;

		if (token1 == ";") {
			break;
		}
		
		if (token1.compare("*") != 0 && token1.compare("+") != 0 && token1.compare("/") != 0 && token1.compare("-") != 0) {

			stack->push(new StackItem(token1));
			
		}
		else {

				int num1 = atoi((stack->top()->toString()).c_str());
				stack->pop();
				int num2 = atoi((stack->top()->toString()).c_str());
				stack->pop();
				
				int inResult;
				if (token1 == "+") {
					inResult = num1 + num2;
					
				}
				else if (token1 == "-") {
					inResult = num2-num1;
				}
				else if (token1 == "*") {
					inResult = num1 * num2;
				}
				else if (token1 == "/") {
					inResult = num2 / num1;
				}
					

				string s = to_string(inResult);
				
				stack->push(new StackItem(s));
			
			
		}
	}
	
	
	int result = atoi(stack->top()->toString().c_str());
	stack->pop();
	
	return result;
}
Calculator::~Calculator() {

}