#pragma once
#include <string>

class Logging {

	private:
		void TimeStamp();

	public:
		Logging();
		void Section(std::string message);
		void Info(std::string message, std::string section);
		void Warning(std::string message, std::string section);
		void Error(std::string message, std::string section);
		void Debug(std::string message);
		~Logging();
};

