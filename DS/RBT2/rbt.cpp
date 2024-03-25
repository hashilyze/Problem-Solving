#include <cassert>
#include <stdexcept>

class Rbt {
public: // Type definition
    enum EColor { BLACK = 0x00, RED = 0x01};

    // Node for Red Black Tree
    struct Node {
    public: // Constructor
        Node(int key = 0, EColor color = EColor::BLACK, Node* parent = 0, Node* left = 0, Node* right = 0)
            : m_key(key), m_color(color), m_parent(parent), m_left(left), m_right(right)
        { }
    public: // getter/setter
        EColor color() { return m_color; }
        void color(EColor color) { m_color = color; }

        int key() { return m_key; }
        void key(int key) { m_key = key; }

        Node* parent() { return m_parent; }
        void parent(Node* parent) { m_parent = parent; }

        Node* left() { return m_left; }
        void left(Node* left) { m_left = left; }

        Node* right() { return m_right; }
        void right(Node* right) { m_right = right; }
    private:
        int m_key;
        EColor m_color;

        Node* m_parent;
        Node* m_left;
        Node* m_right;
    };
public: // Constructor
    Rbt() { 
        m_nil = new Node();
        m_root = m_nil;
    }
    ~Rbt() {
        delete m_nil;
    }
public: // Interface
    Node* search(int k);
    Node* min(Node* x);
    Node* max(Node* x);
    Node* predecessor(Node* x);
    Node* successor(Node* x);

    void insert(Node* z);
public: // getter
    Node* nil() { return m_nil; }
    Node* root() { return m_root; }
private: // Support Functions
    void insertFixup(Node* z);

    bool isNull(Node* x){ return x == m_nil; }

    void linkLeftChild(Node* parent, Node* child){
        parent->left(child);
        if(!isNull(child)){
            child->parent(parent);
        }
    }
    void linkRightChild(Node* parent, Node* child){
        parent->right(child);
        if(!isNull(child)){
            child->parent(parent);
        }
    }

    void leftRotate(Node* x){
        if(isNull(x) || isNull(x->right())) { // Can not rotate
            throw std::runtime_error("There are not nodes to left-rotate");
        }
        Node* y = x->right();

        linkRightChild(x, y->left());   // X.right = Y.left
        y->parent(x->parent());         // Y.parent = X.parent
        if(isNull(x->parent())){
            m_root = y;
        } else if(x->parent()->left() == x){
            x->parent()->left(y);
        } else{
            x->parent()->right(y);
        }
        linkLeftChild(y, x);            // Y.left = X
    }
    void rightRotate(Node* x){
        if(isNull(x) || isNull(x->left())) { // Can not rotate
            throw std::runtime_error("There are not nodes to right-rotate");
        }
        Node* y = x->left();

        linkLeftChild(x, y->right());   // X.left = Y.right
        y->parent(x->parent());         // Y.parent = X.parent
        if(isNull(x->parent())){
            m_root = y;
        } else if(x->parent()->left() == x){
            x->parent()->left(y);
        } else{
            x->parent()->right(y);
        }
        linkRightChild(y, x);            // Y.right = X
    }
private: // Data
    Node* m_nil;
    Node* m_root;
};

// ================
// =====query======
// ================

auto Rbt::search(int k) -> Node* {
    Node* x = m_root;
    while(!isNull(x) && x->key() != k){
        if(k < x->key()){
            x = x->left();
        } else{
            x = x->right();
        }
    }
    return x;
}

auto Rbt::min(Node* x) -> Node* {
    if(isNull(x)) return x;
    while(!isNull(x->left())){
        x = x->left();
    }
    return x;
}
auto Rbt::max(Node* x) -> Node* {
    if(isNull(x)) return x;
    while(!isNull(x->right())){
        x = x->right();
    }
    return x;
}

auto Rbt::predecessor(Node* x) -> Node* {
    if(isNull(x)) return x;
    
    if(isNull(x->left())){
        Node* y = x->parent();
        while(!isNull(y) && x == y->left()){
            x = y;
            y = y->parent();
        }
        return y;
    } 
    return max(x->left());
}
auto Rbt::successor(Node* x) -> Node* {
    if(isNull(x)) return x;
    
    if(isNull(x->right())){
        Node* y = x->parent();
        while(!isNull(y) && x == y->right()){
            x = y;
            y = y->parent();
        }
        return y;
    } 
    return min(x->right());
}

// ================
// =====insert=====
// ================

void Rbt::insert(Node* z){
    Node* y = this->m_nil;
    Node* x = this->m_root;
    while(!isNull(x)){ // Find insert position
        y = x;
        if(z->key() < x->key()){
            x = x->left();
        } else{
            x = x->right();
        }
    }

    z->parent(y);   // Insert Z
    if(isNull(y)){
        m_root = z;
    } else if(z->key() < y->key()){
        y->left(z);
    } else{
        y->right(z);
    }
    z->left(m_nil);
    z->right(m_nil);
    z->color(EColor::RED);
    
    insertFixup(z); // Fixup color
}

void Rbt::insertFixup(Node* z){
    while(z->parent()->color() == EColor::RED){
        if(z->parent() == z->parent()->parent()->left()){ // Left Case
            Node* y = z->parent()->parent()->right(); // uncle

            if(y->color() == EColor::RED){      // Case.1: Propagation
                y->color(EColor::BLACK);
                z->parent()->color(EColor::BLACK);
                z->parent()->parent()->color(EColor::RED);
                z = z->parent()->parent();
                continue;
            }

            if(z == z->parent()->right()){      // Case.2: Resolve Zig-Zag
                z = z->parent();
                leftRotate(z);
            }
            z->parent()->color(EColor::BLACK);  // Case.3
            z->parent()->parent()->color(EColor::RED);
            rightRotate(z->parent()->parent());
        } else{ // Right Case
            Node* y = z->parent()->parent()->left();

            if(y->color() == EColor::RED){      // Case.1: Propagation
                y->color(EColor::BLACK);
                z->parent()->color(EColor::BLACK);
                z->parent()->parent()->color(EColor::RED);
                z = z->parent()->parent();
                continue;
            }

            if(z == z->parent()->left()){       // Case.2: Resolve Zig-Zag
                z = z->parent();
                rightRotate(z);
            }
            z->parent()->color(EColor::BLACK);  // Case.3
            z->parent()->parent()->color(EColor::RED);
            leftRotate(z->parent()->parent());
        }
    }

    m_root->color(EColor::BLACK);   // Root is always Black
}

int main(void){
    // Test Cases
    const int TEST_MIN = 0;
    const int TEST_MAX = 9;

    Rbt rbt;
    // Empty Tree Query
    assert(rbt.search((TEST_MAX + TEST_MIN) / 2) == rbt.nil());
    assert(rbt.min(rbt.root()) == rbt.nil());
    assert(rbt.max(rbt.root()) == rbt.nil());
    assert(rbt.predecessor(rbt.root()) == rbt.nil());
    assert(rbt.successor(rbt.root()) == rbt.nil());

    // Insert
    for(int i = TEST_MIN; i <= TEST_MAX; ++i){
        rbt.insert(new Rbt::Node(i));
    }
    // Search
    for(int i = TEST_MIN; i <= TEST_MAX; ++i){
        assert(rbt.search(i) != rbt.nil());
    }
    assert(rbt.search(TEST_MIN - 1) == rbt.nil());
    assert(rbt.search(TEST_MAX + 1) == rbt.nil());
    // Min/Max
    assert(rbt.min(rbt.root())->key() == TEST_MIN);
    assert(rbt.max(rbt.root())->key() == TEST_MAX);
    // Predecessor/Successor
    Rbt::Node* cursor = 0;
    cursor = rbt.search(TEST_MAX);
    while(true){
        Rbt::Node* prev = rbt.predecessor(cursor);
        if(prev == rbt.nil()) {
            break;
        }
        assert(cursor->key() - 1 == prev->key());
        cursor = prev;
    }
    cursor = rbt.search(TEST_MIN);
    while(true){
        Rbt::Node* next = rbt.successor(cursor);
        if(next == rbt.nil()) {
            break;
        }
        assert(cursor->key() + 1 == next->key());
        cursor = next;
    }
}