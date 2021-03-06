#ifndef ACCOUNT_H
#define ACCOUNT_H

class account{
	public:
	bool open;
	int accountNum;
	double deposit;
	void setaccountNum(int y){
		accountNum = y;
	}
	void setbalance(double x){
                deposit = x;
        }
          
	void setPin(string n){
		pin = n;
	}
	
	bool isPin(string s){
		if(s==pin){
			return true;
		}
		return false;
	}
	private:
	string pin;
};

#endif
