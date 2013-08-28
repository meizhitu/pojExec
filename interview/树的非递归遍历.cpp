//前序遍历
void preOrder2(TNode* root)
{
    if ( root != NULL)
    {
        Stack S;
        S.push(root);
        while (!S.empty())
        {
            TNode* node = S.pop(); 
            Visit(node);          // 先访问根节点，然后根节点就无需入栈了
            S.push(node->right);  // 先push的是右节点，再是左节点
            S.push(node->left);
        }
    }
}
//中序遍历
void InOrder1(TNode* root)
{
    Stack S;
    while ( root != NULL || !S.empty() )
    {
        while( root != NULL )   // 左子树入栈
        {
            S.push(root);
            root = root->left;
        }
        if ( !S.empty() )
        {
            root = S.pop();
            Visit(root->data);   // 访问根结点
            root = root->right;  // 通过下一次循环实现右子树遍历
        }
    }
}

//后续遍历
void PostOrder(TNode* root)
{
    Stack S;
    if( root != NULL )
    {
        S.push(root);
    }
    while ( !S.empty() )
    {
        TNode* node = S.pop(); 
        if ( node->bPushed )
        {   // 如果标识位为true,则表示其左右子树都已经入栈，那么现在就需要访问该节点了
            Visit(node);        
        }
        else
        {              
			S.push(node);
			// 左右子树尚未入栈，则依次将 右节点,左节点,根节点 入栈
            if ( node->right != NULL )
            {
                node->right->bPushed = false; // 左右子树均设置为false
                S.push(node->right);
            }
            if ( node->left != NULL )
            {
                node->left->bPushed = false;
                S.push(node->left);
            }
            node->bPushed = true;            // 根节点标志位为true
        }
    }
}