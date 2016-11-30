#pragma once

#ifndef DEL
#define	DEL( p )		{delete p; p = NULL;}
#define	DELX( p )		{delete[] p; p = NULL;}
#endif

#define		NOCOPY_CLASS( className )		className( const className & ) {} className& operator= ( const className& ) {}

template< class T >
class TH_Singleton
{
private:
	TH_Singleton(){}
	~TH_Singleton(){}
	NOCOPY_CLASS( TH_Singleton )

	static T *m_pInstance;
	static CCriticalSection m_cs;


public:
	static T *instance()
	{
		m_cs.Lock();
		if( !m_pInstance )  
			m_pInstance = new T();
		
		m_cs.Unlock();
		return m_pInstance;
	}

	static void release()
	{
		m_cs.Lock();
		if( m_pInstance )
		{
			DEL( m_pInstance );
		}
		m_cs.Unlock();
	}
};

template <class T>
T *TH_Singleton<T>::m_pInstance = NULL;

template <class T>
CCriticalSection TH_Singleton<T>::m_cs;


