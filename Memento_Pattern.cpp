// 备忘录模式
// 备忘录模式（Memento Pattern）保存一个对象的某个状态，以便在适当的时候恢复对象。备忘录模式属于行为型模式。

#include<iostream>
#include<string>
#include<vector>
using namespace std;


class memento{//用于记录状态的类
    string state;
public:
    memento(string s){
        state = s;
    }
    string getState(){
        return state;
    }
};


class originator{//当前状态类
    string state;
public:
    void setState(string s){
        state = s;
    }
    string getState(){
        return state;
    }
    memento *saveStateToMemento(){
        return new memento(state);
    }
    void getStateFromMemento(memento * m){
        state =  m->getState();
    }
};


class CareTaker{//管理过去状态的类
public:
    vector<memento*> mementoList;

    void add(memento* m){
        mementoList.push_back(m);
    }
    memento * get(int index){
        return mementoList[index];
    }
    memento * getLast(){
        if(mementoList.empty()) return nullptr;
        else{
            memento* temp = mementoList.back();
            mementoList.pop_back();
            return temp;
        }
    }
};



class MementoPatternDemo{
public:
    static void method(){
        originator * ori = new originator();
        CareTaker * ct = new CareTaker();
        ori->setState("State #1");
        ori->setState("State #2");
        ct->add(ori->saveStateToMemento());
        ori->setState("State #3");
        ct->add(ori->saveStateToMemento());
        ori->setState("State #4");

        cout<<"Current state:"<<ori->getState()<<endl;
        memento * lastState;
        while(lastState = ct->getLast()){
            ori->getStateFromMemento(lastState);
            cout<<"Last state is:"<<ori->getState()<<endl;
        }
        // ori->getStateFromMemento(ct->get(0));
        // cout<<"Current state:"<<ori->getState()<<endl;
        // ori->getStateFromMemento(ct->get(1));
        // cout<<"Current state:"<<ori->getState()<<endl;
    }
};


int main(){
    MementoPatternDemo::method();
}