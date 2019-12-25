/*
*/
#include <iostream>
#include <vector>

//using namespace std;

struct intput_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public intput_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};


template <class Category, class T, class Distance = int, class Pointer = T*, class Reference = T&>
struct iterator
{
	typedef Category  iterator_category;
	typedef T		  value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;
};

//榨汁机 traits
template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type		 value_type;
	typedef typename Iterator::difference_type   difference_type;
	typedef typename Iterator::pointer		     pointer;
	typedef typename Iterator::reference         reference;
};

//偏特化版本traits
template <class T>
struct iterator_traits<T*>
{
	typedef random_access_iterator_tag iterator_category;
	typedef T						   value_type;
	typedef ptrdiff_t				   difference_type;
	typedef T*						   pointer;
	typedef T&						   reference;
};

template <class Iterator>
typename iterator_traits<Iterator>::iterator_category iterator_category(const Iterator&)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return category();
}

template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type __distance(InputIterator first, InputIterator last, intput_iterator_tag k)
{
	typename iterator_traits<InputIterator>::difference_type n = 0;
	//while (first != last)
	//{
	//	++first;
	//	++n;
	//}
	std::cout << "intput_iterator_tag __distance!" << std::endl;
	return n;
}

template <class RandomAccessIterator>
typename iterator_traits<RandomAccessIterator>::difference_type __distance(RandomAccessIterator first, RandomAccessIterator last, random_access_iterator_tag k)
{
	typename iterator_traits<RandomAccessIterator>::difference_type n = 0;
	std::cout << "random_access_iterator_tag __distance!" << std::endl;
	return n;
}

template <class InputIterator>
typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
{
	typedef typename iterator_traits<InputIterator>::iterator_category category;
	return __distance(first, last, category());
}

template <class InputIterator, class Distance>
void __advance(InputIterator& i, Distance n, intput_iterator_tag k)
{
	while (n--) ++i;
}

template <class BidirectionalIterator, class Distance>
void __advance(BidirectionalIterator& i, Distance n, bidirectional_iterator_tag k)
{
	if (n > 0)
		while (n--)++i;
	else
		while (n++)--i;
}

template <class RandomAccessIterator, class Distance>
void __advance(RandomAccessIterator& i, Distance n, random_access_iterator_tag k)
{
	i += n;
}

template <class InputIterator, class Distance>
void advance(InputIterator& i, Distance n)
{
	__advance(i, n, iterator_category(i));
}



int main()
{
	iterator<random_access_iterator_tag, int, int, int*, int&>rfirst, rlast;
	iterator_traits<iterator<random_access_iterator_tag, int, int, int*, int&>>::difference_type dis;
	dis = distance(rfirst, rlast);
}


