// Name: Adnan Mohammed
// Seneca Student ID: 174731216
// Seneca email: amohammed109@myseneca.ca
// Date of completion: 10th November, 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <fstream>
#include "Utilities.h"
#include "CustomerOrder.h"

size_t sdds::CustomerOrder::m_widthField = 0;

namespace sdds
{
	CustomerOrder::CustomerOrder() {}

	/*One-argument constructor
	Parameters const string& record*/
	CustomerOrder::CustomerOrder(const std::string& record) {
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

		//Dynamic allocation based on number of items in string
		m_lstItem = new Item*[m_cntItem];
		m_name = util.extractToken(record, pos, more);
		m_product = util.extractToken(record, pos, more);
		for (size_t i = 0u; i < m_cntItem; i++)
		{
			//Adding item to list of items
			Item* copy = new Item(util.extractToken(record, pos, more));
			m_lstItem[i] = copy;
		}
		m_widthField > util.getFieldWidth() ? m_widthField : m_widthField = util.getFieldWidth();
	}

	/*Copy Constructor
	Parameters: const CustomerOrder& rhs*/
	CustomerOrder::CustomerOrder(const CustomerOrder& rhs) {
		throw "Error";
	}

	/*Move Constructor
	Parameters: CustomOrder&& rhs*/
	CustomerOrder::CustomerOrder(CustomerOrder&& rhs) noexcept {
		*this = std::move(rhs);
	}

	/*Move assignment oprrator
	Parameters: CustomerOrder&& rhs*/
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& rhs) noexcept {
		if (this != &rhs)
		{
			for (size_t i=0u; i<m_cntItem; i++)
			{
				//Deallocating each item
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}
			//Deallocating pointer
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

	/*Destructor*/
	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0u; i < m_cntItem; i++)
		{
			//Deallocating each item in the list
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}
		//Deallocating item ptr
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	/*Returns true if all the items in the order ar filled else false*/
	bool CustomerOrder::isOrderFilled() const {
		bool result{true};
		for (size_t i=0u; i<m_cntItem; i++)
		{
			if (!(m_lstItem[i]->m_isFilled)) {
				result = false;
			}
		}
		return result;
	}

	/*Returns true if item received in argument is filled in current order else false
	Parameters: const string& itemName*/
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool result{true};
		for (size_t i=0u; i<m_cntItem && !result; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				result = (m_lstItem[i]->m_isFilled);
			}
		}
		return result;
	}

	/*Fills an item in CustomerOrder if the station manages item requested in order and have it in stock
	Parameters: Station& station
	std::ostream& os*/
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		bool matched{};
		for (size_t i = 0u; i < m_cntItem && !matched; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName())
			{
				matched = true;
				if (station.getQuantity() > 0)
				{
					station.updateQuantity();
					m_lstItem[i]->m_isFilled = true;
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}

	/*Displays CustomerOrder object to ostream
	Parameters: std::ostream& os*/
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl;
		for (auto i=0u; i<m_cntItem; i++)
		{
			os << "[";
			//os.width(6);
			os <<std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			//os.width(m_widthField);
			os << std::setfill(' ');
			os << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
			m_lstItem[i]->m_isFilled ? os << "FILLED" : os << "TO BE FILLED" << std::endl;
		}
	}
}