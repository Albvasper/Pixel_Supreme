#include "../include/Logging.h"
#include<iostream>
#include <windows.h>
#pragma warning(disable : 4996)
#include <ctime>

Logging* Logging::logging;

Logging::Logging() {
}

Logging* Logging::Get() {
	if (logging == nullptr) {
		logging = new Logging();
		return logging;
	} else {
		return logging;
	}
}

void Logging::Section(std::string message) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "-------------------------------------";
	std::cout << " " << message << " ";
	std::cout << "-------------------------------------" << std::endl;
	//Save in msg string
	logTxt = logTxt + "-------------------------------------";
	logTxt = logTxt + " " + message + " ";
	logTxt = logTxt + "-------------------------------------\n";
}

void Logging::Info(std::string message, std::string section) {
	unsigned int color = 10;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "INFO          ";
	logTxt = logTxt + "INFO          ";
	TimeStamp();
	std::cout << "          " << section << "->";
	logTxt = logTxt + "          " + section + "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
		logTxt = logTxt + " ";
	}
	std::cout << message << std::endl;
	logTxt = logTxt + message + "\n";
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Logging::Warning(std::string message, std::string section) {
	unsigned int color = 224;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "WARNING       ";
	logTxt = logTxt + "WARNING       ";
	TimeStamp();
	std::cout << "          " << section << "->";
	logTxt = logTxt + "          " + section + "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
		logTxt = logTxt + " ";
	}
	std::cout << message << std::endl;
	logTxt = logTxt + message + "\n";
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Logging::Error(std::string message, std::string section) {
	unsigned int color = 207;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "ERROR         ";
	logTxt = logTxt + "ERROR         ";
	TimeStamp();
	std::cout << "          " << section << "->";
	logTxt = logTxt + "          " + section + "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
		logTxt = logTxt + " ";
	}
	std::cout << message << std::endl;
	logTxt = logTxt + message + "\n";
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Logging::Debug(std::string message) {
	unsigned int color = 15;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "DEBUG         ";
	logTxt = logTxt + "DEBUG         ";
	TimeStamp();
	std::cout << "          " << "Log" << "->";
	logTxt = logTxt + "          " + "Log" + "->";
	std::cout << "                  " << "'" << message << "'" << std::endl;
	logTxt = logTxt + "                  " + "'" + message + "'" + "\n";
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Logging::TimeStamp() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::cout << ltm->tm_mday;
	std::cout << "/" << 1 + ltm->tm_mon;
	std::cout << "/" << 1900 + ltm->tm_year;
	std::cout << " [" << 1 + ltm->tm_hour << ":";
	std::cout << 1 + ltm->tm_min << ":";
	std::cout << 1 + ltm->tm_sec << "]";
	//Save in msg string
	logTxt = logTxt + std::to_string(ltm->tm_mday);
	logTxt = logTxt + "/" + std::to_string(1 + ltm->tm_mon);
	logTxt = logTxt + "/" + std::to_string(1900 + ltm->tm_year);
	logTxt = logTxt + " [" + std::to_string(1 + ltm->tm_hour) + ":";
	logTxt = logTxt + std::to_string(1 + ltm->tm_min) + ":";
	logTxt = logTxt + std::to_string(1 + ltm->tm_sec) + "]";
}

void Logging::Save() {
	std::ofstream logFile;
	logFile.open("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\LastLog.txt");
	logFile << logTxt;
	logFile.close();	
}

Logging::~Logging() {
}
