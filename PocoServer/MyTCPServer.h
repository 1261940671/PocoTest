#pragma once
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Application.h"

class MyTCPServer : public Poco::Util::ServerApplication
{
public:
	MyTCPServer() {}
	~MyTCPServer() {}
protected:
	void initialize(Poco::Util::Application& self);
	void uninitialize();
	int main(const std::vector<std::string>& args);
};