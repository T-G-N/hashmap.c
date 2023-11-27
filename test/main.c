#include <string.h>
#include <assert.h>
#include "../hashmap.h" //replace it to your header dir

typedef const char* string;

defineMap(int, char);
defineMap(string, int);

int main(){
    Map(string, int) map1 = new_map(string, int);
    map_insert(map1,"a", 10);
    map_count(map1);
    map_find(map1, "a");
    map_erase(map1, "a");
    map_clear(map1);
    map_size(map1);

    Map(string, int) map2 = new_map(string, int);
    map_swap(map1, map2);

    Map(int, char) map3 = new_map(int, char);

    struct _Map_stringint map4 = _map_create_stringint();

    return 0;
}