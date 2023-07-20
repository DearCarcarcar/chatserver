#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

string func1() {
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "ls";
    js["msg"] = "what are you doing now";

    string sendBuf = js.dump();

    //cout << sendBuf.c_str() << endl;

    return sendBuf;
}

string func2() {
    json js;
    // 添加数组
    js["id"] = {1,2,3,4,5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    cout << js << endl;

    return js.dump();

}

void func3() {
    json js;
    
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;
    
    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;

    string strBuf = js.dump();//将json数据对象 -》序列化 json字符串 
    cout << strBuf << endl;
}

int main() {
    
    string recvBuf = func1();
    //数据反序列化 json字符串 -》 反序列化 数据对象（看作容器方便访问）
    json jsbuf = json::parse(recvBuf);
    cout<<jsbuf["msg_type"]<<endl;
    cout<<jsbuf["from"]<<endl;
    cout<<jsbuf["to"]<<endl;
    cout<<jsbuf["msg"]<<endl;

    string recvBuf2 = func2();
    json jsbuf2 = json::parse(recvBuf2);
    cout<<jsbuf2["id"]<<endl;
    auto arr = jsbuf2["id"];
    cout<<arr[2]<<endl;

    return 0;
}