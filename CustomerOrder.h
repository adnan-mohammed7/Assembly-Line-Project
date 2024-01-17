/*
Name: Adnan Mohammed
Email: mohammedadnanaz7@gmail.com
*/
#pragma once
#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H

#include <string>
#include"Station.h"

namespace sdds
{
	class CustomerOrder {
		//Item definition
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		//Resource(list of items)
		Item** m_lstItem{};
		//class variable
		static size_t m_widthField;
	public:
		//Constructors
		CustomerOrder();
		CustomerOrder(const std::string& record);

		//Copy Semantics
		CustomerOrder(const CustomerOrder& rhs);
		CustomerOrder& operator=(const CustomerOrder& rhs) = delete;

		//Move Semantics
		CustomerOrder(CustomerOrder&& rhs) noexcept;
		CustomerOrder& operator=(CustomerOrder&& rhs) noexcept;

		//Destructor
		~CustomerOrder();

		//Instance Functions
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}

#endif // !SDDS_CUSTOMER_ORDER_H
