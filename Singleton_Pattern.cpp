//单例模式
// 单例模式(Singleton Pattern)：单例模式确保某一个类只有一个实例，而且自行实例化并向整个系统提供这个实例，这个类称为单例类，它提供全局访问的方法。
// 单例模式的要点有三个：一是某个类只能有一个实例；二是它必须自行创建这个实例；三是它必须自行向整个系统提供这个实例。单例模式是一种对象创建型模式。单例模式又名单件模式或单态模式。

#include<iostream>

using namespace std;


class Singleton{
private:
    Singleton(){};//构造函数private，防止外部构造
public:
    static Singleton * instance ;//静态数据类型用来保存唯一单例
    ~Singleton(){
        delete instance;
    }
    static Singleton* getInstance(){
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return  instance;
    }
    void singletonOperation(){
        cout << "singletonOperation" << endl;
    }
};

Singleton * Singleton::instance = NULL;

int main(int argc, char **argv){
	Singleton * sg = Singleton::getInstance();
	sg->singletonOperation();
	return 0;
}