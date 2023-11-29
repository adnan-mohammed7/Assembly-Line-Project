// Name: Adnan Mohammed
// Seneca Student ID: 174731216
// Seneca email: amohammed109@myseneca.ca
// Date of completion: 29th November, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include"Workstation.h"

namespace sdds
{
	std::deque<CustomerOrder>g_pending{};
	std::deque<CustomerOrder>g_completed{};
	std::deque<CustomerOrder>g_incomplete{};

	Workstation::Workstation(){}
	Workstation::Workstation(const std::string& station) : Station(station){}
	void Workstation::fill(std::ostream& os)
	{
		if (m_orders.size() > 0)
		{
			m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder()
	{
		bool moved{};
		if (m_orders.size() > 0)
		{
			if (m_orders.front().isItemFilled(this->getItemName()) || (this->getQuantity()) < 1)
			{
				moved = true;
				if (m_pNextStation != nullptr)
				{
					*m_pNextStation += std::move(m_orders.front());
				}
				else {
					if (m_orders.front().isOrderFilled())
					{
						g_completed.push_back(std::move(m_orders.front()));
					}
					else
					{
						g_incomplete.push_back(std::move(m_orders.front()));
					}
				}
				m_orders.pop_front();
			}
		}
		return moved;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		if (station != nullptr)
		{
			m_pNextStation = station;
			station = nullptr;
		}
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		os << this->getItemName() << " --> ";
		if (m_pNextStation != nullptr)
		{

		}
		os << (m_pNextStation != nullptr ? m_pNextStation->getItemName() : "End of Line");
		os << "\n";
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}