// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Eval_Expr_Tree.h"
#include <stdexcept> // to catch division by 0

// constructor
Eval_Expr_Tree::Eval_Expr_Tree (void)
    : result_ (0),
      stack_  (new Stack<int>()),
      num1_ (0),
      num2_ (0)
{

}

// destructor
Eval_Expr_Tree::~Eval_Expr_Tree (void)
{
    delete stack_;
}

// visit addition node
void Eval_Expr_Tree::Visit_Addition_Node (Add_Expr_Node & node)
{
    // visit left child
    node.get_left_child()->accept(*this);

    // visit right child
    node.get_right_child()->accept(*this);

    // remove numbers from stack and set them to private variables (num1 and num2)
    num2_ = stack_->top();
    stack_->pop();
    num1_ = stack_->top();
    stack_->pop();

    // result of addition is pushed to stack
    stack_->push(num1_ + num2_);
}

// visit subtraction node
void Eval_Expr_Tree::Visit_Subtraction_Node (Subtract_Expr_Node & node)
{
    // visit left child
    node.get_left_child()->accept(*this);

    // visit right child
    node.get_right_child()->accept(*this);

    // remove numbers from stack and set them to private variables (num1 and num2)
    num2_ = stack_->top();
    stack_->pop();
    num1_ = stack_->top();
    stack_->pop();

    // result of subtraction is pushed to stack
    stack_->push(num1_ - num2_);
}

// visit multiplication node
void Eval_Expr_Tree::Visit_Multiplication_Node (Multiply_Expr_Node & node)
{
    // visit left child
    node.get_left_child()->accept(*this);

    // visit right child
    node.get_right_child()->accept(*this);

    // remove numbers from stack and set them to private variables (num1 and num2)
    num2_ = stack_->top();
    stack_->pop();
    num1_ = stack_->top();
    stack_->pop();

    // result of multiplication is pushed to stack
    stack_->push(num1_ * num2_);
}

// visit division node
void Eval_Expr_Tree::Visit_Division_Node (Divide_Expr_Node & node)
{

    // visit left child
    node.get_left_child()->accept(*this);

    // visit right child
    node.get_right_child()->accept(*this);

    // remove numbers from stack and set them to private variables (num1 and num2)
    num2_ = stack_->top();
    // check if division by 0 occurs
    if(num2_ == 0) {
        throw std::runtime_error("Division by 0");
    }
    stack_->pop();
    num1_ = stack_->top();
    stack_->pop();

    // result of division is pushed to stack
    stack_->push(num1_ / num2_);
}

// visit modulus node
void Eval_Expr_Tree::Visit_Modulus_Node (Modulus_Expr_Node & node)
{
    // visit left child
    node.get_left_child()->accept(*this);

    // visit right child
    node.get_right_child()->accept(*this);

    // remove numbers from stack and set them to private variables (num1 and num2)
    num2_ = stack_->top();
    // check if division by 0 occurs
    if(num2_ == 0) {
        throw std::runtime_error("Division by 0");
    }
    stack_->pop();
    num1_ = stack_->top();
    stack_->pop();

    // result of modulus is pushed to stack
    stack_->push(num1_ % num2_);
}

// visit number node
void Eval_Expr_Tree::Visit_Number_Node (Number_Expr_Node & node)
{
    stack_->push(node.eval());
}

// result
int Eval_Expr_Tree::result (void)
{
    result_ = stack_->top();
    return result_;
}