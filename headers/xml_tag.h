#ifndef XML_TAG_H
#define XML_TAG_H

#include <string>

using std::string;

namespace xml_utilites
{
	class xml_tag
	{
		public:
			xml_tag();
			xml_tag(const string _tag_name);
			~xml_tag();
			
			const string getOpenTag()const;
			const string getCloseTag()const;
			
		protected:
			string m_tag_name;
	};
}
#endif
