# 0x19. C - Stacks, Queues - LIFO, FIFO    

This project discusses the concept of stacks and queues and how do they operate.     

## Stacks - LIFO    

A stack is a linear data structure, a collection of items of the same type.      

In a stack, the insertion and deletion of elements happen only at one endpoint. 
The behavior of a stack is described as “Last In, First Out” (LIFO). 
When an element is “pushed” onto the stack, it becomes the first item that will be “popped” out of the stack. 
In order to reach the oldest entered item, you must pop all the previous items.  

### Opeartions Preformed on Stacks   

- `push`: Add new element to the top.   
- `pop`: Removes the topmost element.   
- `isEmpty`: Checks whether the stack is empty.    
- `isFull`: Checks whether the stack is full.   
- `top`: Displays the topmost element.   

### Underlying Mechanics of Stacks   

Initially, a pointer `top` is set to keep tack of the topmost item in the stack. The stack is initialized to `-1`.    

Then, a check is preformed to determine if the stack is empty by comparing the top to `-1`.    

As elements are added to the stack, the position of `top` is updated.    


## Queues - FIFO    

A Queue is a linear data structure that stores a collection of elements. 
The queue operates on first in first out (FIFO) algorithm. 
The insertion is done from the back/rear of the Queue, and the insertion is done from the front of the Queue.    

### Operations on Queues    

- `enqueue`: Add new element to the Queue.    
- `dequeue`: Remove element from the Queue.    
- `front`: Get the first element from the Queue.    
- `rear`: Get the last element form the Queue.    
- `isEmpty`: Checks if the Queue is empty.
- `isFull`: Checks if the Queue is full.   



## The `extern` Keyword in C    

The `extern` keyword applies to C variables and Functions, allowing them to extend their 
visibility across the program. When we use `extern` we only declare the variable, telling the 
compiler that this variable exists and can be accessed globaly, but it does not have any memory allocated to it yet.    

- Syntax of extern in C: `extern data_type variable_name;`   


