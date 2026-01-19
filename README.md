	
Използвам iostream защото, тя ми дава достъп до обектите cin (за въвеждане на данни) и cout (за извеждане на резултати).

Използвам iomanip защото, служи за разкрасяване и прецизно форматиране на данните, които се показват на екрана. 

Без нея резултатите от инвестицията щяха да изглеждат разхвърляни. Например, вместо $1200.50, може да се изпише просто $1200.5 или число с твърде
много цифри.

	#include <iostream>
	#include <iomanip>

  Използвам int за менюто (1. Savings, 2. Stocks, 3. Bonds). Тъй като int е най-ефективният и правилен избор.
  
  Използвам double защото, този тип данни е за числа с плаваща запетая и ми позволява работа с много големи числа и голяма точност след десетичната запетая.
  
  Principal служи за чистата сума. Rate служи за лихвения процент. Years e периода. FinalAmount e крайната сума. 
  Profit e крайната печалба
  
    int main() {
      int choice;
    	double principal, rate, years, finalAmount, profit;

  Това е главното меню което показва за какво служи програмата и какви избори можем да изберем. Избрал съм тези 3 опции защото, са най-важните в областта на инвестициите.

    cout << "=== Investment Return Calculator ===" << endl;
    cout << "Select investment type:" << endl;
    cout << "1. Savings Account (Low Risk)" << endl;
    cout << "2. Stocks (High Risk)" << endl;
    cout << "3. Bonds (Moderate Risk)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
  Целта на този цикъл е ако потребителят въведе число, по-малко от 1 или по-голямо от 3, програмата влиза в while цикъл.
  
  Потребителят получава съобщение за грешка и нова подкана за въвеждане, докато не предостави валидна опция.
  
  Използвам оператора "ИЛИ" (||), за да се провери дали въведената стойност е извън  диапазон (1, 3).
    
    while(choice < 1 || choice > 3) {
        cout << "Invalid choice! Please enter 1, 2, or 3: ";
        cin >> choice;
    }
  Този блок от кода отговаря за събирането на необходимите финансови променливи от потребителя.
    
    cout << "Enter initial investment amount: $";
    cin >> principal;
    cout << "Enter annual return rate (%): ";
    cin >> rate;
    cout << "Enter number of years: ";
    cin >> years;
	
Програмата автоматично конвертира въведената от потребителя процентна стойност в десетичен дроб чрез операцията
	
    rate = rate / 100;

Вместо статична формула, използвах for цикъл, който симулира растежа на капитала година по година. При всяка итерация текущата сума (finalAmount) се умножава по коефициента (1 + rate).

Чрез формулата finalAmount = finalAmount \times (1 + rate), печалбата от предходната година се реинвестира автоматично.
    
    finalAmount = principal;
    for(int i = 0; i < years; i++) {
        finalAmount = finalAmount * (1 + rate);
    }

  Този ред отговаря за финализирането на финансовия анализ, като извлича чистата стойност на инвестицията.
  
    profit = finalAmount - principal;

  Fixed e манипулация която инструктира програмата да използва фиксирана десетична точка.

  Функцията setprecision(2) ограничава изхода до точно два знака след десетичната запетая.
  
    cout << fixed << setprecision(2);
    cout << "\n=== Results ===" << endl;
    
    if(choice == 1) {
        cout << "Investment Type: Savings Account" << endl;
    } else if(choice == 2) {
        cout << "Investment Type: Stocks" << endl;
    } else if(choice == 3) {
        cout << "Investment Type: Bonds" << endl;
    }

  Този блок служи за визуализацията на крайните резултати
    
    cout << "Initial Investment: $" << principal << endl;
    cout << "Annual Return Rate: " << (rate * 100) << "%" << endl;
    cout << "Investment Period: " << years << " years" << endl;
    cout << "Final Amount: $" << finalAmount << endl;
    cout << "Total Profit: $" << profit << endl;
    
    return 0;
    }
