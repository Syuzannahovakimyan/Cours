#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class Calculator{
    private:
        class Node{
            public:    
                int value;
                char op;
                Node* left  = nullptr;
                Node* right = nullptr;
        };
        Node* head;
        void parser(std::string expr, Node* ptr);
    public:
        Calculator(){}
        ~Calculator(){}

        double calculate(std::string expr);
        std::string erase_remove_spaces(std::string expr);
        bool is_sum_or_sub(const char& c);
        bool is_div_or_mul(const char& c);

};