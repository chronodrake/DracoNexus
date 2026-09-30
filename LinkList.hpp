#pragma once
namespace draco::nexus
{
    template <typename T>
    class LinkList
    {
    public:
        LinkList(int length)
        {
            this->head = new LinkNode();
            this->tail = this->head;
        }

        ~LinkList();

        // 拷贝添加链表元素
        LinkList &append(T nextData)
        {
            tail->next = new LinkNode(nextData);
            tail = tail->next;
            return *this;
        }

        // 重载运算符+添加元素
        LinkList &operator+(T nextData)
        {
            return this->append(nextData);
        }

        // 合并两个链表 重载运算符+ 返回一个新链表
        LinkList &operator+(LinkList &other)
        {
            LinkList mergedList();
            return
        }

    private:
        int length;
        LinkList *head;
        LinkList *tail;

        class LinkNode
        {
        public:
            LinkNode(T data)
            {
                this->data = data;
                this->next = nullptr;
            }
            LinkNode()
            {
                this->data = NULL;
                this->next = nullptr;
            }

        private:
            T data;
            LinkNode *next;
        }
    };
}
