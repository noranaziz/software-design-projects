// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Expr_Tree_Builder.h"

// initializer
Expr_Tree_Builder::Expr_Tree_Builder (void)
    : tree_ (nullptr),
      not_finished_ (nullptr),
      finished_ (true),
      open_parenthesis_ (0),
      close_parenthesis_ (0),
      is_open_ (false),
      parenthesis_ ()
{

}

// destructor
Expr_Tree_Builder::~Expr_Tree_Builder (void)
{

}

// start expression
void Expr_Tree_Builder::start_expression (void)
{
    tree_ = new Expr_Tree ();
}

// build number
void Expr_Tree_Builder::build_number (int n)
{
    // create a number node
    Number_Expr_Node * node = new Number_Expr_Node(n);
    node->set_nested_level(open_parenthesis_);

    // set root to the number node if it's the first node.
    // otherwise, insert the node somewhere in the tree.
    if(tree_->get_root() == nullptr) {
        tree_->set_root(node);
    } else {
        insert_node(node);
    }
}

// build add operator 
void Expr_Tree_Builder::build_add_operator (void)
{
    // create add node
    Add_Expr_Node * node = new Add_Expr_Node();
    node->set_nested_level(open_parenthesis_);

    // insert node
    insert_node(node);
}

// build subtract operator
void Expr_Tree_Builder::build_subtract_operator (void)
{
    // create substract node
    Subtract_Expr_Node * node = new Subtract_Expr_Node();
    node->set_nested_level(open_parenthesis_);

    // insert node
    insert_node(node);
}

// build multiply operator
void Expr_Tree_Builder::build_multiply_operator (void)
{
    // create multiply node
    Multiply_Expr_Node * node = new Multiply_Expr_Node();
    node->set_nested_level(open_parenthesis_);

    // insert node
    insert_node(node);
}

// build divide operator
void Expr_Tree_Builder::build_divide_operator (void)
{
    // create divide node
    Divide_Expr_Node * node = new Divide_Expr_Node();
    node->set_nested_level(open_parenthesis_);

    // insert node
    insert_node(node);
}

// build modulus operator
void Expr_Tree_Builder::build_modulus_operator (void)
{
    // create modulus node
    Modulus_Expr_Node * node = new Modulus_Expr_Node();
    node->set_nested_level(open_parenthesis_);

    // insert node
    insert_node(node);
}

// build open parenthesis
void Expr_Tree_Builder::build_open_parenthesis (void)
{
    open_parenthesis_++;
    is_open_ = true;

    // save current root
    if(tree_->get_root() != nullptr) {
        parenthesis_.push(tree_->get_root());
        tree_->set_root(nullptr);
    }
}

// build close parenthesis
void Expr_Tree_Builder::build_close_parenthesis (void)
{
    // check if there are mismatched parenthesis
    // exception is thrown if there is
    close_parenthesis_++;
    if(open_parenthesis_ - close_parenthesis_ < 0) {
        throw std::runtime_error("Mismatched parenthesis.");
    }
    is_open_ = false;

    // get old root
    if(!parenthesis_.is_empty()) {
        Expr_Node * temp = parenthesis_.top();
        parenthesis_.pop();
        
        // fill the nodes in
        if(temp == nullptr) {
            temp = tree_->get_root();
            tree_->set_root(nullptr);
        } else if(temp->get_left_child() == nullptr) {
            temp->set_left_child(tree_->get_root());
            tree_->set_root(temp);
            return;
        } else {
            temp->set_right_child(tree_->get_root());
            tree_->set_root(temp);
            return;
        }

        // create a new number node from the result and add back to tree
        Number_Expr_Node * result_node = new Number_Expr_Node(temp->eval());
        insert_node(result_node);
    }
}

// end expression
void Expr_Tree_Builder::end_expression (void)
{
    delete tree_;
}

// insert node
void Expr_Tree_Builder::insert_node (Expr_Node * node)
{
    node->set_nested_level(open_parenthesis_);
    // if there is a node that hasn't finished being built,
    // finish building it by setting the new node to its right child
    if(finished_ == false) {
        not_finished_->set_right_child(node);
        finished_ = true;
    }

    // general algorithm:
    // if root is a number, set node as root and old root as its left child.
    // if root has left child but not a right child, set right child to node.
    // if the precedence of node is <= root, set node as root and old root as its left child
    // otherwise, set old node as left child of new node, and new node as right child of root
    else if(tree_->get_root()->get_precedence() == 3) {
        Expr_Node * temp = tree_->get_root();
        tree_->set_root(node);
        tree_->get_root()->set_left_child(temp);
    } else if(tree_->get_root()->get_right_child() == nullptr) {
        tree_->get_root()->set_right_child(node);
    } else if(node->get_precedence() <= tree_->get_root()->get_precedence() || (open_parenthesis_ > close_parenthesis_ && is_open_) || node->get_nested_level() > tree_->get_root()->get_nested_level()) {
        Expr_Node * temp = tree_->get_root();
        tree_->set_root(node);
        tree_->get_root()->set_left_child(temp);
    } else {
        Expr_Node * temp = tree_->get_root()->get_right_child();
        tree_->get_root()->set_right_child(node);
        node->set_left_child(temp);
        not_finished_ = node;
        finished_ = false;
    }
}

// get expression
Expr_Tree * Expr_Tree_Builder::get_expression (void)
{
    return this->tree_;
}