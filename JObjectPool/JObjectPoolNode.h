#pragma once


namespace jutil
{
	// Forward declaration
	template<typename T> class JObjectPool;


	template<typename T> class JObjectPoolNode
	{
	public:
		JObjectPoolNode(JObjectPool<T>* pool)
		{
			m_Pool = pool;
			m_bIsInUse = false;

			data = new T();
		}

		~JObjectPoolNode()
		{
			if (m_Pool)
			{
				m_Pool->RemoveNode(this);
				m_Pool = nullptr;
			}
			else
			{
				m_Previous = nullptr;
				m_Next = nullptr;
			}

			delete data;
		}

		/// <summary>
		/// Returns the node to its related J Object Pool. Use this function when the node is not needed anymore.
		/// </summary>
		void ReturnToPool()
		{
			if (!m_Pool)
				return;

			m_Pool->ReturnNode(this);
		}

		/// <summary>
		/// Gets the data inside of this node.
		/// </summary>
		/// <returns>Data in the node.</returns>
		inline T* GetData() { return data; }
		/// <summary>
		/// Sets the data inside of this node. It won't delete the old data from the memory.
		/// </summary>
		/// <param name="newData">New data to set.</param>
		inline void SetData(T* newData) { data = newData; }

		/// <summary>
		/// Sets the data inside of this node and delete the old data from the memory.
		/// </summary>
		/// <param name="newData">New data to set.</param>
		inline void SetDataDeleteOld(T* newData)
		{
			delete data;
			data = newData;
		}

		/// <summary>
		/// Gets the related J Object Pool.
		/// </summary>
		/// <returns>The J Object Pool where this node is in</returns>
		inline JObjectPool<T>* GetPool() { return m_Pool; }

		/// <summary>
		/// Returns the node's status.
		/// </summary>
		/// <returns>True if the node is in use and vice-versa.</returns>
		inline bool IsInUse() { return b_IsInUse; }

	private:
		JObjectPool<T>* m_Pool;

		JObjectPoolNode<T>* m_Next;
		JObjectPoolNode<T>* m_Previous;

		T* data;

		bool m_bIsInUse;



		// Friend class declaration
		template<typename T> friend class JObjectPool;
	};
}
