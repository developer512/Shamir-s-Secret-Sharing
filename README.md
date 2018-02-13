# Shamir-s-Secret-Sharing
This is a simple implementation of Shamir's secrete sharing cryptographic algorithm in C++.
What the programm does:
- generates pseudorandom cryptographic numbers that are users' identifier;
- generates a secrete polynomial over a chosen finite field;
- generates users' personal secrete keys;
- resolves sharing secrete by means of users' secrete keys.

Whenever exploiting, consider:
1) t - number of users to join their secrete keys in order to resolve sharing secrete,
2) modulus - prime number that initializes numeric field,
3) usersNumber - overall number of users currently supported by algorithm.

Within exploiting (console mode), consider:
1) List of users - list of users' cryptographic numbers,
2) List of users' keys - list of corresponding users' personal keys,
3) Secrete polynomial - list of coefficients of polynomial from the lowest degree monomial of x^0 to the highest degree of monomial x^(t-1),
4) Resolved secrete - sharing secrete.
