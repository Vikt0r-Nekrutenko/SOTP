#ifndef XML_WRITER_H
#define XML_WRITER_H

#include <iostream>
#include "xml_node.h"

namespace xml_utilites{

	class xml_writer
	{
		public:
			xml_writer(const std::string _file_name);
			~xml_writer();
			
			void Write(xml_node& _node);
		private:
			std::ofstream m_file;
	};
}
#endif
