#pragma once

#include "pch.h"


namespace jutil
{
	// Forward declaration
	template<typename T> class JObjectPool;


	template<typename T> class JObjectPoolNode
	{
	public:
		JObjectPoolNode(JObjectPool<T>* pool);
		~JObjectPoolNode();

		void ReturnToPool();

	private:
		JObjectPool<T>* m_Pool;

		JObjectPoolNode<T>* m_Next;
		JObjectPoolNode<T>* m_Previous;

		T* data;

		bool m_bIsInUse;



		template<typename T> friend class JObjectPool;
	};
}
