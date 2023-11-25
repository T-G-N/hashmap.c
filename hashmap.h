#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>

#define defineMap(_key_type, _value_type)                                                   \
                                                                                            \
    typedef struct _Map_##_key_type##_value_type {                                          \
        _key_type key_type;                                                                 \
        _value_type value_type;                                                             \
        bool (*insert)(_key_type key_type, _value_type value_type);                         \
    } Map_##_key_type##_value_type;                                                         \
                                                                                            \
    bool map_##_key_type##_value_type_insert(_key_type key_type, _value_type value_type)    \
    {                                                                                       \
        return false;                                                                       \
    }                                                                                       \
                                                                                            \
    Map_##_key_type##_value_type map_create_##_key_type##_value_type()                      \
    {                                                                                       \
        Map_##_key_type##_value_type map;                                                   \
        map.insert = map_##_key_type##_value_type_insert;                                   \
        return map;                                                                         \
    }                                                                                       \


#define Map(_key_type, _value_type) \
    Map_##_key_type##_value_type

#define new_map(_key_type, _value_type) \
    map_create_##_key_type##_value_type() \


#endif /* HASHMAP_H */