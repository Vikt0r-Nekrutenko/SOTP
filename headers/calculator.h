#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <mutex>
#include <atomic>
#include <math.h>
#include <thread>
#include <iostream>
#include "interval.h"
#include "container.h"

class calculator
{
	public:
		calculator(container& _shared_container);
		~calculator();
		
		void startCalculation(const std::vector<interval>& _intrvs);
		
	private:
		inline void printState(const std::string _thread_state, const std::string _interval_state,  const interval& _intrv);
		void Calculation(const interval& _intrv);
		void Insert(const interval& _intrv, const std::vector<int>& _field);
		
		container* m_shared_container;
		std::recursive_mutex mtx;
		// if use nonatomic unsigned int, app is crashes, use of mutex is useless
		std::atomic<unsigned int> m_threads_count;
};

#endif
