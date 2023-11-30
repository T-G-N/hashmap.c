#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "../hashmap.h" //replace it to your header dir

typedef const char* string;

defineMap(int, char);
defineMap(char, char);
// defineMap(string, int);

int main(){
    // Map(string, int) map1 = new_map(string, int);
    // map_insert(map1,"helloWorld", 10);
    // map_count(map1);
    // map_find(map1, "a");
    // map_erase(map1, "a");
    // map_clear(map1);
    // map_size(map1);

    // Map(string, int) map2 = new_map(string, int);
    // map_swap(map1, map2);

    Map(int, char) map3 = new_map(int, char);
    for(int i =0; i < 10; i++){
        map_insert(map3, i, i+10);
    }
    printf("%zu\n", map_find(map3, 15));

    Map(char, char) map4 = new_map(char, char);
    map_insert(map4, 'a', 'A');
    map_insert(map4, 'b', 'B');
    map_insert(map4, 'c', 'C');
    printf("MAP4: %d %zu \n", map4._entities, map_size(map4));

    Map(char, char) map6 = new_map(char, char);
    map_insert(map6, '1', 'X');
    printf("MAP6: %d %zu \n", map6._entities, map_size(map6));

    map_swap(map4, map6);

    printf("MAP4: %c %d %zu \n", *map_find(map4, '1'), map4._entities, map_size(map4));
    printf("MAP6: %c %d %zu \n", *map_find(map6, 'a'), map6._entities, map_size(map6));

    map_clear(map4);
    printf("MAP4: size:%zu entityCount:%d\n", map_size(map4), map4._entities);
    printf("%d\n", map_empty(map4));

    // struct _Map_stringint map5 = _map_create_stringint();

    return 0;
}