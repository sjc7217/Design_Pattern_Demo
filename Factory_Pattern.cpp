// 工厂模式
// 工厂模式（Factory Pattern）是最常用的设计模式之一。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。
// 在工厂模式中，我们在创建对象时不会对客户端暴露创建逻辑，并且是通过使用一个共同的接口来指向新创建的对象。


#include<iostream>
#include<string>
using namespace std;

class Shape {
public:
   virtual void draw() = 0;
};



class Rectangle:public Shape {
public:
    void draw() {
        cout<<"Inside Rectangle::draw() method."<<endl;
    }
};



class Square :public Shape {
public:
    void draw() {
        cout<<"Inside Square ::draw() method."<<endl;
    }
};


class Circle  :public Shape {
public:
    void draw() {
        cout<<"Inside Circle  ::draw() method."<<endl;
    }
};



class ShapeFactory {
public:
    //使用 getShape 方法获取形状类型的对象
    Shape * getShape(string shapeType){    
        if(shapeType == "CIRCLE"){
            return new Circle();
        } else if(shapeType == "RECTANGLE"){
            return new Rectangle();
        } else if(shapeType == "SQUARE"){
            return new Square();
        }
        return nullptr;
        }
};



class FactoryPatternDemo {
public: 
static void method() {
    ShapeFactory* shapeFactory = new ShapeFactory();
    //获取 Circle 的对象，并调用它的 draw 方法
    Shape* shape1 = shapeFactory->getShape("CIRCLE");
    //调用 Circle 的 draw 方法
    shape1->draw();
    //获取 Rectangle 的对象，并调用它的 draw 方法
    Shape* shape2 = shapeFactory->getShape("RECTANGLE");
    //调用 Rectangle 的 draw 方法
    shape2->draw();
    //获取 Square 的对象，并调用它的 draw 方法
    Shape* shape3 = shapeFactory->getShape("SQUARE");
    //调用 Square 的 draw 方法
    shape3->draw();
    }
};


int main(int argc,char ** argv){
    FactoryPatternDemo::method();
}