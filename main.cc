#include <bits/stdc++.h>

using namespace std;

string numberToWords(long long int n)
{
  bool add_and_mult = false;
	long long int limit = 1000000000000, curr_hun, t = 0;

	if (n == 0)
		return ("Zero");

	string multiplier[] = { 
    "", "trilhão", "bilhão",
    "milhão", "mil" 
  };

  string cents[] = {
    "", "cem", "duzentos", "trezentos", "quatrocentos",
    "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"
  };
	
	string first_twenty[] = {
    "",	 "um", "dois", "três",
    "quatro", "cinco", "seis", "sete",
    "oito", "nove", "dez", "onze",
    "doze", "treze", "quatorze", "quinze",
    "dezesseis", "dezessete", "dezoito", "dezenove"
  };

	string tens[] = { 
    "", "vinte", "trinta", "quarenta", "cinquenta",
    "sessenta", "setenta", "oitenta", "noventa" 
  };

	if (n < 20)
		return (first_twenty[n]);

	// Answer variable to store the conversion
	string answer = "";
	for (long long int i = n; i > 0;
		i %= limit, limit /= 1000) {

		// Store the value in multiplier[t], i.e n =
		// 1000000, then r = 1, for multiplier(million), 0
		// for multipliers(trillion and billion)
		curr_hun = i / limit;

		// It might be possible that the current multiplier
		// is bigger than your number
		while (curr_hun == 0) {

			// Set i as the remainder obtained when n was
			// divided my the limit
			i %= limit;

			// Divide the limit by 1000, shifts the
			// multiplier
			limit /= 1000;

			// Get the current value in hundereds, as
			// English system works in hundreds
			curr_hun = i / limit;

			// Shift the multiplier
			++t;
    }

		// If current hundered is greater that 99, Add the
		// hundreds' place
		if (curr_hun > 99) {
      string and_cent = " ";

      if (curr_hun % 100 > 0)
        and_cent = " e ";

      if (curr_hun > 100 && curr_hun < 200) // Trata caso cento
        answer += "cento e ";
      else
        answer += cents[curr_hun / 100] + and_cent;
    }

		// Bring the current hundered to tens
		curr_hun = curr_hun % 100;

		// If the value in tens belongs to [1,19], add using
		// the first_twenty

		if (curr_hun > 0 && curr_hun < 20)
    {
			answer += (first_twenty[curr_hun] + " ");
    }
		// If curr_hun is now a multiple of 10, but not 0
		// Add the tens' value using the tens array
		else if (curr_hun % 10 == 0 && curr_hun != 0)
    {
			answer += (tens[curr_hun / 10 - 1] + " ");
    }
		// If the value belongs to [21,99], excluding the
		// multiples of 10 Get the ten's place and one's
		// place, and print using the first_twenty array

		else if (curr_hun > 20 && curr_hun < 100)
    {
      string and_tens = " ";

      if (curr_hun % 10 > 0)
        and_tens = " e ";

			answer += (tens[curr_hun / 10 - 1] + and_tens
					+ first_twenty[curr_hun % 10] + " ");
    }
		// If Multiplier has not become less than 1000,
		// shift it
		if (t < 4)
    {
      string and_mult = " ";
      if (t == 3)
      {
        if (/*(curr_hun % 10 > 0)||*/ (i % 1000 > 0))
          and_mult = " e "; 
      }

			answer += (multiplier[++t] + and_mult);
    }
	}

	return (answer);
}

int main()
{
  cout << ">>>>>>>>>>>>>>>> TESTES <<<<<<<<<<<<<<<<<\n\n";
  long long int n = 36;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 30;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
	n = 1000;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
	n = 1001;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 1151;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
	n = 15000;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 15502;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 150001;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 155001;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 155201;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 155231;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 1155001;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 500000;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 500002;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 500042;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 505042;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 515042;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 815042;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 99999;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 999999;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 990999;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 100;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 101;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 150;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 152;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 299;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 80;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 82;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 28;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 04;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";
  n = 1995;
	cout << n << ": " << numberToWords(n) << "\n-------------------------------\n\n";

	return 0;
}

