// 抽象工厂模式
// 抽象工厂模式（Abstract Factory Pattern）是围绕一个超级工厂创建其他工厂。该超级工厂又称为其他工厂的工厂。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。
// 在抽象工厂模式中，接口是负责创建一个相关对象的工厂，不需要显式指定它们的类。每个生成的工厂都能按照工厂模式提供对象。

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



class Color {
public:
    virtual void fill() = 0;
};



class Red :public Color {
public:
    void fill() {
        cout<<"Inside Red ::fill() method."<<endl;
    }
};


class Green  :public Color {
public:
    void fill() {
        cout<<"Inside Green::fill() method."<<endl;
    }
};



class Blue :public Color {
public:
    void fill() {
        cout<<"Inside Blue::fill() method."<<endl;
    }
};




class AbstractFactory {
public:
    virtual Color* getColor(string color) = 0;
    virtual Shape* getShape(string shape) = 0;
};




class ShapeFactory: public AbstractFactory {
public:
    Shape* getShape(string shapeType){     
        if(shapeType == "CIRCLE"){
            return new Circle();
        } else if(shapeType == "RECTANGLE"){
            return new Rectangle();
        } else if(shapeType == "SQUARE"){
            return new Square();
        }
        return nullptr;
    }
    Color* getColor(string color) {
        return nullptr;
    }
};



class ColorFactory: public AbstractFactory {
public:
    Shape* getShape(string shapeType){     
        return nullptr;
    }
    Color* getColor(string color) {
        if(color == "Red"){
            return new Red();
        } else if(color == "Green"){
            return new Green();
        } else if(color == "Blue"){
            return new Blue();
        }
        return nullptr;
    }
};



class FactoryProducer {
public:
    static AbstractFactory* getFactory(string choice){
        if(choice == "SHAPE"){
            return new ShapeFactory();
        } else if(choice == "COLOR"){
            return new ColorFactory();
        }
        return nullptr;
    }
};




class AbstractFactoryPatternDemo {
public:
    static void method() {
    //获取形状工厂
    AbstractFactory* shapeFactory = FactoryProducer::getFactory("SHAPE");
    //获取形状为 Circle 的对象
    Shape* shape1 = shapeFactory->getShape("CIRCLE");
    //调用 Circle 的 draw 方法
    shape1->draw();
    //获取形状为 Rectangle 的对象
    Shape* shape2 = shapeFactory->getShape("RECTANGLE");
    //调用 Rectangle 的 draw 方法
    shape2->draw();
    //获取形状为 Square 的对象
    Shape* shape3 = shapeFactory->getShape("SQUARE");
    //调用 Square 的 draw 方法
    shape3->draw();
    //获取颜色工厂
    AbstractFactory* colorFactory = FactoryProducer::getFactory("COLOR");
    //获取颜色为 Red 的对象
    Color* color1 = colorFactory->getColor("Red");
    //调用 Red 的 fill 方法
    color1->fill();
    //获取颜色为 Green 的对象
    Color* color2 = colorFactory->getColor("Green");
    //调用 Green 的 fill 方法
    color2->fill();
    //获取颜色为 Blue 的对象
    Color* color3 = colorFactory->getColor("Blue");
    //调用 Blue 的 fill 方法
    color3->fill();
   }
};



int main(int argc,char** argv){
    AbstractFactoryPatternDemo::method();
}