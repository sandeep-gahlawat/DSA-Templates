// Red Black Trees are self-balancing, meaning that the tree adjusts itself automatically after each insertion or deletion operation. It uses a simple but powerful mechanism to maintain balance, by coloring each node in the tree either red or black. 

// Red Black Tree-

// Red-Black tree is a binary search tree in which every node is colored with either red or black. It is a type of self balancing binary search tree. It has a good efficient worst case running time complexity.

// Properties of Red Black Tree:
// The Red-Black tree satisfies all the properties of binary search tree in addition to that it satisfies following additional properties –

// 1. Root property: The root is black.

// 2. External property: Every leaf (Leaf is a NULL child of a node) is black in Red-Black tree.

// 3. Internal property: The children of a red node are black. Hence possible parent of red node is a black node.

// 4. Depth property: All the leaves have the same black depth.

// 5. Path property: Every simple path from root to descendant leaf node contains same number of black nodes. 

// The result of all these above-mentioned properties is that the Red-Black tree is roughly balanced.

// Rules That Every Red-Black Tree Follows: 
// Every node has a color either red or black.
// The root of the tree is always black.
// There are no two adjacent red nodes (A red node cannot have a red parent or red child).
// Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
//  Every leaf (e.i. NULL node) must be colored BLACK.


// Why Red-Black Trees?
// Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that the height of the tree remains O(log n) after every insertion and deletion, then we can guarantee an upper bound of O(log n) for all these operations. The height of a Red-Black tree is always O(log n) where n is the number of nodes in the tree. 

// Comparison with AVL Tree:
// The AVL trees are more balanced compared to Red-Black Trees, but they may cause more rotations during insertion and deletion. So if your application involves frequent insertions and deletions, then Red-Black trees should be preferred. And if the insertions and deletions are less frequent and search is a more frequent operation, then AVL tree should be preferred over the Red-Black Tree.