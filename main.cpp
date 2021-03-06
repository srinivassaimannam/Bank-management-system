#include "global.h"
#include "bank.h"


int main(){
	bank sbi;
	
	while(1){
		cout << "Transaction Type?" << endl;
		char x;
		cin >> x;
		
		if(x == 'E'){
			if(sbi.Master()){
				sbi.E();
				break;
			}else{
				cout << "Incorrect Master key" << endl;
			}
		}
		if(bankopen){
			switch(x){
				case 'O':sbi.O();
					break;
					
				case 'B':sbi.B();
					break;
					
				case 'D':sbi.D();
					break;
					
				case 'W':sbi.W();
					break;
					
				case 'C':sbi.C();
					break;
					
				case 'I':sbi.I();
					break;
					
				case 'P':sbi.P();
					break;
					
				case 'S':sbi.S();
					break;
					
				default : cout << "Invalid Transaction Key " << endl;
			}
		}else{
			if(x == 'S'){
				if(sbi.Master()){
					bankopen=true;
				}
			}else{
				cout << "Bank is not open yet " << endl;
			}
		}
	}
	return 0;
}
