/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

 /**
 * @file	: XmlSerializeObject.h
 * @brief	: xml序列化对象基类声明
 * @author	: liuk
 * @date	: 2017/04/09 10:31:34
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 *
 */
#ifndef _XMLSERIALIZEOBJECT_H
#define _XMLSERIALIZEOBJECT_H
#include "XmlSerialize_Global.h"
#include <string>

class CXmlElement;
class CXmlDocument;
/*!
 * @class	: CXmlSerializeObject
 * @brief	: xml序列化基类，所有序列化类从此处派生
 * @author	: liuk
 * @date	: 2017/04/09 10:35
 */
class XMLSERILIZE_EXPORT CXmlSerializeObject
{
public:
	CXmlSerializeObject();
	virtual ~CXmlSerializeObject();
protected:
	/**
	 * @fn		: ReadDataFromXmlFile
	 * @brief	: 从xml文件里读取数据
	 * @access	: protected 
	 * @return	: void
	 */
	bool ReadXmlFile(const std::string& strFile);

	/**
	 * @fn		: WriteData2XmlFile
	 * @brief	: 保存数据到xml文件
	 * @access	: protected 
	 * @return	: void
	 */
	bool StoreXmlFile(const std::string& strFile);
protected:
	virtual CXmlElement* XMLSerialize(bool bStore, CXmlElement* pRootXmlElement) = 0;
//	virtual bool Store2XmlFile(const std::string& strFile) = 0;
//	virtual bool LoadFromXmlFile(const std::string& strFile) = 0;

protected:
	CXmlElement* m_pXmlElement;
	CXmlDocument* m_pXmlDocument;
};

#endif // _XMLSERIALIZEOBJECT_H