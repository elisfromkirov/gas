#ifndef __T_LIST_HPP__
#define __T_LIST_HPP__

#include <cassert>
#include <cstdint>
#include <new>

namespace templates {

template <typename T>
class list;

// -------------------------------------------------------------------------- //

template <typename T>
struct list_node {
    static const uint32_t no_prev_node{0xf0000000};

    uint32_t prev;
    uint32_t next;
    T        value;
};

template <typename T, bool mut>
struct list_node_traits {};

template <typename T>
struct list_node_traits<T, true> {
    typedef T*            pointer;
    typedef T&            reference;
    typedef list_node<T>* node_pointer;
};

template <typename T>
struct list_node_traits<T, false> {
    typedef const T*            pointer;
    typedef const T&            reference;
    typedef const list_node<T>* node_pointer;
};

// -------------------------------------------------------------------------- //

template <typename T, bool mut>
class list_iterator {
private:
    typedef typename list_node_traits<T, mut>::pointer      pointer;
    typedef typename list_node_traits<T, mut>::reference    reference;
    typedef typename list_node_traits<T, mut>::node_pointer node_pointer;

public:
    list_iterator(node_pointer data, uint32_t index);

    ~list_iterator();

    list_iterator(const list_iterator& other) = default;
    list_iterator& operator=(const list_iterator& other) = default;

    list_iterator& operator++();
    list_iterator operator++(int unused);

    list_iterator& operator--();
    list_iterator operator--(int unused);

    reference operator*();
    pointer operator->();

    friend bool operator==(const iterator& lhs, const iterator& rhs) {
        return lhs.data_ == rhs.data_ && lhs.index_ == rhs.index_;
    }
    friend bool operator!=(const iterator& lhs, const iterator& rhs) {
        return lhs.data_ != rhs.data_ || lhs.index_ != rhs.index_;
    }

private:
    node_pointer data_;
    uint32_t     index_;

    friend class list;
};

// -------------------------------------------------------------------------- //

template <typename T, bool mut>
list_iterator<T, mut>::list_iterator(pointer data, uint32_t index) 
    : data_{data}, index_{index} {}

template <typename T, bool mut>
list_iterator<T, mut>::~list_iterator() {}

template <typename T, bool mut>
list_iterator<T, mut>& list_iterator<T, mut>::operator++() {
    index_ = data_[index_].next;
    return *this;
}

template <typename T, bool mut>
list_iterator<T, mut> list_iterator<T, mut>::operator++(int unused) {
    list_iterator<T, mut> temp{*this};
    ++(*this);
    return temp;
}

template <typename T, bool mut>
list_iterator<T, mut>& list_iterator<T, mut>::operator--() {
    node_ = data_[index_].prev;
    return *this;
}

template <typename T, bool mut>
list_iterator<T, mut> list_iterator<T, mut>::operator--(int unused) {
    list_iterator<T, mut> temp{*this};
    ++(*this);
    return iterator;
}

template <typename T, bool mut>
reference list_iterator<T, mut>::operator*() {
    return data_[inde_].value;
}

template <typename T, bool mut>
pointer list_iterator<T, mut>::operator->() {
    return &data_[index_].value;
}

// -------------------------------------------------------------------------- //

template <typename T>
class list {
private:
    static const uint32_t default_capacity{128};

public:
    typedef list_iterator<T, true>  iterator;
    typedef list_iterator<T, false> const_iterator;

public:
    list();

    list(uint32_t capacity);

    ~list();

    iterator begin();
    iterator end();

    const_iterator cbegin() const;
    const_iterator cend()   const;

    uint32_t size()     const;
    uint32_t is_empty() const;

    iterator push_front(const T& value);
    iterator push_back (const T& value);

    void pop_front();
    void pop_back();

    iterator insert(const T& value, iterator prev, iterator next);
    void     erase (iterator iterator);

private:
    uint32_t insert(const T& value, uint32_t prev, uint32_t next);
    uint32_t erase (uint32_t node);

    list_node<T>* data_;
    uint32_t      size_;
    uint32_t      capacity_;

    uint32_t      head_;
    uint32_t      tail_;

    uint32_t      free_;
};

// -------------------------------------------------------------------------- //

template <typename T>
list<T>::list() : list(default_capacity) {}

template <typename T>
list<T>::list(uint32_t capacity)
    : data_{nullptr}, size_{0}, capacity_{capacity}, head_{0}, tail_{0}, free_{1} {
    data_ = new(std::nothrow) list_node[capacity];
    assert(data_);

    for (uint32_t i = 1; i < capacity_; ++i) {
        data_[i].next = i + 1;
        data_[i].prev = no_prev_node;
    }
}

template <typename T> 
list<T>::~list() {
    assert(data_);
    
    delete[] data_;
}

template <typename T> 
typename list<T>::iterator list<T>::begin() {
    return iterator{data_, head_};
}

template <typename T> 
typename list<T>::iterator list<T>::end() {
    return iterator{data_, 0};
}

template <typename T> 
typename list<T>::const_iterator list<T>::begin() const {
    return iterator{data_, head_};
}

template <typename T> 
typename list<T>::cosnt_iterator list<T>::end() const {
    return iterator{data_, 0};
}

template <typename T> 
uint32_t list<T>::size() const {
    return size_;
}

template <typename T> 
bool list<T>::is_empty() const {
    return size_ == 0;
}

template <typename T> 
typename list<T>::iterator list<T>::push_front(const T& value) {
    head_ = insert(value, 0, head_);
    if (size_ == 1) {
        tail_ = head_;
    }

    return Iterator{this, head_};
}

template <typename T>
typename list<T>::iterator List<T>::push_back(const T& value) {
    tail_ = insert(value, tail_, 0);
    if (size_ == 1) {
        head_ = tail_;
    }

    return iterator{data_, tail_};
}

template <typename T> 
void list<T>::pop_front() {
    erase(head_);
}

template <typename T> 
void list<T>::pop_back() {
    erase(tail_);
}

template <typename T> 
typename list<T>::iterator list<T>::insert(const T& value, iterator prev, iterator next) {
    return iterator{data_, insert(value, prev.index_, next.index_)};
}

template <typename T> 
void list<T>::erase(iterator iterator) {
    erase(iterator.index_);
}

template <typename T>
uint32_t list<T>::insert(const T& value, uint32_t prev, uint32_t next) {
    assert(data_);
    assert(size_ < capacity_);
    assert(prev  < capacity_);
    assert(next  < capacity_);

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
uint32_t list<T>::erase(uint32_t node) {
    assert(data_);
    assert(size_ != 0);
    assert(node != 0 && node < capacity_);
    assert(data_[node].prev != no_prev_node);

    data_[data_[node].next].prev = data_[node].prev;
    data_[data_[node].prev].next = data_[node].next;

    if (node == tail_) {
        tail_ = data_[node].prev;
    }
    if (node == head_) {
        head_ = data_[node].next;
    }

    data_[node].prev = no_prev_node;
    data_[node].next = free_;
    free_ = node;

    size_--;
    return node;
}

#endif // __T_LIST_HPP__

};
