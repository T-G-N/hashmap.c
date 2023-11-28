# hashmap

Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order. In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key.

## Feature
- Any DataType Can Be Used As `Key` / `Value` In The Hashmap (except struct & pointer*)
- HashMap Functionallity `insert`, `find`, `clear`, `swap`, `size`, `count`, `erase`

## Documentation
@todo:
    add documentation for hashmap functions & types

## Example Usage
```c
#include <hashmap.h>

defineMap(char, int);

int main(void){

    Map(char, int) hashmap = new_map(char, int);

    map_insert(hashmap, 'a', 0);
    map_insert(hashmap, 'b', 1);

    map_find(hashmap, 'a');
    map_erase(hashmap, 'a');

    map_count(hashmap);
    map_size(hashmap);

    map_clear(hashmap);

    Map(char, int) nextHashmap = new_map(char, int);
    map_swap(hashmap, nextHashmap);

    return 0;
}
```
## Todo
#### Pointers
    Pointers Are Not Supported As Key For Now Because Of Naming And Size Problem But With The Help Of `typedef` We Can Solve 
    The Naming Problem But Without Knowing The Actual Size The `Hashmap` Takes The Pointers Size As The Key/Value Size And So
    It Results In Excess Collision.
#### Structure
    Structures Are Not Supported For Now. Can't Be Used As A Key/Value.
#### Abstraction
    Due To No Template In C, `Hashmap` Is Forced To Hardcode All The Methods And Members In The Header File. Atleast Some    
    Some Functions Should Be Abstracted.
#### Unit Test
    As For Now I Used The Test File As A Debugging File And It Should Be Changed To Unit Testing With `<Asserts.h>`.
#### Excess Functionallity
    Extra Functions For The `Hashmap`
    - At()          :access specified element with bounds checking
    - empty()       :checks whether the container is empty
    - max_size()    :returns the maximum possible number of elements
    - insert_range():inserts a range of elements
    - contains()    :checks if the container contains element with specific key
#### Key Comparison (==)
    `Hashmap` uses key as a unique id to access/manipulate the element and when the key type is string/struct/any... comparision
    of two key may differ according to the key type and so it should be customized by user of having their own function or any
#### Traversal
    There Is No Mean Of Traversal Of Elements In The Map. Only By Using Key The Value Are Retrieved.

