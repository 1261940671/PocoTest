#pragma once
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/StreamSocket.h"
#include <string>

class MyTCPConnection : public Poco::Net::TCPServerConnection
{
public:
	MyTCPConnection(const Poco::Net::StreamSocket& s,
		const std::string& arg1,
		int arg2,
		double arg3);

	void run();
private:

	std::string _arg1;
	int _arg2;
	double _arg3;
};