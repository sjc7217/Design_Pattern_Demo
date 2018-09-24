// 观察者模式
// 当对象间存在一对多关系时，则使用观察者模式（Observer Pattern）。比如，当一个对象被修改时，则会自动通知它的依赖对象。观察者模式属于行为型模式。


#include<iostream>
#include<vector>

using namespace std;

class Subject;

class Obeserver{
public:
	Obeserver(){};
	virtual ~Obeserver(){};
	virtual void update(Subject * sub) = 0;
};


class Subject{
public:
	Subject(){};
	virtual ~Subject(){};
	Obeserver *m_Obeserver;

	void attach(Obeserver * pObeserver){
	    m_vtObj.push_back(pObeserver);
    }
	void detach(Obeserver * pObeserver){
        for(auto itr = m_vtObj.begin();itr != m_vtObj.end(); ++itr){
            if(*itr == pObeserver){
                m_vtObj.erase(itr);
                return;
            }			
        }
    }
	void notify(){
        for(auto itr = m_vtObj.begin();itr != m_vtObj.end(); ++itr){	
            (*itr)->update(this);		
        }
    }
		
	virtual int getState() = 0;
	virtual void setState(int i) = 0;
private:
	vector<Obeserver*> m_vtObj;
};



class ConcreteObeserver : public Obeserver{
public:
	ConcreteObeserver(string name){m_objName = name;}
	~ConcreteObeserver(){}
	void update(Subject * sub){
	    m_observerState = sub->getState();
	    cout << "update oberserver["<< m_objName << "] state:" << m_observerState << endl;
    }
private:
	string m_objName;
	int m_observerState;
};



class ConcreteSubject :public Subject{
public:
    int getState(){return state;}
    void setState(int i){state = i;}
private:
    int state = 0;
};


int main(int argc, char *argv[])
{
	Subject * subject = new ConcreteSubject();
	Obeserver * objA = new ConcreteObeserver("A");
	Obeserver * objB = new ConcreteObeserver("B");
	subject->attach(objA);
	subject->attach(objB);
	
	subject->setState(1);
	subject->notify();
	
	cout << "---------------------------------------------" << endl;
	subject->detach(objB);
	subject->setState(2);
	subject->notify();

	return 0;
}