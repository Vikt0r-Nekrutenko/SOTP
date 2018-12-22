#ifndef XML_DATA_H
#define XML_DATA_H

#include <string>

using std::string;

namespace xml_utilites
{
	class xml_data
	{
		public:
			xml_data();
			xml_data(const string _data);
			~xml_data();
			
			const string& toStr()const;
			const int toInt()const;
			
		private:
			string m_data;
	};
}
#endif
