#pragma once


template<typename T>
class DisjointSet
{
public:
	struct Set;

	static Set* Create(T Data)
	{
		Set* set = new Set();
		set->Parent = NULL;

		return set;
	}

	static void DestroySet(Set* set);
	
	static Set* FinedSet(Set* set)
	{
		while (set->Parent != NULL)
			set = set->Parent;

		return set;
	}
	static void UnionSet(Set* parent, Set* set);//누구한테 붙일건지

private:
	struct Set
	{
		T Data;
		Set* Parent;
	};
};

template<typename T>
inline void DisjointSet<T>::DestroySet(Set * set)
{
	delete set;
	set = NULL;
}

template<typename T>
inline void DisjointSet<T>::UnionSet(Set * parent, Set * set)
{
	set = FinedSet(set);
	set->Parent = parent;
}
