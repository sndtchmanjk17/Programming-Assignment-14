// Programming Assignment 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Start
// Display “ Enter the following information for the company : ”
// For North Division :
// Display “North Division : ”
// Display “Quarter 1 : $ ”
// Read northquarter1
// Display “Quarter 2 : $ ”
// Read northquarter2
// Display “Quarter 3 : $ ”
// Read northquarter3
// Display “Quarter 4 : $ ”
// Read northquarter4
// North Total = northquarter1 + northquarter2 + northquarter3 + northquarter4
// Read northtotal
// North Average = northtotal / 4
// Read northaverage
// Lowest = northquarter1 < northquarter2 < northquarter3 < northquarter4
// Read northlowest
// Highest = northquarter1 > northquarter2 > northquarter3 > northquarter4
// Read northhighest
// For South Division
// Display “South Division : ”
// Display “Quarter 1 : $ ”
// Read southquarter1
// Display “Quarter 2 : $ ”
// Read southquarter2
// Display “Quarter 3 : $ ”
// Read southquarter3
// Display “Quarter 4 : $ ”
// Read southquarter4
// South Total = southquarter1 + southquarter2 + southquarter3 + southquarter4
// Read southtotal
// South Average = southtotal / 4
// Read southaverage
// Lowest = southquarter1 < southquarter2 < southquarter3 < southquarter4
// Read southlowest
// Highest = southquarter1 > southquarter2 > southquarter3 > southquarter4
// Read southhighest
// For East Division
// Display “East Division : “
// Display “Quarter 1 : $ “
// Read eastquarter1
// Display “Quarter 2 : $ “
// Read eastquarter2
// Display “Quarter 3 : $ “
// Read eastquarter3
// Display “Quarter 4 : $ ”
// Read eastquarter4
// East Total = eastquarter1 + eastquarter2 + eastquarter3 + eastquarter4
// Read easttotal
// East Average = easttotal / 4
// Read eastaverage
// Lowest = eastquarter1 < eastquarter2 < eastquarter3 < eastquarter4
// Read eastlowest
// Highest = eastquarter1 > eastquarter2 > eastquarter3 > eastquarter4
// Read easthighest
// For West Division
// Display “West Division : “
// Display “Quarter 1 : $ “
// Read westquarter1
// Display “Quarter 2 : $ “
// Read westquarter2
// Display “Quarter 3 : $ “
// Read westquarter3
// Display “Quarter 4 : $ ”
// Read westquarter4
// West Total = westquarter1 + westquarter2 + westquarter3 + westquarter4
// Read westtotal
// West Average = westtotal / 4
// Read westaverage
// Lowest = westquarter1 < westquarter2 < westquarter3 < westquarter4
// Read westlowest
// Highest = westquarter1 > westquarter2 > westquarter3 > westquarter4
// Read westhighest
// Quarter Total = northquarter1 + southquarter1 + eastquarter1 + westquarter1
// Read quarter1total
// Quarter Total = northquarter2 + southquarter2 + eastquarter2 + westquarter2
// Read quarter2total
// Quarter Total = northquarter3 + southquarter3 + eastquarter3 + westquarter3
// Read quarter3total
// Quarter Total = northquarter4 + southquarter4 + eastquarter4 + westquarter4
// Read quarter4total
// Grand Total = quarter1total + quarter2total + quarter3total + quarter4total
// Read grandtotal
// Create table as follows :
// Column[0][0] : blank
// Column[0][1] : “North”
// Column[0][2] : “South”
// Column[0][3] : “East”
// Column[0][4] : “West”
// Column[0][5] : “Quarter Total”
// Column[1][0] : “Quarter 1”
// Column[1][1] : northquarter1
// Column[1][2] : southquarter1
// Column[1][3] : eastquarter1
// Column[1][4] : westquarter1
// Column[1][5] : quarter1total
// Column[2][0] : “Quarter 2 ”
// Column[2][1] : northquarter2
// Column[2][2] : southquarter2
// Column[2][3] : eastquarter2
// Column[2][4] : westquarter2
// Column[2][5] : quarter2total
// Column[3][0] : “Quarter 3 ”
// Column[3][1] : northquarter3
// Column[3][2] : southquarter3
// Column[3][3] : eastquarter3
// Column[3][4] : westquarter3
// Column[3][5] : quarter3total
// Column[4][0] : “Quarter 4 ”
// Column[4][1] : northquarter4
// Column[4][2] : southquarter4
// Column[4][3] : eastquarter4
// Column[4][4] : westquarter4
// Column[4][5] : quarter4total
// Column[5][0] : “Division Total ”
// Column[5][1] : northtotal
// Column[5][2] : southtotal
// Column[5][3] : easttotal
// Column[5][4] : westtotal
// Column[5][5] : grandtotal


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


const int ROWS = 5;
const int COLS = 5;
double total = 0;
double average;
double lowest;
double highest;
double sales[ROWS][COLS];


double getTotal(double[][COLS]);
double getAverage(double[][COLS]);
double getRowTotal(double[][COLS], int);
double getColumnTotal(double[][COLS], int);
double getHighest(double[][COLS], int& row, int& col);
double getLowest(double[][COLS], int& row, int& col);

int main()
{

	string div[] = { "North", "South", "East", "West", "Quarter Total" };

	// get the sales info
	double sales[ROWS][COLS];
	cout << "Sales data for the North division: $\n";
	cin >> sales[0][0] >> sales[0][1] >> sales[0][2] >> sales[0][3];
	cout << "Sales data for the South division: $\n";
	cin >> sales[1][0] >> sales[1][1] >> sales[1][2] >> sales[1][3];
	cout << "Sales data for the East Division: $\n";
	cin >> sales[2][0] >> sales[2][1] >> sales[2][2] >> sales[2][3];
	cout << "Sales data for the West Division: $\n";
	cin >> sales[3][0] >> sales[3][1] >> sales[3][2] >> sales[3][3];
	cout << endl;

	double columnTotal[5];
	double rowTotal[5];

	//double sale;
	//double average;
	//double highest;
	//double lowest;

	average = getAverage(sales);
	highest = getHighest(sales, ROWS, COLS); 
	lowest = getLowest(sales, 4, 4);

	cout << setw(15) << " " << setw(15) << "Quarter 1" << setw(15) << "Quarter 2" << setw(15) << "Quarter 3" << setw(15) << "Quarter 4" << endl;
	cout << setw(15) << div[0] << setw(15) << sales[0][0] << setw(15) << sales[0][1] << setw(15) << sales[0][2] << setw(15) << sales[0][3] << setw(15) << rowTotal[0] << endl;
	cout << setw(15) << div[1] << setw(15) << sales[1][0] << setw(15) << sales[1][1] << setw(15) << sales[1][2] << setw(15) << sales[1][3] << setw(15) << rowTotal[1] << endl;
	cout << setw(15) << div[2] << setw(15) << sales[2][0] << setw(15) << sales[2][1] << setw(15) << sales[2][2] << setw(15) << sales[2][3] << setw(15) << rowTotal[2] << endl;
	cout << setw(15) << div[3] << setw(15) << sales[3][0] << setw(15) << sales[3][1] << setw(15) << sales[3][2] << setw(15) << sales[3][3] << setw(15) << rowTotal[3] << endl;
	cout << setw(15) << columnTotal[4] << setw(15) << columnTotal[4] << setw(15) << columnTotal[4] << setw(15) << columnTotal[4] << setw(15) << rowTotal[4] << endl;
	cout << endl;
	cout << endl;
	cout << "The average sales are: " << fixed << showpoint << setprecision(2) << average << endl;
	cout << "The highest sales are: " << highest << endl;
	cout << "The lowest sales are: " << lowest << endl;


	system("Pause");
	return 0;
}






double getTotal(double numbers[][COLS])
{
	double total = 0;
	for (int i = 0; i < 4; i++)
	{
		total += numbers[ROWS][COLS];
	}

	total += numbers[4][4];
	return total;
}



double getAverage(double numbers[][COLS])
{
	return total / 16;
}


double getRowTotal(double numbers[][COLS], int row)
{
	double rowTotal = 0;

	for (int i = 0; i < COLS; i++)
	{
		rowTotal += numbers[row][i];
	}

	return rowTotal;
}

double getColumnTotal(double numbers[][COLS], int col)
{

	double columnTotal = 0;

	for (int i = 0; i < ROWS; i++)
	{
		columnTotal += numbers[i][COLS];
	}

	return columnTotal;
}


double getHighest(double numbers[][COLS], int& row, int& col)
{
	int highest = numbers[0][0];

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; i < COLS; i++)
		{
			if (numbers[i][j] > highest)
				highest = numbers[i][j];
		}
	}

	return highest;
}

double getLowest(double numbers[][COLS], int& row, int& col)
{


	int lowest = numbers[0][0];

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; i < COLS; i++)
		{
			if (numbers[i][j] < lowest)
				lowest = numbers[i][j];
		}
	}

	return lowest;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file