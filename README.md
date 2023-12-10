## J Object Pool
This is the Object Pool data structure created with a double linked list\
C# version is [here](https://github.com/cemalaydeniz/j-object-pool-csharp).

## How Does It Work?
The logic behind the J Object Pool is that the head node always shows the next available node while the tail node always shows the last reserved node that is still in use. When a node is needed, the pool returns the head node and put the node at the end of the list, which the node becomes the new tail node. If the head node is not avaialable to use, the pool's size is increased first and then it returns an available node

## Big O Notations
`JObjectPool`
| Function Name          | Notation |
| ---------------------- | ---------|
| Constructor            | O(n)     |
| Deconstructor          | O(n)     |
| IncreasePoolSize       | O(n)     |
| GetNode                | O(1)     |
| GetAllNodes            | O(n)     |
| ReturnNode             | O(1)     |
| RemoveNode             | O(1)     |
| ClearPool              | O(n)     |
| GetCount               | O(1)     |
| GetIncrementSize       | O(1)     |
| SetIncrementSize       | O(1)     |
| GetNumofNodesInUse     | O(1)     |
| GetNumofAvailableNodes | O(1)     |

`JObjectPoolNode`
| Function Name    | Notation |
| ---------------- | ---------|
| Constructor      | O(1)     |
| Deconstructor    | O(1)     |
| ReturnToPool     | O(1)     |
| GetData          | O(1)     |
| SetData          | O(1)     |
| SetDataDeleteOld | O(1)     |
| GetPool          | O(1)     |
| IsInUse          | O(1)     |

## License
This project is licensed under the MIT License - see the LICENSE.md file for details
