#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <fstream>
#include <string>
#include <iostream>

#include "xml_string.h"
#include "interval.h"

namespace xml_utilites
{
	class xml_parser
	{
		public:
			xml_parser(const std::string _file_name);
			~xml_parser();
			
			void Parse();
			void addInterval(const interval& _intrv);
			bool checkIdentity(const interval& _intrv)const;
			const std::vector<interval>& getIntervals()const;
		private:
			std::vector<interval> m_intervals;
			std::ifstream m_file;
	};
}
#endif
