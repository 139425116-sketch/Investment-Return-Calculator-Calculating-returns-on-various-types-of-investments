	
Използвам iostream защото, тя ми дава достъп до обектите cin (за въвеждане на данни) и cout (за извеждане на резултати).

Използвам iomanip защото, служи за разкрасяване и прецизно форматиране на данните, които се показват на екрана. Без нея резултатите
от инвестицията щяха да изглеждат разхвърляни. Например, вместо $1200.50, можеше да се изпише просто $1200.5 или число с твърде
много цифри.

	#include <iostream>
	#include <iomanip>

  Използвам int за менюто (1. Savings, 2. Stocks, 3. Bonds). Тъй като int е най-ефективният и правилен избор.
  
  Използвам double защото, този тип данни е за числа с плаваща запетая и ми позволява работа с много големи числа и голяма точност след десетичната запетая.
  Парите почти винаги имат центове. Използвам double, за да може потребителят да инвестира например $1000.50.
  
  Principal служи за чистата сума. Rate служи за лихвения процент. Years e периода. FinalAmount e крайната сума. 
  Profit e крайната печалба
  
    int main() {
      int choice;
    	double principal, rate, years, finalAmount, profit;

  Това е главното меню което показва за какшо служи програмата и какви избори можем да изберем. Избрал съм тези 3 опции защото, са най-важните в областта на инвестициите.

    cout << "=== Investment Return Calculator ===" << endl;
    cout << "Select investment type:" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Stocks" << endl;
    cout << "3. Bonds" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
  ш
    
    while(choice < 1 || choice > 3) {
        cout << "Invalid choice! Please enter 1, 2, or 3: ";
        cin >> choice;
    }
  ш 
    
    cout << "Enter initial investment amount: $";
    cin >> principal;
    cout << "Enter annual return rate (%): ";
    cin >> rate;
    cout << "Enter number of years: ";
    cin >> years;
    
    // Convert percentage to decimal
    rate = rate / 100;
    
    // Calculate final amount using compound interest
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
