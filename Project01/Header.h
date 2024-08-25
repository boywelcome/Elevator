#pragma once
#include<iostream>
#include<list>
#include<ctime>
using namespace std;

struct OutsideRequest {
	int floor;
	int upOrdown;
};

class Elevator {
	int floorNum;
	int pos;
	list<OutsideRequest> OutRequests;
	list<int>InRequests;
	int numIn;
public:
	//Constructors
	Elevator();
	Elevator(int floorNum);

	//Return position of the elevator
	int elevator_position() {return pos;}
	//Display elevator loading
	void elevator_loading_screen();
	//Change elevator position
	void elevator_change();

	//Return the request from outside people
	void outside_random_requests();

	//Set inside requests
	void set_inside_requests();

	//Handle the request queue
	void handle_requests();


};

