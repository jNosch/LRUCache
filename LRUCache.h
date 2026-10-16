//
// Created by RageZ on 05/10/2026.
//


//Use a  unordered map to find a key instantly and then use the Doubly linked list to keep order.
//map is for fast lookup but is unordered, list on the other hand is for order(what ame last) but lacks in fast lookup

#pragma once
#ifndef UNTITLED_LRUCACHE_H
#define UNTITLED_LRUCACHE_H
#include <unordered_map>



class LRUCache {
private:

    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    std::unordered_map<int, Node*> map;
    int capacity;
    Node* head;
    Node* tail;

    void  remove(Node* node);
    void addToFront(Node* node);

public:
    explicit LRUCache(int capacity);
    ~LRUCache();

    LRUCache(const LRUCache&) = delete;
    LRUCache& operator=(const LRUCache&) = delete;

    int get(int key);
    void put(int key, int value);
};


#endif //UNTITLED_LRUCACHE_H
