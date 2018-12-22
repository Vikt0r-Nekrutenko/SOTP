#include "xml_node.h"
using xml_utilites::xml_node;

xml_node::xml_node(const std::string _tag_name) : xml_string(_tag_name, ""){}

xml_node::~xml_node(){}

xml_node::xml_node(const std::string _tag_name, const std::string _data) : 
					xml_string(_tag_name, _data){}

void xml_node::addChildNode(xml_node& _node){
	m_childs.push_back(&_node);
}

void xml_node::getTreeToFile(std::ofstream& _file){
	if (!m_childs.empty()){
		_file << m_tag.getOpenTag() << std::endl;
		for(xml_node* i : m_childs){
			i->getTreeToFile(_file);
		}
		_file << m_tag.getCloseTag() << std::endl;
	}
	else{
		_file << getStr() << std::endl;
	}
}
