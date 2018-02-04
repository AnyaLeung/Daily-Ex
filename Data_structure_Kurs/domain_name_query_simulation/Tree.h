#include <iostream>

using namespace std;

typedef struct TreeNode *PtrToNode;

struct TreeNode{ //node
    string data;
    PtrToNode left;
    PtrToNode right;
};

struct BinTree{ //IP binary tree
    TreeNode* root; 
    //root node, with left node point to IP binary tree    
};
