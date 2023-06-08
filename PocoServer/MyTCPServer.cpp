#include "MyTCPServer.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/TCPServer.h"
#include "MyTCPConnectionFactory.h"

void MyTCPServer::initialize(Application& self)
{
	ServerApplication::loadConfiguration();
	ServerApplication::initialize(self);
}

void MyTCPServer::uninitialize()
{
	ServerApplication::uninitialize();
}

int MyTCPServer::main(const std::vector<std::string>& args)
{
	unsigned short port = (unsigned short)config().getInt("MyTCPServer.port", 12346);
	std::string format(config().getString("MyTCPServer.format", Poco::DateTimeFormat::ISO8601_FORMAT));

	// 1. Bind a ServerSocket with an address
	Poco::Net::ServerSocket serverSocket(port);

	// 2. Pass the ServerSocket to a TCPServer
	Poco::Net::TCPServer server(new MyTCPConnectionFactory(format, 1, 1.0), serverSocket);

	// 3. Start the TCPServer
	server.start();

	// 4. Wait for termination
	waitForTerminationRequest();

	// 5. Stop the TCPServer
	return Application::EXIT_OK;
}