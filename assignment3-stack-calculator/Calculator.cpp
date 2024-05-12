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

// infix_to_postfix
// method to convert infix expression to postfix.
void Calculator::infix_to_postfix (const std::string & infix, Expr_Command_Factory & factory, Array <Expr_Command *> & postfix)
{
    // create an input stream parser
    std::istringstream input (infix);

    // current token in string/stream
    std::string token;

    // create command object
    Expr_Command * command = 0;

    // create stack to store commands
    Stack <Expr_Command *> temp;

    // counter to keep track of open parenthesis
    int open_parenthesis = 0;

    // create queue to store postfix
    Queue <Expr_Command *> postfix_queue;

    // read infix string
    while(!input.eof()) {
        input >> token;
        // create appropriate commands
        if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
            if(token == "+") {
                command = factory.create_add_command();
            } else if(token == "-") {
                command = factory.create_subtract_command();
            } else if(token == "*") {
                command = factory.create_multiply_command();
            } else if(token == "/") {
                command = factory.create_divide_command();
            } else if(token == "%") {
                command = factory.create_modulus_command();
            }
            // if stack is empty or the operator has greater 
            // precedence than the top of the stack, push
            // the command onto the stack.
            if(temp.is_empty() || command->get_precedence() > temp.top()->get_precedence()) {
                command->set_nested_level(open_parenthesis);
                temp.push(command);
            } else {
                // otherwise, enqueue the top of the stack to postfix and pop it from the stack, then push a new command.
                while(!temp.is_empty() && command->get_precedence() <= temp.top()->get_precedence() && open_parenthesis == command->get_nested_level()) {
                    postfix_queue.enqueue(temp.top());
                    temp.pop();
                }
                temp.push(command);
            }
        // If token is a parenthesis, pop elements from stack 
        // and append until found matching open parenthesis
        } else if(token == "(") {
            open_parenthesis++;
        } else if(token == ")") {
            open_parenthesis--;
            Expr_Command * current = command;
            // empty temp stack into postfix queue
            while(!temp.is_empty() && command->get_precedence() <= temp.top()->get_precedence() && open_parenthesis == current->get_nested_level()) {
                current = temp.top();
                postfix_queue.enqueue(temp.top());
                temp.pop();
            }
        } else if(token != " ") {
            command = factory.create_number_command(std::stoi(token));
            command->set_nested_level(open_parenthesis);
            postfix_queue.enqueue(command);
        } else {
            continue;
        }
    }
    
    // empty stack into postfix queue
    while(!temp.is_empty()) {
        postfix_queue.enqueue(temp.top());
        temp.pop();
    }

    // check matching parenthesis
    if(open_parenthesis != 0) {
        throw std::runtime_error("Unmatched parenthesis.");
    }

    // get postfix from queue
    postfix.resize(postfix_queue.size());
    for(size_t i = 0; !postfix_queue.is_empty(); i++) {
        postfix[i] = postfix_queue.dequeue();
    }
}

// evaluate_postfix
// method to evaluate postfix expression.
void Calculator::evaluate_postfix(Array<Expr_Command *> & postfix)
{
    for(Array_Iterator<Expr_Command *> iter(postfix); !iter.is_done(); iter.advance()) {
        (*iter)->execute();
        delete * iter;
    }
}

// calculate
// method to calculate expressions
void Calculator::calculate (void)
{
    try {
        // initialize variables needed to convert to postfix
        std::string infix = "";
        Stack<int> result;
        Stack_Expr_Command_Factory factory(result);
        Array<Expr_Command *> postfix;
        // loop until user enters QUIT
        while(infix != "QUIT") {
            infix = get_infix();
            if(infix == "QUIT") {
                return;
            }
            infix_to_postfix(infix, factory, postfix);
            evaluate_postfix(postfix);
            std::cout << result.top() << "\n\n";
        }
    } catch(...) {
        std::cerr << "Exception occurred.\n";
    }
}