//享元模式
//享元模式（Flyweight Pattern）主要用于减少创建对象的数量，以减少内存占用和提高性能。这种类型的设计模式属于结构型模式，它提供了减少对象数量从而改善应用所需的对象结构的方式。
#include<string>
#include<iostream>
#include<unordered_map>
#include<cstdlib>
#include<vector>

using namespace std;

class shape{
public:
    virtual void draw() = 0; 
    virtual ~shape(){}
};


class circle:public shape{
    int x,y;
    int radis;
    string color;
public:
    void setX(int a){x = a;}
    void setY(int b){y = b;}
    void setRadis(int r){radis = r;}
    void setColor(string s){color = s;};
    void draw(){
        cout<<"The center of circle is in ("<<x<<","<<y<<"). Radis:"<<radis<<";color:"<<color<<endl;
    }
    virtual ~circle(){}
};

class Factory{
private:
    unordered_map<string,shape *> dict;
public:
    shape * getShapeByColor(string str){
        if(dict.count(str)){
            return dict[str];
        }else{
            dict[str] = new circle();
            static_cast<circle*>(dict[str])->setColor(str);
            return dict[str];
        }
    }
    ~Factory(){
        for(auto item:dict){
            delete(item.second);
        }
    }
};


class PatternDemo{
private:
    vector<string> ppp = {"RED","GREEN","BLACK","ORANGE"};
    Factory f;
public:
    void method(){
        for(int i = 0; i<20; ++i){
            string c = ppp[rand()%4];
            shape * t = f.getShapeByColor(c);
            static_cast<circle*>(t)->setX(rand());
            static_cast<circle*>(t)->setY(rand());
            static_cast<circle*>(t)->setRadis(rand());
            t->draw();
        }
    }
};


int main(int argc,char** argv){
    PatternDemo de;
    de.method();
}
