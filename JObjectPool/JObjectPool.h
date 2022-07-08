#pragma once

#include <vector>
#include "pch.h"


namespace jutil
{
	// Forward declaration
	template<typename T> class JObjectPoolNode;


	template<typename T>
	class JObjectPool
	{
	public:
		JObjectPool(int initialSize, int incrementSize);
		~JObjectPool();

		void IncreasePoolSize(int incrementSize);

		JObjectPoolNode<T>* GetNode();
		std::vector<JObjectPoolNode<T>*> GetAllNodes();

		bool ReturnNode(JObjectPoolNode<T>* node);
		bool RemoveNode(JObjectPoolNode<T>* node);

		void ClearPool();

	private:
		JObjectPoolNode<T>* m_Head;
		JObjectPoolNode<T>* m_Tail;

		int m_Count;
		int m_IncrementSize;

		int m_NumofNodeInUse;
	};
}
