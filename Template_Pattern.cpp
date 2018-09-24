//模板模式
//在模板模式（Template Pattern）中，一个抽象类公开定义了执行它的方法的方式/模板。它的子类可以按需要重写方法实现，但调用将以抽象类中定义的方式进行。这种类型的设计模式属于行为型模式。

#include<iostream>
using namespace std;

class Game {
public:
   virtual void initialize() = 0;
   virtual void startPlay() = 0;
   virtual void endPlay() = 0;
 
public:
    void play(){
      //初始化游戏
      initialize();
      //开始游戏
      startPlay();
      //结束游戏
      endPlay();
   }
};

class Cricket :public Game {
public:
    void endPlay() {
        cout<<"Cricket Game Finished!"<<endl;
    }
    void initialize() {
        cout<<"Cricket Game Initialized! Start playing."<<endl;
    }
    void startPlay() {
        cout<<"Cricket Game Started. Enjoy the game!"<<endl;
    }
};



class Football:public Game {
public:
    void endPlay() {
        cout<<"Football Game Finished!"<<endl;
    }

    void initialize() {
        cout<<"Football Game Initialized! Start playing."<<endl;
    }
    void startPlay() {
        cout<<"Football Game Started. Enjoy the game!"<<endl;
    }
};



int main(){
    Game* game = new Cricket();
    game->play();
    cout<<endl;
    game = new Football();
    game->play();   
}