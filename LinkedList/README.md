# LinkedList - Problems

S.No. | Problem | Approach/Logic used | Level | Link | Solution |
------|---------|---------------------|-------|------|----------|
1 | Middle of the Linked List | Just iterate over the list till n/2 length of the given linkedlist and then return "tmp" pointer | Easy | [view](https://leetcode.com/problems/middle-of-the-linked-list/) | [view](middle-of-the-LL.cpp) 
2 | Linked List cycle | floyd's aglo or Hare and Tortoise algo(keep two pointers are slow and fast, slow increment once whereas fast increment twice). if they will match (slow==fast) then there must be a cycle | Easy | [view](https://leetcode.com/problems/linked-list-cycle/description/) | [view](LL-cycle.cpp) 
12 | Reverse Linked List | Recursive approach - change first link b/w first and second node and rest recursion will take care | Easy | [view](https://leetcode.com/problems/reverse-linked-list/description/) | [view](reverse-LL.cpp) 