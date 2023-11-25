#include <string.h>
#include <assert.h>
#include "../hashmap.h" //replace it to your header dir

defineMap(char, int);
defineMap(int, float);


int main(){

    Map(char, int) map = new_map(char, int);
    map.insert('a', 10);

    return 0;
}