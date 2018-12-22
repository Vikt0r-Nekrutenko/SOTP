#ifndef XML_STRING_H
#define XML_STRING_H

#include "xml_tag.h"
#include "xml_data.h"

namespace xml_utilites
{
	class xml_string
	{
		public:
			xml_string();
			xml_string(const string _str);
			xml_string(const string _tag_name, const string _data);
			~xml_string();
			
			const string getStr()const;
			const xml_tag& getTag()const;
			const xml_data& getData()const;
			
			bool Check();
		protected:
			bool isOnlyOpenTag()const;
			bool isValid()const;
			
			bool searchForTags();
			bool searchForData();
	
			xml_data m_data;
			xml_tag m_tag;
		private:
			string m_buffer;
	};	
}

#endif
