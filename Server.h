#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>

class Server
{
private:
    std::string name;

public:
    Server(const std::string& name = "IoT Server");
    Server(const Server& other);
    Server& operator=(const Server& other);
    ~Server();

    void consoleWrite(const std::string& type, int id, const std::string& value) const;

    void fileWrite(const std::string& type, int id, const std::string& value) const;

    friend std::ostream& operator<<(std::ostream& os, const Server& server);
};

#endif
