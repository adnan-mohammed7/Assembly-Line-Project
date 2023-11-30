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
	/*To store the orders in different category*/
	std::deque<CustomerOrder>g_pending{};
	std::deque<CustomerOrder>g_completed{};
	std::deque<CustomerOrder>g_incomplete{};

	/*default constructor*/
	Workstation::Workstation(){}

	/*One-Argument constructor Initializes the Workstation object
	Parameters: const string& station*/
	Workstation::Workstation(const std::string& station) : Station(station){}
	void Workstation::fill(std::ostream& os)
	{
		if (m_orders.size() > 0)
		{
			m_orders.front().fillItem(*this, os);
		}
	}

	/*Move the order from current workstation to next station 
	in line, returns true if order is moved*/
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

	/*Updates the next station ptr in current workstation*/
	void Workstation::setNextStation(Workstation* station)
	{
		if (station != nullptr)
		{
			m_pNextStation = station;
			station = nullptr;
		}
	}

	/*Returns a ptr to next workstation in current object*/
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	/*Displays a single workstation object
	Parameters: ostream& os*/
	void Workstation::display(std::ostream& os) const
	{
		os << this->getItemName() << " --> ";
		os << (m_pNextStation != nullptr ? m_pNextStation->getItemName() : "End of Line");
		os << "\n";
	}

	/*Adds a order to the current object and returns reference current object
	Parameters: Customer&& order*/
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}