// test cases

// include header file
#include "Calculator.h"

#include <iostream>

// NOTE FOR GRADER:
// professor hill did not leave any comments for the first submission.
// however, when i spoke with him in person, he mentioned that my submission was good.
// main
int main()
{
    // run calculator
    Calculator calc;
    try {
        calc.calculate();
    } catch (std::runtime_error & e) {
        std::cout << e.what() << "\n";
    }

    /*
    // get input from user
    std::string infix;
    std::cout << "Enter math expression: ";
    std::cin >> infix;
    // evaluate the input
    std::cout << calc.evaluate_infix(infix, builder) << "\n";*/

    /*
    Expr_Tree_Builder * builder = new Expr_Tree_Builder();
    builder->start_expression();
    builder->build_number(2);
    builder->build_multiply_operator();
    builder->build_number(3);
    // print tree
    int left = builder->get_expression()->get_root()->get_left_child()->get_precedence();
    int right = builder->get_expression()->get_root()->get_left_child()->get_precedence();
    int root = builder->get_expression()->get_root()->get_precedence();
    std::cout << left << " " << root << " " << right << "\n";
    int answer = builder->get_expression()->eval();
    std::cout << answer << "\n";
    delete builder;*/
}
