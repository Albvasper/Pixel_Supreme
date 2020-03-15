#include "../include/Logging.h"
#include<iostream>
#include <windows.h>
#pragma warning(disable : 4996)
#include <ctime>
#include <fstream>

Logging::Logging() {
}

void Logging::Section(std::string message) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "-------------------------------------";
	std::cout << " " << message << " ";
	std::cout << "-------------------------------------" << std::endl;
}

void Logging::Info(std::string message, std::string section) {
	unsigned int color = 10;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "INFO          ";
	TimeStamp();
	std::cout << "          " << section << "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
	}
	std::cout << message << std::endl;
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Logging::Warning(std::string message, std::string section) {
	unsigned int color = 224;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "WARNING       ";
	TimeStamp();
	std::cout << "          " << section << "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
	}
	std::cout << message << std::endl;
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Logging::Error(std::string message, std::string section) {
	unsigned int color = 207;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "ERROR         ";
	TimeStamp();
	std::cout << "          " << section << "->";
	int sectionL = section.length();
	sectionL = 21 - sectionL;
	for (int i = 0; i < sectionL; i++) {
		std::cout << " ";
	}
	std::cout << message << std::endl;
	//Reset console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Logging::Debug(std::string message) {
	unsigned int color = 15;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "DEBUG         ";
	TimeStamp();
	std::cout << "          " << "Log" << "->";
	std::cout << "                  " << "'" << message << "'" << std::endl;
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
}

Logging::~Logging() {
}
