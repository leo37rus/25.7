#pragma once
#include<string>
#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<memory.h>

class Network
{public:
    Network();
    ~Network();
    int connectServerOpen();
    int connectClientOpen();
    void sendMessage(int connect, const std::string &str);
    std:: string reseiveMessage(int connect);
    void connectClose(int socket_discriptor);};