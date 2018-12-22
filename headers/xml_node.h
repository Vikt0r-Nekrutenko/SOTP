#ifndef XML_NODE_H
#define XML_NODE_H

#include <fstream>
#include <vector>
#include <string>
#include "xml_string.h"
#include "xml_tag.h"

namespace xml_utilites{
	
	class xml_node : private xml_string
	{
		public:
			xml_node(const std::string _tag_name);
			xml_node(const std::string _tag_name, const std::string _data);
			~xml_node();
			void addChildNode(xml_node& _node);
			void getTreeToFile(std::ofstream& _file);
		private:
			std::vector<xml_node*> m_childs;
	};
}
#endif
