#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class HouseInterestsPlan {
private:
    double principalAmount;
    double interestRate;
    int loanTerm;
    public:
    HouseInterestsPlan(double principalAmount, double interestRate, int loanTerm) {
        this->principalAmount = principalAmount;
        this->interestRate = interestRate;
        this->loanTerm = loanTerm;
    }
    double totalInterest () {
        return principalAmount * (interestRate/100) * loanTerm;
    }
    double totalPayment () {
        return principalAmount + totalInterest();
    }
    double EMI () {
        double monthlyRate = (interestRate / 100) / 12;  // Convert annual rate to monthly
        int months = loanTerm * 12;  // Convert years to months

        return (principalAmount * monthlyRate * pow(1 + monthlyRate, months)) / (pow(1 + monthlyRate, months) - 1);

    }
    void print() {
        cout << "--- House Interest Plan Details ---";
        cout << "Principal amount : " << principalAmount << endl;
        cout << "Interest Rate : " << interestRate << endl;
        cout << "Loan term : " << loanTerm << endl;
        cout << "Total Interest : " << totalInterest() << endl;
        cout << "Total Payment : " << totalPayment()<< endl;
        cout << "Total EMI : " << setprecision(6) << EMI() << endl;
    }

};
int main()
{
    double principalAmount, interestRate;
    int loanTerm;

    do {
        cout << "Enter principal amount (or -1 to exit): ";
        cin >> principalAmount;

        if (principalAmount == -1) {
            cout << "Exiting the program." << endl;
            break;
        }

        cout << "Enter interest rate (as a percentage): ";
        cin >> interestRate;

        cout << "Enter loan term in years: ";
        cin >> loanTerm;

        // Create a HouseInterestsPlan object and display the results
        HouseInterestsPlan plan(principalAmount, interestRate, loanTerm);
        plan.print();

        cout << endl; // Add an empty line for spacing

    } while (principalAmount != -1);

    return 0;
}
