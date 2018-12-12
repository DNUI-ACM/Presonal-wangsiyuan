#include <iostream>
#include <cstdlib>
#include <string.h>
#include<math.h>
#include<algorithm>
#include <assert.h>
using namespace std;

template<class T>

class Vector{
	private:
		T * Date;
		int size;
		int capacity;

		// 修改数组容量
		void alter (int New_capacity){
			T *New_Date = new T[New_capacity];
			memmove(New_Date,Date,size);
			Date = New_Date;
			delete [] New_Date;
			capacity = New_capacity;
		}
	public:
		//默认构造 
		Vector(){
			Date = new T[5];
			size = 0;
			capacity = 5;
		}

		//构造函数
		Vector(int New_capacity = 5){
			Date = new T[New_capacity];
			size = 0;
			this -> capacity = New_capacity;
		}

		//复制函数
		Vector(const Vector & V){
			size = V.size;
			capacity = V.capacity;
			Date = new T[capacity];
			memmove(V.Date,Date,Date * sizeof(T));
		}

		//重载 == 
		bool operator == (Vector& V){
			for (int i = 0; i < sizeof(T); ++i)
			{
				if( *(V.Date + i) != *(this.Date + i)){
					return false;
				}
			}
			return true;
		}

		//重载 = 复制
		Vector& operator = (Vector& V){
			if(this == &V){
				return *this;
			}
			size = V.size;
			capacity = V.capacity;
			T *t = new T[capacity];
			memmove(t,V.Date,Date * sizeof(T));
			delete [] Date;
			Date = t;
			return *this;
		}

		//获取内存大小
		int Get_capacity(){
			return capacity;
		}

		// 获取长度
		int Get_size(){
			return size;
		}

		bool IsEmpty(){
			if(size == 0){
				return false;
			}
			return true;
		}

		// 扩大
		void large(){
			// printf("213243\n");
			capacity *= 2;
			T *New_Date = new T[capacity];
			memcpy(New_Date,Date,size * sizeof(T));
			delete [] Date;
			Date = New_Date;
			delete [] New_Date;
		}

		// 缩小
		void narrow(){
			// printf("2121\n");
			capacity /= 2;
			T *New_Date = new T[capacity];
			memmove(New_Date,Date,size * sizeof(T));
			delete [] Date;
			Date = New_Date;
			delete [] New_Date;
		}

		// 打印
		void prin(){
			cout << "size = " << size<< " " << "capacity = " << capacity << endl;
			for (int i = 0; i < size; ++i)
			{
				cout << Date[i] << " ";
			}
			cout << endl << endl;
		}

		void pushback(int value){
		if(size < capacity){
			Date[size] = value;
			++size;
			// cout <<"!" << Date[size - 1] << endl;
		}
		else{
			if(size == 0){
				size = 1;
				capacity = 1;
				T *Date = new T[capacity];
				Date[size] = value;
				// cout << "!" <<Date[size] << endl;
			}
			else{
				large();
				Date[size] = value;
				// cout << "!" <<Date[size] << endl;
				++size;
			}
		}
	}

		void popback(){
			if(size == 0){
				delete [] Date;
			}
			else if(size == 1){
				Date = NULL;
				size--;
				capacity= 0;
			}
			else{
				if(size - 1 == capacity / 2){
					narrow();
					size--;
				}
				else
					size--;
			}
		}

		void insert(int index ,T value){
			assert(index >= 0 && index <= size);
			if(size == capacity){
				// printf("23232\n");
				large();
			}
			for (int i = size - 1; i < index; --i)
			{
				Date[i + 1] = Date[i];
			}
			Date[index] = value;
			++size;
		}
};

int main(int argc, char const *argv[])
{
	Vector<int> *array = new Vector<int>(5);
	for (int i = 0; i < 10; ++i)
	{
		array -> pushback(i);
		array -> prin();
	}
	array -> insert(7,6);
	array -> prin();
	for (int i = 0;i < 10;++i)
	{
		array -> popback();
		array -> prin();
	}
	array -> pushback(999);
	array -> prin();
	return 0;
}