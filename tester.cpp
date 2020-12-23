/*
 * tester.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: guest-mwxj73
 */
#include "tester.h"
#include <string>
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <chrono>
#include "print_ts.h"

std::mutex m;
using namespace std;



//get value of if the thread should be cancelled or not
bool canceledOrNot;

/*
 * starts cancelable threads (this means that each thread periodicaly checks to see if it should stop)
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */
std::vector<thread> threads;
void thrdfunc(std::string s, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay){


	//starts cancellable threads
	//change the logic?
//		for(int i = 0; i < numTimesToPrint; i++){
//
//			if(canceledOrNot == true){
//
//
//				switch(wp){
//								case P1	: PRINT1(s);
//								std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
//										    break;
//								case P2: PRINT2(s, s);
//								std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
//												break;
//								case P3: PRINT3(s, s, s);
//								std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
//												break;
//								case P4: PRINT4(s, s, s, s);
//								std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
//												break;
//
//								case P5: PRINT5(s, s, s, s, s);
//								std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
//												break;
//								}
//
//
//
//
//			}
//
//
//
//
//				}

		int numberOfTimesPrinted = 0;

		while (numberOfTimesPrinted < numTimesToPrint){
			if(canceledOrNot == true){

				switch(wp){
												case P1	: PRINT1(s);
												std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
														    break;
												case P2: PRINT2(s, s);
												std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
																break;
												case P3: PRINT3(s, s, s);
												std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
																break;
												case P4: PRINT4(s, s, s, s);
												std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
																break;

												case P5: PRINT5(s, s, s, s, s);
												std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
																break;
												}

				numberOfTimesPrinted +=1;


			}
		}




}


void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay){


//	if(canceledOrNot == false){
//		std::cout << USER_CHOSE_TO_CANCEL << endl;
//	}


	for (int i = 0; i < numThreads; i++){
					threads.push_back(thread(thrdfunc, s , wp, numTimesToPrint, millisecond_delay));

				}




		//sleep_for? look at mutex lock_guard notes
		//numTimesToPrintComparable++;

		//or yield


		}






	//might need a switch function
//	for (unsigned int i = 0 ; i < numThreads; i++){
//		threads.pushback(threads());
//	}










void setCancelThreads(bool bCancel){

	canceledOrNot = bCancel;
}


void joinThreads(){
	for (auto & t : threads){
		t.join();
	}
	threads.clear();
}





//int main()
//{
//	std::vector<std::thread> vecThreads;
//
//	//how many cores (2 virtual cores per physical core)
//	int numbThreads = std::thread::hardware_concurrency();
//
//	//lets start up 1 per core
//	for (int i=0;i<numbThreads/2;i++){
//		vecThreads.push_back(std::thread(thrdfunc));
//	}
//
//	//let em run a bit (90 seconds)
//	this_thread::sleep_for(chrono::milliseconds(90000));
//
//	//ask them all to stop
//	canceledOrNot = false;
//
//	//wait for em to finish
//	for(auto& t : vecThreads){
//		t.join();
//	}
//
//	cout<<"All threads done!"<<endl;
//
//	return 0;
//}




