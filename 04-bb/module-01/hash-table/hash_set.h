// #include "../test_runner.h"

#include <forward_list>
#include <iterator>
#include <algorithm>
#include <vector>
/*
Требования:
В любой момент времени в вашей хеш-таблице должно быть ровно num_buckets корзин. Рехеширование выполнять не нужно.
Метод Add не должен менять содержимое таблицы, если элемент, равный данному, уже есть в таблице.
Метод Has должен возвращать true тогда и только тогда, когда элемент, равный данному, есть в таблице.
Метод Erase должен стирать элемент, равный данному, из таблицы, если он там есть, в противном случае он не должен менять содержимое таблицы.
Метод GetBucket должен возвращать ссылку на бакет, который содержал бы данный элемент, вне зависимости от того, есть он в таблице или нет.

*/
template <typename Type, typename Hasher>
class HashSet {
public:
  using BucketList = std::forward_list<Type>;

public:
  explicit HashSet(
      size_t num_buckets,
      const Hasher& hasher = {}
  );

  void Add(const Type& value);
  bool Has(const Type& value) const;
  void Erase(const Type& value);
  size_t GetBucketIndex(const Type& value) const;
  const BucketList& GetBucket(const Type& value) const;

private:
    size_t num_buckets_;
    std::vector<BucketList> buckets_;
    Hasher hasher_;
};

template<typename Type, typename Hasher>
size_t HashSet<Type, Hasher>::GetBucketIndex(const Type &value) const {
    return hasher_(value) % num_buckets_;
}

template<typename Type, typename Hasher>
HashSet<Type, Hasher>::HashSet(size_t num_buckets, const Hasher &hasher) :
    num_buckets_(num_buckets), buckets_(num_buckets), hasher_(hasher) {}

template<typename Type, typename Hasher>
void HashSet<Type, Hasher>::Add(const Type &value) {
    if (!Has(value)){
        auto bucket_index = hasher_(value) % num_buckets_;
        buckets_[bucket_index].push_front(value);
    }
}

template<typename Type, typename Hasher>
bool HashSet<Type, Hasher>::Has(const Type &value) const {
    auto bucket_index = GetBucketIndex(value);
    if (bucket_index < buckets_.size()){
        auto & bucket = buckets_[bucket_index];
        if (std::find(begin(bucket), end(bucket), value) != end(bucket))
            return true;
    }

    return false;
}

template<typename Type, typename Hasher>
void HashSet<Type, Hasher>::Erase(const Type &value) {
    if (Has(value)){
        auto bucket_index = GetBucketIndex(value);
        buckets_[bucket_index].remove(value);
    }
}

template<typename Type, typename Hasher>
const typename HashSet<Type, Hasher>::BucketList &HashSet<Type, Hasher>::GetBucket(const Type &value) const {
    auto bucket_index = GetBucketIndex(value);
    return buckets_[bucket_index];
}

