#pragma once

class Time {
public:
	Time();
	Time(double _timeValueSeconds);
	
	float GetTimeSeconds();
	float GetTimeMilliseconds();

	float operator- (Time _timeValue);
	float operator+ (Time _timeValue);
	void operator+= (Time _timeValue);
	void operator-= (Time _timeValue);

private:
	float timeValueSeconds;
};