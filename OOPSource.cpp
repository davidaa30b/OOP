#include<iostream>
#include<stdexcept>
#pragma warning(disable : 4996)
using namespace std;

class User {
protected:
	char* username;
	char* email;
	double balance;
	void free() {
		delete[] username;
		delete[] email;
		
	}
	void copyFrom(const User& other) {
		setUsername(other.username);
		setEmail(other.email);
		setBalnce(other.balance);
	}
public:
	const char* getUsername()const {
		return username;
	}

	const char* getEmail()const {
		return email;
	}
	double getBalance()const {
		return balance;
	}

	void setUsername(const char * username) {
		delete[] this->username;
		this->username = new char[strlen(username) + 1];
		strcpy(this->username, username);
	}

	void setEmail(const char* email) {
		delete[] this->email;
		this->email = new char[strlen(email) + 1];
		strcpy(this->email, email);
	}
	void setBalnce(double balance) {
		if (balance < 0) {
			throw invalid_argument("Invalid argument.The balance can not be a negative number!");
		}
		this->balance = balance;
	}

	User():username(nullptr),email(nullptr),balance(0) {}

	User(const char* username, const char* email, double balance) {
		setUsername(username);
		setEmail(email);
		setBalnce(balance);
	}

	User(const User& other) {
		copyFrom(other);
	}

	User& operator=(const User& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
	
	void depositMoney(const double amount) {
		if (amount < 0) {
			throw invalid_argument("Invalid argument.The amount can not be a negative number!");
		}
		balance += amount;
	}

	~User() {
		free();
	}
};

class PremiumUser:public User {
private:
	char*  bankAccountIBAN;
	long subscriptionStratTimestamp;
public:

	const char* getBankAccountIBAN()const {
		return bankAccountIBAN;
	}

	long getSubscriptionStratTimestamp() const {
		return subscriptionStratTimestamp;
	}

	void setBankAccountIBAN(const char* bankAccountIBAN) {
		delete[] this->bankAccountIBAN;
		this->bankAccountIBAN = new char[strlen(bankAccountIBAN) + 1];
		strcpy(this->bankAccountIBAN, bankAccountIBAN);
	}

	PremiumUser():User() {
		setBankAccountIBAN(0);
		this->subscriptionStratTimestamp = 0;
	}

	PremiumUser(const char* username, const char* email, double balance, const char* bankAccountIBAN,long subscriptionStratTimestamp):User(username, email, balance) {
		setBankAccountIBAN(bankAccountIBAN);
		this->subscriptionStratTimestamp = subscriptionStratTimestamp;
	}

	PremiumUser(const PremiumUser& other) :User(other) {
		setBankAccountIBAN(other.bankAccountIBAN);
		this->subscriptionStratTimestamp = other.subscriptionStratTimestamp;

	}

	PremiumUser& operator=(const PremiumUser& other) {
		if (this != &other) {
			
			User::operator=(other);
			setBankAccountIBAN(other.bankAccountIBAN);
			this->subscriptionStratTimestamp = other.subscriptionStratTimestamp;

		}
		return *this;
	}
	
	void withdrawMoney(const double amount) {
		if (amount < 0) {
			throw invalid_argument("Invalid argument.The amount can not be a negative number!");
		}
		balance -= amount;
	}

	void chargeForSubscription() {
		balance -= 42;
	}

	~PremiumUser() {
		delete[] bankAccountIBAN;
	}

};

int main() {
	PremiumUser user1("David","davidbaruch@gmail.com",1000.577,"IBAN871231CAA",0);
	cout << user1.getUsername()<<" "<<user1.getBankAccountIBAN() << " has balance :" << user1.getBalance() << endl;
	user1.depositMoney(1000.66);
	cout << user1.getUsername() << " has balance :" << user1.getBalance() << endl;
	user1.withdrawMoney(500.20);
	cout << user1.getUsername() << " has balance :" << user1.getBalance() << endl;
	user1.chargeForSubscription();
	cout << user1.getUsername() << " has balance :" << user1.getBalance() << endl;
	PremiumUser user2 = user1;
	cout << "-------------------user2 becames user1--------------\n";
	cout << user2.getUsername() << " " << user2.getBankAccountIBAN() << " has balance :" << user2.getBalance() << endl;
	PremiumUser user3("Boris", "boriskostov@gmail.com", 1000.32, "IBAN123141EER",0);
	cout << user3.getUsername() << " " << user3.getBankAccountIBAN() << " has balance :" << user3.getBalance() << endl;

	user3 = user1;
	cout << "-------------------change of user3-----------------\n";
	cout << user3.getUsername() << " " << user3.getBankAccountIBAN() << " has balance :" << user3.getBalance() << endl;


	return 0;
}