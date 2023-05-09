#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int divisor = 1, numerator = 1, numeratorT, fraction[2000], result[2000], maxL = 1000;
	for (int i = 0; i < maxL; i++) {
		result[i] = 0;
	}

	for (int i = 0; divisor < 1073741823 * 2; i++) {
		std::cout << divisor << "\n";

		numeratorT = 1;

		for (int j = 0; j < maxL; j++) {
			fraction[j] = 0;
		}

		for (int j = 0; j < maxL; j++) {
			if (numeratorT < divisor) {
				numeratorT = numeratorT * 10;
			}
			else {
				fraction[j] = numeratorT / divisor;
				numeratorT = numeratorT % divisor;
				numeratorT = numeratorT * 10;
			}
			if (fraction[j] > 9) {
				int rollover;
				rollover = fraction[j] / 10;
				fraction[j] = fraction[j] - rollover * 10;
				fraction[j - 1] = fraction[j - 1] + rollover;
			}
		}


		int rollover{};
		for (int j = maxL - 1; j >= 0; j--) {
			fraction[j] = fraction[j] * 4 + rollover;
			rollover = 0;
			if (fraction[j] > 9) {
				rollover = fraction[j] / 10;
				fraction[j] = fraction[j] - rollover * 10;
			}
		}


		for (int j = maxL - 1; j >= 0; j--) {
			result[j] = result[j] + fraction[j];
			if (result[j] > 9) {
				int rollover;
				rollover = result[j] / 10;
				result[j] = result[j] - rollover * 10;
				result[j - 1] = result[j - 1] + rollover;
			}
		}

		divisor += 2;
		std::cout << result[0] << ".";
		for (int j = 1; j < maxL; j++) {
			std::cout << result[j];
		}
		std::cout << "\n\n\n\n";




		std::cout << divisor << "\n";

		numeratorT = 1;

		for (int j = 0; j < maxL; j++) {
			fraction[j] = 0;
		}

		for (int j = 0; j < maxL; j++) {
			if (numeratorT < divisor) {
				numeratorT = numeratorT * 10;
			}
			else {
				fraction[j] = numeratorT / divisor;
				numeratorT = numeratorT % divisor;
				numeratorT = numeratorT * 10;
			}
			if (fraction[j] > 9) {
				int rollover;
				rollover = fraction[j] / 10;
				fraction[j] = fraction[j] - rollover * 10;
				fraction[j - 1] = fraction[j - 1] + rollover;
			}
		}


		for (int j = maxL - 1; j >= 0; j--) {
			fraction[j] = fraction[j] * 4 + rollover;
			rollover = 0;
			if (fraction[j] > 9) {
				rollover = fraction[j] / 10;
				fraction[j] = fraction[j] - rollover * 10;
			}
		}


		for (int j = maxL - 1; j >= 0; j--) {
			
			if (result[j] < fraction[j]) {
				result[j - 1] = result[j - 1] - 1;
				result[j] = result[j] + 10;
			}
			result[j] = result[j] - fraction[j];
		}

		divisor += 2;
		std::cout << result[0] << ".";
		for (int j = 1; j < maxL; j++) {
			std::cout << result[j];
		}
		std::cout << "\n\n\n\n";
	}
}