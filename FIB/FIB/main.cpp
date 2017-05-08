#include <iostream>

using namespace std;

long makeRabbits(long, long, long, long);

int main(int argc, char *argv[])
{
	long months = 80, popPairGrowth = 1, initPairs = 1, totalPop = 0;

	totalPop = makeRabbits(initPairs, popPairGrowth, months, 0);

	cout << "totalPop: " << totalPop << endl;

	return 0;
}

long makeRabbits(long pairs, long growth, long months, long prevMonthPop)
{
	/*cout << "pairs: " << pairs << endl;
	cout << "growth: " << growth << endl;
	cout << "months: " << months << endl;
	cout << "prevMonthPop: " << prevMonthPop << endl;*/

	long pop = pairs + prevMonthPop * growth;
	//cout << "pop: " << pop << endl;
	if(months > 2)
	{
		pop = makeRabbits(pop, growth, months - 1, pairs);
		return pop;
	}
	return pop;
}
