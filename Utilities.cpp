#define _CRT_SECURE_NO_WARNINGS

#include"Utilities.h"

namespace sdds
{
	/*Sets the field width for the instance to the received argument
	Parameters: size_t newWidth*/
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	/*Returns instance's field width*/
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		return std::string();
	}
	/*sets class memeber m_delimeter to received argument
	Parameters: char newDelimiter*/
    void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	/*Retruns class delimeter(m_delimiter)*/
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}