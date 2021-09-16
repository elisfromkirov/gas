#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <cassert>
#include <cstdint>
#include <new>

template <typename T>
class List {
private:
    static const uint32_t kNoPrevNode = 0xf0000000;

    struct Node {
        uint32_t prev;
        uint32_t next;
        T        value;
    };

public:
    class Iterator {
    public:
        Iterator(const Iterator& other);
        Iterator(List* list, uint32_t node);

        ~Iterator();

        Iterator& operator=(const Iterator& other);

        Iterator& operator++();
        Iterator operator++(int unused);

        Iterator& operator--();
        Iterator operator--(int unused);

        T& operator*();
        const T& operator*() const;

        T* operator->();
        const T* operator->() const;

        uint32_t GetNode() const;

        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return lhs.node_ == rhs.node_;
        }
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return lhs.node_ != rhs.node_;
        }

    private:
        List<T>* list_;
        uint32_t node_;
    };

    friend class Iterator;

public:
    List(uint32_t capacity);

    ~List();

    Iterator Begin();
    Iterator End();

    uint32_t GetSize() const;
    bool     IsEmpty() const;

    Iterator Insert     (const T& value, Iterator prev, Iterator next);
    Iterator InsertFront(const T& value);
    Iterator InsertBack (const T& value);
    
    void Erase     (Iterator iterator);
    void EraseFront();
    void EraseBack ();

private:
    uint32_t Insert(const T& value, uint32_t prev, uint32_t next);
    uint32_t Erase (uint32_t node);

    Node*    data_;
    uint32_t size_;
    uint32_t capacity_;

    uint32_t head_;
    uint32_t tail_;

    uint32_t free_;
};

template <typename T>
using ListIterator = typename List<T>::Iterator;

// -------------------------------------------------------------------------- //

template <typename T>
List<T>::List(uint32_t capacity)
        : data_{nullptr}, size_{0}, capacity_{capacity}, head_{0}, tail_{0}, free_{1} {
    data_ = new(std::nothrow) Node[capacity];
    assert(data_);

    for (uint32_t i = 1; i < capacity_; ++i) {
        data_[i].next = i + 1;
        data_[i].prev = kNoPrevNode;
    }
}

template <typename T> 
List<T>::~List() {
    assert(data_);
    
    delete[] data_;
}

template <typename T>
ListIterator<T> List<T>::Begin() {
    return Iterator{this, head_};
}

template <typename T> 
ListIterator<T> List<T>::End() {
    return Iterator{this, 0};
}

template <typename T> 
uint32_t List<T>::GetSize() const {
    return size_;
}

template <typename T> 
bool List<T>::IsEmpty() const {
    return size_ == 0;
}

template <typename T> 
ListIterator<T> List<T>::Insert(const T& value, Iterator prev, Iterator next) {
    return Iterator{this, Insert(value, prev.GetNode(), next.GetNode())};
}

template <typename T> 
ListIterator<T> List<T>::InsertFront(const T& value) {
    head_ = Insert(value, 0, head_);
    if (size_ == 1) {
        tail_ = head_;
    }

    return Iterator{this, head_};
}

template <typename T>
ListIterator<T> List<T>::InsertBack(const T& value) {
    tail_ = Insert(value, tail_, 0);
    if (size_ == 1) {
        head_ = tail_;
    }

    return Iterator{this, tail_};
}

template <typename T> 
void List<T>::Erase(Iterator iterator) {
    Erase(iterator.GetNode());
}

template <typename T> 
void List<T>::EraseFront() {
    Erase(head_);
}

template <typename T> 
void List<T>::EraseBack() {
    Erase(tail_);
}

template <typename T>
uint32_t List<T>::Insert(const T& value, uint32_t prev, uint32_t next) {
    assert(data_);
    assert(prev < capacity_);
    assert(next < capacity_);

    uint32_t result = free_;
    free_ = data_[result].next;
    
    data_[result].value = value;
    data_[result].prev  = prev;
    data_[result].next  = next;

    data_[next].prev = result;
    data_[prev].next = result;

    size_++;
    return result;
}

template <typename T>
uint32_t List<T>::Erase(uint32_t node) {
    assert(data_);
    assert(node != 0 && node < capacity_);
    assert(data_[node].prev != kNoPrevNode);

    data_[data_[node].next].prev = data_[node].prev;
    data_[data_[node].prev].next = data_[node].next;

    if (node == tail_) {
        tail_ = data_[node].prev;
    }
    if (node == head_) {
        head_ = data_[node].next;
    }

    data_[node].prev = kNoPrevNode;
    data_[node].next = free_;
    free_ = node;

    size_--;
    return node;
}

// -------------------------------------------------------------------------- //
    
template <typename T>
List<T>::Iterator::Iterator(const Iterator& other) 
    : list_{other.list_}, node_{other.node_} {}
        
template <typename T>
List<T>::Iterator::Iterator(List* list, uint32_t node) 
    : list_{list}, node_{node} {}

template <typename T>
List<T>::Iterator::~Iterator() {}

template <typename T>
ListIterator<T>& List<T>::Iterator::operator=(const Iterator& other) {
    if (this == &other) {
        return *this;
    }

    list_ = other.list_;
    node_ = other.node_;

    return *this;
}

template <typename T>
ListIterator<T>& List<T>::Iterator::operator++() {
    node_ = list_->data_[node_].next;
    return *this;
}

template <typename T>
ListIterator<T> List<T>::Iterator::operator++(int unused) {
    Iterator iterator{*this};
    ++(*this);
    return iterator;
}

template <typename T>
ListIterator<T>& List<T>::Iterator::operator--() {
    node_ = list_->data_[node_].prev;
    return *this;
}

template <typename T>
ListIterator<T> List<T>::Iterator::operator--(int unused) {
    Iterator iterator{*this};
    ++(*this);
    return iterator;
}

template <typename T>
T& List<T>::Iterator::operator*() {
    return list_->data_[node_].value;
}

template <typename T>
const T& List<T>::Iterator::operator*() const {
    return list_->data_[node_].value;
}

template <typename T>
T* List<T>::Iterator::operator->() {
    return &list_->data_[node_].value;
}

template <typename T>        
const T* List<T>::Iterator::operator->() const {
    return &list_->data_[node_].value;
}

template <typename T>
uint32_t List<T>::Iterator::GetNode() const {
    return node_;
}

#endif // __LIST_HPP__
