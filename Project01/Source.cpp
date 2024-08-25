/*
Handle multiply input at all time
Let n be number of floors
Store floor status in a map size n: -2-down, -1-up, 0-none

*/

#include"Header.h"
#include<iterator>

//Constructors
Elevator::Elevator() {
	floorNum = 2;
	pos = 1;
	numIn = 0;
}

Elevator::Elevator(int floorNum) {
	floorNum = floorNum;
	pos = 1;
	numIn = 0;
}

//Getters
//Setters

//Display elevator loading
void Elevator::elevator_loading_screen() {
	//FIXME
	system("CLS");
	cout << "\tFloor: " << pos << endl;
	cout << "====================||====================" << endl;
	for (int i = 0; i < 10; i++)
		cout << "||                  ||                  ||" << endl;
	cout << "====================||====================" << endl;
}

//Change elevator position
void Elevator::elevator_change() {
	clock_t clk = clock();
	do {
		clk = clock() - clk;
	} while (clk / CLOCKS_PER_SEC < 3);
}

//Return the request from outside people
void Elevator::outside_random_requests() {
	srand(time(0));
	OutsideRequest request;
	request.floor = rand() % floorNum + 1;
	// -2: down, -1: up
	request.upOrdown = rand() % 3 - 2;
	OutRequests.push_back(request);
}

//Set inside requests
void Elevator::set_inside_requests() {
	int destination;
	int people;

	//Get destinations
	elevator_loading_screen();
	cout << "Enter destinations, (0) to stop" << endl;
	cin >> destination;
	while (destination > 0){
		numIn++;
		InRequests.push_back(destination);
		cin >> destination;
	}
	
}

//Handle the request queue
void Elevator::handle_requests() {

	set_inside_requests();

	//1 new outside request
	outside_random_requests();
	//Pick up new people in the way
	InRequests.push_back(OutRequests.front().floor);
	numIn++;

	while (!InRequests.empty()) {
		//Going up first
		if (InRequests.front() >= pos) {
			//Organize base on priority
			InRequests.sort();
			list<int>::iterator it = InRequests.begin();
			for (; it != InRequests.end(); it++) {

			}

			while (!InRequests.empty()) {
				//Changing position
				elevator_loading_screen();
				cout << "Going Up...";
				elevator_change();
				pos++;
				//Elevator stop at 1 destination
				if (pos == InRequests.front()) {
					InRequests.pop_front();
					set_inside_requests();
				}
					
			}
		}
		else {
			InRequests.sort();
			InRequests.reverse();
		}

	}
}