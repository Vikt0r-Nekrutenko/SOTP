#include "xml_tag.h"

using xml_utilites::xml_tag;

xml_tag::xml_tag(){}

xml_tag::xml_tag(const string _tag_name){
	if(_tag_name.front() == '<' && _tag_name.back() == '>')
		m_tag_name = string(_tag_name.begin()+1, _tag_name.end()-1);
	else
		m_tag_name = _tag_name;
}

xml_tag::~xml_tag(){}

const string xml_tag::getOpenTag()const{
	return string('<' + m_tag_name + '>');
}

const string xml_tag::getCloseTag()const{
	return string("</" + m_tag_name + '>');
}
