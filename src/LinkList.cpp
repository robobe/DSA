#include <iostream>
#include <LinkList.hpp>

LinkList::LinkList()
{
    head = nullptr;
    last = nullptr;
}

void LinkList::Append(int data)
{
    auto node = new Node(data);

    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        last->link = node;
    }

    last = node;
}

void LinkList::Traverse()
{
    auto current = head;
    while (current->link)
    {
        std::cout << current->data << std::endl;
        current = current->link;
    }
    // print last one
    std::cout << current->data << std::endl;
}

int LinkList::Find(int data)
{
    int pos = 0;
    auto current = head;
    while (current)
    {
        if (current->data == data)
        {
            return pos;
        }
        current = current->link;
        pos += 1;
    }

    return -1;
}
