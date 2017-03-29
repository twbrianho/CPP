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
inline bool Queue<T>::IsEmpty(){return front == rear;}

template <class T>
inline T& Queue<T>::Front()
{
  if(IsEmpty()) throw "Queue is empty. No front element.";
  return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear()
{
  if(IsEmpty()) throw "Queue is empty. No rear element.";
  return queue[rear];
}

template <class T>
void Queue<T>::Push(const& x)
{
  rear = (rear + 1) % capacity;
  queue[rear]=x;
}

template <class T>
void Queue<T>::Pop()
{
  if(IsEmpty()) throw "Queue is empty. Cannot delete.";
  front = (front + 1) % capacity;
  queue[front].~T();
}


int main(int argc, char **argv)
{
  int capinput;
  cin >> capinput;
  string cmd;
  Queue<int> Q;
  while(getline(cin, cmd))
  {
    if(cmd.substr(0,3) == "push")
    {
      if((rear + 1) % capacity == front) cout << "Full";
      int number = 0;
      cin >> "push" >> number;
      Q.Push(number);
    }
    else if(cmd == "pop")
    {
      Q.Pop();
    }
    else if(cmd == "front")
    {
      if(IsEmpty()) cout << "Empty";
      else Q.Front();
    }
  }
  return 0;
}
