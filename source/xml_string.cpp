#include "xml_string.h"
#include <regex>

using xml_utilites::xml_string;
using xml_utilites::xml_data;
using xml_utilites::xml_tag;

xml_string::xml_string(){}

xml_string::~xml_string(){}

xml_string::xml_string(const string _str) : m_buffer(_str){ 
	Check();
}

xml_string::xml_string(const string _tag_name, const string _data) : m_tag(_tag_name), m_data(_data){}

const string xml_string::getStr()const{
	return m_tag.getOpenTag() + m_data.toStr() + m_tag.getCloseTag();
}

const xml_tag& xml_string::getTag()const{
	return m_tag;
}

const xml_data& xml_string::getData()const{
	return m_data;
}

bool xml_string::isOnlyOpenTag()const{
	std::regex o_tag_p("<?\\w+>?");
	return std::regex_match(m_buffer, o_tag_p);		
}

bool xml_string::isValid()const{
	std::regex str_p("(\\s+)?<\\w+>(\\s+)?\\d+(\\s+)?</\\w+>(\\s+)?");
	return std::regex_match(m_buffer, str_p);
}

bool xml_string::searchForTags(){
	std::smatch result;
	std::regex o_tag_p("<\\w+>");
	if (std::regex_search(m_buffer, result, o_tag_p)){
		xml_tag tmp_o_tag = result.str();
		std::regex c_tag_p = std::regex(tmp_o_tag.getCloseTag());
		if(std::regex_search(m_buffer, result, c_tag_p)){
			m_tag = tmp_o_tag;
			return true;
		}
		return false;
	}
	return false;
}

bool xml_string::searchForData(){
	std::smatch result;
	size_t end_open_tag = m_buffer.find_first_of('>') + 1;
	size_t begin_close_tag = m_buffer.find_last_of('<');
	string data_region = string(m_buffer.begin()+end_open_tag, m_buffer.begin()+begin_close_tag);
	
	if (std::regex_search(data_region, result, std::regex("\\d+"))){
		m_data = result.str();
		return true;
	}
	return false;
}

bool xml_string::Check(){
	if(isOnlyOpenTag()){
		m_tag = xml_tag(m_buffer);
	}
	else if(isValid()){
		if(searchForTags() && searchForData())
			return true;
		return false;
	}
	return false;
}
			
