// 10. Vertical order traversal

vector<vector<int>> verticalTraversal(TreeNode* root){

	// vertical->[level->node]
	map<int, map<int, multiset<int>>> nodes;

	// node, vertical, level
	queue<pair<TreeNode*, pair<int,int>>> todo;

	todo.push({root,{0,0}});

	while(!todo.empty()){
		auto p = todo.front();
		todo.pop();

		TreeNode* node = p.first;

		int vertical = p.second.first;
		int level = p.second.second;

		nodes[vertical][level].insert(node->val);

		if(node->left){
			todo.push({node->left,{vertical-1, level+1}});
		}
		if(node->right){
			todo.push({node->right,{vertical+1, level+1}});
		}
	}

	vector<vector<int>> ans;

	for(auto p: nodes){
		vector<int> col;

		for(auto q: p.second){
			col.insert(col.end(), q.second.begin(), q.second.end());
		}

		ans.push_back(col);
	}

	return ans;
}