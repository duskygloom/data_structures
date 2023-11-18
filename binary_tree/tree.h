typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int value);
void print_inorder(const Node *root);
void print_reverse_inorder(const Node *root);
void print_preorder(const Node *root);
void print_postorder(const Node *root);
