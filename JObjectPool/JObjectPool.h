#pragma once

#include <vector>


namespace jutil
{
	// Forward declaration
	template<typename T> class JObjectPoolNode;


	template<typename T>
	class JObjectPool
	{
	public:
		JObjectPool(int initialSize, int incrementSize)
		{
			m_Head = nullptr;
			m_Tail = nullptr;

			m_Count = 0;
			m_IncrementSize = incrementSize < 1 ? 5 : incrementSize;

			IncreasePoolSize(initialSize < 1 ? 5 : initialSize);
		}

		~JObjectPool()
		{
			ClearPool();
		}

		/// <summary>
		/// Increases the J Object Pool size.
		/// </summary>
		/// <param name="incrementSize">The number of new nodes that is going to be added to the J Object Pool.</param>
		void IncreasePoolSize(int incrementSize)
		{
			for (int i = 0; i < incrementSize; i++)
			{
				JObjectPoolNode<T>* node = new JObjectPoolNode<T>(this);
				if (m_Head && m_Tail)
				{
					node->m_Next = m_Head;
					m_Head->m_Previous = node;

					m_Head = node;
				}
				else
				{
					m_Head = node;
					m_Tail = node;
				}

				++m_Count;
			}
		}

		/// <summary>
		/// Returns the next node that is not in use. If there is no node avaiable, it increases the J Object Pool size first and then returns the node.
		/// </summary>
		/// <returns>A node that is not in use</returns>
		JObjectPoolNode<T>* GetNode()
		{
			if (m_Head->bIsInUse)
			{
				IncreasePoolSize(m_IncrementSize);
			}

			JObjectPoolNode<T>* node = m_Head;
			node->bIsInUse = true;
			++m_NumofNodeInUse;

			m_Head = m_Head->m_Next;

			m_Head->m_Previous = nullptr;
			node->m_Next = nullptr;

			node->m_Previous = m_Tail;
			m_Tail->m_Next = node;
			m_Tail = node;

			return node;
		}

		/// <summary>
		/// Returns all the nodes in this J Object Pool.
		/// </summary>
		/// <returns>Returns the list of the nodes.</returns>
		std::vector<JObjectPoolNode<T>*>& GetAllNodes()
		{
			std::vector<JObjectPoolNode<T>*> nodes;

			JObjectPoolNode<T>* node = m_Head;
			while (node)
			{
				nodes.push_back(node);
				node = node->m_Next;
			}

			return nodes;
		}

		/// <summary>
		/// Returns the node to this J Object Pool.
		/// </summary>
		/// <param name="node">The node to return.</param>
		/// <returns>Return true if the node is successfully returned. Return false if the node does not belong to this J Object Pool.</returns>
		bool ReturnNode(JObjectPoolNode<T>* node)
		{
			if (node->m_Pool != this) return false;
			if (!node->bIsInUse) return true;

			if (node != m_Head)
			{
				if (node == m_Tail)
				{
					m_Tail = node->m_Previous;
					m_Tail->m_Next = nullptr;

					node->m_Previous = nullptr;
					node->m_Next = m_Head;

					m_Head->m_Previous = node;
					m_Head = node;
				}
				else
				{
					node->m_Previous->m_Next = node->m_Next;
					node->m_Next->m_Previous = node->m_Previous;

					node->m_Previous = nullptr;
					node->m_Next = m_Head;

					m_Head->m_Previous = node;
					m_Head = node;
				}
			}

			node->m_bIsInUse = false;
			--m_NumofNodeInUse;

			return true;
		}

		/// <summary>
		/// Removes the node from this J Object Pool.
		/// </summary>
		/// <param name="node">The node to remove.</param>
		/// <returns>Return true if the node is successfully deleted. Return false if the node does not belong to this J Object Pool.</returns>
		bool RemoveNode(JObjectPoolNode<T>* node)
		{
			if (node->m_Pool != this)
				return false;

			if (m_Count != 1)
			{
				if (node == m_Head)
				{
					m_Head = m_Head->m_Next;
					m_Head->m_Previous = nullptr;
				}
				else if (node == m_Tail)
				{
					m_Tail = m_Tail->m_Previous;
					m_Tail->m_Next = nullptr;
				}
				else
				{
					node->m_Previous->m_Next = node->m_Next;
					node->m_Next->m_Previous = node->m_Previous;
				}
			}
			else
			{
				m_Head = nullptr;
				m_Tail = nullptr;
			}

			node->m_Previous = nullptr;
			node->m_Next = nullptr;

			--m_Count;

			delete node;
			return true;
		}

		/// <summary>
		/// Removes all the nodes from this J Object Pool and the memory.
		/// </summary>
		void ClearPool()
		{
			JObjectPoolNode<T>* node = m_Head;
			while (node)
			{
				JObjectPoolNode<T>* temp = node;
				node = node->m_Next;
				node->m_Previous = nullptr;

				delete temp;
			}

			m_Count = 0;
		}

		/// <summary>
		/// Gets the total number of nodes in this J Object Pool.
		/// </summary>
		inline int GetCount() { return m_Count; }

		/// <summary>
		/// Gets the increment size of this J Object Pool, which is used to increase the pool size when there is no available nodes
		/// </summary>
		inline int GetIncrementSize() { return m_IncrementSize; }
		/// <summary>
		/// Sets the increment size of this J Object Pool.
		/// </summary>
		/// <param name="incrementSize">The new increment size.</param>
		inline void SetIncrementSize(int incrementSize) { m_IncrementSize = incrementSize; }

		/// <summary>
		/// Gets the number of the nodes that are in use.
		/// </summary>
		inline int GetNumofNodesInUse() { return m_NumofNodeInUse; }
		/// <summary>
		/// Gets the number of the nodes that are avaiable to use.
		/// </summary>
		inline int GetNumofAvailableNodes() { return m_Count - m_NumofNodeInUse; }

	private:
		JObjectPoolNode<T>* m_Head;
		JObjectPoolNode<T>* m_Tail;

		int m_Count;
		int m_IncrementSize;

		int m_NumofNodeInUse;
	};
}
