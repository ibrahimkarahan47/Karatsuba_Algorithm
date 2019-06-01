#include <iostream>
#include <string>
#include <cmath>
#include<time.h>
using namespace std;

string additionOp(string adder1, string adder2){ // handling addition operation of two number 
	int carry = 0;
	string additionResult = "0";
	if (adder1.size() > adder2.size()){ // control the size of numbers and make equal size 
		int gap = adder1.size() - adder2.size();
		for (int i = 0; i < gap; i++)
		{
			adder2 = '0' + adder2;
		}
	}
	else if (adder1.size() < adder2.size()){ // control the size of numbers and make equal size 
		int gap = adder2.size() - adder1.size();
		for (int i = 0; i < gap; i++)
		{
			adder1 ='0' + adder1;
		}
	}
	int size = adder1.size();
	for (int i = 0; i < size-1; i++) // creating result value for keeping 
	{
		additionResult = additionResult + '0';
	}
	for (int i = size; i >=0; i--) // handle each element bit by bit 
	{
		if (adder1[i] == '0' && adder2[i] == '0' && carry == 0){ // control the all posibilities
			additionResult[i] = '0';
			carry = 0;
		}
		else if (adder1[i] == '1' && adder2[i] == '0' && carry == 0){
			additionResult[i] = '1';
			carry = 0;
		}
		else if (adder1[i] == '0' && adder2[i] == '1' && carry == 0){
			additionResult[i] = '1';
			carry = 0;
		}
		else if (adder1[i] == '1' && adder2[i] == '1' && carry == 0){
			additionResult[i] = '0';
			carry = 1;
		}
		else if (adder1[i] == '1' && adder2[i] == '1' && carry == 1){
			additionResult[i] = '1';
			carry = 1;
		}
		else if (adder1[i] == '0' && adder2[i] == '0' && carry == 1){
			additionResult[i] = '1';
			carry = 0;
		}
		else if (adder1[i] == '0' && adder2[i] == '1' && carry == 1){
			additionResult[i] = '0';
			carry = 1;
		}
		else if (adder1[i] == '1' && adder2[i] == '0' && carry == 1){
			additionResult[i] = '0';
			carry = 1;
		}
	}
	if (carry == 1){
		additionResult = '1' + additionResult;
	}
	return additionResult;
}

long int convertDecimal(string result){ // converting the string to decimal number 
	long int convertResult = 0;
	int value = 0;
	int k = 0;
	int size = result.size();
	for (int i = size-1; i >=0; i--) // handle each number bit by bit
	{
		if (result[i] == '1'){
			value = 1;
		}
		else if (result[i] == '0'){
			value = 0;
		}
		convertResult = convertResult + (value * pow(2, k));
		k++;
	}
	return convertResult;
}

long int casualMultiply(string nm1, string nm2){ // casual method for multiplication 
	long int result;
	string temp_result="0";
	string firstShift = "0";
	string seconShift = "0";
	string temp_nm;
	if (nm1.size() > nm2.size()){ // control size of numbers and make equal size 
		int gap = nm1.size() - nm2.size();
		for (int i = 0; i < gap; i++)
		{
			nm2 = '0' + nm2;
		}
	}
	else if (nm1.size() < nm2.size()){ // control size of numbers and make equal size 
		int gap = nm2.size() - nm1.size();
		for (int i = 0; i < gap; i++)
		{
			nm1 = '0' + nm1;
		}
	}
	int size = nm1.size(); // size zero means zero 
	if (size == 0){
		return 0;
	}
	if (size == 1){ // size 1 equal to first bit multiplication 
		result = nm1[0] * nm2[0];
		return result * 1;
	}
	for (int i = 0; i < size; i++) // creating temp_result value for keeping the result 
	{
		temp_result = temp_result + '0';
	}
	size = nm1.size() - 1;
	firstShift = temp_result;
	seconShift = temp_result;
	for (int i = size; i >=0; i--) // handle each element of number2
	{
		if (nm2[i] == '0' && i==size){ // control all posibilities 
			for (int i = 0; i < size; i++)
			{
				firstShift = firstShift + '0';
			}
			temp_result = additionOp(temp_result, firstShift);
		}
		else if (nm2[i] == '1' && i == size){
			firstShift = nm1;
			temp_result = additionOp(temp_result, firstShift);
		}
		else if (nm2[i] == '0'){
			for (int j = 0; j < size-i; j++)
			{
				seconShift = seconShift + '0';
			}
			temp_result = additionOp(temp_result, seconShift);
		}
		else if (nm2[i] == '1'){
			temp_nm = nm1;
			for (int k = 0; k < size-i; k++)
			{
				temp_nm = temp_nm + '0';
			}
			temp_result = additionOp(temp_result, temp_nm);
			temp_nm = nm1;
		}
	}
	result = convertDecimal(temp_result);
	return result;
}

long int multiply(string nm1, string nm2){ // given algorithm for binary multiplication 
	if (nm1.size() == 0 || nm2.size() == 0){ // size equal to means zero 
		return 0;
	}
	if (nm1.size() == 1 && nm2.size() == 1){ // size equal to 1 means multiplication of fisrt bit of numbers 
		return (nm1[0] - '0')*(nm2[0] - '0');
	}
	if (nm1.size() > nm2.size()){ // control the size of numbers and make equal 
		int gap = nm1.size() - nm2.size();
		for (int i = 0; i < gap; i++)
		{
			nm2 = '0' + nm2;
		}
	}
	if (nm1.size() < nm2.size()){ // control the size of numbers and make equal 
		int gap = nm2.size() - nm1.size();
		for (int i = 0; i < gap; i++)
		{
			nm1 = '0' + nm1;
		}
	}
	int numberSize = nm1.size();
	int firstPartOfnm = numberSize / 2; // finding the mind point 
	int secondPartOfnm = numberSize - firstPartOfnm; // finding the mind point 

	string leftPartOfnm1 = nm1.substr(0, firstPartOfnm); // sperarte number 
	string rightPartOfnm1 = nm1.substr(firstPartOfnm, secondPartOfnm);

	string leftPartOfnm2 = nm2.substr(0, firstPartOfnm); // sperarte number 
	string rightPartOfnm2 = nm2.substr(firstPartOfnm, secondPartOfnm);

	long int P1 = multiply(leftPartOfnm1, leftPartOfnm2); // recursive call
	long int P2 = multiply(rightPartOfnm1, rightPartOfnm2);
	long int P3 = multiply(additionOp(rightPartOfnm1, leftPartOfnm1), additionOp(rightPartOfnm2, leftPartOfnm2));

	return P1*(1 << (numberSize)) + (P3 - P1 - P2)*(1 << secondPartOfnm) + P2; // convert to binary 
}

int main()
{
	clock_t start_casualTwo, end_casualTwo, start_givenAlgorithmTwo, end_givenAlgorithmTwo; // for 2 Bit number time calculation 
	clock_t start_casualFour, end_casualFour, start_givenAlgorithmFour, end_givenAlgorithmFour; // for 4 Bit number time calculation 
	clock_t start_casualEight, end_casualEight, start_givenAlgorithmEight, end_givenAlgorithmEight; // for 8 Bit number time calculation 
	clock_t start_casualSixteen, end_casualSixteen, start_givenAlgorithmSixteen, end_givenAlgorithmSixteen; // for 16 Bit number time calculation 
	clock_t start_casualThirtyTwo, end_casualThirtyTwo, start_givenAlgorithmThirtyTwo, end_givenAlgorithmThirtyTwo; // for 32 Bit number time calculation 
	clock_t start_casualSixtyFour, end_casualSixtyFour, start_givenAlgorithmSixtyFour, end_givenAlgorithmSixtyFour; // for 64 Bit number time calculation 

	double total_casualTwo, total_givenAlgorithmTwo; // total amount of time 
	double total_casualFour, total_givenAlgorithmFour;
	double total_casualEight, total_givenAlgorithmEight;
	double total_casualSixteen, total_givenAlgorithmSixteen;
	double total_casualThirtyTwo, total_givenAlgorithmThirtyTwo;
	double total_casualSixtyFour, total_givenAlgorithmSixtyFour;

	string twoBit_number1 = "01";
	string twoBit_number2 = "10";

	string fourBit_number1 = "0100";
	string fourBit_number2 = "1010";

	string eightBit_number1 = "01010101";
	string eightBit_number2 = "10000000";

	string sixteenBit_number1 = "0110100000000000";
	string sixteenBit_number2 = "1000000000000011";

	string thirtyTwoBit_number1 = "01101011100000000000000000000000";
	string thirtyTwoBit_number2 = "10000000000000110000000000000000";

	string sixtyFourBit_number1 = "0111111111100000000000000000000011111000000000000000000000010000";
	string sixtyFourBit_number2 = "1000000000000000000000000000000000000011101010000000000000000000";

	start_casualTwo = clock();  // for 2 Bit number operation 
	cout << "Result Of 2 Bit Number Casual Multiplication:"<<casualMultiply(twoBit_number1, twoBit_number2) << endl;
	end_casualTwo = clock();
	total_casualTwo = (double)(end_casualTwo - start_casualTwo) / CLOCKS_PER_SEC;
	cout << "Total Time For 2 Bit Number Casual Multiplication:" << total_casualTwo << endl;
	cout << endl;
	start_givenAlgorithmTwo = clock();
	cout << "Result Of 2 Bit Number Given Algorithm Multiplication:" << multiply(twoBit_number1, twoBit_number2) << endl;
	end_givenAlgorithmTwo = clock();
	total_givenAlgorithmTwo = (double)(end_givenAlgorithmTwo - start_givenAlgorithmTwo) / CLOCKS_PER_SEC;
	cout << "Total Time For 2 Bit Number Casual Multiplication:" << total_givenAlgorithmTwo << endl;
	cout << endl;

	start_casualFour = clock(); // for 4 Bit number operation 
	cout << "Result Of 4 Bit Number Casual Multiplication:" << casualMultiply(fourBit_number1, fourBit_number2) << endl;
	end_casualFour = clock();
	total_casualFour = (double)(end_casualFour - start_casualFour) / CLOCKS_PER_SEC;
	cout << "Total Time For 4 Bit Number Casual Multiplication:" << total_casualFour << endl;
	cout << endl;
	start_givenAlgorithmFour = clock();
	cout << "Result Of 4 Bit Number Given Algorithm Multiplication:" << multiply(fourBit_number1, fourBit_number2) << endl;
	end_givenAlgorithmFour = clock();
	total_givenAlgorithmFour = (double)(end_givenAlgorithmFour - start_givenAlgorithmFour) / CLOCKS_PER_SEC;
	cout << "Total Time For 4 Bit Number Casual Multiplication:" << total_givenAlgorithmFour << endl;
	cout << endl;

	start_casualEight = clock(); // for 8 Bit number operation 
	cout << "Result Of 8 Bit Number Casual Multiplication:" << casualMultiply(eightBit_number1, eightBit_number2) << endl;
	end_casualEight = clock();
	total_casualEight = (double)(end_casualEight - start_casualEight) / CLOCKS_PER_SEC;
	cout << "Total Time For 8 Bit Number Casual Multiplication:" << total_casualEight << endl;
	cout << endl;
	start_givenAlgorithmEight = clock();
	cout << "Result Of 8 Bit Number Given Algorithm Multiplication:" << multiply(eightBit_number1, eightBit_number2) << endl;
	end_givenAlgorithmEight = clock();
	total_givenAlgorithmEight = (double)(end_givenAlgorithmEight - start_givenAlgorithmEight) / CLOCKS_PER_SEC;
	cout << "Total Time For 8 Bit Number Casual Multiplication:" << total_givenAlgorithmEight << endl;
	cout << endl;

	start_casualSixteen = clock(); // for 16 Bit number operation 
	cout << "Result Of 16 Bit Number Casual Multiplication:" << casualMultiply(eightBit_number1, eightBit_number2) << endl;
	end_casualSixteen = clock();
	total_casualSixteen = (double)(end_casualSixteen - start_casualSixteen) / CLOCKS_PER_SEC;
	cout << "Total Time For 16 Bit Number Casual Multiplication:" << total_casualSixteen << endl;
	cout << endl;
	start_givenAlgorithmSixteen = clock();
	cout << "Result Of 16 Bit Number Given Algorithm Multiplication:" << multiply(eightBit_number1, eightBit_number2) << endl;
	end_givenAlgorithmSixteen = clock();
	total_givenAlgorithmSixteen = (double)(end_givenAlgorithmSixteen - start_givenAlgorithmSixteen) / CLOCKS_PER_SEC;
	cout << "Total Time For 16 Bit Number Casual Multiplication:" << total_givenAlgorithmSixteen << endl;
	cout << endl;

	start_casualThirtyTwo = clock(); // for 32 Bit number operation 
	cout << "Result Of 32 Bit Number Casual Multiplication:" << casualMultiply(thirtyTwoBit_number1, thirtyTwoBit_number2) << endl;
	end_casualThirtyTwo = clock();
	total_casualThirtyTwo = (double)(end_casualThirtyTwo - start_casualThirtyTwo) / CLOCKS_PER_SEC;
	cout << "Total Time For 32 Bit Number Casual Multiplication:" << total_casualThirtyTwo << endl;
	cout << endl;
	start_givenAlgorithmThirtyTwo = clock();
	cout << "Result Of 32 Bit Number Given Algorithm Multiplication:" << multiply(thirtyTwoBit_number1, thirtyTwoBit_number2) << endl;
	end_givenAlgorithmThirtyTwo = clock();
	total_givenAlgorithmThirtyTwo = (double)(end_givenAlgorithmThirtyTwo - start_givenAlgorithmThirtyTwo) / CLOCKS_PER_SEC;
	cout << "Total Time For 32 Bit Number Casual Multiplication:" << total_givenAlgorithmThirtyTwo << endl;
	cout << endl;

	start_casualSixtyFour = clock(); // for 64 Bit number operation 
	cout << "Result Of 64 Bit Number Casual Multiplication:" << casualMultiply(sixtyFourBit_number1, sixtyFourBit_number2) << endl;
	end_casualSixtyFour = clock();
	total_casualSixtyFour = (double)(end_casualSixtyFour - start_casualSixtyFour) / CLOCKS_PER_SEC;
	cout << "Total Time For 64 Bit Number Casual Multiplication:" << total_casualSixtyFour << endl;
	cout << endl;
	start_givenAlgorithmSixtyFour = clock();
	cout << "Result Of 64 Bit Number Given Algorithm Multiplication:" << multiply(sixtyFourBit_number1, sixtyFourBit_number2) << endl;
	end_givenAlgorithmSixtyFour = clock();
	total_givenAlgorithmSixtyFour = (double)(end_givenAlgorithmSixtyFour - start_givenAlgorithmSixtyFour) / CLOCKS_PER_SEC;
	cout << "Total Time For 64 Bit Number Casual Multiplication:" << total_givenAlgorithmSixtyFour << endl;
	cout << endl;

	return 0;
 }
