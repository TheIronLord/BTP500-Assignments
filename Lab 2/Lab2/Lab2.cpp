#include <iostream>
using namespace std;

unsigned int fact(unsigned int n){
	if (n > 0){
		n = n * fact(n - 1);
	}
	else if (n == 0){
		return 1;
	}
	return n;
}

double pow(double base, unsigned int n){
	int ans;
	if (base == 0){
		return 0;
	}
	else if (n == 0){
		return 1;
	}
	else if (n % 2 == 0){
		ans = pow(base, n / 2);
		return ans*ans;
	}
	else{
		base = base * pow(base, n - 1);
	}
	return base;
}

unsigned int fib(unsigned int n){
	if (n > 1){
		n = fib(n - 1) + fib(n - 2);
	}
	return n;
}