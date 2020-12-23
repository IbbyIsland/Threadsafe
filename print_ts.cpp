/*
 * print_ts.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: guest-mwxj73
 */
#include <string>
#include "print_ts.h"
#include <mutex>
#include <iostream>


using namespace std;

mutex mu;

void PRINT1(std::string &txt){

	lock_guard<mutex> lock(mu);
	std::cout << txt << endl;

}
void PRINT2(std::string &txt, std::string &txt1){
	lock_guard<mutex> lock(mu);
		std::cout << txt << txt1 << endl;
}
void PRINT3(std::string &txt, std::string &txt1, std::string &txt2){
	lock_guard<mutex> lock(mu);
	std::cout << txt << txt1 << txt2<< endl;
}
void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3){
	lock_guard<mutex> lock(mu);
	std::cout << txt << txt1 << txt2 << txt3 << endl;
}
void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4){
	lock_guard<mutex> lock(mu);
	std::cout << txt << txt1 << txt2 << txt3 << txt4 << endl;
}
