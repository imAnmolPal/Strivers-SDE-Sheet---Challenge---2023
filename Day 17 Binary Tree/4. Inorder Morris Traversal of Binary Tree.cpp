// 4. Morris Traversal of Binary Tree

vector<int> getInorder(TreeNode* root){
	vector<int> inOrder;

	TreeNode *cur = root;

	while(cur!=NULL){
		if(cur->left==NULL){
			inOrder.push_back(cur->val);
			cur = cur->right;
		}else{
			TreeNode *prev = cur->left;
			while(prev->right and prev->right!=cur){
				prev = prev->right;
			}

			if(prev->right==NULL){
				prev->right = cur;
				cur = cur->left;
			}
			else{
				prev->right = NULL;
				inOrder.push_back(cur->val);
				cur= cur->right;
			}
		}
	}

	return inOrder;
}