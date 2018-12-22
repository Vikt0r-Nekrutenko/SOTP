#include "xml_parser.h"

using xml_utilites::xml_parser;
using xml_utilites::xml_string;

xml_parser::xml_parser(const std::string _file_name){
	m_file.open(_file_name);
	if(!m_file.is_open()){
		std::cout << "file: "<< _file_name <<" isn't opened" << std::endl;
	}
}

xml_parser::~xml_parser(){
	if(m_file.is_open()){
		m_file.close();
	}
}

const std::vector<interval>& xml_parser::getIntervals()const{
	return m_intervals;
}

void xml_parser::Parse(){
	if (!m_file.is_open()) return;
	interval intrv;
	std::string buffer;
	do {		
		std::getline(m_file, buffer);
		xml_string curr_str = xml_string(buffer);
		
		if(curr_str.Check()){
			if(curr_str.getTag().getOpenTag() == "<low>"){
				intrv.setLow(curr_str.getData().toInt());
			}
			else if(curr_str.getTag().getOpenTag() == "<high>"){
				intrv.setHigh(curr_str.getData().toInt());
				addInterval(intrv);
			}
		}
	} while(!m_file.eof());
}

void xml_parser::addInterval(const interval& _intrv){
	if(checkIdentity(_intrv) && _intrv.isValid()){
		m_intervals.push_back( _intrv );
	}
}

bool xml_parser::checkIdentity(const interval& _intrv)const{
	for(interval i : m_intervals){
		if(i == _intrv) {
			return false;
		}
	}
	return true;
}
