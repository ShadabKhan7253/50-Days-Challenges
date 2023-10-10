#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node *next;
            Node *prev;
        Node(int key,int val) {
            this->key =key;
            this->val = val;
        }
    };

    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    int cap;
    unordered_map <int,Node*> map;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *newNode) {
        Node *temp = head->next;
        newNode->next =temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *deleteNode) {
        Node *deletePrev = deleteNode->prev;
        Node *deleteNext = deleteNode->next;
        deletePrev->next = deleteNext;
        deleteNext->prev = deletePrev;
    }

    int get(int key) {
        if(map.find(key) != map.end()) {
            Node *resNode = map[key];
            int res = resNode->val;
            map.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            map[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            Node *existingNode = map[key];
            map.erase(key);
            deleteNode(existingNode);
        }
        if(map.size() == cap) {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        map[key] = head->next;
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout<<lRUCache.get(1)<<endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout<<lRUCache.get(2)<<endl;    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout<<lRUCache.get(1)<<endl;    // return -1 (not found)
    cout<<lRUCache.get(3)<<endl;    // return 3
    cout<<lRUCache.get(4)<<endl;    // return 4
    return 0;
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */