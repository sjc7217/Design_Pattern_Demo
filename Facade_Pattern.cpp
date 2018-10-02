// 外观模式
// 外观模式(Facade Pattern)：外部与一个子系统的通信必须通过一个统一的外观对象进行，为子系统中的一组接口提供一个一致的界面，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。外观模式又称为门面模式，它是一种对象结构型模式。


#include<iostream>
using namespace std;


class Shape {
public:
   virtual void draw()=0;
};


class Rectangle : public Shape {
public:
    void draw() {
       cout<<"Rectangle::draw()"<<endl;
    }
};


class Square  : public Shape {
public:
    void draw() {
       cout<<"Square ::draw()"<<endl;
    }
};



class Circle   : public Shape {
public:
    void draw() {
       cout<<"Circle ::draw()"<<endl;
    }
};


class ShapeMaker {

    Shape *circle;
    Shape *rectangle;
    Shape *square;

public:
    ShapeMaker() {
        circle = new Circle();
        rectangle = new Rectangle();
        square = new Square();
    }
    void drawCircle(){
        circle->draw();
    }
    void drawRectangle(){
        rectangle->draw();
    }
    void drawSquare(){
        square->draw();
    }
};


class FacadePatternDemo {
public: 
    static void method(int argc,char**argv) {
        ShapeMaker *shapeMaker = new ShapeMaker();
        shapeMaker->drawCircle();
        shapeMaker->drawRectangle();
        shapeMaker->drawSquare();      
    }
};


int main(int argc,char**argv){
    FacadePatternDemo::method(argc,argv);
    return 0;
}