# LinkedList - Problems

S.No. | Problem | Approach/Logic used | Level | Link | Solution |
------|---------|---------------------|-------|------|----------|
1 | Middle of the Linked List | Just iterate over the list till n/2 length of the given linkedlist and then return "tmp" pointer | Easy | [view](https://leetcode.com/problems/middle-of-the-linked-list/) | [view](middle-of-the-LL.cpp) 
2 | Linked List cycle | floyd's aglo or Hare and Tortoise algo(keep two pointers are slow and fast, slow increment once whereas fast increment twice). if they will match (slow==fast) then there must be a cycle | Easy | [view](https://leetcode.com/problems/linked-list-cycle/description/) | [view](LL-cycle.cpp) 
3 | Convert Binary num in a Linked list to integer |  | Easy | [view](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/) | [view](Convert-binary-num-to-decimal.cpp) 
4 | Remove Duplicates from Sorted List |  | Easy | [view](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) | [view](remove-dups-from-sorted-lst.cpp) 
7 | Merge Two Sorted Lists | first create a dummyNode then add smaller num of the two current LL nodes next to the dummyNode then finally return dummyNode->next(head of the final node) | Easy | [view](https://leetcode.com/problems/merge-two-sorted-lists/description/) | [view](mergeTwoSortedLst.cpp) 
12 | Reverse Linked List | Recursive approach - change first link b/w first and second node and rest recursion will take care | Easy | [view](https://leetcode.com/problems/reverse-linked-list/description/) | [view](reverse-LL.cpp) 
13 | addTwoNums | fixed approach keep a carry variable and assign digits and carries in new linkedlist as digit=value%10 and carry=value/10 | Medium | [view](https://leetcode.com/problems/add-two-numbers/description/) | [view](addTwoNums.cpp)
15 | addTwoNums-II | firstly, reverse given lists l1 and l2 then apply same logic similiar to problem13 and then return reversed final list l3 | Medium | [view](https://leetcode.com/problems/add-two-numbers-ii/description/) | [view](addTwoNums-II.cpp)
23 | Sort List | store all elements of the given list in a vector and then sort the vector then copy values from sorted vector to original list | Medium | [view](https://leetcode.com/problems/sort-list/description/) | [view](sortList.cpp)