#ifndef BANK_H
#define BANK_H
#include "account.h"

bool bankopen = false;
class bank{
	public:

       int count=0;
       account* accounts[100]={NULL};
       int arr[100]={0};
       
  
       void O(){
               if(count<100){

                       account* acc=new account;

                       cout<<"Initial Deposit? = "<<endl;
                       int x;
                       cin >> x;
                       cout <<"PIN? = "<<endl;
                       string n;
                       cin >> n;
                       acc->open=true;
                       acc->setbalance(x);
                       acc->setPin(n);
                       acc->setaccountNum(count+1001);
                       arr[count] = 1;
                       accounts[count]=acc;
   
                       cout<< "Account number = "<< count+1001<<endl;
                       count++;
                       
               }else{
                       cout<< "You had exceeded the accounts limit "<<endl;
                }
       }
                

	
	void B(){
		int a;
		string pin;
		cout<<" Account Number? = " << endl;
		cin>> a;
		cout<<"PIN? = " <<endl;
		cin>> pin;
		bool x= arr[a-1001];
		if(x){	
			if(accounts[a-1001]->isPin(pin)){
				cout<< "Account Num = " << accounts[a-1001]->accountNum << "  Balance = " << accounts[a-1001]->deposit << endl;
			}else{
				cout<<"The credentials are incorrect"<<endl;
			}
		}else{
			cout<<" The Account doesn't exist "<< endl;
			
		}
	}
	
	void D(){
		int a;
		double deposit;
		string pin;
		cout<<"Account Number? = "<<endl;
		cin>> a; 
		bool x= arr[a-1001];
		if(x){
			cout <<"Amount? = "<<endl;
			cin>> deposit;
			cout<<"PIN? = "<<endl;
			cin>>pin;
			if(accounts[a-1001]->isPin(pin)){
				accounts[a-1001]->deposit = accounts[a-1001]->deposit + deposit;
				cout<<"Account Num =  "<< accounts[a-1001]->accountNum <<"  Balance = "<< accounts[a-1001]->deposit <<endl;
			}else{
				cout<<"The credentials are incorrect "<<endl;
			}	
		}else{
			cout<<" The Account doesn't exist "<< endl;
			
		}
	}
	
	void W(){
		int a;
		cout<<"Account Number? = "<<endl;
		cin>>a;
		bool x= arr[a-1001];
		if(x){
			string pin;
			double amount;
			cout<<"Amount? = "<<endl;
			cin>>amount;
			cout<<"PIN? = "<<endl;
			cin>>pin;
			if(accounts[a-1001]->isPin(pin)){
				if(accounts[a-1001]->deposit >=amount){
					accounts[a-1001]->deposit = accounts[a-1001]->deposit - amount;
				       cout<<"Account Num =  "<<accounts[a-1001]->accountNum<<"  Balance = "<<accounts[a-1001]->deposit<<endl;
				}else{
					cout<<"Funds are insufficient"<<endl;
				}	
			}else{
				cout<<"The credentials are incorrect "<<endl;
			}
		}else{
			cout<<"The Account doesn't exist "<< endl;
		}
	}
	
	void C(){
		int a;
		cout<<"Account Number? = "<<endl;
		cin>>a;
		bool x= arr[a-1001];
		if(x){
			string pin;
			cout<<"PIN?"<<endl;
			cin>>pin;
			if(accounts[a-1001]->isPin(pin)){
				accounts[a-1001]->open=false;
				arr[a-1001]=0;
						
			}else{
				cout<<"The credentials are incorrect "<<endl;
			}
		}else{
			cout<<"The Account doesn't exist "<<endl;
		}
	}
	
	void I(){
		if(Master()){
			double interestrate;
			cout<<"Interest rate?"<<endl;
			cin>>interestrate;
			for(int itr=0;itr<100;itr++){
				if(arr[itr] != 0){
					accounts[itr]->deposit = accounts[itr]->deposit + (double)((accounts[itr]->deposit)*interestrate)/100;
				}
			}
		}else{
			cout<<"Master key is INCORRECT"<<endl;
		}
	}
	
	void P(){
		if(Master()){
			for(int itr=0;itr<100;itr++){
				if(arr[itr] != 0){
					cout<<"Account Num = "<<accounts[itr]->accountNum <<"  Deposit = "<<accounts[itr]->deposit <<endl;
				}
			}
		}else{
			cout<<"Master key is INCORRECT"<<endl;
		}
	}
	
	void E(){
		account* accounts[100]={NULL};
                int arr[100]={0};
		cout<<"Closing all the bank Accounts "<<endl;
	}
	
	void S(){
		cout<<"The bank is opened already"<<endl;
	}
	
	bool Master(){
		string s;
		cout << "Please Enter The Master key = "<< endl;
		cin >> s;
		if(s == masterKey){
			return true;
		}else{
			return false;
		}
	}	
	
	private:
	string masterKey = "password";
	
	
};



	


#endif


