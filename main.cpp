#include < iostream > 
#include < ctime > 
#include < stdlib.h > 
#include < math.h >

using namespace std;

int modularPowering(int a, int exponent, int modulus) {

  int result = 1;
  int A = a;
  int n = exponent;
  while (n > 0) {
    if (n % 2 == 1) {
      result *= A;
      result %= modulus;
      n--;
    } else {
      A *= A;
      A %= modulus;
      n /= 2;
    }
  }
  return result;
}

int getInverse(int a, int modulus) {
  int result = modularPowering(a, modulus - 2, modulus);

  return result;
}

int * usersInitialization(int & n, int & modulus) {
  int * r = new int[n];
  bool check;
  r[0] = rand() % (modulus - 1) + 1;
  for (int i = 1; i < n; i++) {
    do {
      check = false;
      r[i] = rand() % (modulus - 1) + 1;
      for (int j = 0; j < i; j++)
        if (r[i] == r[j]) {
          check = true;
          break;
        }
    } while (check);
  }
  return r;
}

int * polynomialGenerator(int t, int & modulus) {
  int * polynomial = new int[t];
  for (int i = 0; i < t; i++)
    polynomial[i] = rand() % modulus;

  return polynomial;
}

void printVector(int * vector, int & length) {
  for (int i = 0; i < length; i++)
    cout << vector[i] << " ";
  cout << endl;
}

int getUserKey(int & userNumber, int * polynomial, int & t, int & modulus) {
  int * rVector = new int[t];
  int userKey = 0;
  int temp;
  for (int i = 0; i < t; i++) {
    rVector[i] = modularPowering(userNumber, i, modulus);
    temp = (rVector[i] * polynomial[i]) % modulus;
    userKey += temp;
    userKey %= modulus;
  }

  delete[] rVector;

  return userKey;
}

int secretResolving(int * userNumbers, int * polynomial, int & t, int & modulus) {
  int * userKeys = new int[t];
  int * w = new int[t];
  int mainKey = 0, difference;
  int temp;
  for (int i = 0; i < t; i++)
    userKeys[i] = getUserKey(userNumbers[i], polynomial, t, modulus);

  for (int i = 0; i < t; i++) {
    w[i] = 1;
    for (int j = 0; j < t; j++) {
      if (j != i) {
        difference = (userNumbers[j] - userNumbers[i]) % modulus;
        if (difference < 0)
          difference += modulus;
        w[i] *= userNumbers[j];
        w[i] %= modulus;
        w[i] *= getInverse(difference, modulus);
        w[i] %= modulus;
      }

    }
    temp = (userKeys[i] * w[i]) % modulus;
    mainKey += temp;
    mainKey %= modulus;
  }

  delete[] userKeys;
  delete[] w;
  return mainKey;
}

int main() {
  while (true) {

    int * A, * R;
    int n, t, p;
    srand(time(NULL));
    cout << "Enter t-parameter" << endl;
    cin >> t;
    cout << "Enter modulus" << endl;
    cin >> p;
    do {
      cout << "Enter number of users" << endl;
      cin >> n;
      if (n >= p - 1)
        cout << "Excessively many users" << endl;
    } while (n >= p - 1);

    R = usersInitialization(n, p);

    cout << "List of users:" << endl;
    printVector(R, n);
	A = polynomialGenerator(t, p);
	cout << "List of users' keys:" << endl;
	for (int i = 0; i < n; i++)
	  cout << getUserKey (R[i], A, t, p) << " ";
    cout << endl << "Secret polynomial: ";
    printVector(A, t);

    cout << "Resolved secret: ";
    cout << secretResolving(R, A, t, p) << endl;
    cout << "_______________________________" << endl;
    delete[] A;
    delete[] R;
  }
  return 0;
}