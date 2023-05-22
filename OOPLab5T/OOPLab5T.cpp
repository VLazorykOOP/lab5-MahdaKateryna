// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>

// Ваші файли загловки 
//
#include "task1.h"
#include "task2.h"
#include "task3.h"

void menutask1()
{
    Quad* quad1 = new Quad(5, 7, 6, 8);
    Rectangle* rect1 = new Rectangle(4, 9);
    Square* square1 = new Square(5);

    quad1->print();
   
    std::cout << "P: " << quad1->P() << std::endl;

    rect1->print();
    std::cout << "S: " << rect1->S() << std::endl;
    std::cout << "P: " << rect1->P() << std::endl;

    square1->print();
    std::cout << "S: " << square1->S() << std::endl;
    std::cout << "P: " << square1->P() << std::endl;

    delete quad1;
    delete rect1;
    delete square1;

}
void menutask2()
{
    BinaryTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Breadth-First Traversal: ";
    tree.breadthFirstTraversal();

    cout << "Reverse Traversal: ";
    tree.reverseTraversal(tree.root);
    cout << endl;
}

void menutask3() 
{
    String str("bebebububebe");
    cout << str << endl;

    DerivedString derivedStr("kitik");
    cout << derivedStr << endl;

    DerivedString derivedStr2("frog");
    cout << derivedStr2 << endl;

    DerivedString derivedStr3(derivedStr);
    cout << derivedStr3 << endl;

    DerivedString derivedStr4;
    cin >> derivedStr4;
    cout << derivedStr4 << endl;

    derivedStr4 = derivedStr3;
    cout << derivedStr4 << endl;
}

int main()
{
    std::cout << " Lab #5  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту

    int choose = 0;
    do
    {

        cout << "Choose task: " << endl;
        cin >> choose;
        system("cls");

        switch (choose)
        {
        case 1:
            system("cls");
            menutask1();
            break;
        case 2:
            system("cls");
            menutask2();
            break;
        case 3:
            system("cls");
            menutask3();
            break;
        default:
            system("cls");
            break;
        }
    } while (choose != 0);
}
