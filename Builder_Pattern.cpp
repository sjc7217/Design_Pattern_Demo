// 建造者模式
// 建造者模式(Builder Pattern)：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
// 建造者模式是一步一步创建一个复杂的对象，它允许用户只通过指定复杂对象的类型和内容就可以构建它们，用户不需要知道内部的具体构建细节。建造者模式属于对象创建型模式。根据中文翻译的不同，建造者模式又可以称为生成器模式。


#include <iostream>
#include <string>

// 产品[product]角色
class Person {   // 待建造的l人
public :
	void SetHead(std::string head){
		this->m_head = head;
	}
	std::string GetHead(){
		return this->m_head;
	}
	void SetBody(std::string body) {
		this->m_body = body;
	}
	std::string GetBody() {
		return this->m_body;
	}
	void SetFoot(std::string foot) {
		this->m_foot = foot;
	}
	std::string GetFoot() {
		return this->m_foot;
	}
	void ShowPerson() {        // 显示当前的人的信息
		std::cout <<"This is a person has" <<std::endl;
		std::cout <<"HEAD : "<<this->m_head <<", BODY : " <<this->m_body <<", FOOT : " <<this->m_foot <<std::endl;
	}
 
protected :
    std::string m_head;     // 人的头
    std::string m_body;     // 人的躯体
    std::string m_foot;     // 人的脚
};

// 建造者[build]角色
class Builder {   // 建造者的基类
public :
    Builder() {            // 无参数的构造函数
        this->m_person = new Person( );
    }
    virtual ~Builder() {      // 析构函数
        delete this->m_person;
    }
    Person* GetPerson() {           // 获取建造者建造的人对象
        return this->m_person;
    }
    virtual void BuildHead() = 0;          // 建造人的头
    virtual void BuildBody() = 0;          // 建造人的躯体
    virtual void BuildFoot() = 0;          // 建造人的脚
protected :
    Person *m_person;
};
 
//实际建造者-=> 具体建造者[Concrete Builder]
class FatBuilder : public Builder {
public :
    FatBuilder():Builder(){}      // 无参数的构造函数
    virtual ~FatBuilder(){}      // 析构函数

	void BuildHead() {         // 建造人的头
		this->m_person->SetHead("Fat Head");
		std::cout <<"Build Fat head..." <<std::endl;
	}
	void BuildBody() {        // 建造人的躯体
		this->m_person->SetBody("Fat Body");
		std::cout <<"Build Fat body..." <<std::endl;
	}
	void BuildFoot() {         // 建造人的脚
		this->m_person->SetFoot("Fat Foot");
		std::cout <<"Build Fat foot..." <<std::endl;
	}
 
};
 
 
 
// 瘦人的实际建造者-=>具体建造者[Concrete Builder]
class ThinBuilder : public Builder {
public :
    ThinBuilder():Builder(){}  // 无参数的构造函数
    virtual ~ThinBuilder(){}     // 析构函数
	void BuildHead(){          // 建造人的头
		this->m_person->SetHead("Thin Head");
		std::cout <<"Build thin head..." <<std::endl;
	}
	void BuildBody() {        // 建造人的躯体
		this->m_person->SetBody("Thin Body");
		std::cout <<"Build thin body..." <<std::endl;
	}
	void BuildFoot() {          // 建造人的脚
		this->m_person->SetFoot("Thin Foot");
		std::cout <<"Build thin foot..." <<std::endl;
	}
};


// 向导
class Director {
public :
    Director(Builder *builder) {         // 向导类构造函数
        this->m_builder = builder;
    }
	void CreatePerson(){
		this->m_builder->BuildHead();      // 利用建造者建造人的头
		this->m_builder->BuildBody();      // 利用建造者建造人的躯体
		this->m_builder->BuildFoot();      // 利用建造者建造人的脚
	}
    ~Director(){
        if(m_builder) delete m_builder;
    }
protected:
    Builder *m_builder;         //用来存储建造者
};



int main(int argc,char**argv) {
    std::cout <<"Start create thin person..." <<std::endl;
    ThinBuilder* thinBuilder = new ThinBuilder();
    Director *thinDirector = new Director(thinBuilder);
    thinDirector->CreatePerson();
    Person *thinPerson = thinBuilder->GetPerson();
    thinPerson->ShowPerson();
    std::cout <<std::endl;
    delete thinDirector;

    std::cout<<"========================================================"<<std::endl;

    std::cout <<"Start create fat person..." <<std::endl;
    FatBuilder* fatBuilder = new FatBuilder();
    Director *fatDirector = new Director(fatBuilder);
    fatDirector->CreatePerson( );
    Person *fatPerson = fatBuilder->GetPerson( );
    fatPerson->ShowPerson( );
    std::cout <<std::endl;
    delete fatDirector;

    return 0;
}
