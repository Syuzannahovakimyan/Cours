#include "calculator.hpp"

void Calculator::parser(std::string expr, Node* ptr){
    int op_index = 0;
    for(int i = 0; i < expr.length(); ++i){
        if(is_sum_or_sub(expr[i])){
            ptr->op = expr[i];
            op_index = i;
            break;
        }
        if (is_div_or_mul(expr[i]) && !ptr->op) {
            ptr->op = expr[i];
            op_index = i;
        }
    }
}

double Calculator::calculate(std::string expr){
    expr = erase_remove_spaces(expr);
    parser(expr, head);
    return 0.0;
}



std::string Calculator::erase_remove_spaces(std::string expr){
    expr.erase(std::remove(expr.begin(), expr.end(), ' '), expr.end());
    return expr;
}

bool Calculator::is_sum_or_sub(const char &c){
    bool result = false;
    if(c == '+' || c == '-'){
        result = true;
    }
    return result;
}

bool Calculator::is_div_or_mul(const char &c){
    bool result = false;
    if(c == '*' || c == '/'){
        result = true;
    }
    return result;
}
