#pragma once

#include <iostream>

using namespace std;

class Vehicle {

	int m_speed;
	int m_gearnumber;
	bool m_isWork;
	double m_price;
	string m_brand;

public:
	Vehicle(double price = 0.0, string brand = "") {
		m_isWork = false;
		m_gearnumber = 0;
		m_speed = 0;
		m_price = price;
		m_brand = brand;

	}
	bool getWork()const { return m_isWork; }
	int getSpeed()const { return m_speed; }
	int getGearnumber() const { return m_gearnumber; }
	double getPrice()const { return m_price; }
	string getBrand()const { return m_brand; }

	void setWork(bool is_work) { m_isWork = is_work; }
	void setGearNumber(int gear_number) { m_gearnumber = gear_number; }
	void setSpeed(int speed) { m_speed = speed; }
	void setPrice(double price) { m_price = price; }
	void setBrand(string brand) { m_brand = brand; }
	void startEngine() {
		m_isWork = true;
		m_gearnumber = 1;
	}
	void stopEngine() {
		m_isWork = false;
		m_gearnumber = 0;
	}
	virtual void displayInformation() {
		cout << "Brand:" << m_brand << endl;
		cout << "Price:" << m_price << endl;
		cout << "Speed:" << m_speed << endl;
		m_isWork ? cout << "Engine on" << endl : cout << "Engine off" << endl;

	}

	virtual void increaseSpeed() = 0;
	virtual void decreaseSpeed() = 0;

};

class Car : public Vehicle {

public:
	Car(double car_price,string car_brand):Vehicle(car_price,car_brand){}

	void increaseSpeed() {
		if (getWork()) {
			int speed_temp = getSpeed();
			if (speed_temp <= 120) {
				int gear_temp = getGearnumber();
				setSpeed(speed_temp + 30);
				if (gear_temp < 6) {
					setGearNumber(gear_temp + 1);
				}
			}
		}
		else {
			cout << "Motoru calistirin" << endl;
		}
	}

	void decreaseSpeed() {
		if (getWork()) {
			int speed_temp = getSpeed();
			if (speed_temp >= 30) {
				int gear_temp = getGearnumber();
				setSpeed(speed_temp - 30);
				if (gear_temp >= 2) {
					setGearNumber(gear_temp - 1);
				}
			}
		}
		else {
			cout << "Motoru calistirin" << endl;
		}
	}

	void displayInformation() {
		cout << "Car information" << endl;
		Vehicle::displayInformation();
	}

};

class MotorCycle : public Vehicle {
public:
	MotorCycle(double motor_price, string motor_brand){}

	void increaseSpeed() {
		if (getWork()) {
			int speed_temp = getSpeed();
			if (speed_temp <= 90) {
				int gear_temp = getGearnumber();
				setSpeed(speed_temp + 20);
				if (gear_temp < 6) {
					setGearNumber(gear_temp + 1);
				}
			}
		}
		else {
			cout << "Motoru calistirin" << endl;
		}
	}

	void decreaseSpeed() {
		if (getWork()) {
			int speed_temp = getSpeed();
			if (speed_temp >= 20) {
				int gear_temp = getGearnumber();
				setSpeed(speed_temp - 20);
				if (gear_temp >= 2) {
					setGearNumber(gear_temp - 1);
				}
			}
		}
		else {
			cout << "Motoru calistirin" << endl;
		}
	}

	void displayInformation() {
		cout << "MotorCycle information" << endl;
		Vehicle::displayInformation();
	}





};