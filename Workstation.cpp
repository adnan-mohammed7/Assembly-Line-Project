#define _CRT_SECURE_NO_WARNINGS

#include"Workstation.h"

namespace sdds
{
	std::deque<CustomerOrder>g_pending{};
	std::deque<CustomerOrder>g_completed{};
	std::deque<CustomerOrder>g_incomplete{};

	Workstation::Workstation()
	{
	}
	Workstation::Workstation(const std::string& station)
	{
	}
	void Workstation::fill(std::ostream& os)
	{
	}
	bool Workstation::attemptToMoveOrder()
	{
		return false;
	}
	void Workstation::setNextStation(Workstation* station)
	{
	}
	Workstation* Workstation::getNextStation() const
	{
		return nullptr;
	}
	void Workstation::display(std::ostream& os) const
	{
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		return *this;
	}
}