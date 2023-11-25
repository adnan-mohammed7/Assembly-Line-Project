#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <memory>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& stations)
	{
		ifstream file(filename);
		if(file)
		{
			Utilities util;
			util.setDelimiter('|');
			size_t pos{};
			bool more{ true };
			string line{};

			while (file)
			{
				if (file.peek() != EOF)
				{
					more = true;
					pos = 0;
					getline(file, line);

					Workstation* newStation = new Workstation(util.extractToken(line, pos, more));
					if (more)
					{
						newStation->setNextStation(new Workstation(util.extractToken(line, pos, more)));
					}
					m_activeLine.push_back(move(newStation));
				}
				else
				{
					file.get();
				}
			}
			for_each(m_activeLine.begin(), m_activeLine.end(), [=](Workstation* set) {
				bool matched{};

				/*for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* subSet) {
					if (set != nullptr && subSet->getNextStation() != nullptr)
					{
						string a1 = set->getItemName();
						string a2 = (subSet->getNextStation()->getItemName());
						if (a1 == a2) {
							matched = true;
						}
					}
					});*/
				matched = any_of(m_activeLine.begin(), m_activeLine.end(), [=](Workstation* subSet) {
					bool result{};
					if (set != nullptr && subSet->getNextStation() != nullptr) {
						result = (set->getItemName() == ((subSet->getNextStation())->getItemName()));
					}
					return result;
					});
				if (!matched)
				{
					m_firstStation = set;
				}
				});
			m_cntCustomerOrder = g_pending.size();
		}
		else {
			throw "Error";
		}
		
	}
	void LineManager::reorderStations()
	{
		Workstation* temp{};
		if (m_activeLine[0] != m_firstStation) {
			temp = m_activeLine[0];

			bool swapped{};
			for (auto it=m_activeLine.begin(); it != m_activeLine.end() && !swapped; it++)
			{
				if (*it == m_firstStation)
				{
					*it = temp;
					swapped = true;
				}
			}
			m_activeLine[0] = m_firstStation;
		}
		for (auto it = m_activeLine.begin(); it != m_activeLine.end(); it++)
		{
			temp = nullptr;
			if ((*it)->getNextStation() != nullptr)
			{
				if (((*it)->getNextStation())->getItemName() != it[1]->getItemName())
				{
					temp = (it[1]);
					bool swapped{};
					for (auto j = m_activeLine.begin(); j != m_activeLine.end() && !swapped; j++ )
					{
						if (((*it)->getNextStation())->getItemName() == (*j)->getItemName())
						{
							/*it[1] = *j;
							(*j) = temp;*/
							it[1] = j[0];
							j[0] = temp;
							swapped = true;
						}
					}
				}
			}
		}
		vector<Workstation> sizeaa();
	}
	bool LineManager::run(std::ostream& os)
	{
		static int iterationCount{};
		bool filled{};
		os << "Line Manager Iteration: " << ++iterationCount << endl;
		*m_activeLine[0] += std::move(g_pending[0]);
		for (auto it = m_activeLine.begin(); it != m_activeLine.end(); it++)
		{
			(*it)->fill(os);
			filled = (*it)->attemptToMoveOrder();
			
		}
		return filled;
	}
	void LineManager::display(std::ostream& os) const
	{
		for (auto it=m_activeLine.begin(); it!=m_activeLine.end(); it++)
		{
			(*it)->display(os);
		}
	}
}