/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
/**
 * @file	: XmlDocument.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/16 10:10:26
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */

#ifndef _XMLDOCUMENT_H
#define _XMLDOCUMENT_H
#include <string>
#include "XmlSerialize_Global.h"
class CXmlElement;

/*!
 * @class	: CXmlDocument
 * @brief	: xml文档类，负责xml的读取或存入
 * @author	: liuk
 * @date	: 2017/04/16 10:53
 */
class XMLSERILIZE_EXPORT CXmlDocument
{
public:
	CXmlDocument();
	~CXmlDocument();

public:

	/**
	 * @fn		: SaveFile
	 * @brief	: 将xml文档保存到本地文件中
	 * @access	: public 
	 * @param	: const std::string & strFile 文件名
	 * @return	: bool
	 */
	bool SaveFile(const std::string& strFile);

	/**
	 * @fn		: LoadFile
	 * @brief	: 本地文件中加载xml文档
	 * @access	: public 
	 * @param	: const std::string & strFile
	 * @return	: bool
	 */
	bool LoadFile(const std::string& strFile);

	/**
	 * @fn		: RootElement
	 * @brief	: 获取根节点
	 * @access	: public 
	 * @return	: CXmlElement*
	 */
	CXmlElement* RootElement();

	/**
	 * @fn		: SetVersion
	 * @brief	:设置版本，在调用保存前调用
	 * @access	: public 
	 * @param	: const std::string & strVersion
	 * @return	: void
	 */
	void SetVersion(const std::string& strVersion);

	/**
	 * @fn		: SetCodec
	 * @brief	: 设置字符编码，在调用保存前调用
	 * @access	: public 
	 * @param	: const std::string & strCodec
	 * @return	: void
	 */
	void SetCodec(const std::string& strCodec);

	/**
	 * @fn		: SetStandalone
	 * @brief	: 设置标准，在调用保存前调用
	 * @access	: public 
	 * @param	: const std::string & strStandalone
	 * @return	: void
	 */
	void SetStandalone(const std::string& strStandalone);

	/**
	 * @fn		: SetRootElement
	 * @brief	: 设置要保存到文件的xml节点，该节点会成为xnl文件的根节点
	 * @access	: public 
	 * @param	: CXmlElement * pSrcElement
	 * @return	: void
	 */
	void SetRootElement(CXmlElement* pSrcElement);
private:
	CXmlElement* m_pRootElement;

	// 版本
	std::string m_strVersion;
	// 字符编码
	std::string m_strCodec;
	//标准
	std::string m_strStandalone;
};

#endif // _XMLDOCUMENT_H