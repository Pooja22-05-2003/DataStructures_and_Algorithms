class BinaryTree{
    public:
    int data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }

};