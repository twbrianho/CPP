#include <iostream>
#include <string>
using namespace std;

int capinput = 1;

template <class T>
class Queue
{
public:
  Queue(int queueCapacity = capinput);
  bool IsEmpty() const;
  T& Front() const;
  T& Rear() const;
  void Push(const T& item);
  void Pop();
private:
  T*queue;
  int front,rear,capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity)
{
  if(capacity < 1) throw "Queue capacity must be > 0";
  queue = new T[capacity];
  front = rear = 0;
}

template <class T>
void Queue<T>::Pop()
{
  //if(IsEmpty()) throw "Queue is empty. Cannot delete.";
  front = (front + 1) % capacity;
  queue[front].~T();
}

int main(int argc, char **argv)
{
  int capinput;
  cin >> capinput;
  string cmd;
  Queue<int> Q;
  return 0;
}
