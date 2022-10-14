// LRU Cache
// LRU --> Least Recently Used

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int key;
    int val;
    node *next;
    node *prev;

    node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// class implementation for LRU cache
class LRUCache
{
public:
    unordered_map<int, node *> mp;
    int capacity;

    // two dummy nodes to keep track of starting and ending points of list
    node *head = new node(0, 0);
    node *tail = new node(0, 0);

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // function to insert a node
    void insert(node *currnode)
    {
        currnode->next = head->next; // adding node in next of head (front of our cache)
        head->next->prev = currnode;
        head->next = currnode;
        currnode->prev = head;
        mp[currnode->key] = currnode; // update map accordingly
    }

    // function to remove a node
    void remove(node *currnode)
    {
        mp.erase(currnode->key);
        currnode->next->prev = currnode->prev;
        currnode->prev->next = currnode->next;
    }

    // function to get the value of a key
    int get(int key)
    {
        // if key is not present than return -1;
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        // if key is present , then update the node and return the value associated with the key
        //  for update first we remove the node and then add at start of list with the help of insert function
        node *currnode = mp[key];
        remove(currnode);
        insert(currnode);
        return currnode->val;
    }

    void put(int key, int value)
    {
        // if key is already present then we have to update it
        //  here also we first remove and then add node in front with the help of insert helper
        if (mp.find(key) != mp.end())
        {
            remove(mp[key]);
        }

        // if size is full then we have to remove the least recently used node
        if (mp.size() == capacity)
        {
            remove(tail->prev);
        }
        insert(new node(key, value));
    }

    // function to display the cache
    void display()
    {
        node *cur = head->next;
        while (cur != tail)
        {
            cout << cur->key << " --> " << cur->val << endl;
            cur = cur->next;
        }
    }
};

int main()
{
    LRUCache lru(5);

    lru.insert(new node(1, 1));
    lru.insert(new node(2, 2));
    lru.insert(new node(3, 3));
    lru.insert(new node(4, 4));
    lru.insert(new node(5, 5));

    cout << "LRU cache before operations: (Most recently used to least recently used)\n";
    lru.display();
    cout << endl;

    int val = lru.get(3);
    cout << "Value of key " << 3 << " is " << val << endl;

    lru.put(5, 10);

    lru.remove(lru.mp[2]);

    cout << "\nLRU cache after operations: (Most recently used to least recently used)\n";
    lru.display();
    cout << endl;

    return 0;
}