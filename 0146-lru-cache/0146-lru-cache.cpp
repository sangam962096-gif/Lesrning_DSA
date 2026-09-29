class LRUCache {
public:

// Doubly Linked list ke leye Node structure Node strucutre define keye
// Isme key aur value dono store karenge taaki tail se delete karte waqt map se key erase ho skte
 struct Node {
    int key ; 
    int val ;
    Node* next ;
    Node* prev;

    Node( int _key , int _val){
        key = _key;
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
 };

 // Cache ki maximum capacity
  int cap ;

  // key se node ke direct address/pointer ko store karane ke liye hash map
  unordered_map< int , Node*> mp ;

  // Dummy head aur tail pointer ( doundary handling ko simple banane ke leye)
  Node* head ;
  Node* tail;

  // Helper ! : Diye gye node ko uski jagah se detech/delete karane ke leye
  void deleteNode( Node* node){
    Node* prevNode = node->prev;
    Node* nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }
  // helper 2 : Node ko dummy head ke theek baad insert karne k liye( Most recently Used position)
  void insertAfterHead(Node* node){
    Node* currAfterHead = head->next;

    // Node ke next aur prev set kiye
    node->next = currAfterHead;
    node->prev =  head;

    // Head aur uske agle node ke position update kiye
    head->next = node;
    currAfterHead->prev = node;
  }
  // Constructor : Capacity initialize karo aur dummy head/tail ko connect karo
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();

        // Dummy nodes banaye jinke key value -1 hai
         head = new Node(-1 ,-1);
         tail = new Node(-1 ,-1);

         // Initially head aur tail aapas mein connected rehte hain
         head->next = tail;
         tail->prev = head;
    }
    // get(key) : agr key exist karti hai toh value return karo aur usko mru bana do
    int get(int key) {
       // Agar key map mein nahi mili toh -1 return karo
       if(mp.find(key) == mp.end()){
        return -1;
       } 

       // Agar key mil gaye toh node ka address nikalo
       Node* targetNode = mp[key];
       int resultVal = targetNode->val;

       // Node use ho gya , toh isko recent banane ke leye:
       // 1 : Current position se delete karo
       //2 : dummy head ke thik baad insert karo
       deleteNode(targetNode);
       insertAfterHead(targetNode);

       return resultVal;
    }
    // put ( key , value) : naya pair add karo ya existing key ki value update karo
    void put(int key, int value) {
        // Case 1 : key pahle se cache mein mojbood hai
        if( mp.find(key) != mp.end()){
            Node* existingNode = mp[key];

            // Value update karo
            existingNode->val = value;

           // Use huva ahi to isko most recently used position par shift karo
            deleteNode(existingNode);
            insertAfterHead( existingNode);
            return;
        }
        // Case  2: key cache mein nahi hai aur capacity full ho chuki hai
        if ( mp.size() == cap){
            // Least recently used node dummy tail ke peche wala hota hai
            Node* lruNode = tail->prev;

            // map se uski key hatao
            mp.erase(lruNode->key);

           // Doubly linked list se us node ko unlink karo
            deleteNode(lruNode);

            // delete lruNode;
        }
        // Nayi node create karo
        Node* newNode = new Node ( key , value);

        // Map mein store karo aur head ke theek baad insert karo
        mp[key] = newNode ;
        insertAfterHead( newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */