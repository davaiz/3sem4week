# 3sem4week
#include <stdlib.h>
#include <iostream>

struct Node       //Структура являющаяся звеном списка
{
    long x;
    long y;
    Node *next;
    Node *prev; //Указатели на адреса следующего и предыдущего элементов списка
};


struct List   //Создаем тип данных Список
{
    Node *head;
    Node *tail;  //Указатели на адреса начала списка и его конца
};

void add(List *list, long x, long y )
{
    Node *temp = new Node(); // Выделение памяти под новый элемент структуры
    temp->next = nullptr;       // Указываем, что изначально по следующему адресу пусто
    temp->x = x;
    temp->y = y;             // Записываем значение в структуру

    if ( list->head != nullptr ) // Если список не пуст
    {
        temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
        list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
        list->tail = temp;       //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->prev = nullptr; // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
    }
}
void print( List * list )
{
    Node * temp = list->head;  // Временно указываем на адрес первого элемента
    while( temp != nullptr )      // Пока не встретим пустое значение
    {
        std::cout << temp->x << temp->y <<" "; //Выводим значение на экран
        temp = temp->next;     //Смена адреса на адрес следующего элемента
    }
    std::cout<<"\n";
}
int main()
{
    struct List list;
    for (int i = 0; i < 21; i++)
    {
        long x = random();
        long y = random();
        add(&list, x, y);
    }
    print(&list);

}
