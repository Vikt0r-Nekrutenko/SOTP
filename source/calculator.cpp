#include "calculator.h"

calculator::calculator(container& _shared_container):m_threads_count(0),
	m_shared_container(&_shared_container){}

calculator::~calculator(){}

void calculator::startCalculation(const std::vector<interval>& _intrvs){
	for(const interval& i : _intrvs){
		while(m_threads_count >= std::thread::hardware_concurrency()){
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		std::thread ths(&calculator::Calculation, this, std::cref(i));
		m_threads_count++;
		ths.detach();
	}
	while(m_threads_count != 0) std::this_thread::sleep_for(std::chrono::seconds(1));
}

void calculator::printState(const std::string _thread_state, const std::string _interval_state, const interval& _intrv){
	mtx.lock();
	std::cout << _thread_state <<"\tCount:" << m_threads_count << "\t"<< _interval_state <<":\t" << _intrv.getLow() <<"-"<< _intrv.getHigh() <<std::endl;
	mtx.unlock();
}

void calculator::Calculation(const interval& _intrv){
	printState("BEGIN", "Interval", _intrv);
	std::vector<int> _field = std::vector<int>(_intrv.getHigh());
	for (int i = (int)sqrt(_intrv.getHigh()); i >= 2; --i){
		for (long j = i*i; j < _intrv.getHigh(); j += i){
			_field[j] = 1;
		}
	}
	Insert(_intrv, _field);
	m_threads_count--;
	printState("END", "CALCULATED", _intrv);
}

void calculator::Insert(const interval& _intrv, const std::vector<int>& _field){
	for (size_t i = _intrv.getLow() < 2 ? 2 : _intrv.getLow(); i < _field.size(); i++){
		if (_field[i] == 0){
			m_shared_container->add(i);
		}
	}
}
