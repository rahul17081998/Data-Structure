#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// we have 4 branches
unordered_map<int, int> dB1, dB2, dB3, dB4; // data base for each branches, which contain each customer ID and their amount
unordered_map<int, unordered_map<int,int> > branchName; 


void showAccountsDetails(unordered_map<int, int> &dB){
	cout<<"Account details: "<<endl;
	for(auto x: dB){
		cout<<"ID: "<<x.first<<"    Amount: "<<x.second<<endl;
	}
}

void details(int branchId){
	showAccountsDetails(branchName[branchId]);
}



bool Execute(int Id, string operation, int amount, int branchId){
		// access the account detail(data base of the perticuler branch)
		unordered_map<int,int> &dataBase = branchName[branchId];
	// check if we have to do credit them check amount in the account is sufficient or not
	if(operation =="credit"){
		if(dataBase[Id]<amount) {
			cout<<"Transection failed: insufficient money you have in your account"<<endl;
			return false; // Transection failed
		}
		else{
			dataBase[Id] = dataBase[Id] - amount; 
		}
	}
	else{ // debited the amount
		dataBase[Id] = dataBase[Id] + amount; 
	}
	return true;
}

void executeTransection(int Id, string operation, int amount, int IntialBranchVisit){
	// access the data base of the of the initial visited Branch
	
	bool executed = Execute(Id, operation, amount, IntialBranchVisit);

	// Pass this information to the other branches to perform the transection
	// check first of all initial visited branch preforment the transection or not
	bool allBranchOperationFinish = executed;
	if(executed==true){
		for(int branchNo=1; branchNo<=4; branchNo++){
			if(branchNo == IntialBranchVisit) continue; // skip the initial visited branch
			bool f = Execute(Id, operation, amount, branchNo);
			allBranchOperationFinish = allBranchOperationFinish & f;
		}
	}
	if(allBranchOperationFinish==true) cout<<"Transection Executed sucessfully at all the branches"<<endl;

}

int main(){
	// int N;
	// cout<<"How many branches you want to open: ";
	// cin>> N;
	// make N branches
	// /*
	int Id, amount, IntialBranchVisit;
	string operation;

	
	// */
	// give some initial data to the bank i.e. some customer id's and their amount
	int x = 230101, val = 300;
	for(int i=0; i<10; i++){
		dB1[x] = val; 
		dB2[x] = val; 
		dB3[x] = val; 
		dB4[x] = val;
		x++;
		val = val + 150; 
	}
	branchName[1] = dB1;
	branchName[2] = dB2;
	branchName[3] = dB3;
	branchName[4] = dB4;

	// showAccountsDetails(dB1);
	details(1);

	cout<< "Enter customer ID: ";
	cin>>Id;
	cout<<"Enter the operation you want to do (Enter either 'debit' or 'credit'): ";
	cin>>operation;
	cout<<"Enter the Amount: ";
	cin>>amount;
	cout<<"Enter the branch id where you want to visit: ";
	cin>>IntialBranchVisit;
	cout<<Id<<" "<<operation<<" "<<amount<<" "<<IntialBranchVisit<<endl;



	executeTransection(Id, operation, amount, IntialBranchVisit);
	cout<<"Account Details after ececuting the transection"<<endl;
	details(IntialBranchVisit);
	return 0;
}
