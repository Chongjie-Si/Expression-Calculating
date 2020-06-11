//
// Created by 司翀杰 on 2019/9/1.
//

#ifndef UNTITLED_EQUATION_COMMON_H
#define UNTITLED_EQUATION_COMMON_

#endif //UNTITLED_EQUATION_COMMON_H

#include <string>
#include <sstream>
#include <stack>
#include "equation.h"


class Node{
public:
    string data = "";
    Node* left = nullptr;
    Node* right = nullptr;
};

// 判断单个char是否为数字
bool isnumber(char c){
    if(c>='0' and c<='9') return true;
    else return c == '.' ?  true : false;
}

// 判断 string 是否为数字
bool isStringNum(string &s){
    for(char i : s) {
        if(s.size()>1 && i == '-') return true;
        else if(i == 'e' or i == 'i') return true;
        else if (!isnumber(i)) return false;
    }
    return true;
}

//创建一棵树
void CreateTree(Node* &t){
    t = new Node;
    cin>>t->data;
    if(t->data == "-1"){
        t = nullptr;
        return;
    }
    CreateTree(t->left);
    CreateTree(t->right);
}

// string 转 double  把str输入到流当中，再把流输入到double
double StringToNum(const string &str){
    istringstream iss(str);
    double num;
    iss>>num;
    return num;
}

// string 转 complex
complex<double> StringToComplex(const string &str){
    string::size_type pos = str.find('i');
    if(pos != string::npos){
        string temp = str.substr(0,pos);
        if(temp == ""){
            complex<double> num(0,1);
            return num;
        }
        istringstream iss(temp);
        double image;
        iss>>image;
        complex<double> num(0,image);
        return num;
    }
    else{
        istringstream iss(str);
        double real;
        iss>>real;
        complex<double> num(real);
        return num;
    }
}

// 一元运算符通用
template <typename T>
void unaryOperator(Node* &root, stack<T> &path){
    T temp = path.top();
    path.pop();
    if(root->data == "sin") path.push(sin(temp));
    else if(root->data == "cos") path.push(cos(temp));
    else if(root->data == "tan") path.push(tan(temp));
    else if(root->data == "asin") path.push(asin(temp));
    else if(root->data == "acos") path.push(acos(temp));
    else if(root->data == "atan") path.push(atan(temp));
    else if(root->data == "abs") path.push(abs(temp));
    else if(root->data == "ln") path.push(log(temp));
    else if (root->data == "lg") path.push(log10(temp));
}


/* 二元运算符 */
template <typename T>
void binaryOperator(Node* &root, stack<T>&path){
    T temp1 = path.top();
    path.pop();
    if(root->data == "-") {
        if(!root->left) path.push((T)0 - temp1);
        else {
            T temp2 = path.top();
            path.pop();
            path.push(temp2 - temp1);
        }
    }
    else{
        T temp2 = path.top();
        path.pop();
        if (root->data == "+") path.push(temp2 + temp1);
        else if (root->data == "*") path.push(temp2 * temp1);
        else if (root->data == "/" or root->data == "div") path.push(temp2/temp1);
        else if (root->data == "^") path.push(pow(temp2, temp1));
        else if (root->data == "log") path.push(log(temp1) / log(temp2));
    }
}