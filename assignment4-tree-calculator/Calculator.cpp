// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Calculator.h"

// default constructor
Calculator::Calculator (void)
{

}

// default destructor
Calculator::~Calculator (void) 
{

}

// get_infix
// method to get infix expression from user.
std::string Calculator::get_infix (void)
{
    // prompt the user to input a mathematical expression.
    std::string infix;
    std::cout << "type a mathematical expression: \n";
    getline(std::cin, infix);
    return infix;
}

// evaluate_infix
// method to evaluate infix expression.
int Calculator::evaluate_infix(std::string & infix, Expr_Builder & builder)
{
    std::istringstream input (infix);
    std::string token;

    // build expression
    builder.start_expression();
    while(!input.eof()) {
        input >> token;
        if(token == "+") {
            builder.build_add_operator();
        } else if(token == "-") {
            builder.build_subtract_operator();
        } else if(token == "*") {
            builder.build_multiply_operator();
        } else if(token == "/") {
            builder.build_divide_operator();
        } else if(token == "%") {
            builder.build_modulus_operator();
        } else if(token == "(") {
            builder.build_open_parenthesis();
        } else if(token == ")") {
            builder.build_close_parenthesis();
        } else if(token != " ") {
            builder.build_number(std::stoi(token));
        }
    }

    // return result
    int result = builder.get_expression()->eval();
    builder.end_expression();
    return result;
}

// calculate
// method to calculate expressions
void Calculator::calculate (void)
{
    // initialize variables needed to evaluate expression
    std::string infix = "";
    Expr_Tree_Builder builder;
    // loop until user enters QUIT
    while(infix != "QUIT") {
        infix = get_infix();
        if(infix == "QUIT") {
            return;
        }
        try {
            int answer = evaluate_infix(infix, builder);
            std::cout << answer << "\n";
            infix.clear();
        } catch (std::runtime_error & e) {
            std::cout << e.what() << "\n";
            builder.end_expression();
            continue;
        }
    }
}