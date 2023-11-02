#define _CRT_SECURE_NO_WARNINGS

#include "Station.h"

namespace sdds
{
	Station::Station(const std::string& str)
	{
	}
	const std::string& Station::getItemName() const
	{
		return m_name;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}
	size_t Station::getQuantity() const
	{
		return m_quantity;
	}
	void Station::updateQuantity()
	{
		if (m_quantity > 0)
		{
			m_quantity--;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
	}
}