#include <iostream>
#include <climits>
#include <fstream>

using namespace std;

//Variables used in this program
int unsigned months, lengthOfLife;
char writeToFile, proceed;
bool proceedFlag;

int main(void)
{
	//Initialising months and lengthOfLife
	do
	{
		proceedFlag = false;
		cout << "Please enter duration of the experiment in months: ";
		cin >> months;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Please enter rabbit's life span in months: ";
		cin >> lengthOfLife;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Duration of the experiment in months: " << months << endl;
		cout << "Rabbit's life span in months: " << lengthOfLife << endl;
		//Double-checking data with the user
		do
		{
			cout << "Do you want to proceed with the above parameters?(Y/N)" << endl;
			cin >> proceed;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			if(proceed == 'Y' || proceed == 'y')
			{
				proceedFlag = true;
			}
			else if(proceed != 'N' && proceed != 'n')
			{
				cout << "You have provided an invalid response, please enter \"Y\" or \"N\"." << endl;
			}
		}
		while(proceed != 'Y' && proceed != 'y' && proceed != 'N' && proceed != 'n');
	}
	while(!proceedFlag);

	//Calculations based on the data entered
	long unsigned monthTable[months][4];
	for(int unsigned i = 0; i < months; i++)
	{
		//The two initial months
		if(i <= 1)
		{
			//Population at the beginning of the month
			monthTable[i][0] = 1;
			//Rabbits "retired"
			monthTable[i][1] = 0;
			//Rabbits born
			monthTable[i][2] = 0;
			//Total rabbits
			monthTable[i][3] = monthTable[i][0];
		}
		//All other subsequent months
		else
		{
			monthTable[i][0] = monthTable[i - 1][3];
			monthTable[i][1] = monthTable[i - 1][3] - monthTable[i - 1][1];
			if(i < lengthOfLife)
				monthTable[i][2] = 0;
			else if(i == lengthOfLife)
				monthTable[i][2] = 1;
			else if(i > lengthOfLife)
				monthTable[i][2] = monthTable[i - lengthOfLife][1];
			monthTable[i][3] = monthTable[i][0] + monthTable[i][1] - monthTable[i][2];
		}
		//Monthly stats
		cout << "Month:   " << i + 1 << endl;
		cout << "Pop:     " << monthTable[i][0] << endl;
		cout << "Young:   " << monthTable[i][1] << endl;
		cout << "Retired:-" << monthTable[i][2] << endl;
		cout << "Total:   " << monthTable[i][3] << endl;
		cout << endl;
	}
	//Result
	cout << "Result:  " << monthTable[months - 1][3] << endl;
	cout << endl;

	//Check if result needs to be put into a file
	do
	{
		cout << "Write result to file?(Y/N)" << endl;
		cin >> writeToFile;
		if(writeToFile == 'Y' || writeToFile == 'y')
		{
			ofstream fout;
			fout.open("result.txt", ios_base::trunc);
			fout << monthTable[months - 1][3];
			fout.close();
		}
		else if(writeToFile != 'N' && writeToFile != 'n')
		{
			cout << "You have provided an invalid response, please enter \"Y\" or \"N\"." << endl;
		}
	}
	while(writeToFile != 'Y' && writeToFile != 'y' && writeToFile != 'N' && writeToFile != 'n');

	return 0;
}
