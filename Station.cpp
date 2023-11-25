// Name: Adnan Mohammed
// Seneca Student ID: 174731216
// Seneca email: amohammed109@myseneca.ca
// Date of completion: 7th November, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Station.h"
#include "Utilities.h"

size_t sdds::Station::m_widthField = 0;
size_t sdds::Station::id_generator = 0;

namespace sdds
{
	/*No-argument constructor*/
	Station::Station(){}

	/*One-argument Constructor
	Parameters: const string& str*/
	Station::Station(const std::string& str)
	{
		Utilities util;
		size_t pos = 0;
		bool more = true;

		if (str != "")
		{
			m_id = ++id_generator;
			m_name = util.extractToken(str, pos, more);
			if (more) {
				m_serialNumber = std::stoul(util.extractToken(str, pos, more));
				m_quantity = std::stoul(util.extractToken(str, pos, more));
				m_widthField > util.getFieldWidth() ? m_widthField : m_widthField = util.getFieldWidth();
				m_description = util.extractToken(str, pos, more);
			}
		}
	}
	/*Retruns station name*/
	const std::string& Station::getItemName() const
	{
		return m_name;
	}
	/*Returns next serial number*/
	size_t Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}
	/*Returns quantity*/
	size_t Station::getQuantity() const
	{
		return m_quantity;
	}
	/*Subtacts 1 from quantity if greater than 0*/
	void Station::updateQuantity()
	{
		if (m_quantity > 0)
		{
			m_quantity--;
		}
		else {
			std::cout << "Quantity: 0" << std::endl;
		}
	}
	/*Displays Station object to ostream*/
	void Station::display(std::ostream& os, bool full) const
	{
		os.setf(std::ios::right);
		os.fill('0');
		os.width(3);
		os << m_id << " | ";
		os.unsetf(std::ios::right);
		os.setf(std::ios::left);
		os.fill(' ');
		os.width(m_widthField);
		os << m_name << " | ";
		os.unsetf(std::ios::left);
		os.setf(std::ios::right);
		os.fill('0');
		os.width(6);
		os << m_serialNumber << " | ";
		os.fill(' ');
		if (full)
		{
			os.width(4);
			os << m_quantity << " | ";
			os.unsetf(std::ios::right);
			os.setf(std::ios::left);
			os << m_description;
		}
		os << std::endl;
	}
}