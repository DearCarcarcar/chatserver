# chatserver
工作在nginx TCP负载均衡环境中的集群聊天服务器和客户端源码 muduo redis mysql

编译方式
cd build
rm -rf *
cmake ..
make

环境：
Json开发库
boost + muduo网络库开发环境
redis环境
mysql数据库环境
nginx
CMake环境