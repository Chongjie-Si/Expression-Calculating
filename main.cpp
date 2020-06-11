#include "integral_limitation.h"

// 后续遍历计算表达式
void postOrderCalculate(Node* &root, stack<double>& path){
    if(root){
        if(root->data == "integral") IntegralCaculate(root, path);
        if(root->data == "limit") LimitCaculate(root, path);
        postOrderCalculate(root->left, path);
        postOrderCalculate(root->right, path);
        if(!isStringNum(root->data)){
            if(root->data.size() > 1 and root->data != "div" and root->data != "log")
                unaryOperator(root, path);
            else binaryOperator(root, path);
        }
        else path.push(StringToNum(root->data));
    }
}

void complexCaculate(Node* &root, stack<complex<double>>& path){
    if(root){
        complexCaculate(root->left, path);
        complexCaculate(root->right, path);
        if(!isStringNum(root->data)){
            if(root->data.size() > 1 and root->data != "div" and root->data != "log")
                unaryOperator(root, path);
            else binaryOperator(root, path);
        }
        else path.push(StringToComplex(root->data));
    }
}

void solveEquation(Node* &root, stack<Equation>& path) {
    if (root) {
        solveEquation(root->left, path);
        solveEquation(root->right, path);
        if (root->data == "=") {
            Equation temp2 = path.top();
            path.pop();
            Equation temp1 = path.top();
            path.pop();
            path.push(temp1 - temp2);
        }
        else if (root->data == "x") {
            Equation ret(0, 1);
            path.push(ret);
        }
        else if (!isStringNum(root->data)) {
            if (root->data.size() > 1 and root->data != "div" and root->data != "log")
                unaryOperator(root, path);
            else binaryOperator(root, path);
        }
        else path.push(StringToNum(root->data));
    }
}

int main(){
    Node* t = nullptr;
    CreateTree(t);
    if(t->data == "=") {
        stack<Equation> com;
        solveEquation(t, com);
        cout<<endl<<com.top().getdx()<<" "<<com.top().getx()<<" "<<com.top().getreal()<<endl;
        solution(com.top().getdx(), com.top().getx(), com.top().getreal());
    }
    else if(t->data == "complex"){
        stack<complex<double>> complex;
        complexCaculate(t->left,complex);
        cout<<complex.top()<<endl;
    }
    else{
        stack<double> str;
        postOrderCalculate(t, str);
        cout<<endl<<str.top()<<endl;
    }
}