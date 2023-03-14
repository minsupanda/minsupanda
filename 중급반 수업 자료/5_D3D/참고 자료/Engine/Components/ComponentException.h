#pragma once
#include <string>
#include <comdef.h>

class ComponentException
{
private:
	std::string msg;

public:
	ComponentException(const std::string& msg, const std::string& file, const std::string& func, int line)
	{
		this->msg = "Exception message: " + msg + "\n";
		this->msg += "File: " + file;
		this->msg += "\nFunction: " + func;
		this->msg += "\nFunction: " + std::to_string(line) + "\n";
	}

	const char* what() const
	{
		return msg.c_str();
	}
};

#define ThrowComponentException(msg) throw ComponentException(msg, __FILE__, __FUNCTION__, __LINE__)