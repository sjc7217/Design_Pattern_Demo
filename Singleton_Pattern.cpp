//单例模式
// 单例模式(Singleton Pattern)：单例模式确保某一个类只有一个实例，而且自行实例化并向整个系统提供这个实例，这个类称为单例类，它提供全局访问的方法。
// 单例模式的要点有三个：一是某个类只能有一个实例；二是它必须自行创建这个实例；三是它必须自行向整个系统提供这个实例。单例模式是一种对象创建型模式。单例模式又名单件模式或单态模式。


//单例模式比较复杂，有很多方式，分线程安全和非线程安全版本，以下将这些版本一一列举：

//方式一：非线程安全版本
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

Singleton * Singleton::instance = new Singleton();








//方式二：线程安全版本，静态成员实例的懒汉模式，使用mutex和double-check来保证thread safety
#include<iostream>
#include <mutex>

class Singleton{
private:
    static Singleton * instance ;//静态数据类型用来保存唯一单例
    static std::mutex m;
    Singleton(){};//构造函数private，防止外部构造
public:
    ~Singleton(){
        delete instance;
    }
    static Singleton* getInstance(){
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lg(m);
            if(instance == nullptr)
                instance = new Singleton();
        }
        return  instance;
    }
    void singletonOperation(){
        std::cout << "singletonOperation" << std::endl;
    }
};

Singleton * Singleton::instance = new Singleton();
std::mutex Singleton::m;






//方式三：线程安全版本，内部静态实例的懒汉模式, 局部静态变量的使用非常有意思，推荐使用！
#include<iostream>
#include <mutex>

class Singleton{
private:
    Singleton(){};//构造函数private，防止外部构造
public:
    static Singleton* getInstance(){
        static Singleton instance;
        return  &instance;
    }
    void singletonOperation(){
        std::cout << "singletonOperation" << std::endl;
    }
};






//方式四：线程安全版本，静态成员实例的饿汉模式, 推荐使用， 静态初始化确保线程安全
#include<iostream>
#include <mutex>

class Singleton{
private:
    static Singleton * instance;
    Singleton(){};//构造函数private，防止外部构造
public:
    static Singleton* getInstance(){
        return  instance;
    }
    void singletonOperation(){
        std::cout << "singletonOperation" << std::endl;
    }
};

Singleton* Singleton::instance = new Singleton();


int main(int argc, char **argv){
 Singleton * sg = Singleton::getInstance();
 sg->singletonOperation();
 return 0;
}
