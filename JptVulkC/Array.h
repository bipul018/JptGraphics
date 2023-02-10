#pragma once
#include <stdlib.h>
#define createArray(type, count) initArray(sizeof(type) * count)
#define getArrElem(type,arr,index) (*((type*)((char*)arr.data + sizeof(type) * index)))
#define getArrSize(type, arr) (arr.size_in_bytes/sizeof(type))

//Runs expression for each element in array, warning,
//for example for int type, uses iint as loop variable, 
// warning , does a copy of element
//Also you can use elemIdent as identifier to use in the expression
#define runOverArr(type, arr,elemIdent, expression) \
for(size_t i##type=0;i##type < getArrSize(type,arr);++i##type){\
type elemIdent = getArrElem(type, arr, i##type);\
(expression); \
}

//Runs assignments to each element in array, warning,
//for example for int type, uses iint as loop variable
//Also you can use elemIdent as identifier to use in the expression
#define assignOverArr(type, arr, expression) \
for(size_t i##type=0;i##type < getArrSize(type,arr);++i##type){\
getArrElem(type, arr, i##type) = (expression);\
}

struct Array {
	void* data;
	size_t size_in_bytes;
};
typedef struct Array Array;

inline Array initArray(size_t size) {
	Array arr;
	arr.data = malloc(size);
	arr.size_in_bytes = size;
	return arr;
}

inline void freeArray(Array* pArr) {
	if (!pArr)
		return;
	free(pArr->data);
	pArr->data = NULL;
	pArr->size_in_bytes = 0;

}