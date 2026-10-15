#include "Server.h"

#include <fstream>
#include <filesystem>

Server::Server(const std::string& name) : name(name)
{
}

Server::Server(const Server& other) : name(other.name)
{
}

Server& Server::operator=(const Server& other)
{
    if (this != &other)
    {
        name = other.name;
    }

    return *this;
}

Server::~Server()
{
}

void Server::consoleWrite(const std::string& type, int id, const std::string& value) const
{
    std::cout << type << ", " << id << ", " << value << std::endl;
}

void Server::fileWrite(const std::string& type, int id, const std::string& value) const
{
    std::filesystem::create_directories("logs");
    const std::string filename = "logs/" + type + ".csv";
    const bool writeHeader = !std::filesystem::exists(filename) || std::filesystem::file_size(filename) == 0;
    std::ofstream file(filename, std::ios::app);
    
    if (!file)
    {
        std::cerr << "Erreur : impossible d'ouvrir " << filename << std::endl;
        return;
    }

    if (writeHeader)
    {
        file << "ID,Value\n";
    }

    file << id << "," << value << '\n';
}

std::ostream& operator<<(std::ostream& os, const Server& server)
{
    os << "Server: " << server.name;
    return os;
}

