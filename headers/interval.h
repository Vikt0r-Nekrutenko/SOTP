#ifndef INTERVAL_H
#define INTERVAL_H

#include <vector>
#include <tuple>

class interval : private std::pair<int,int>
{
	public:
		interval();
		interval(const int _low, const int _high);
		~interval();
		
		bool isValid()const;
		bool operator==(const interval& _intrv);
		const int& getLow()const;
		const int& getHigh()const;
	
		void setLow(const int _var);
		void setHigh(const int _var);
};

#endif
