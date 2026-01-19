#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int choice;
    double principal, rate, years, finalAmount, profit;
    
    cout << "=== Investment Return Calculator ===" << endl;
    cout << "Select investment type:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Stocks" << endl;
    cout << "3. Bonds" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    while(choice < 1 || choice > 3) {
        cout << "Invalid choice! Please enter 1, 2, or 3: ";
        cin >> choice;
    }
    
    cout << "Enter initial investment amount: $";
    cin >> principal;
    cout << "Enter annual return rate (%): ";
    cin >> rate;
    cout << "Enter number of years: ";
    cin >> years;
    
    rate = rate / 100;
    
    finalAmount = principal;
    for(int i = 0; i < years; i++) {
        finalAmount = finalAmount * (1 + rate);
    }
    
    profit = finalAmount - principal;
    
    cout << fixed << setprecision(2);
    cout << "\n=== Results ===" << endl;
    
    if(choice == 1) {
        cout << "Investment Type: Savings Account" << endl;
    } else if(choice == 2) {
        cout << "Investment Type: Stocks" << endl;
    } else if(choice == 3) {
        cout << "Investment Type: Bonds" << endl;
    }
    
    cout << "Initial Investment: $" << principal << endl;
    cout << "Annual Return Rate: " << (rate * 100) << "%" << endl;
    cout << "Investment Period: " << years << " years" << endl;
    cout << "Final Amount: $" << finalAmount << endl;
    cout << "Total Profit: $" << profit << endl;
    
    return 0;
}
