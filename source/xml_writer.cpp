#include "xml_writer.h"

using xml_utilites::xml_writer;
using xml_utilites::xml_node;

xml_writer::xml_writer(const std::string _file_name){
	m_file.open(_file_name, std::ios::trunc);
	if(!m_file.is_open()){
		std::cout << "file " << _file_name << " isn't opened!" << std::endl;
	}
}

xml_writer::~xml_writer(){
	if(m_file.is_open()){
		m_file.close();
	}
}

void xml_writer::Write(xml_node& _node){
	if (!m_file.is_open()) return;
	_node.getTreeToFile(m_file);
}
