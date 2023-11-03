#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Station.h"

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
	}
	/*Displays Station object to ostream*/
	void Station::display(std::ostream& os, bool full) const
	{
		os.width(3);
		os << m_id << " | ";
		os.width(m_widthField);
		os << m_name << " | ";
		os.width(6);
		os << m_serialNumber << " |";
		if (full)
		{
			os << " ";
			os.width(4);
			os << m_quantity << " | ";
			os << m_description;
		}
		os << std::endl;
	}
}