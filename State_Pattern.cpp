// 状态模式
// 在状态模式（State Pattern）中，类的行为是基于它的状态改变的。这种类型的设计模式属于行为型模式。
// 在状态模式中，我们创建表示各种状态的对象和一个行为随着状态对象改变而改变的 context 对象。


#include<iostream>
#include<string>

using namespace std;

class State;

class Context {//上下文环境，拥有状态
    State* state;
public:
    Context(){
        state = nullptr;
    }
    void setState(State* state){
        this->state = state;     
    }
    State* getState(){
        return state;
    }
};



class State {//状态接口，可扩展出多种不同的状态
public:
    virtual void doAction(Context* context) = 0;
    virtual string toString() = 0;
};



class StartState :public State {//具体的状态，doAction方法能够以当前状态直接影响上下文
public:
    void doAction(Context* context) {
        cout<<"Player is in start state"<<endl;
        context->setState(this); 
    }

    string toString(){
        return "Start State";
    }
};



class StopState :public State {
public:
    void doAction(Context* context) {
        cout<<"Player is in stop state"<<endl;
        context->setState(this); 
    }

    string toString(){
        return "Stop State";
    }
};


class StatePatternDemo {
public:
    static void method() {
        Context* context = new Context();//上下文环境

        StartState* startState = new StartState();//第一次改变状态
        startState->doAction(context);
        cout<<context->getState()->toString()<<endl;

        StopState* stopState = new StopState();//第二次改变状态
        stopState->doAction(context);
        cout<<context->getState()->toString()<<endl;
    }
};


int main(int argc,char** argv){
    StatePatternDemo::method();
}