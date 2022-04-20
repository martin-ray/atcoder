#include <algorithm>
#include <random>
template <class RandomIter>
void bogosort( RandomIter first, RandomIter last )
{
  while( !std::is_sorted( first, last ) )
    std::shuffle( first, last, std::default_random_engine() );
}


int main(void){

  std::vector<int> a = {2,4,2,56,1,146,6464,};

  bogosort(a.begin(),a.end());
  return 0;
}