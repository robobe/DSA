#include <memory>

struct Node
{
    int data;
    Node* link;
    Node(int data): data(data), link(nullptr){}
};

class LinkList
{
    private:
        Node* head;
        Node* last;
    public:
        LinkList();
        void Append(int data);
        void Traverse();
        int Find(int data);
};