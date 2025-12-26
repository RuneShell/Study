    // Project 2-2
    // queue : singly linked lisk
    // QueueType.hpp

    #ifndef QUEUETYPE_H
    #define QUEUETYPE_H
    #include <iostream>

    template <class ItemType> // StackType.hpp의 NodeType과 중복정의됨
    struct NodeType{
        ItemType value;
        NodeType * next;
    };

    template <class ItemType>
    class QueueType{
    private:
        NodeType<ItemType> * pFront;
        NodeType<ItemType> * pRear;
    
    public: 
        QueueType();
        ~QueueType();

        void copyQueue(NodeType<ItemType>*& copy, const NodeType<ItemType>* originalQueue);
        void operator=(const QueueType<ItemType>& originalQueue);
    
        void clear();
        void enqueue(ItemType newItem);
        ItemType dequeue();

        int size() const;
        bool isFull() const;
        bool isEmpty() const;
    
        void Print();
    };


    template <class ItemType>
    QueueType<ItemType>::QueueType(){
        pFront = nullptr;
        pRear = nullptr;
    }

    template <class ItemType>
    QueueType<ItemType>::~QueueType(){    
        clear();
    }

    template <class ItemType>
    void QueueType<ItemType>::copyQueue(NodeType<ItemType>*& copy, const NodeType<ItemType>* originalQueue) {
        if (originalQueue == NULL) copy = NULL;
        else        {
            copy = new NodeType<ItemType>;
            copy->value = originalQueue->value;
            copyQueue(copy->next, originalQueue->next);
        }
    }

    template <class ItemType>
    void QueueType<ItemType>::operator=(const QueueType<ItemType>& originalQueue) {
        if (&originalQueue == this) return;
        this->clear();
        
        copyQueue(pFront, originalQueue.pFront);
    }

    template <class ItemType>
    void QueueType<ItemType>::clear(){
        NodeType<ItemType>* tempNode = pFront;
        while (tempNode != nullptr) {
            pFront = tempNode->next;
            delete tempNode;
            tempNode = pFront;
        }

        pRear = nullptr;
    }

    template <class ItemType>
    void QueueType<ItemType>::enqueue(ItemType newItem){
        if (isFull()) return;

        NodeType<ItemType>* newNode = new NodeType<ItemType>{ newItem, nullptr }; // pRear에 붙일 거니까 nullptr

        if (isEmpty()) {
            pFront = newNode;
            pRear = newNode;
        }
        else {
            pRear->next = newNode;
            pRear = newNode;
        }

    }

   template <class ItemType>
   ItemType QueueType<ItemType>::dequeue(){
        if (isEmpty()) return NULL;
        ItemType result = pFront->value;

        NodeType<ItemType>* tempNode = pFront;
        
        pFront = tempNode->next;
        if(isEmpty()) pRear = nullptr; // front가 비었으면 rear도 빈 것이다.

        delete tempNode;
        return result;
    }


    template <class ItemType>
    int QueueType<ItemType>::size() const{
        int len = 0;
        NodeType<ItemType>* tempNode = pFront;
        while (tempNode != nullptr) {
            len++;
            tempNode = tempNode->next;
        }
    
        return len;
    }

    template <class ItemType>
    bool QueueType<ItemType>::isEmpty() const{
        return (pFront == nullptr);
    }

    template <class ItemType>
    bool QueueType<ItemType>::isFull() const{
        NodeType<ItemType> * newNode;
        try {
            newNode = new NodeType<ItemType>;
            delete newNode;
            return false;
        }
        catch (std::bad_alloc exception){
            return true;
        }
    }

    template <class ItemType>
    void QueueType<ItemType>::Print(){
        if(isEmpty()){
            std::cout << "[EMPTY QUEUE]" << std::endl;
            return;
        }
    
        std::cout << "(front)\t[";
        NodeType<ItemType> * tempPtr = pFront;
    
        while(tempPtr != nullptr){
            std::cout << tempPtr -> value << "\t";
            tempPtr = tempPtr->next;
        }
        std::cout << "]\t(rear)" << std::endl;
    }


    #endif
