#pragma once
#include <string>
#include <fstream>

class Logging {

	private:
		std::string language;
		static Logging* logging;
		std::string logTxt;
		Logging();
		void TimeStamp();
		~Logging();

	public:
		static Logging* Get();
		void Section(std::string message);
		void Info(std::string message, std::string section);
		void Warning(std::string message, std::string section);
		void Error(std::string message, std::string section);
		void Debug(std::string message);
		std::string CheckLang();
		void Save();
};

