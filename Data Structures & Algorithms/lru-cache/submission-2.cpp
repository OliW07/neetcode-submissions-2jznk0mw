struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node() : value(-1), key(-1), next(nullptr), prev(nullptr) {}
    Node(int key, int value, Node* next, Node* prev) 
        : key(key),
          value(value), 
          next(next), 
          prev(prev) 
    {
        next->prev = this;
        prev->next = this;
    };

};

class LRUCache {
private:
    int capacity;
    int curSize;
    map<int,Node*> nodes;
    Node* start;
    Node* end;

public:
    LRUCache(int capacity) 
        :   capacity(capacity),
            start(new Node()),
            end(new Node()),
            curSize(0)

    {
        cout << "init\n";
        start->next = end;
        end->prev = start;
        
    }
    
    int get(int key) {
        cout << "get\n";
        if(!nodes.contains(key)){
            return -1;
        }
        // Update order
        int val = nodes[key]->value;
        remove(nodes[key]);
        insert(key, val);

        return val;
    }

    void insert(int key, int value){
        Node* newNode = new Node(key, value, end, end->prev);
        nodes[key] = newNode;
        curSize++;
    }

    void remove(Node* toRemove){
        Node* prev = toRemove->prev;
        Node* next = toRemove->next;
        prev->next = prev->next->next;
        next->prev = next->prev->prev;

        nodes.erase(toRemove->key);
        delete toRemove;
        curSize--;
    }
    
    void put(int key, int value) {
        cout << "put\n";

        if(nodes.contains(key)){
            remove(nodes[key]);
        }
        else if(curSize >= capacity){
            remove(start->next);
        }

        insert(key, value);
    }

};
