// Name: Adnan Mohammed
// Seneca Student ID: 174731216
// Seneca email: amohammed109@myseneca.ca
// Date of completion: 7th November, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <fstream>
#include "Utilities.h"
#include "CustomerOrder.h"

using namespace std;

size_t sdds::CustomerOrder::m_widthField = 0;

namespace sdds
{
	CustomerOrder::CustomerOrder() {

	}

	CustomerOrder::CustomerOrder(const string& record) {
		Utilities util;

		size_t pos{};
		bool more{ true };
		for (auto i = 0u; i < record.length(); i++)
		{
			if (record[i] == util.getDelimiter())
			{
				m_cntItem++;
			}
		}
		m_cntItem--;
		m_lstItem = new Item*[m_cntItem];
		m_name = util.extractToken(record, pos, more);
		m_product = util.extractToken(record, pos, more);
		for (size_t i = 0u; i < m_cntItem; i++)
		{
			Item* copy = new Item(util.extractToken(record, pos, more));
			m_lstItem[i] = copy;
		}
		m_widthField > util.getFieldWidth() ? m_widthField : m_widthField = util.getFieldWidth();
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& rhs) {
		throw "Error";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& rhs) noexcept {
		*this = move(rhs);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& rhs) noexcept {
		if (this != &rhs)
		{
			delete[] m_lstItem;

			m_name = rhs.m_name;
			m_product = rhs.m_product;
			m_cntItem = rhs.m_cntItem;

			rhs.m_name = "";
			rhs.m_product = "";
			rhs.m_cntItem = 0;

			m_lstItem = rhs.m_lstItem;
			rhs.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0u; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	bool CustomerOrder::isOrderFilled() const {
		return true;
	}

	bool CustomerOrder::isItemFilled(const string& itemName) const {
		return true;
	}

	void CustomerOrder::fillItem(Station& station, ostream& os) {

	}

	void CustomerOrder::display(ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (auto i=0u; i<m_cntItem; i++)
		{
			os << "[";
			//os.width(6);
			os <<setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			//os.width(m_widthField);
			os << setfill(' ');
			os <<setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			m_lstItem[i]->m_isFilled ? os << "FILLED" : os << "TO BE FILLED" << endl;
		}
	}
}