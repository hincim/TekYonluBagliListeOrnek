#include <bits/stdc++.h> 
#include <malloc.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* start = NULL;
struct Node* last = NULL;

struct Node* yeniDugumOlustur(int data)
{
    struct Node* gecici = (struct Node*)malloc(sizeof(struct Node));
    // BELLEKTE DÜÐÜM OLUÞTURUR.
    gecici->data = data;
    gecici->next = NULL;
    return gecici;
}

void basaekle(int data)
{
    struct Node* ilk = yeniDugumOlustur(data);
    if(start == NULL)
        start = ilk;
    else
    {
        struct Node* temp = start;
        start = ilk;
        ilk->next = temp;
    }
}

void sonElemaniSil()
{
    if(start == NULL)
        return;
    struct Node* temp = start;
    while(temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void tersCevir()
{
    struct Node* prev = NULL;
    struct Node* current = start;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}
void yazdir(struct Node* node)
{

    cout<< "\n"<<node->data;
    node = node->next;
    while(node != NULL)
    {
        cout<< " "<< node->data;
        node = node->next;
    }
    cout<<" NULL";
}

void birerAtlamaliYazdir(struct Node* node){

    cout<< "\n"<<node->data;
    node = node->next->next;
    while(node != NULL)
    {
        cout<< " "<< node->data;
        node = node->next->next;
    }
    cout<<" NULL";
}

int main() {
    basaekle(2);
    basaekle(7);
    basaekle(5);
    basaekle(8);
    basaekle(4);  
    yazdir(start);
    
	sonElemaniSil();
  	yazdir(start);
    
 	//tersCevir();
  	//birerAtlamaliYazdir(start);
  	
  	return 0;
}
