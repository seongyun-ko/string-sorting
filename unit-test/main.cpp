static int cmp(int a, int b);

#include "../src/vector_brodnik.h"
#include "../src/vector_bagwell.h"
#include "../src/vector_block.h"
#include "../src/vector_realloc.h"
#include "../src/vector_malloc.h"
#include "../src/losertree.h"
#include <cassert>
#include <iostream>
#include <array>
#include <vector>
#include <utility>

template <typename Container>
void test_basics()
{
	std::cerr<<__PRETTY_FUNCTION__<<std::endl;
	{
		Container v;
		assert(v.size()==0);
	}
	{
		Container v;
		v.push_back(1);
		assert(v.size()==1);
		assert(v[0]==1);
	}
	{
		Container v;
		const unsigned N=1000000;
		for (unsigned i=0; i < N; ++i) {
			assert(v.size()==i);
			v.push_back(i);
			assert(v[i]==i);
		}
		assert(v.size()==N);
	}
	{
		Container v;
		const unsigned N=1000000;
		for (unsigned i=0; i < N; ++i) v.push_back(i);
		for (unsigned i=0; i < N; ++i) assert(v[i]==i);
		v.clear();
		assert(v.size()==0);
		for (unsigned i=0; i < N; ++i) v.push_back(i);
		for (unsigned i=0; i < N; ++i) assert(v[i]==i);
		v.clear();
		assert(v.size()==0);
		for (unsigned i=0; i < N; ++i) v.push_back(i);
		for (unsigned i=0; i < N; ++i) assert(v[i]==i);
		v.clear();
		assert(v.size()==0);
	}
}

static int cmp(int a, int b)
{
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;
}

static void
test_loser_tree()
{
	std::cerr<<__PRETTY_FUNCTION__<<std::endl;
	{
		std::array<int, 5> seq1 = { 2, 4, 6, 8, 10 };
		std::array<int, 5> seq2 = { 3, 5, 7, 9, 11 };
		std::vector<std::pair<int*, size_t> > seqs;
		seqs.push_back(std::make_pair(seq1.data(), 5));
		seqs.push_back(std::make_pair(seq2.data(), 5));
		loser_tree<int> tree(seqs.begin(), seqs.end());
		assert(tree._nonempty_streams == 2);
		assert(tree.min() == 2);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 3);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 4);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 5);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 6);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 7);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 8);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 9);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 10); assert(tree._nonempty_streams == 1);
		assert(tree.min() == 11); assert(tree._nonempty_streams == 0);
	}
	{
		std::array<int, 3> seq1 = { 2, 5, 8  };
		std::array<int, 3> seq2 = { 3, 6, 9  };
		std::array<int, 3> seq3 = { 4, 7, 10 };
		std::vector<std::pair<int*, size_t> > seqs;
		seqs.push_back(std::make_pair(seq1.data(), 3));
		seqs.push_back(std::make_pair(seq2.data(), 3));
		seqs.push_back(std::make_pair(seq3.data(), 3));
		loser_tree<int> tree(seqs.begin(), seqs.end());
		assert(tree._nonempty_streams == 3);
		assert(tree.min() == 2);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 3);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 4);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 5);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 6);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 7);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 8);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 9);  assert(tree._nonempty_streams == 1);
		assert(tree.min() == 10); assert(tree._nonempty_streams == 0);
	}
	{
		std::array<int, 3> seq1 = { 2, 5, 8  };
		std::array<int, 3> seq2 = { 3, 6, 9  };
		std::array<int, 3> seq3 = { 4, 7, 10 };
		std::vector<std::pair<int*, size_t> > seqs;
		seqs.push_back(std::make_pair(seq3.data(), 3));
		seqs.push_back(std::make_pair(seq2.data(), 3));
		seqs.push_back(std::make_pair(seq1.data(), 3));
		loser_tree<int> tree(seqs.begin(), seqs.end());
		assert(tree._nonempty_streams == 3);
		assert(tree.min() == 2);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 3);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 4);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 5);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 6);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 7);  assert(tree._nonempty_streams == 3);
		assert(tree.min() == 8);  assert(tree._nonempty_streams == 2);
		assert(tree.min() == 9);  assert(tree._nonempty_streams == 1);
		assert(tree.min() == 10); assert(tree._nonempty_streams == 0);
	}
	{
		const unsigned items = 32;
		std::vector<std::vector<int> > data(25000);
		for (unsigned i=0; i < data.size(); ++i) {
			for (unsigned j=0; j < items; ++j) {
				data[i].push_back(j);
			}
		}
		std::vector<std::pair<int*, size_t> > seqs;
		for (unsigned i=0; i < data.size(); ++i) {
			seqs.push_back(std::make_pair(data[i].data(), items));
		}
		loser_tree<int> tree(seqs.begin(), seqs.end());
		assert(tree._nonempty_streams == data.size());
		for (unsigned i=0; i < items; ++i) {
			for (unsigned j=0; j < data.size(); ++j) {
				assert(tree.min() == i);
			}
		}
		assert(tree._nonempty_streams == 0);
	}
}

struct OK { ~OK() { std::cerr << "*** All OK ***\n"; } };

int main()
{
	OK ok;
	/*********************************************************/
	test_loser_tree();
	/*********************************************************/
	test_basics<vector_brodnik<int> >();
	test_basics<vector_bagwell<int> >();
	test_basics<vector_block<int> >();
	test_basics<vector_malloc<int> >();
	test_basics<vector_malloc_counter_clear<int> >();
	test_basics<vector_realloc<int> >();
	test_basics<vector_realloc_counter_clear<int> >();
	test_basics<vector_realloc_shrink_clear<int> >();
	/*********************************************************/
	test_basics<vector_brodnik<uint64_t> >();
	test_basics<vector_bagwell<uint64_t> >();
	test_basics<vector_block<uint64_t> >();
	test_basics<vector_malloc<uint64_t> >();
	test_basics<vector_malloc_counter_clear<uint64_t> >();
	test_basics<vector_realloc<uint64_t> >();
	test_basics<vector_realloc_counter_clear<uint64_t> >();
	test_basics<vector_realloc_shrink_clear<uint64_t> >();
	/*********************************************************/
}
