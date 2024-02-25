#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
	//implement bubble sort
	//create linkedlist object for the sorted list
	//LinkedList<T> sortedList;
	//find the max length of the list
	int length = list.getLength();

	//for (size_t i = 0; i < length; i++)
	//{
	//	sortedList.insert(i,list.getEntry(i));
	//}
	int swap;
	do{
		swap = 0;
		for (size_t i = 0; i < length - 1; i++)
		{
			for (size_t j = 0; j < length - 1; j++)
			{
				T index = list.getEntry(i);
				T indexNext = list.getEntry(i+1);
				if(index > indexNext){
					list.setEntry(i,indexNext);
					list.setEntry(i+1,index);
					swap++;
				}
				// if(sortedList.getEntry(i)>sortedList.getEntry(j)){
				// 	T temp = sortedList.getEntry(j);
				// 	sortedList.remove(j);
				// 	sortedList.insert(j, sortedList.getEntry(j+1));
				// 	sortedList.remove(j+1);
				// 	sortedList.insert(j+1,temp);
				// }
			}

		}
	}while(swap>0);
	return list;
}

#endif
