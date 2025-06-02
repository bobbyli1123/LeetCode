// 2025-5-30
// BM39 序列化二叉树 <Hard> []

#include "environment.h"

using namespace std;

class Solution {
public:
    void SerializeFunction(TreeNode* root, string& str){
        if(root == nullptr){
            str += '#';
            return;
        }
        string temp = to_string(root->val);
        str += temp + '!';
        SerializeFunction(root->left, str);
        SerializeFunction(root->right, str);
    }
  
    char* Serialize(TreeNode *root) {  
        if(root == nullptr)
            return "#";  
        string res;
        SerializeFunction(root, res);
        char* charRes = new char[res.length() + 1];
        strcpy(charRes, res.c_str());
        charRes[res.length()] = '\0';
        return charRes;
    }
  
    TreeNode* DeserializeFunction(char** str){
        if(**str == '#'){
            (*str)++;
            return nullptr;
        }
        int val = 0;
        // while(**str != '!' && **str != '\0'){
        while(**str != '!'){
            val = val * 10 + ((**str) - '0');
            (*str)++;
        }
        TreeNode* root = new TreeNode(val);
        // if(**str == '\0')
        //     return root;
        // else
        //     (*str)++;
        (*str)++;
        root->left = DeserializeFunction(str);
        root->right = DeserializeFunction(str);
        return root;
    }
  
    TreeNode* Deserialize(char *str) {
        if(str == "#")  
            return nullptr;
        TreeNode* res = DeserializeFunction(&str);
        return res;
    }
};