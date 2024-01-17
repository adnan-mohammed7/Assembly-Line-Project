/*
Name: Adnan Mohammed
Email: mohammedadnanaz7@gmail.com
*/

#pragma once
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds
{
	class Station {
		int m_id{};
		std::string m_name{};
		std::string m_description{};
		size_t m_serialNumber{};
		size_t m_quantity{};

		/*class variables*/
		static size_t m_widthField;
		static size_t id_generator;
	public:
		//Constructor
		Station();
		Station(const std::string& str);

		//Instance functions
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SDDS_UTILITIES_H
