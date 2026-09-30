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
            this->length++;
            return *this;
        }

        // 重载运算符+添加元素
        LinkList &operator+(T nextData)
        {
            return this->append(nextData);
        }

        // 合并两个链表 重载运算符+ 返回一个新链表
        LinkList operator+(LinkList &other) const
        {
            LinkList mergedList();
            // 为什么这里要开在栈上：CPP有RVO返回值优化，直接
            LinkNode *curNode = this->head;
            LinkNode *curNodeCopy = mergedList.head;
            LinkNode * lastNodeCopy = this->head;

            while (curNode != nullptr)
            {
                if (curNodeCopy = nullptr)
                {
                    curNodeCopy = new LinkNode;
                }

                *curNodeCopy = *curNode;

                curNode = curNode->next;
                lastNodeCopy = curNodeCopy;
                curNodeCopy = curNodeCopy->next;
            }

            curNode = other.head->next;

            while (curNode != nullptr)
            {
                if (curNodeCopy = nullptr)
                {
                    curNodeCopy = new LinkNode;
                }

                *curNodeCopy = *curNode;

                curNode = curNode->next;
                curNodeCopy = curNodeCopy->next;
            }
            mergedList.length = this->length + other.length;
            mergedList.tail

            return mergedList;
        }

    private:
        int length;
        LinkList *head;
        LinkList *tail;

        struct LinkNode
        {
            LinkNode *next;
            T data;
        };
    };
}
