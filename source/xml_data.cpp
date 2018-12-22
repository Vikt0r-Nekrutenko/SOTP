#include "xml_data.h"
#include <exception>

using xml_utilites::xml_data;

xml_data::xml_data(){}

xml_data::~xml_data(){}

xml_data::xml_data(const string _data) : m_data(_data){}

const string& xml_data::toStr()const{
	return m_data;
}

const int xml_data::toInt()const{
	try{
		return stoi(m_data);
	}
	catch(std::exception){ 
		return INT_MIN;
	}
}
