#include<iostream>
using namespace std;
class ring_buffer
{
	private:
		int*m_ptr;
		[[maybe_unused]] int m_pos;
		[[maybe_unused]] int m_size;
	public:
		ring_buffer(int size):m_pos(0),m_size(size)
		{
			m_ptr = new int[size];
		}
		void insert(int data)
		{
			(m_pos!=m_size)?(m_ptr[m_pos++]=data):(m_pos=0,m_ptr[m_pos++]=data);
		}		
		void display()
		{
			for(int i=0; i<m_size;++i)
				cout<<m_ptr[i]<<" ";
		}
};
int main()
{
	ring_buffer ring(5);
	for(int i=0; i<5;++i)
		ring.insert(10);
	
	ring.display(); /*no overflow at this point*/
	cout<<endl;
	ring.insert(9);/*ring buffer, no overflow*/
	ring.display();	
}

