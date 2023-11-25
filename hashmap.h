#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>

#define defineMap(_key_type, _value_type)                                                   \
                                                                                            \
    typedef struct _Map_##_key_type##_value_type {                                          \
        _key_type key_type;                                                                 \
        _value_type value_type;                                                             \
                                                                                            \
        bool (*insert)(_key_type key_type, _value_type value_type);                         \
        bool (*erase)(_key_type key_type);                                                  \
        void (*swap)(struct _Map_##_key_type##_value_type map);                             \
        bool (*clear)();                                                                    \
                                                                                            \
        _value_type (*find)(_key_type key);                                                 \
        int (*count)();                                                                     \
                                                                                            \
        size_t (*size)();                                                                   \
    } Map_##_key_type##_value_type;                                                         \
                                                                                            \
    bool map_##_key_type##_value_type##_insert(_key_type key_type, _value_type value_type)  \
    {                                                                                       \
        return false;                                                                       \
    }                                                                                       \
                                                                                            \
    bool map_##_key_type##_value_type##_erase(_key_type key_type)                           \
    {                                                                                       \
        return false;                                                                       \
    }                                                                                       \
                                                                                            \
    void map_##_key_type##_value_type##_swap(Map_##_key_type##_value_type map)              \
    {                                                                                       \
        return;                                                                             \
    }                                                                                       \
                                                                                            \
    bool map_##_key_type##_value_type##_clear()                                             \
    {                                                                                       \
        return false;                                                                       \
    }                                                                                       \
                                                                                            \
    _value_type map_##_key_type##_value_type##_find(_key_type key)                          \
    {                                                                                       \
        return (_value_type)0;                                                              \
    }                                                                                       \
                                                                                            \
    int map_##_key_type##_value_type##_count()                                              \
    {                                                                                       \
        return 0;                                                                           \
    }                                                                                       \
                                                                                            \
    size_t map_##_key_type##_value_type##_size()                                            \
    {                                                                                       \
        return (size_t)0;                                                                   \
    }                                                                                       \
                                                                                            \
    Map_##_key_type##_value_type map_create_##_key_type##_value_type()                      \
    {                                                                                       \
        Map_##_key_type##_value_type map;                                                   \
        map.insert = map_##_key_type##_value_type##_insert;                                 \
        map.erase = map_##_key_type##_value_type##_erase;                                   \
        map.swap = map_##_key_type##_value_type##_swap;                                     \
        map.clear = map_##_key_type##_value_type##_clear;                                   \
        map.find = map_##_key_type##_value_type##_find;                                     \
        map.count = map_##_key_type##_value_type##_count;                                   \
        map.size = map_##_key_type##_value_type##_size;                                     \
                                                                                            \
        return map;                                                                         \
    }                                                                                       \


#define Map(_key_type, _value_type)                                                         \
    Map_##_key_type##_value_type                                                            \

#define new_map(_key_type, _value_type)                                                     \
    map_create_##_key_type##_value_type()                                                   \


#endif /* HASHMAP_H */