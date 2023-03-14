#pragma once

template<typename T> class Singleton
{
private:
	static T* m_pInstance;

protected:
	Singleton() { }
	virtual ~Singleton() { }

public:
	static T* get_instance()
	{
		if (NULL == m_pInstance) m_pInstance = new T;
		return m_pInstance;
	}
	static void destroy_instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
};
template<typename T> T* Singleton<T>::m_pInstance = NULL;