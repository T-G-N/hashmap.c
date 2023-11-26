#include <string.h>
#include <assert.h>
#include "../hashmap.h" //replace it to your header dir

defineMap(char, int);
defineMap(int, char);


int main(){

    Map(char, int) map1 = new_map(char, int);
    map1.insert(&map1,'a', 10);
    map1.erase(&map1,'a');
    map1.clear(&map1);

    map_insert(map1,'a', 10);

    Map(int, char) map2 = new_map(int, char);
    map2.insert(&map2,20,'b');
    map2.erase(&map2,20);
    map2.clear(&map2);

    Map(char, int) map3 = new_map(char, int);
    
    return 0;
}