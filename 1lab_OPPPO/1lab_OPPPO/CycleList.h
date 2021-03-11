#ifndef CYCLELIST_H
#define CYCLELIST_H

#include "iostream"
#include "Forest.h"
#include "fstream"

struct ForestElement
{
	Forest forestElement;
};

struct Node
{
	ForestElement forestElement;
	Node* next, *prev;
};

class List
{
private:
    Node* first;
    Node* last;
public:
    List()             
    {
        first = NULL;
        last  = NULL;
    }

    ~List()            
    {
        while(first != last)
        {
            Node* temp = first;
            first = first ->prev;
            delete temp;
        }
        delete last;
    }

void addNewElement(Forest& forestObject)   
{
    /*if(forestObject.getType() == "tree")
        std::cout << forestObject.getAge() /*<< " " << forestObject.getAge() << " " << fgetName() << std::endl;*/
    Node* newNode = new Node;
	ForestElement* newElement = new ForestElement;
	newElement->forestElement = forestObject;
    newNode->forestElement = *newElement;
    /*if(forestObject.getType() == "tree")
        std::cout << newNode->forestElement.forestElement.getAge();*/
     
    if(first)
    {
          newNode ->prev = first;
          first ->next =  newNode;
    } 
    else
        last = newNode;
 
    newNode ->next = last;
    last ->prev = newNode;
    first = newNode;
    //std::cout << newNode->forestElement->forestElement.getType() << std::endl;
}
 
void printList()             
{
    Node* node = last;
    if(first)
    do
	{
        if(node->forestElement.forestElement.getType() == "tree")
            std::cout << "Type is: " << node->forestElement.forestElement.getType() << " age is: " << node->forestElement.forestElement.getAge() << 
                " name is: " << node->forestElement.forestElement.getName() << ";"<< std::endl;
        else if(node->forestElement.forestElement.getType() == "bush")
            std::cout << "Type is: " << node->forestElement.forestElement.getType() << " month is: " << node->forestElement.forestElement.getMonth() << 
                " name is: " << node->forestElement.forestElement.getName() << ";"<< std::endl;
       node = node->next;
    } while(node != last);
 
}

Node* find(std::string name)           
{
    Node* temp = first;
    if(first)
        do
        {
        if(temp->forestElement.forestElement.getName() == name)
            return temp;

        temp = temp ->prev;
        } while(temp  != first);

        temp = NULL;
        return temp;
}

void deleteNode(Node* temp)   
{
    if(first)                  
    {
        if(temp ->next == temp)    
        {
            first = NULL;
            last  = NULL;
        }
        else
        {
            if(temp == last)     
                last = last ->next;

            if(temp == first)     
                first = first ->prev;

        (temp ->next) ->prev = temp ->prev;
        (temp ->prev) ->next = temp ->next;

        delete temp;
        }
    }
}

void sortlist()                        
{
    std::string tempdata;
    Node* temp1 = first;

    int n = howmany_links();

    for(int x = 0; x<n-1; x++)
    {
        Node* temp2 = temp1 ->prev;

    for(int i = x; i<n-1; i++)
    {
        if((temp1 ->forestElement.forestElement.getName()).length() > (temp2 ->forestElement.forestElement.getName()).length())
        {
            tempdata = temp2 ->forestElement.forestElement.getName();
            temp2 ->forestElement.forestElement.setName(temp1 ->forestElement.forestElement.getName());
            temp1 ->forestElement.forestElement.setName(tempdata);
        }
        temp2 = temp2 ->prev;
    }
        temp1 = temp1 ->prev;
    }
}

int howmany_links()             
{
    if(first)
    {
        Node* temp = first;
        int i = 0;
        do
        {
            temp = temp ->prev;
            i++;
        } while(temp  != first);
        return i;
    }
    return 0;
}

void printOut(char *OutDir)
{
    std::ofstream dataOut(OutDir, std::ios_base::out | std::ios_base::trunc);

    Node* node = last;
    if(first)
    do
    {
        if(node->forestElement.forestElement.getType() == "tree")
            dataOut << "Type is: " << node->forestElement.forestElement.getType() << " age is: " << node->forestElement.forestElement.getAge() << 
                " name is: " << node->forestElement.forestElement.getName() << ";" << "\n";
        else if(node->forestElement.forestElement.getType() == "bush")
            dataOut << "Type is: " << node->forestElement.forestElement.getType() << " month is: " << node->forestElement.forestElement.getMonth() << 
                " name is: " << node->forestElement.forestElement.getName() << ";"<< "\n";
    node = node->next;
    } while(node != last);
    dataOut.close();
}

};

#endif