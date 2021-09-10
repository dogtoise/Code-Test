#include "../stdafx.h"

/*
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language.
*/

class MyCircularQueue {
public:
	MyCircularQueue(int k) {
		m_allocSize = k;
		m_pArr = new int[k];
	}

	bool enQueue(int value) {
		if (m_count == m_allocSize)
			return false;

		if (m_tail == m_allocSize - 1)
			m_tail = 0;
		else
			m_tail++;
		m_pArr[m_tail] = value;

		m_count++;
		return true;
	}

	bool deQueue() {
		if (m_count == 0)
			return false;

		if (m_head == m_allocSize - 1)
			m_head = 0;
		else
			m_head++;
		m_count--;
		return true;
	}

	int Front() {
		if (m_count == 0)
			return -1;
		return m_pArr[m_head];
	}

	int Rear() {
		if (m_count == 0)
			return -1;
		return m_pArr[m_tail];
	}

	bool isEmpty() {
		if (m_count == 0)
			return true;
		else
			return false;
	}

	bool isFull() {
		if (m_count == m_allocSize)
			return true;
		else
			return false;
	}

private:
	int* m_pArr = nullptr;
	int m_allocSize = 0;
	int m_count = 0;

	int m_head = 0;
	int m_tail = -1;
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue* obj = new MyCircularQueue(k);
* bool param_1 = obj->enQueue(value);
* bool param_2 = obj->deQueue();
* int param_3 = obj->Front();
* int param_4 = obj->Rear();
* bool param_5 = obj->isEmpty();
* bool param_6 = obj->isFull();
*/