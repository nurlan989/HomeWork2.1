#include <iostream>
#include <bitset>

#include "OperationWithBits.h"

#define PRINT(x) std::cout << (x) << std::endl

void PrintWithBit_32_t(int value)
{
	std::bitset<32>bits(value);
	PRINT(bits);
}

void PrintWithBit_8_t(int value)
{
	std::bitset<8>bits(value);
	PRINT(bits);
}


void GlueBits()
{
	std::cout << "Operation glue bits " << std::endl;

	while (true)
	{  
		std::cout << "Enter any number, please :";
		int number{ };
		std::cin >> number;
		
		std::cout << "Your number in bits :";
		PrintWithBit_32_t(number);

		std::cout << "Which bit to glue :";
		int i{ };
		std::cin >> i;
		
		int mask{ 0 };
		int mask_2{ 0 };
		
		for (int currentIndex = 0; currentIndex < i; ++currentIndex)
		{
			int nextBit{ 1 };
			nextBit = nextBit << currentIndex;
			mask |= nextBit;	
		}
		
		int shiftNumbers = number & mask;
		shiftNumbers <<= 1;
		
		mask_2 = ~ mask;
		int dontShiftNumbers = mask_2 & number;
		
		number = shiftNumbers | dontShiftNumbers;
		
		std::cout << "Your number in bits after glue :";
		PrintWithBit_32_t(number);
		
		std::cout << "Your number after glue :";
		PRINT(number);
		
		system("pause");
		system("cls");

	}
}


void OlderBitFromInt()
{
	std::cout << "Enter any number, please :";
	unsigned int number{ };
	std::cin >> number;
	
	std::cout << "Your number in bits :";
	PrintWithBit_32_t(number);

	unsigned int mask{ };
	mask = 1 << 31;
	
	while (number < mask)
	{
		mask >>= 1;
	}
	
	std::cout << "Older bit in your number :";
	PrintWithBit_32_t(mask);
}

void ClearBitFromNumber()
{
	std::cout << "Enter any number, please :";
	int mask{ 0b00000001 };
	int num{}, i{ };
	std::cin >> num;
	std::cout << "Your number in bits :";
	PrintWithBit_32_t(num);
	std::cout << "Which bit to clear :";
	std::cin >> i;
	mask <<= i;
	mask = ~mask;
	num &= mask;
	std::cout << "Your number in bits after clear :";
	PrintWithBit_32_t(num);
	std::cout << "Your number after clear :";
	std::cout << num << std::endl;
}

void SnakeBits()
{
	while (true)
	{
	
		int number{ }, shiftToLeft{ };
		std::cout << "Enter a number from 0 to 255 :";
		std::cin >> number;
		PrintWithBit_8_t(number);
		std::cout << "How much shift to left :";
		std::cin >> shiftToLeft;
		number = (number << shiftToLeft) | (number >> (8 - shiftToLeft));
		std::cout << "Your namber in bits after shift :";
		PrintWithBit_8_t(number);
		std::cout << "Your number after shift :";
		PRINT(int(int8_t(number)));
	}
}

void CountNumberTwo()
{
	std::cout << "Press any number, please :";
	int value{ };
	std::cin >> value;
	int result{ };
	int mask1{ };
	int mask2{ 0b01 };
	int mask3{ 0b11 };
	PrintWithBit_32_t(value);

	while (value > 0)
	{
		mask1 = 0b11 & value;
		int count = mask2 ^ mask1;
		result += count == mask3;
		value >>= 1;
	}

	std::cout <<"Quantity of \"10\" in bits = " << result << std::endl;

}

void CountNumberNull()
{
	std::cout << "Press any number, please :";
	int value{ };
	std::cin >> value;
	int result{ };
	int mask1{  };
	int mask2{ 0b11 };
	int mask3{ 0b11 };
	PrintWithBit_32_t(value);

	while (value > 0)
	{
		int invertValue = ~ value;
		mask1 = mask2 & invertValue;
		result += mask1 == mask3;
		value >>= 1;
	}

	std::cout <<"Quantity of \"00\" in bits = " << result << std::endl;

}



