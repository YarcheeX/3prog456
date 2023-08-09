#include <iostream>
#include "blogger.h"
#include <locale.h>
#include <Windows.h>
#include <string>


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color f0");
    
    
    
    /*работа со статическими полями и методами*/
    //printf("Кол-во блоггеров: %d\n", blogger::getstat());
    //blogger b1;
    //printf("Кол-во блоггеров: %d\n", b1.getstat());
    //blogger* b2 = new blogger();
    //blogger* b3 = new blogger();
    //printf("Кол-во блоггеров: %d\n", b2->getstat());
    //delete b2;
    //printf("Кол-во блоггеров: %d\n", b3->getstat());
    //delete b3;
    //printf("Кол-во блоггеров: %d\n", blogger::getstat());
    
    
    
    /*возвраты значений*/
    //Time t(1, 2, 3);
    //int t_val[3];
    //t.get_time(t_val[0], t_val[1], t_val[2]);
    //printf("Time: ");
    //for (int i = 0; i < 3; i++) {
    //    printf("%d ", t_val[i]);
    //}
    //
    //date d(4, 5, 2015);
    //int d_val[3];
    //d.get_date(&d_val[0], &d_val[1], &d_val[2]);
    //printf("date: ");
    //for (int i = 0; i < 3; i++) {
    //    printf("%d ", d_val[i]);
    //}

    

    //перегрузка +
    //Time t1(1, 45, 50);
    //Time t2(0, 30, 20);
    //в сумме должно получиться 2:16:10
    //Time t3 = t1 + t2;
    //t3.print_time();



    //перегрузка ++
    //date d1(31, 1, 2018); 
    //date d2 , d3(d1);
    //постфикс
    //d2 = d1++;
    //d2 должно быть равно изначальному значению d1, 
    //а дата d будет обозначать следующий день
    //d1.print_date();
    //d2.print_date();
    //префикс
    //d2 = ++d3;
    //теперь d2 и d3 будут обозначать 1.2.2018
    //d2.print_date();
    //d3.print_date();




}


