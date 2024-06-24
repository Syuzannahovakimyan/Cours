#include "calculator.hpp"

void Calculator::parser(std::string expr, Node* ptr) {
    if(expr.empty()) {
        return;
    }

    if (expr[0] == '(' && expr[expr.length() - 1] == ')' ) {
        expr = expr.substr(1, expr.length() - 2);
    }

    int op_index = find_op_index(expr, ptr);
    // [1*2+6-3/7]
    ptr = new Node;
    ptr->op = expr[op_index];

    auto left = expr.substr(0, op_index);
    auto right = expr.substr(op_index + 1, expr.length() - op_index - 1);

    parser(left, ptr->left);
    parser(right, ptr->right);
}

int Calculator::find_op_index(std::string expr, Node *ptr) {
    int op_index = 0;
    int brackets_level = 0;

    for(int i = 0; i < expr.length(); ++i){
        if (expr[i] == '(') {
            brackets_level++;
        }
        else if (expr[i] == ')') {
            brackets_level--;
        }

        if(brackets_level == 0) {
            if (is_sum_or_sub(expr[i])){
                ptr->op = expr[i];
                op_index = i;
                break;
            }
            else if (is_div_or_mul(expr[i]) && !ptr->op) {
                ptr->op = expr[i];
                op_index = i;
            }
        }
    }

    return op_index;
}

double Calculator::calculate(std::string expr) {
    expr = erase_remove_spaces(expr);
    parser(expr, head);
    return 0.0;
}



std::string Calculator::erase_remove_spaces(std::string expr) {
    expr.erase(std::remove(expr.begin(), expr.end(), ' '), expr.end());
    return expr;
}

bool Calculator::is_sum_or_sub(const char &c) {
    bool result = false;
    if(c == '+' || c == '-'){
        result = true;
    }
    return result;
}

bool Calculator::is_div_or_mul(const char &c) {
    bool result = false;
    if(c == '*' || c == '/'){
        result = true;
    }
    return result;
}
