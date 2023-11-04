#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"Utilities.h"

//Initializing m_delimeter(class variable)
char sdds::Utilities::m_delimiter = ',';

namespace sdds
{
	/*Self-Developed function which removes prevailing and trailing spaces from a string
	Parameters: const string& str*/
	std::string Utilities::trim(const std::string& str)
	{
		//Removes spaces
		std::string result{};
		if (str != "")
		{
			result = str.substr(str.find_first_not_of(' '), (str.find_last_not_of(' ') - str.find_first_not_of(' ') + 1));
		}
		return result;
	}

	Utilities::Utilities(){}

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
	/*Exracts a token from the string using the arguments received
	Parameters: const string& str
	size_t& next_pos
	bool& more*/
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		size_t delimeterPos = str.find(m_delimiter, next_pos);
		std::string result{};
		
		if (str[next_pos] == m_delimiter)
		{
			more = false;
			throw "Error!";
		}
		else
		{
			if (str == "")
			{
				more = false;
				std::cout << "Error! Empty String";
				result = "";
			}
			
			if (delimeterPos != std::string::npos)
			{
				result = trim(str.substr(next_pos, (delimeterPos - next_pos)));

				if (delimeterPos == std::string::npos)
				{
					more = false;
					next_pos++;
				}
				else {
					next_pos = (delimeterPos + 1);
				}

			}
			else {
				more = false;
				result = trim(str.substr(next_pos));
			}
		}
		
		//Updaes field width if it is less than the current token length
		m_widthField < result.length() ? m_widthField = result.length() : m_widthField;

		return result;
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