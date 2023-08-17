#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Fermat's Theorem states that, if p is a prime number then :
// a^p = a ( mod p ), which can also be written as : (a^p) % p = a, and therefore as : a^(p-1) % p = 1

// So, we will reduce a and b into integers using Fermat's Theorem.

// In a^b%M,
// a^b % M = ((a%M)^b) %M ( As (x * y * z)%M = (x%M * y%M * z%M)%M )
// So reduce a to a%M.

// Next, for b, we know from Fermats Theorem that a^(M-1) % M = 1
// So a^b = a^(M-1) * a^(M-1) * ...... * a^(M-1) * a^(b%(M-1)) = 1 * 1 * .... * 1 * a^(b%(M-1)) = a^(b%(M-1))
// So we can reduce b to b%(M-1).

// Finally, after we have a and b as integers, we can just computer a^b % M using binary exponentiation.

// Returns modulo exponentiation for two numbers
// represented as long long int. It is used by
// powerStrings(). Its complexity is log(n)
ll MOD;
ll powerLL(ll x, ll n)
{
	ll result = 1;
	while (n) {
		if (n & 1)
			result = result * x % MOD;
		n = n / 2;
		x = x * x % MOD;
	}
	return result;
}

// Returns modulo exponentiation for two numbers
// represented as strings. It is used by
// powerStrings()
ll powerStrings(string sa, string sb)
{
	// We convert strings to number

	ll a = 0, b = 0;

	// calculating  a % MOD
	// Using the concept that a number XYZ % M = ( ( (X%M)*10 + Y%M)*10 + Z%M)%M
	for (int i = 0; i < sa.length(); i++)
		a = (a * 10 + (sa[i] - '0')) % MOD;

	// calculating  b % (MOD - 1)
	for (int i = 0; i < sb.length(); i++)
		b = (b * 10 + (sb[i] - '0')) % (MOD - 1);

	// Now a and b are long long int. We
	// calculate a^b using modulo exponentiation
	return powerLL(a, b);
}