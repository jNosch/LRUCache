//
// Created by RageZ on 05/10/2026.
//

#include "LRUCache.h"

LRUCache::LRUCache(int capacity)
: capacity(capacity),
head(new Node(0, 0)),
tail(new Node(0, 0))
{
    head->next = tail;
    tail->next = head;
}

void LRUCache::remove(LRUCache::Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void LRUCache::addToFront(LRUCache::Node *node) {
    Node* first = head->next;
    node->prev = head;
    node->next = first;
    head->next = node;
    first->prev = node;
}


int LRUCache::get(int key) {
    auto it = map.find(key);

    if (it == map.end()) {
        return -1;
    }

    Node* node = it->second;
    remove(node);
    addToFront(node);
    return node->val;
}

void LRUCache::put(int key, int value) {
auto it = map.find(key);

if (it != map.end()) {

}
}

