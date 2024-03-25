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
        EColor m_color;
        int m_key;

        Node* m_parent;
        Node* m_left;
        Node* m_right;
    };
public: // Interface
    Rbt() { 
        m_nil = new Node();
        m_root = m_nil;
    }
    ~Rbt() {
        delete m_nil;
    }

private: // Support Functions
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
            x->parent()->right(x);
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
            x->parent()->right(x);
        }
        linkRightChild(y, x);            // Y.right = X
    }
private: // Data
    Node* m_nil;
    Node* m_root;
};


int main(void){
    Rbt rbt;
}

