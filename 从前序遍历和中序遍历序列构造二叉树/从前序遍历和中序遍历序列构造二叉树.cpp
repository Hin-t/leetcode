#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

bool isleaf(vector<int> &preorder, vector<int> &inorder, int index)
{
    // 如果中序中某个元素左右的元素在先序中都在该元素之前，则该元素为叶子
    int preorder_left, preorder_mid, preorder_right;
    if (index == 0)
    {
        preorder_mid = distance(
            preorder.begin(),
            find(preorder.begin(), preorder.end(), inorder[index]));
        preorder_right = distance(
            preorder.begin(),
            find(preorder.begin(), preorder.end(), inorder[index + 1]));
        if (preorder_right < preorder_mid)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (index == preorder.size() - 1)
    {
        preorder_left = distance(
            preorder.begin(),
            find(preorder.begin(), preorder.end(), inorder[index - 1]));
        preorder_mid = distance(
            preorder.begin(),
            find(preorder.begin(), preorder.end(), inorder[index]));
        if (preorder_left < preorder_mid)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        preorder_left = distance(
            preorder.begin(),
            find(preorder.begin(), preorder.end(), inorder[index - 1]));
        preorder_mid = distance(
            preorder.begin(),
            find(preorder.begin(), preorder.end(), inorder[index]));
        preorder_right = distance(
            preorder.begin(),
            find(preorder.begin(), preorder.end(), inorder[index + 1]));

        if (preorder_left < preorder_mid && preorder_right < preorder_mid)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool ispop(vector<int> &preorder, vector<int> &inorder, TreeNode *node)
{
    int preorder_left, preorder_mid, preorder_right;
    int index = distance(inorder.begin(),
                         find(inorder.begin(), inorder.end(), node->val));
    if (node->left != nullptr && node->right != nullptr)
    {
        return true;
    }
    else if (node->left != nullptr && index == inorder.size() - 1)
    {
        return true;
    }
    else if (node->right != nullptr && index == 0)
    {
        return true;
    }
    preorder_left =
        distance(preorder.begin(), find(preorder.begin(), preorder.end(),
                                        inorder[index - 1]));
    preorder_mid =
        distance(preorder.begin(),
                 find(preorder.begin(), preorder.end(), inorder[index]));
    preorder_right =
        distance(preorder.begin(), find(preorder.begin(), preorder.end(),
                                        inorder[index + 1]));
    if (node->left != nullptr && preorder_left < preorder_mid)
    {
        return true;
    }
    else if (node->right != nullptr && preorder_right < preorder_mid)
    {
        return true;
    }
    return false;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int rootindex = distance(
        inorder.begin(), find(inorder.begin(), inorder.end(), preorder[0]));
    int childrenindex = 0;
    deque<TreeNode *> dq;
    TreeNode *root = new TreeNode(preorder[0]);
    dq.push_back(root);
    for (int i = 1; i < preorder.size(); i++)
    {
        childrenindex =
            distance(inorder.begin(),
                     find(inorder.begin(), inorder.end(), preorder[i]));
        TreeNode *node = new TreeNode(preorder[i]);
        if (childrenindex < rootindex)
        {
            dq.front()->left = node;
            if (!isleaf(preorder, inorder, childrenindex))
            {
                dq.push_back(node);
            }
        }
        else if (childrenindex > rootindex)
        {
            dq.front()->right = node;
            if (!isleaf(preorder, inorder, childrenindex))
            {
                dq.push_back(node);
            }
        }
        while (!dq.empty() && ispop(preorder, inorder, dq.front()))
        {
            dq.pop_front();
        }
        rootindex =
            distance(inorder.begin(),
                     find(inorder.begin(), inorder.end(), preorder[i]));
    }
    return root;
}

int main()
{
    vector<int> pre({1, 2, 4,3});
    vector<int> inorder({1, 2, 3, 4});
    for (int i = 0; i < 4; i++)
    {
        cout << isleaf(pre, inorder, i);
    }
}