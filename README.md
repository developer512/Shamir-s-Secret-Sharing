# Shamir-s-Secret-Sharing
This is a simple implementation of Shamir's secrete sharing cryptographic algorithm in C++
What the programm does:
- generates pseudorandom cryptographic numbers that are users' identifier;
- generates a secrete polynomial over a chosen finite field;
- generates users' personal secrete keys;
- resolves sharing secrete by means of users' secrete keys.

Whenever exploiting, consider
t - number of users to join their secrete keys in order to resolve sharing secrete,
modulus - prime number that initializes numeric field,
usersNumber - overall number of users currently supported by algorithm.

Within exploiting (console mode), consider
List of users - list of users' cryptographic numbers,
List of users' keys - list of corresponding users' personal keys,
Secrete polynomial - list of coefficients of polynomial from the lowest degree monomial of x^0 to the highest degree of monomial x^(t-1),
Resolved secrete - sharing secrete.
