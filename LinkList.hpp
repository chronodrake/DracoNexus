#pragma once
namespace draco::nexus
{
    template <typename T>
    // 数据结构：链表，使用切片索引
    class LinkList
    {
    public:
        // 输入长度构造
        LinkList(int length)
        {
            this->head = new LinkNode;
            this->tail = this->head;
            this->length = length;
        }

        // 直接构造
        LinkList()
        {
            this->head = new LinkNode;
            this->tail = nullptr;
            this->length = 0;
        }

        // 拷贝构造
        LinkList(LinkList & other) const
        {
            this->head = new LinkNode;
            this->length = other.length;
            LinkNode * curNode = other.head->next;
            LinkNode * curNodeCopy = this->head;

            while(curNode != nullptr)
            {
                curNodeCopy->next = new LinkList(curNode->data);
                curNode = curNode->next;
                curNodeCopy = curNodeCopy->next;
            }

            this->tail = curNodeCopy;
        }

        // 移动构造
        LinkList(LinkList && other) const
        {
            this->head = other.head;
            this->tail = other.tail;
            this->length = other.length;

            other.head = nullptr;
            other.tail = nullptr;
            other.length = 0;
        }

        // 链表的析构函数
        ~LinkList()
        {
            LinkNode curNode = this->head;

            if(curNode != nullptr){
                LinkNode nextNode = this->head->next;
            }
            else
            {
                nextNode = nullptr;
            }

        
            while(curNode != nullptr)
            {
                delete(curNode);
                curNode = nextNode;
                if(nextNode != nullptr)
                {
                    nextNode = nextNode->next;
                }
            }
        }

        // 交换两个链表的所有权
        LinkList & swap(LinkList & other)
        {
            using std::swap;
            swap(this->head,other.head);
            swap(this->tail,other.tail);
            swap(this->length,other.length);

            return *this;
        }

        // 拷贝赋值
        LinkList & operator=(LinkList & other) const
        {
            // 这里我们使用委托构造，tmp会执行析构让我们的资源死掉
            LinkList tmp(other);
            this->swap(tmp);
            return *this;
        }

        // 移动赋值
        LinkList & operator=(LinkList && other) const
        {
            this->length = other.length;
            this->tail = other.tail;
            this->head = other.head;

            other.head = nullptr;
            other.tail = nullptr;
            other.length = 0;

            return *this;
        } 

        // 拷贝添加链表元素
        LinkList &append(T nextData)
        {
            tail->next = new LinkNode(nextData);
            tail = tail->next;
            this->length++;
            return *this;
        }

        // 重载运算符+=添加元素
        LinkList &operator+=(T nextData)
        {
            return this->append(nextData);
        }

        // 合并两个链表 重载运算符+ 返回一个新链表
        LinkList operator+(LinkList &other) const
        {
            LinkList mergedList();
            // 为什么这里要开在栈上：CPP有RVO返回值优化，直接会在返回栈帧上面开辟新对象，不用担心拷贝成本，生命周期管理由栈帧决定
            LinkNode *curNode = other.head;
            LinkNode *curNodeCopy = mergedList.head;
            LinkNode *lastNodeCopy = this->head;

            while (curNode != nullptr)
            {
                if (curNodeCopy = nullptr)
                {
                    curNodeCopy = new LinkNode;
                }

                curNodeCopy->data = curNode->data;

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

                curNodeCopy->data = curNode->data;

                curNode = curNode->next;
                lastNodeCopy = curNodeCopy;
                curNodeCopy = curNodeCopy->next;
            }
            mergedList.length = this->length + other.length;
            mergedList.tail = lastNodeCopy;

            return mergedList;
        }

        // 合并两个链表，使用成员函数，将填入的链表的所有权移交到这里(所以在调用这个函数的时候最好使用移动语义，否则左值将面临一次深拷贝)
        LinkList &merge(LinkList & other)
        {
            if (other.head == nullptr || other->next = nullptr)
            {
                return *this;
            }

            this->tail->next = other->head->next;
            this->tail = other->tail;
            this->length = other->length + this->length;

            // 这里有一个关键的细节，当other离开作用域的时候，会触发析构
            // 为了防止other与this生命周期不一致，我们需要将other的头指针置空，使其析构函数不会释放已经移交给this的资源
            other->head = nullptr;
            other->tail = nullptr;
            other->length = 0;

            return *this;
        }

        // 合并两个链表，将另外一个链表的所有权移交（+=的语义）
        LinkList & operator+=(LinkList & other) const
        {
            return this->merge(other);
        }

        T & operator[](int index)
        {

        #ifdef OPEN
             if(index + 1 > length || index + 1 < 1)
             {
                throw("index_out_of_range")
             }
        #endif

            if(this->head != nullptr && this->head->next != nullptr)
            {
                LinkList curNode = this->head->next;
    
                for(int i = 0;i < length + 1;i++)
                {
                    curNode = curNode->next;
                }

                return curNode->data;
            }
        
        #ifdef OPEN
            else
            {
                throw();
            }
        #endif
        }

    private:
        int length = 0;
        LinkList *head = nullptr;
        LinkList *tail = nullptr;

        struct LinkNode
        {
            LinkNode(LinkNode * next,T data):
            next(next),
            data(data){}

            LinkNode(T data):
            next(nullptr),
            data(data){}
            
            LinkNode(LinkNode * next):
            next(next),
            data(NULL){}
        
            LinkNode *next;
            T data;
        };
    };
}
