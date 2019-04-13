
/**********************************************************************
 * @特别声明
 *     本段代码由liuk创建，所有通过正常途径获取此文件的开发人员
 * 均可任意修改、增加及删除文件内容，但请保留此声明。
 *     如有疑问请联系作者。
 * @特别声明结束
 ********************************************************************/
 /**
 * @file	: XmlElement.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/09 12:04:59
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */
#ifndef _XMLELEMENT_H
#define _XMLELEMENT_H
#include "XmlSerialize_Global.h"
class TiXmlElement;
/**
 * @file	: XmlElement.h
 * @brief	:
 * @author	: liuk
 * @date	: 2017/04/09 12:05:12
 * @version : 1.0.0.0
 * @contact	: liukangx@hotmail.com
 * 
 */

#include <vector>

/*!
 * @class	: CXmlElement
 * @brief	: 
 * @author	: liuk
 * @date	: 2017/04/09 12:05
 */
class XMLSERILIZE_EXPORT CXmlElement
{
public:
	CXmlElement(const std::string& strName = "");
	~CXmlElement();
	
public:

	/**
	 * @fn		: FromTiXmlElement
	 * @brief	: 从tixml中加载转换
	 * @access	: public 
	 * @param	: TiXmlElement * pTiElement
	 * @return	: void
	 */
	void FromTiXmlElement(TiXmlElement* pTiElement);

	/**
	 * @fn		: SetName
	 * @brief	: 设置节点名称
	 * @access	: public 
	 * @param	: const std::string & strName
	 * @return	: void
	 */
	void SetName(const std::string& strValue);

	/**
	 * @fn		: GetName
	 * @brief	: 获取节点名称
	 * @access	: public 
	 * @return	: std::string
	 */
	std::string GetName();

	/**
	 * @fn		: SetValue
	 * @brief	: 设置节点值
	 * @access	: public 
	 * @param	: const int nValue
	 * @return	: void
	 */
	void SetValue(const int nValue);

	/**
	* @fn		: SetValue
	* @brief	: 设置节点值
	* @access	: public
	* @param	: const double dValue
	* @return	: void
	*/
	void SetValue(const double dValue);

	/**
	* @fn		: SetValue
	* @brief	: 设置节点值
	* @access	: public
	* @param	: const float fValue
	* @return	: void
	*/
	void SetValue(const float fValue);

	/**
	* @fn		: SetValue
	* @brief	: 设置节点值
	* @access	: public
	* @param	: const std::string & strText
	* @return	: void
	*/
	void SetValue(const std::string& strText);

	/**
	 * @fn		: GetValue
	 * @brief	: CXmlElement::GetValue
	 * @access	: public 
	 * @param	: [out] int & nValue
	 * @return	: bool
	 */
	bool GetValue(int& nValue);

	/**
	 * @fn		: GetValue
	 * @brief	: CXmlElement::GetValue
	 * @access	: public 
	 * @param	: [out] double & dValue
	 * @return	: bool
	 */
	bool GetValue(double& dValue);

	/**
	 * @fn		: GetValue
	 * @brief	: CXmlElement::GetValue
	 * @access	: public 
	 * @param	: [out] float & fValue
	 * @return	: bool
	 */
	bool GetValue(float& fValue);

	/**
	 * @fn		: GetValue
	 * @brief	: CXmlElement::GetValue
	 * @access	: public 
	 * @param	: [out] std::string & strValue
	 * @return	: bool
	 */
	bool GetValue(std::string& strValue);


	/**
	 * @fn		: SetAttribute
	 * @brief	: 设置一个属性
	 * @access	: public 
	 * @param	: const std::string & strName
	 * @param	: const std::string & strValue
	 * @return	: void
	 */
	void SetAttribute(const std::string& strName, const std::string& strValue);

	/**
	* @fn		: SetAttribute
	* @brief	: 设置一个属性
	* @access	: public
	* @param	: const std::string & strName 属性名
	* @param	:  int nValue 值
	* @return	: void
	*/
	void SetAttribute(const std::string& strName, int nValue);

	/**
	* @fn		: SetAttribute
	* @brief	: 设置一个属性
	* @access	: public
	* @param	: const std::string & strName
	* @param	: double dValue
	* @return	: void
	*/
	void SetAttribute(const std::string& strName, double dValue);

	/**
	* @fn		: SetAttribute
	* @brief	: 设置一个属性
	* @access	: public
	* @param	: const std::string & strName
	* @param	: float fValue
	* @return	: void
	*/
	void SetAttribute(const std::string& strName, float fValue);

	/**
	 * @fn		: GetAttribute
	 * @brief	: 获取一个属性
	 * @access	: public 
	 * @param	: const std::string & strName
	 * @param	: [out] std::string & strValue
	 * @return	: bool
	 */
	bool GetAttribute(const std::string& strName, std::string& strValue);

	/**
	* @fn		: GetAttribute
	* @brief	: 获取一个属性
	* @access	: public
	* @param	: const std::string & strName
	* @param	: [out] int& nValue
	* @return	: bool
	*/
	bool GetAttribute(const std::string& strName, int& nValue);

	/**
	* @fn		: GetAttribute
	* @brief	: 获取一个属性
	* @access	: public
	* @param	: const std::string & strName
	* @param	: [out] double& dValue
	* @return	: bool
	*/
	bool GetAttribute(const std::string& strName, double& dValue);

	/**
	* @fn		: GetAttribute
	* @brief	: 获取一个属性
	* @access	: public
	* @param	: const std::string & strName
	* @param	: [out] float& fValue
	* @return	: bool
	*/
	bool GetAttribute(const std::string& strName, float& fValue);

	/**
	 * @fn		: NextChildElement
	 * @brief	: 获取下一个子节点
	 * @access	: public 
	 * @return	: CXmlElement*
	 */
	CXmlElement* NextChildElement();
	
	/**
	 * @fn		: FirstChildElement
	 * @brief	: 获取第一个子节点，并将游标置于头
	 * @access	: public 
	 * @return	: CXmlElement*
	 */
	CXmlElement* FirstChildElement();


	/**
	 * @fn		: PushChild
	 * @brief	: 插入尾后子节点
	 * @access	: public 
	 * @param	: CXmlElement * pChild
	 * @return	: void
	 */
	void PushChild(CXmlElement* pChild);

	/**
	 * @fn		: IsEnd
	 * @brief	: 是否已经遍历到最后一个节点
	 * @access	: public 
	 * @return	: bool
	 */
	bool IsEnd();

	/**
	 * @fn		: CurrentElement
	 * @brief	: 获取当前节点关联的tixml对象
	 * @access	: public 
	 * @return	: TiXmlElement*
	 */
	TiXmlElement* CurrentElement();

	/**
	 * @fn		: Clear
	 * @brief	: 清除节点
	 * @access	: public 
	 * @return	: void
	 */
	void Clear();

	/**
	 * @fn		: ChildCount
	 * @brief	: 获取字成员数量
	 * @access	: public 
	 * @return	: int
	 */
	int ChildCount();


private:
	/// 子节点
	std::vector<CXmlElement*> m_vecChildNode;
	// 当前子节点
	int m_nCursor;

	TiXmlElement* m_pXmlNode;

};

#endif //_XMLELEMENT_H