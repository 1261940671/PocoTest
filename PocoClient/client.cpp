#include <iostream>
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketAddress.h"

#define BUFFER_SIZE 1024

using Poco::Net::SocketAddress;
using Poco::Net::StreamSocket;

int main(int argc, const char* argv[])
{
    SocketAddress address("127.0.0.1", 12346);
    StreamSocket socket(address);
    char buffer[BUFFER_SIZE];
    while (true)
    {
        if (socket.available())
        {
            int len = socket.receiveBytes(buffer, BUFFER_SIZE);
            buffer[len] = '\0';
            std::cout << "" << buffer << std::endl;
        }
    }
    return 0;
}