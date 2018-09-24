// 策略模式
// 在策略模式（Strategy Pattern）中，一个类的行为或其算法可以在运行时更改。这种类型的设计模式属于行为型模式。
// 在策略模式中，我们创建表示各种策略的对象和一个行为随着策略对象改变而改变的 context 对象。策略对象改变 context 对象的执行算法。


#include<iostream>

using namespace std;


class Strategy {
public:
    virtual int doOperation(int num1, int num2) = 0;
};


class OperationAdd :public Strategy{
public:
    int doOperation(int num1, int num2) {
       return num1 + num2;
    }
};




class OperationSubstract  :public Strategy{
public:
    int doOperation (int num1, int num2) {
       return num1 - num2;
    }
};



class OperationMultiply   :public Strategy{
public:
    int doOperation(int num1, int num2) {
       return num1 * num2;
    }
};



class Context {
    Strategy* strategy;
public:
    Context(Strategy* strategy){
        this->strategy = strategy;
    }

    void setStrategy(Strategy* st){
        if(this->strategy != nullptr)  delete this->strategy;//注意析构
        this->strategy = st;
    }

    int executeStrategy(int num1, int num2){
        return strategy->doOperation(num1, num2);
    }
};


class StrategyPatternDemo {
public:
    static void method() {
        Context* context = new Context(new OperationAdd());    
        cout<<"10 + 5 = " << context->executeStrategy(10, 5)<<endl;

        context->setStrategy(new OperationSubstract());      
        cout<<"10 - 5 = " << context->executeStrategy(10, 5)<<endl;

        context->setStrategy(new OperationMultiply());    
        cout<<"10 * 5 = " << context->executeStrategy(10, 5)<<endl;
    }
};


int main(int argc,char** argv){
    StrategyPatternDemo::method();
}


