#include "interval.h"

interval::interval() : std::pair<int, int>(0,0){}

interval::interval(const int _low, const int _high) : std::pair<int, int>(_low, _high){}

interval::~interval(){}

bool interval::isValid()const{	
	if(first >= 0 && second > first){
		return true;
	}
	return false;
}

bool interval::operator==(const interval& _intrv){
	if(first == _intrv.getLow() && second == _intrv.getHigh()){
		return true;
	}
	return false;
}


const int& interval::getLow()const{
	return first;
}

const int& interval::getHigh()const{
	return second;
}

void interval::setLow(const int _var){
	first = _var;
}

void interval::setHigh(const int _var){
	second = _var;
}
