// 命令模式
// 命令模式（Command Pattern）是一种数据驱动的设计模式，它属于行为型模式。请求以命令的形式包裹在对象中，并传给调用对象。调用对象寻找可以处理该命令的合适的对象，并把该命令传给相应的对象，该对象执行命令。


#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Order {//对于命令的抽象接口
public:
    virtual void execute() = 0;
};


class Stock {//具体有行动的实体，命令作用于该实体
    string name = "ABC";
    int quantity = 10;
public:
    void buy(){
        cout<<"Stock [ Name: "<<name<<", Quantity: " << quantity <<" ] bought"<<endl;
    }
    void sell(){
        cout<<"Stock [ Name: "<<name<<", Quantity: " << quantity <<" ] sold"<<endl;
    }
};



class BuyStock :public Order {//具体的命令
    Stock* abcStock;
public:
    BuyStock(Stock* abcStock){
        this->abcStock = abcStock;
    }

    void execute() {
        abcStock->buy();
    }
};



class SellStock :public Order {//具体的命令
    Stock* abcStock;
public:
    SellStock(Stock* abcStock){
        this->abcStock = abcStock;
    }

    void execute() {
        abcStock->sell();
    }
};




class Broker {//命令管理类用于存储命令并统一执行
    vector<Order*> orderList;
public:
    void takeOrder(Order* order){
        orderList.push_back(order);      
    }

    void placeOrders(){
        for (auto order : orderList) {
            order->execute();
        }
        orderList.clear();
    }
};



class CommandPatternDemo {
public:
    static void method() {
        Stock* abcStock = new Stock();

        BuyStock* buyStockOrder = new BuyStock(abcStock);
        SellStock* sellStockOrder = new SellStock(abcStock);

        Broker* broker = new Broker();//命令管理对象
        broker->takeOrder(buyStockOrder);
        broker->takeOrder(sellStockOrder);

        broker->placeOrders();//执行命令！
    }
};



int main(int argc,char**argv){
    CommandPatternDemo::method();
}