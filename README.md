[English](#english)\
[Deutsch](#deutsch)

# English

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


# Deutsch

## J Object Pool
Dies ist die Object-Pool-Datenstruktur, die mit einer Doppelverknüpfte-Liste erstellt wurde\
C# Version ist [hier](https://github.com/cemalaydeniz/j-object-pool-csharp).

## Wie Funktioniert Das?
Die Logik hinter dem J Object Pool ist, dass der Kopfknoten immer den nächsten verfügbaren Knoten anzeigt und der Endknoten immer den letzten reservierten Knoten anzeigt, den noch verwendet wird. Wenn ein Knoten benötigt wird, gibt der Pool den Kopfknoten und legt der Pool den Knoten an das Ende der Liste, was der Knoten den neuen Endknoten wird. Wenn der Kopfknoten nicht verfügbar ist, steigert die Größe des Pools und dann gibt der Pool einen verfügbaren Knoten

## Big O Notationen
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

## Lienz
Das Projekt wird unter der MIT-Lizenz lizenziert - sehen Sie die LICENSE.md Datei für Details
