#include "container.h"

container::container(){}

container::~container(){}

void container::add(const int& _value){
	m_ranges_of_prime.push_back(_value);
}

const std::string container::getStr()const{
	std::string str;
	for(size_t i = 0; i < m_ranges_of_prime.size(); i++){
		str += std::to_string(m_ranges_of_prime.at(i)) + " ";
	}
	return str;
}

const int container::getPrime(const std::size_t _index)const{
	return m_ranges_of_prime.at(_index);
}

const std::size_t container::getSize()const{
	return m_ranges_of_prime.size();
}
