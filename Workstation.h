/*
Name: Adnan Mohammed
Email: mohammedadnanaz7@gmail.com
*/

#pragma once
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"

namespace sdds
{
	/*Store the customer order in different category*/
	extern std::deque<CustomerOrder>g_pending;
	extern std::deque<CustomerOrder>g_completed;
	extern std::deque<CustomerOrder>g_incomplete;

	class Workstation : public Station {
		std::deque<CustomerOrder>m_orders;
		Workstation* m_pNextStation{};
	public:
		Workstation();
		Workstation(const std::string& station);

		//Deleted Functions
		Workstation(const Workstation& rhs) = delete;
		Workstation& operator=(const Workstation& rhs) = delete;
		Workstation(Workstation&& rhs) = delete;
		Workstation& operator=(Workstation&& rhs) = delete;

		//Instance Functions
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif // !SDDS_WORKSTATION_H
