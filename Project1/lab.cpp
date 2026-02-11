//Task 1

#include<iostream>
using namespace std;

class Time {
	private:
	int hour;
	int minute;
	int second;
public:
	void setTime(int hours, int minutes, int seconds);
	int getHour();
	int getMinute();
	int getSecond();
	void displayTime();
	Time addTime(Time,Time);
	int numberofDays(Time,Time);
};

void Time::setTime(int hours, int minutes, int seconds) {
	this->hour = hours;
	this -> minute = minutes;
	this -> second = seconds;
};
int Time::getHour() {
	return hour;
};
int Time::getMinute() {
	return minute;
};
int Time::getSecond() {
	return second;
};

Time Time::addTime(Time t1, Time t2) {
	Time Result;
	int sec = t1.getSecond() + t2.getSecond();
	int min = t1.getMinute() + t2.getMinute() + sec / 60;
	int hr = t1.getHour() + t2.getHour() + min / 60;
	hr = hr % 24;
	min = min % 60;
	sec = sec % 60;
	Result.setTime(hr, min, sec);
	return Result;
	};

int Time::numberofDays(Time t1, Time t2) {
	Time Result = addTime(t1, t2);
	int totalSeconds = Result.getHour() * 3600 + Result.getMinute() * 60 + Result.getSecond();
	int days = totalSeconds / (24 * 3600);
	return days;
};

void Time::displayTime() {
	cout << "Time: " << hour << ":" << minute << ":" << second << endl;
};



int main() {
	Time t1, t2;
	t1.setTime(10, 30, 45);
	t2.setTime(5, 45, 30);
	Time result = t1.addTime(t1, t2);
	result.displayTime();
	int days = t1.numberofDays(t1, t2);
	cout << "Number of days: " << days << endl;
	return 0;

}

