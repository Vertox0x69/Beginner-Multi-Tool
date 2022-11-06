#pragma once
#include "Includes.h"
std::string nullvalue;

class CalculatorM
{
public:
	struct CalculateM
	{
		void M()
		{
			int a,b;
			std::cout << "Give Me Two Numbers Nigga: ";
			std::cin >> a;
			std::cout << "* ";
			std::cin >> b;
			std::cout << "Result: " << a * b << std::endl;
		}

		void P()
		{
			int a, b;
			std::cout << "Give Me Two Numbers Nigga: ";
			std::cin >> a;
			std::cout << "+ ";
			std::cin >> b;
			std::cout << "Result: " << a + b << std::endl;
		}

		void Minus()
		{
			int a, b;
			std::cout << "Give Me Two Numbers Nigga: ";
			std::cin >> a;
			std::cout << "- ";
			std::cin >> b;
			std::cout << "Result: " << a - b << std::endl;
		}

		void Devide()
		{
			int a, b;
			std::cout << "Give Me Two Numbers Nigga: ";
			std::cin >> a;
			std::cout << "/ ";
			std::cin >> b;
			std::cout << "Result: " << a / b << std::endl;

		}
	}Calculate;
}Calculator;