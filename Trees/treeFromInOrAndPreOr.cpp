#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int Findposition(int in[], int inorderStart, int inorderEnd, int element, int n)
{
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}
Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int position = Findposition(in, inorderStart, inorderEnd, element, n);

    root->left = solve(in, pre, index, inorderStart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preorderindex = 0;

    Node *ans = solve(in, pre, preorderindex, 0, n - 1, n);
    return ans;
}

void postorder(Node *root) // left right root
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main(){
    int n;
    cin >> n;
    int inorder[n], preorder[n];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    Node *root = buildTree(inorder, preorder, n);
    postorder(root);
    cout << endl;
}