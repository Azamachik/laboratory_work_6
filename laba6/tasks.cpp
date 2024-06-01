#include <iostream>
#include <cmath>
#include <iostream>
#include <string>

#include "constants.h"
#include "approxEqual.h"
#include "task1.h"
#include "task2.h"

using namespace std;
using namespace constants;



void doTaskDependOnArgsOrPrintError(int countArgs, char* args[]) {
	if (countArgs < 2) {
		cout << "Îòñóòñòâóåò èìÿ ôóíêöèè";
		return;
	}

	string function (args[1]);

	cout << "ôóíêöèÿ " << function << endl << endl;

	if (function == "approximatelyEqual") {
		doApproximatelyEqual(countArgs, args);
	}
	else if (function == "17") {
		doTask17(countArgs, args);
	}
	else if (function == "18") {
		doTask18(countArgs, args);
	}
	else {
		cout << "Ââåäåíî èìÿ íåñóùåñòâóþùåé ôóíêöèè" << endl;
		return;
	}
}