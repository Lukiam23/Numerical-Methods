#include <iostream>
#include <string.h>
#include <sstream>
#include <math.h>
using namespace std;

string conversor(int num){
	int resto;
	string str;
	string bin;
	while(num != 0){
		resto = num % 2;
		num = num / 2;
		ostringstream strs;
		strs << resto;
		str = strs.str();
		str += bin;
		bin = str;
	}
	return bin;
}

int main(){
	int i = 0;
	while(i != -1){
		cout << "Insira o valor na base 10: \n";
		cin >> i;
		cout <<"Binário: " << conversor(i) << "\n";
	}
	return 0;
}