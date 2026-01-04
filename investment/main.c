#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Променливи за програмата
    int izbor;
    double pari, lihva, godini, kraino;
    
    printf("Kalkulator za investicii\n\n");
    
    // Основен цикъл
    while(true) {
        // Меню
        printf("1. Prosta lihva\n");
        printf("2. Slozna lihva\n");
        printf("3. Akcii\n");
        printf("4. Mesecen depozit\n");
        printf("5. Izlaz\n");
        printf("Izberi: ");
        scanf("%d", &izbor);
        
        // Проверка какво е избрано
        switch(izbor) {
            case 1:
                // Проста лихва
                printf("Vavedi pari: ");
                scanf("%lf", &pari);
                printf("Vavedi lihva v procenti: ");
                scanf("%lf", &lihva);
                printf("Vavedi godini: ");
                scanf("%lf", &godini);
                
                // Пресмятане
                kraino = pari + (pari * lihva * godini / 100);
                
                // Показване на резултат
                printf("Nachalna suma: %.2f lv\n", pari);
                printf("Kraina suma: %.2f lv\n", kraino);
                printf("Pechalba: %.2f lv\n\n", kraino - pari);
                break;
                
            case 2: {
                // Сложна лихва
                int chestota;
                printf("Vavedi pari: ");
                scanf("%lf", &pari);
                printf("Vavedi lihva v procenti: ");
                scanf("%lf", &lihva);
                printf("Vavedi godini: ");
                scanf("%lf", &godini);
                printf("Kolko puti godishno (1, 4 ili 12): ");
                scanf("%d", &chestota);
                
                // Пресмятане
                kraino = pari * pow(1 + lihva/(100*chestota), chestota*godini);
                
                // Показване на резултат
                printf("Nachalna suma: %.2f lv\n", pari);
                printf("Kraina suma: %.2f lv\n", kraino);
                printf("Pechalba: %.2f lv\n\n", kraino - pari);
                break;
            }
                
            case 3: {
                // Акции
                double akcii, kupuvane, prodavane, dividend;
                printf("Broi akcii: ");
                scanf("%lf", &akcii);
                printf("Cena pri kupuvane: ");
                scanf("%lf", &kupuvane);
                printf("Cena pri prodavane: ");
                scanf("%lf", &prodavane);
                printf("Dividend v procenti: ");
                scanf("%lf", &dividend);
                printf("Kolko godini: ");
                scanf("%lf", &godini);
                
                // Пресмятане
                pari = akcii * kupuvane;
                kraino = akcii * prodavane + pari * (dividend/100) * godini;
                
                // Показване на резултат
                printf("Investirani pari: %.2f lv\n", pari);
                printf("Kraina stoinost: %.2f lv\n", kraino);
                printf("Pechalba: %.2f lv\n\n", kraino - pari);
                break;
            }
                
            case 4: {
                // Месечен депозит
                double mesecno;
                printf("Mesechna vnoska: ");
                scanf("%lf", &mesecno);
                printf("Godishna lihva v procenti: ");
                scanf("%lf", &lihva);
                printf("Kolko godini: ");
                scanf("%lf", &godini);
                
                // Пресмятане
                double mesechna_lihva = lihva / 1200;
                int meseci = godini * 12;
                kraino = mesecno * ((pow(1 + mesechna_lihva, meseci) - 1) / mesechna_lihva);
                pari = mesecno * meseci;
                
                // Показване на резултат
                printf("Vneseni pari: %.2f lv\n", pari);
                printf("Kraina suma: %.2f lv\n", kraino);
                printf("Pechalba: %.2f lv\n\n", kraino - pari);
                break;
            }
                
            case 5:
                // Изход
                printf("Dovizdane!\n");
                return 0;
                
            default:
                // Грешка
                printf("Greshka! Probvai pak.\n\n");
        }
    }
    
    return 0;
}