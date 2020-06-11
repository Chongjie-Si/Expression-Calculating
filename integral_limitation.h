//
// Created by 司翀杰 on 2019/9/8.
//

#ifndef UNTITLED_INTEGRAL_H
#define UNTITLED_INTEGRAL_H

#include "equation_common.h"
using namespace std;

//将数字变成字符串
string chu(double s){
    stringstream ss;
    ss<<s;
    string num;
    ss>>num;
    return num;
}

// x传入栈，实值"x"
void stackCalculate(Node* &root, stack<double>& path, double x) {
    if (root) {
        stackCalculate(root->left, path,x);
        stackCalculate(root->right, path,x);
        if (!isStringNum(root->data)) {
            if(root->data == "x") path.push(x);
            else if (root->data.size() > 1) unaryOperator(root, path);
            else binaryOperator(root, path);
        }
        else path.push(StringToNum(root->data));
    }
}

// 微元法求积分
// x : 以x作为自变量传入矩形的高，宽用b-a/n
double SliceCalculate(Node* &root, stack<double>& path, double x, double weight){
    stackCalculate(root->right, path, x);
    double rectangle = weight * path.top();
    return rectangle;
}

void IntegralCaculate(Node* &root, stack<double>& path) {
    string space = root->left->data;
    int pos = space.find(',', 0);
    // 积分上下限
    double lower = StringToNum(space.substr(0, pos));
    double upper = StringToNum(space.substr(pos + 1));
    int n = 1000000;
    double  slice = (upper - lower)/n;
    double integral = 0;
    for(int i = 0; i < n; ++i){
        integral += SliceCalculate(root, path, lower, slice);
        path.pop();
        lower += slice;
        if(lower == upper) break;
    }
    root->left = nullptr;
    root->right = nullptr;
    root->data = chu(integral);
}

// 判断极限是否存在
void limitationExist(Node* &root, stack<double>& path, double t1, double t2){
    stackCalculate(root->right, path, t1);
    double temp1 = path.top();
    path.pop();
    stackCalculate(root->right,path,t2);
    double temp2 = path.top();
    path.pop();
    if(t1 - t2 >= 0.1) cout<<"极限不存在！"<<endl;
    else path.push((temp1+temp2)/2);
}

void LimitCaculate(Node* &root, stack<double>& path){
    string value = root->left->data;
    if(value == "inf") limitationExist(root, path, INT_MAX, INT_MIN);
    else if(value == "+inf") stackCalculate(root->right, path, INT_MAX);
    else if(value == "-inf") stackCalculate(root->right,path,INT_MIN);
    else limitationExist(root,path,StringToNum(value) + 0.00001,StringToNum(value) - 0.00001);
    root->left = nullptr;
    root->right = nullptr;
    root->data = chu(path.top());
    path.pop();
}

#endif //UNTITLED_INTEGRAL_H
