// Project 1-2
// queue : dynamic array
// QueueType.hpp

#ifndef QUEUETYPE_H
#define QUEUETYPE_H
#include <iostream>

template<class ItemType>
class QueueType{
private:
    ItemType *  data;
    int         front;
    int         rear;
    int         maxQueue;

public:
    QueueType(int maxQue);
    ~QueueType();

    void        enqueue(ItemType value);
    ItemType    dequeue( );
    
    void        clear( );
    bool        isFull( ) const;
    bool        isEmpty( ) const;

    void        printQueue( ) const;

};


template<class ItemType>
QueueType<ItemType>::QueueType(int maxQue){
    maxQueue = maxQue + 1; // circular queue에서 isFull과 isEmpty를 구분하기 위해. front자리에 reserved가 없으면 empty와 full모두 rear+1 == front가 된다.
    front = maxQueue - 1;
    rear= maxQueue - 1;
    data = new ItemType[maxQueue];
}

template<class ItemType>
QueueType<ItemType>::~QueueType() {
    delete[] data;
}


template<class ItemType>
void QueueType<ItemType>::enqueue(ItemType newItem) {
    if (isFull()) return;

    rear = (rear + 1) % maxQueue;
    data[rear] = newItem;
}

template<class ItemType>
ItemType QueueType<ItemType>::dequeue() {
    if (isEmpty()) return NULL;
    
    front = (front + 1) % maxQueue;
    return data[front];
}


template<class ItemType>
bool QueueType<ItemType>::isFull( ) const {
    return ( (rear + 1) % maxQueue == front );
}


template<class ItemType>
bool QueueType<ItemType>::isEmpty( ) const {
    return ( rear == front );
}

template<class ItemType>
void QueueType<ItemType>::clear( ){
    front = maxQueue - 1;
    rear= maxQueue - 1;
}



template<class ItemType>
void QueueType<ItemType>::printQueue() const{
    if(isEmpty()){
        std::cout << "[EMPTY QUEUE] " << std::endl;
        return;
    }


    std::cout << "[ ";
    
    int i = front;
    do{
        i = (i + 1) % maxQueue;
        std::cout << data[i] << "\t";
    } while(i != rear);

    std::cout << " ]" << std::endl;
}


#endif /* QUEUETYPE_H */
