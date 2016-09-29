#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node       //Структура являющаяся звеном списка
{
    int x;
    int y;  //Значение x будет передаваться в список
    Node *next, *prev; //Указатели на адреса следующего и предыдущего элементов списка
};


struct List   //Создаем тип данных Список
{
    Node *head;
    Node *tail;  //Указатели на адреса начала списка и его конца
};


void add( List *list, int x, int y )
{
    Node *temp = new Node(); // Выделение памяти под новый элемент структуры
    temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
    temp->x = x;
    temp->y = y;// Записываем значение в структуру

    if ( list->head != NULL ) // Если список не пуст
    {
        temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле x, y
        list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
        list->tail = temp;       //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->prev = NULL; // Предыдущий элемент указывает в пустоту
        list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
    }
}

void print( List * list )
{
    Node * temp = list->head;  // Временно указываем на адрес первого элемента
    while( temp != NULL )      // Пока не встретим пустое значение
    {
        cout << temp->x <<";" <<temp->y <<" " ;//Выводим значение на экран
        temp = temp->next;     //Смена адреса на адрес следующего элемента
    }
    cout<<"\n";
}
int search( List * list, int x, int y)
{
    Node * temp = list->head;
    int t = 0;
    while((temp->x != x) and (temp->y !=y) )
        temp = temp->next;
        t++;
    return(t);

}

int main() {
    List list;
    list.head = list.tail = NULL;
    for (int i = 0; i<21; i++)
    {
        int x = rand();
        int y = rand();
        add( &list, x, y );

    }
    add( &list, 1, 1 );
    print( &list );
    int s = search( &list, 1, 1);
    cin >> s;
    return 0;
}
