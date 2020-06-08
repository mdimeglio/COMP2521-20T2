module Tree where

data Tree a = Empty | Node a (Tree a) (Tree a)

insertAVL :: Ord a => a -> Tree a -> Tree a
insertAVL x Empty = Node x Empty Empty
insertAVL x t@(Node v l r) | x == v =  t
insertAVL x (Node v l r) =
        if height l' - heighr r' > 1
            then
            else
    where
        l' = if x < v then insertAVL x l else l
        r' = if x > v then insertAVL x r else r

-- insertAVL(tree,item):
-- |  Input  tree, item
-- |  Output tree with item AVL-inserted
-- |
-- |  if tree is empty then
-- |     return new node containing item
-- |  else if item=tree->data then
-- |     return tree
-- |  else
-- |  |  if item < tree->data then
-- |  |     tree->left=insertAVL(tree->left,item)
-- |  |  else if item> tree->data then
-- |  |     tree->right=insertAVL(tree->right,item)
-- |  |  end if

-- |  |  if height(tree->left)-height(tree->right) > 1 then
-- |  |     if item > (tree->left->data) then
-- |  |        tree->left = rotateLeft(tree->left) 
-- |  |        tree = rotateRight(tree)
-- |  |      else 
-- |  |         tree = rotateRight(tree)
-- |  |     end if

-- |  |  else if height(tree->right)-height(tree->left) > 1 then
-- |  |     if item  < (tree->right->data) then
-- |  |        tree->right = rotateRight(tree->right)
-- |  |        tree = rotateLeft(tree)
-- |  |      else 
-- |  |        tree = rotateLeft(tree)
-- |  |      end if

-- |  |  end if
-- |  |  return tree
-- |  end if