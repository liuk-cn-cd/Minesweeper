#ifndef GAMERECORDTOOL_H__
#define GAMERECORDTOOL_H__
#include "XmlSerializeObject.h"
#include "XmlSerializeMacro.h"

class CGameRecordTool :
	public CXmlSerializeObject
{
	DECLARE_XML_SERIALIZE()
public:
	CGameRecordTool();
	virtual ~CGameRecordTool();
public:

};

#endif // GAMERECORDTOOL_H__




