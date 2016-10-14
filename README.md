This was a project I worked on in one of my ECE classes. The purpose was to implement a Heapsort using linked nodes

https://en.wikipedia.org/wiki/Heapsort

I thought this was an interesting project because of my solution on how to build the heap initially. Since each node only has a pointer to only two nodes below it (left, right), and the initial implementation of how to insert a node is to specify the left pointer first, then the right pointer, you need to a way to constantly locate which root node to use to fill out the tree appropriately. Simply moving the root node down won't work because you would need to backtrack, which can quickly become complicated for large trees.

The solution I came up seemed pretty ingenious for me, which was to use the number of the node and convert that to a binary value and then use that binary as a way to direct you to the root node to use.

For example, using the tree in the Wikipedia page, if I was to insert Node 6, which contains the value 7, I convert 6 to binary, which can be "00000110" (the number of leading zeroes can vary based on the datatype you are using, but the solution doesn't care about that). The program then truncates that binary to remove all leading 0's, the first 1, and the last significant bit, so you get "XXXXXX1X" or "1". The program then reads whatever is left of the binary as left/right directions to go down the tree to use as the root, with 1 representing right and 0 being left. So in this example, starting from node 1 (which contains 8 after being swapped), it goes to the right to node 3 (which contains 3) then places node 6 to the left of node 3, and the compares to swap 7 up.

To use a larger node example: If you wanted to enter in node 78, 78 to binary would be "01001110", truncated to "00111" which turns into the directions left->left->right->right->right to use that node as the next root.

There are probably only 2 things that can be improved: 
1) I believe the conversion of the binary to a string is unnecessary, however, I did not have the knowledge on how to utilize the binary values directly when making this, so the conversion to string was a work-around.
2) The program uses this algorithm to set the root when the binary tree has 4 or more nodes, which is slightly inefficient, as you only need to redirect the root from the main root every other node. Doing so would probably be much more efficient, however, the objective of the project was to just implement the sort without caring if the solution was efficient or not.
