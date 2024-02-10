# **Stack:**
A Stack is a **`linear data structure`** that follows the **`LIFO (Last-In-First-Out) principle`**. Whenever an element is added in the stack, it is added on the top of the stack, and the element can be deleted only from the top of the stack. In other words, a stack can be defined as a container in which insertion and deletion can be done from the one end known as the top of the stack.

A stack is an Abstract Data Type (ADT), that is popularly used in most programming languages. It is named stack because it has the similar operations as the real-world stacks, for example − a pack of cards or a pile of plates, etc.

# **Basic Stack Operations:**
The following are some common operations implemented on the stack:

* **`push():`** When we insert an element in a stack then the operation is known as a push. If the stack is full then the **`overflow`** condition occurs. When we initialize a stack, we set the value of **`top as -1`** to check that the stack is empty. When the new element is pushed in a stack, first, the value of the top gets incremented, i.e., **`top=top+1`**, and the element will be placed at the new position of the top.
* **`pop():`** When we delete an element from the stack, the operation is known as a pop. If the stack is empty means that no element exists in the stack, this state is known as an underflow state. If we try to delete the element from the empty stack, then the **`underflow`** condition occurs. If the stack is not empty, we first access the element which is pointed by the top. Once the pop operation is performed, the top is decremented by 1, i.e., **`top=top-1`**.
* **`isEmpty():`** It determines whether the stack is empty or not.
* **`isFull():`** It determines whether the stack is full or not.'
* **`peek():`** It returns the element at the given position.
* **`count():`** It returns the total number of elements available in a stack.
  
# **Diagram of Stack:**
![0_ddU99ugmu6qcH-8p](https://github.com/mrinmoyxb/Data-Structures-and-Algorithms/assets/141025752/a1a48984-f187-4703-bbd0-41298a0b8fdc)
