// 代理模式
// 在代理模式（Proxy Pattern）中，一个类代表另一个类的功能。这种类型的设计模式属于结构型模式。
// 在代理模式中，我们创建具有现有对象的对象，以便向外界提供功能接口。

#include<iostream>
using namespace std;


//抽象类，抽象的主题类
class AbstractServer {
public:
	virtual void Request() = 0;
};


//真正主题类，具体提供服务的类
class RealServer:public AbstractServer {
	virtual void Request() {
		cout << "Server start..." << endl;
	}
 
};


//代理服务器，非真正的服务器，访问真正服务器必须通过代理服务器
class ProxyServer :public AbstractServer {
public:
	ProxyServer(string name, string pwd) {
		this->name = name;
		this->pwd = pwd;
		this->server = new RealServer;
	}

	//和真正主题类实现共同的接口，对外可以提供一致的接口！
	void Request() {
		PreRequest();
		if (!CheckUser()) {
			cout << "Username or password error..." << endl;
			return;
		}

		cout << "Request success..." << endl;
		this->server->Request();

		PostRequest();
	}
private:
	//访问服务器前进行的动作，可以控制对真实主题类的访问
	bool CheckUser() {
		if ("admin" == this->name && "123456" == this->pwd) {
			return true;
		}
		return false;
	}
	//真正访问服务器前进行的动作，这里进行安全
	void PreRequest() {
		cout << "Entering server..." << endl;
	}
	//访问服务器之后进行的动作
	void PostRequest() {
		cout << "Leaving server..." << endl;
	}
	string name;
	string pwd;
private:
	AbstractServer* server;
};


//客户端通过登录代理服务器访问真实服务器
int main(int argc, char **argv) {
	AbstractServer *proxy = new ProxyServer("admin", "123456");//登录代理服务器
	proxy->Request();//通过代理服务器访问真正服务器
	return 0;
}
