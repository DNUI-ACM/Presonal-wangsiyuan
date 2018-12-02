#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int type;
typedef size_t size_type;
struct Arr
{
	type * base;
	size_type len;
	size_type capacity;
};

enum error
{
	Success,
	MemoryLimit,
	ArrIsEmpty
};

typedef struct Arr arr;

void initial(arr * v){
	v -> base = NULL;
	v -> len = 0;
	v -> capacity = 0;
}

void destory(arr * v){
	if(v -> base == NULL){
		free(v -> base);
	}
}

void add(arr * v,type value){
	if(v -> len < v -> capacity){
		v -> base[v -> len] = value;
		++v -> len; 
	}
	else{
		if(v -> base == NULL){
			v -> base = (type*)malloc(sizeof(type) * (v -> capacity));
			if(v -> base ==  NULL){
				return MemoryLimit;
			}
			else 
				v -> capacity = 1;
		}
		else{
			type * n_base = (type*)malloc(sizeof(type) * ((v -> capacity) * 2));
			if(n_base == NULL){
				return ArrIsEmpty;
			}
			else{
				memcpy(n_base,v -> base,sizeof(type) * (v -> capacity));
				free(v -> base);
				v -> base = n_base;
				v -> capacity *= 2;
			}
		}
		v -> base[v -> len] = value;
		v -> len ++;
	}
	return Success;
}

void Delete(arr * v){
	if(v -> base == NULL){
		return ArrIsEmpty;
	}
	else if(v -> len == 1){
		free(v -> base);
	}
	else if(v -> len - 1 == (v -> capacity) / 2){
		type * n_base = (type*)malloc(sizeof(type) * v -> len);
		memcpy(n_base,v -> base,sizeof(type) * (v -> len - 1));
		free(v -> base);
		v -> base = n_base;
		v-> len --;
		v -> capacity = v -> len;
	}
	else
		v -> len--;
}


type * Index (arr * v,size_type pos){
	if(pos >= v -> len){
		return NULL;
	}
	else
		return v -> base + pos;
}

size_type size(arr * v){
	return v -> len;
}

size_type capacity(arr * v){
	return v -> capacity;
}

int main(int argc, char const *argv[])
{
	arr v;
	initial(&v);
	for (int i = 0; i < 10; ++i)
	{
		add(&v,i);
		printf(" v -> len == %d           ",size(&v));
		printf(" v -> capacity == %d\n",capacity(&v));
	}
	printf("-----------------------------------------\n");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",*Index(&v,i));
	}
	printf("-----------------------------------------\n");
	for (int i = 0; i < 10; ++i)
	{
		Delete(&v);
		printf("v -> len ==%d            ",size(&v));
		printf("v -> capacity == %d\n",capacity(&v));
	}
	destory(&v);
	return 0;
}
