#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>

class container
{
	public:
		container();
		~container();
		
		void add(const int& _value);
		const int getPrime(const std::size_t _index)const;
		const std::string getStr()const;
		const std::size_t getSize()const;
	private:
		std::vector<int> m_ranges_of_prime;
};

#endif
