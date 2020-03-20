#include "../include/Logging.h"
#include<iostream>
#include <windows.h>
#pragma warning(disable : 4996)
#include <ctime>

Logging::Logging() {
}

void Logging::Init() {
}

void Logging::Section(std::string message) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "-------------------------------------";
	std::cout << " " << message << " ";
	std::cout << "-------------------------------------" << std::endl;
	//Save in log file
	std::ofstream logFile;
	logFile.open("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\LastLog.txt");
	logFile << "-------------------------------------";
	logFile << " " << message << " ";
	logFile << "-------------------------------------" << std::endl;
	logFile.close();
}

void Logging::Info(std::string message, std::string section) {
	unsigned int color = 10;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//Open log file
	std::ofstream logFile;
	logFile.open("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\LastLog.txt");
	std::cout << "INFO          ";
	logFile << "INFO          ";
	TimeStamp();
	std::cout << "          " << section << "->";
	logFile << "          " << section << "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
		logFile << " ";
	}
	std::cout << message << std::endl;
	logFile << message << std::endl;
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	logFile.close();
}

void Logging::Warning(std::string message, std::string section) {
	unsigned int color = 224;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//Open log file
	std::ofstream logFile;
	logFile.open("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\LastLog.txt");
	std::cout << "WARNING       ";
	logFile << "WARNING       ";
	TimeStamp();
	std::cout << "          " << section << "->";
	logFile << "          " << section << "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
		logFile << " ";
	}
	std::cout << message << std::endl;
	logFile << message << std::endl;
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	logFile.close();
}

void Logging::Error(std::string message, std::string section) {
	unsigned int color = 207;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//Open log file
	std::ofstream logFile;
	logFile.open("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\LastLog.txt");
	std::cout << "ERROR         ";
	logFile << "ERROR         ";
	TimeStamp();
	std::cout << "          " << section << "->";
	logFile << "          " << section << "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
		logFile << " ";
	}
	std::cout << message << std::endl;
	logFile << message << std::endl;
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	logFile.close();
}

void Logging::Debug(std::string message) {
	unsigned int color = 15;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//Open log file
	std::ofstream logFile;
	logFile.open("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\LastLog.txt");
	std::cout << "DEBUG         ";
	logFile << "DEBUG         ";
	TimeStamp();
	std::cout << "          " << "Log" << "->";
	logFile << "          " << "Log" << "->";
	std::cout << "                  " << "'" << message << "'" << std::endl;
	logFile << "                  " << "'" << message << "'" << std::endl;
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	logFile.close();
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
	//Save in log file
	std::ofstream logFile;
	logFile.open("C:\\Users\\alber\\Desktop\\Pixel_Supreme\\doc\\LastLog.txt");
	logFile << ltm->tm_mday;
	logFile << "/" << 1 + ltm->tm_mon;
	logFile << "/" << 1900 + ltm->tm_year;
	logFile << " [" << 1 + ltm->tm_hour << ":";
	logFile << 1 + ltm->tm_min << ":";
	logFile << 1 + ltm->tm_sec << "]";
}

void Logging::Close() {
}

Logging::~Logging() {
}
