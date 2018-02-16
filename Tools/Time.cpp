#include "Time.h"

Time::Time() {
	timeValueSeconds = 0;
}

Time::Time(double _timeValueSeconds) {
	timeValueSeconds = (float)_timeValueSeconds;
}

float Time::GetTimeSeconds() {
	return timeValueSeconds;
}

float Time::GetTimeMilliseconds() {
	return timeValueSeconds * 1000;
}

float Time::operator- (Time _timeValue) {
	return timeValueSeconds - _timeValue.GetTimeSeconds();
}

float Time::operator+ (Time _timeValue) {
	return timeValueSeconds + _timeValue.GetTimeSeconds();
}

void Time::operator+= (Time _timeValue) {
	timeValueSeconds += _timeValue.GetTimeSeconds();
}

void Time::operator-= (Time _timeValue) {
	timeValueSeconds -= _timeValue.GetTimeSeconds();
}