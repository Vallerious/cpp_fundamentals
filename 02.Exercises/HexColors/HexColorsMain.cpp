#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class HexColor {
private:
	string hexColorStr;
	int red;
	int green;
	int blue;

	void parseToNumeric() {
		int startingIdx = 0;

		if (this->hexColorStr[0] == '#') {
			startingIdx++;
		}

		string redHex = this->hexColorStr.substr(startingIdx, 2);
		string greenHex = this->hexColorStr.substr(startingIdx + 2, 2);
		string blueHex = this->hexColorStr.substr(startingIdx + 4, 2);

		this->red = stoi(redHex, nullptr, 16);
		this->green = stoi(greenHex, nullptr, 16);
		this->blue = stoi(blueHex, nullptr, 16);
	}

	void parseToStr() {
		ostringstream hexStrStream;

		ostringstream redStream;
		redStream << hex << this->red;
		redStream = padWithZeros(redStream);

		ostringstream greenStream;
		greenStream << hex << this->green;
		greenStream = padWithZeros(greenStream);

		ostringstream blueStream;
		blueStream << hex << this->blue;
		blueStream = padWithZeros(blueStream);

		hexStrStream << '#' << hex << redStream.str() << hex << greenStream.str() << hex << blueStream.str();

		this->hexColorStr = hexStrStream.str();
	}

	ostringstream padWithZeros(ostringstream& stream) {
		ostringstream newStream;

		if (stream.str().size() == 1) {
			newStream << stream.str() << '0';
		}
		else {
			newStream << stream.str();
		}

		return newStream;
	}
public:
	HexColor(string hexColorStr) : hexColorStr(hexColorStr) {
		this->parseToNumeric();
	}

	HexColor(int red, int green, int blue) : red(red), green(green), blue(blue) {
		this->parseToStr();
	}

	int getRed() const {
		return this->red;
	}

	int getGreen() const {
		return this->green;
	}

	int getBlue() const {
		return this->blue;
	}

	string getHex() const {
		return this->hexColorStr;
	}

	HexColor operator+(const HexColor& other) {
		return HexColor{
			this->getRed() + other.getRed(),
			this->getGreen() + other.getGreen(),
			this->getBlue() + other.getBlue()
		};
	}

	HexColor operator/(int n) {
		return HexColor{
			this->getRed() / n,
			this->getGreen() / n,
			this->getBlue() / n
		};
	}
};

int main() {
	string c1, c2;
	cin >> c1 >> c2;

	HexColor hex1{ c1 };
	HexColor hex2{ c2 };
	HexColor hex3 = (hex1 + hex2) / 2;

	cout << hex3.getHex() << endl;

	return 0;
}