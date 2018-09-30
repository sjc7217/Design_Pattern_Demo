// 装饰器模式

// 一般有两种方式可以实现给一个类或对象增加行为：
// 1. 继承机制，使用继承机制是给现有类添加功能的一种有效途径，通过继承一个现有类可以使得子类在拥有自身方法的同时还拥有父类的方法。但是这种方法是静态的，用户不能控制增加行为的方式和时机。
// 2. 关联机制，即将一个类的对象嵌入另一个对象中，由另一个对象来决定是否调用嵌入对象的行为以便扩展自己的行为，我们称这个嵌入的对象为装饰器(Decorator)
// 装饰模式以对客户透明的方式动态地给一个对象附加上更多的责任，换言之，客户端并不会觉得对象在装饰前和装饰后有什么不同。装饰模式可以在不需要创造更多子类的情况下，将对象的功能加以扩展。这就是装饰模式的模式动机。

// 装饰器模式（Decorator Pattern）允许向一个现有的对象添加新的功能，同时又不改变其结构。这种类型的设计模式属于结构型模式，它是作为现有的类的一个包装。
// 这种模式创建了一个装饰类，用来包装原有的类，并在保持类方法签名完整性的前提下，提供了额外的功能。



#include <iostream>
using namespace std;


class Component {
public:
     virtual void Operation() = 0;
};


class ConcreteComponent : public Component {
public:
    void Operation() {
        cout<<"I am no decoratored ConcreteComponent"<<endl;
    }
};


class Decorator : public Component {
public:
    Decorator(Component *pComponent) : m_pComponentObj(pComponent) {}
    void Operation() {
        if (m_pComponentObj != NULL) {
            m_pComponentObj->Operation();
        }
    }
protected:
     Component *m_pComponentObj;
};



class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component *pDecorator) : Decorator(pDecorator){}
    void Operation() {
        AddedBehavior();
        Decorator::Operation();
    }
    void  AddedBehavior() {
        cout<<"This is added behavior A."<<endl;
    }
};


class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component *pDecorator) : Decorator(pDecorator){}
    void Operation() {
        AddedBehavior();
        Decorator::Operation();
    }
    void  AddedBehavior() {
        cout<<"This is added behavior B."<<endl;
    }
};


int main(int argc, char** argv) {
     Component *pComponentObj = new ConcreteComponent();
     Decorator *pDecoratorAOjb = new ConcreteDecoratorA(pComponentObj);
     pDecoratorAOjb->Operation();
     cout<<"============================================="<<endl;
     Decorator *pDecoratorBOjb = new ConcreteDecoratorB(pComponentObj);
     pDecoratorBOjb->Operation();
     cout<<"============================================="<<endl;
     Decorator *pDecoratorBAOjb = new ConcreteDecoratorB(pDecoratorAOjb);
     pDecoratorBAOjb->Operation();
     cout<<"============================================="<<endl;
}
