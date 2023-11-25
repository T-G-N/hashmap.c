#include <string.h>
#include <assert.h>
#include "../hashmap.h" //replace it to your header dir

defineMap(char, int);
defineMap(int, char);


int main(){

    Map(char, int) map1 = new_map(char, int);
    map1.insert('a', 10);
    map1.erase('a');
    map1.clear();

    Map(int, char) map2 = new_map(int, char);
    map2.insert(20,'b');
    map2.erase(20);
    map2.clear();

    return 0;
}