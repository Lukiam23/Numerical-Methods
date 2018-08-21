#include <iostream>
#include <math.h>
using namespace std;

int parenteses_encaixado(double num){
	if(num == 0 || num == 1){
		return num;
	}
	int lsb = fmod(num,10); /*least significant bit*/
	num = num / 10;
	return 2*(parenteses_encaixado(num))+lsb;
}

int main (){
	double i = 0;
	while(i != -1){
		cout << "Insira o valor na base 2: \n";
		cin >> i;
		cout << parenteses_encaixado(i) << "\n";
	}
	return 0;
}