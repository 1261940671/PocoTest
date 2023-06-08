#pragma once
#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/StreamSocket.h"
#include "MyTCPConnection.h"
#include <string>

class MyTCPConnectionFactory : public Poco::Net::TCPServerConnectionFactory
{
public:
	MyTCPConnectionFactory(const std::string arg1, int arg2, double arg3)
		: arg1(arg1), arg2(arg2), arg3(arg3)
	{
	}

	Poco::Net::TCPServerConnection* createConnection(const Poco::Net::StreamSocket& socket)
	{
		return new MyTCPConnection(socket, arg1, arg2, arg3);
	}

private:
	std::string arg1;
	int arg2;
	double arg3;
};
