
/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/

/**
 * @file	: XmlSerializeMacro.h
 * @brief	: XML序列化宏定义
 * @author	: liuk
 * @date	: 2017/04/09 10:51:36
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef XMLSERIALIZEMACRO_H
#define XMLSERIALIZEMACRO_H
#include "XmlElement.h"
#include "XmlDocument.h"
#include "string"
 /**
 * @fn		: DECLARE_XML_SERIALIZE(className, nodeName)
 * @brief	: 序列化声明宏，在内中声明
 * @access	: macro
 * @param	: className,类名
 * @param	: nodeName,节点名称
 */
#define DECLARE_XML_SERIALIZE() \
	public:\
		CXmlElement* GetCurrentElement(){return m_pXmlElement;}\
		virtual CXmlElement*  XMLSerialize(bool bStore, CXmlElement* pRootXmlElement); \
//		virtual bool Store2XmlFile(const std::string& strFile);\
//		virtual bool LoadFromXmlFile(const std::string& strFile);\

 /**
 * @fn		: BEGIN_XML_SERIALIZE(className, nodeName)
 * @brief	: 序列化实现宏，在cpp中实现
 * @access	: macro
 * @param	: className,类名
 * @param	: nodeName,节点名称
 */
#define BEGIN_XML_SERIALIZE(className, nodeName)\
CXmlElement*  className::XMLSerialize(bool bStore, CXmlElement* pRootXmlElement)\
{\
	std::string strNodeName = #nodeName;\
	if(bStore)\
	{\
		pRootXmlElement->SetName(strNodeName);\
	}\

 /**
 * @fn		: XML_SER_VAR(name, var)
 * @brief	: 序列化一个基本类型
 * @access	: macro
 * @param	: name,节点名
 * @param	: var,对象
 */
#define XML_SER_VAR(name, var)\
	if(bStore)\
	{\
		CXmlElement* pElement = new CXmlElement;\
		pElement->SetName(#name);\
		pElement->SetValue(var);\
		pRootXmlElement->PushChild(pElement);\
	}\
	else\
	{\
		CXmlElement* pElement = pRootXmlElement->NextChildElement();\
		if(pElement->GetName() == std::string(#name))\
			pElement->GetValue(var);\
	}\
	
 /**
 * @fn		: XML_SER_STL_VAR(name, subName, var)\
 * @brief	: 序列化一个基本类型的标准容器
 * @access	: macro
 * @param	: name,数组名
 * @param	: subName,子节点名
 * @param	: var,对象
 */
#define XML_SER_STL_VAR(name, subName, var)\
	if(bStore)\
	{\
		CXmlElement* pParent = new CXmlElement;\
		pParent->SetName(#name);\
		for(int i = 0; i < var.size(); i++)\
		{\
			CXmlElement* pSubElement = new CXmlElement;\
			pSubElement->SetName(#subName);\
			pSubElement->SetValue(var[i]);\
			pParent->PushChild(pSubElement);\
		}\
		pRootXmlElement->PushChild(pParent);\
	}\
	else\
	{\
		CXmlElement* pParent = pRootXmlElement->NextChildElement();\
		if(pParent->GetName() == std::string(#name))\
		{\
			CXmlElement* pSubElement = pParent->FirstChildElement();\
			var.resize(pParent->ChildCount());\
			int i = 0;\
			while(pSubElement)\
			{\
				pSubElement->GetValue(var[i++]);\
				pSubElement = pParent->NextChildElement();\
			}\
		}\
	}\
	
 /**
 * @fn		: XML_SER_OBJECT(name, var)\
 * @brief	: 序列化xml对象
 * @access	: macro
 * @param	: name,节点名名
 * @param	: var,对象
 */
#define XML_SER_OBJECT(name, var)\
	if(bStore)\
	{ \
		CXmlElement* pObjElement = var.XMLSerialize(bStore, new CXmlElement);\
		pObjElement->SetName(#name);\
		pRootXmlElement->PushChild(pObjElement);\
	}\
	else\
	{\
		var.XMLSerialize(bStore, pRootXmlElement->NextChildElement());\
	}\

 /**
 * @fn		: XML_SER_STL_OBJECT(name, subName, var)\
 * @brief	: 序列化一个xml对象的标准容器
 * @param	: name,数组名
 * @param	: subName,子节点名
 * @param	: var,对象
 */
#define XML_SER_STL_OBJECT(name, subName, var)\
	if(bStore)\
	{\
		CXmlElement* pParent = new CXmlElement;\
		pParent->SetName(#name);\
		for(int i = 0; i < var.size(); i++)\
		{\
			CXmlElement* pObjElement = var[i].XMLSerialize(bStore, new CXmlElement);\
			pObjElement->SetName(#name);\
			pParent->PushChild(pObjElement);\
		}\
		pRootXmlElement->PushChild(pParent);\
	}\
	else\
	{\
		CXmlElement* pParent = pRootXmlElement->NextChildElement();\
		if(pParent->GetName() == std::string(#name))\
		{\
			CXmlElement* pSubElement = pParent->FirstChildElement();\
			var.resize(pParent->ChildCount());\
			int i = 0;\
			while(pSubElement)\
			{\
				var[i++].XMLSerialize(bStore,pSubElement);\
				pSubElement = pParent->NextChildElement();\
			}\
		}\
	}\

 /**
 * @fn		: XML_SER_OBJECT(name, var)\
 * @brief	: 序列化xml属性
 * @access	: macro
 * @param	: name,属性名
 * @param	: var,属性对象
 */
#define  XML_SER_ATTR(name, var)\
	if(bStore)\
	{\
		pRootXmlElement->SetAttribute(#name, var);\
	}\
	else\
	{\
		pRootXmlElement->GetAttribute(#name, var);\
	}\

#define  END_XML_SERIALIZE()\
	return pRootXmlElement;\
	}

#endif // XMLSERIALIZEMACRO_H
