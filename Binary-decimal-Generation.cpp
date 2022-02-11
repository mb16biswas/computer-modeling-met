

//    Roll           students

// 1911301041		Priyam Biswas
// 1911301042		Sushovan Sanfui
// 1911301043		Momojit Biswas
// 1911301044		Azhar Mahmood
// 1911301045		Sayan De
// 1911301047		Barun Kumar Rai

#include <bits/stdc++.h>
using namespace std;
// returns a float between 0 & 1
#define RANDOM_NUM ((float)rand() / (RAND_MAX + 1))
string GetRandomBits(int length);

// Function to convert binary to decimal
int binaryToDecimal(int n)
{
	int num = n;
	int dec_value = 0;

	// Initializing base value to 1, i.e 2^0
	int base = 1;

	int temp = num;
	while (temp)
	{
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}

int main()
{

	struct chromo_typ
	{
		// the binary bit string is held in a std::string
		string bits;

		float fitness;

		chromo_typ() : bits(""), fitness(0.0f){};
		chromo_typ(string bts, float ftns) : bits(bts), fitness(ftns) {}
	};

	string bits;
	int length = 10;
	for (int i = 0; i < length; i++)
	{
		if (RANDOM_NUM > 0.5f)

			bits += "1";

		else

			bits += "0";
		// cout << bits;
	}

	cout << "Generated binary " << bits << "\n";

	cout << "convert binary to decimal " << binaryToDecimal(stoi(bits)) << "\n";

	//}
	return 0;
}

