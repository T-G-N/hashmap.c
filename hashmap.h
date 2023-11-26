#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>

#define defineMap(_key_type, _value_type)                                                   \
                                                                                            \
    typedef struct _Map_##_key_type##_value_type {                                          \
                                                                                            \
        bool (*insert)(struct _Map_##_key_type##_value_type *map, _key_type key, _value_type value);\
        bool (*erase)(struct _Map_##_key_type##_value_type *map, _key_type key);       \
        void (*swap)(struct _Map_##_key_type##_value_type *map, struct _Map_##_key_type##_value_type *nextMap);\
        bool (*clear)(struct _Map_##_key_type##_value_type *map);                           \
                                                                                            \
        _value_type (*find)(struct _Map_##_key_type##_value_type *map, _key_type key);      \
        int (*count)(struct _Map_##_key_type##_value_type *map);                            \
                                                                                            \
        size_t (*size)(struct _Map_##_key_type##_value_type *map);                          \
    } Map_##_key_type##_value_type;                                                         \
                                                                                            \
    bool _map_##_key_type##_value_type##_insert(Map_##_key_type##_value_type *map, _key_type key, _value_type value)\
    {                                                                                       \
        return false;                                                                       \
    }                                                                                       \
                                                                                            \
    bool _map_##_key_type##_value_type##_erase(Map_##_key_type##_value_type *map, _key_type key)\
    {                                                                                       \
        return false;                                                                       \
    }                                                                                       \
                                                                                            \
    void _map_##_key_type##_value_type##_swap(Map_##_key_type##_value_type *map, Map_##_key_type##_value_type *nextMap)\
    {                                                                                       \
        return;                                                                             \
    }                                                                                       \
                                                                                            \
    bool _map_##_key_type##_value_type##_clear(Map_##_key_type##_value_type *map)           \
    {                                                                                       \
        return false;                                                                       \
    }                                                                                       \
                                                                                            \
    _value_type _map_##_key_type##_value_type##_find(Map_##_key_type##_value_type *map, _key_type key)\
    {                                                                                       \
        return (_value_type)0;                                                              \
    }                                                                                       \
                                                                                            \
    int _map_##_key_type##_value_type##_count(Map_##_key_type##_value_type *map)            \
    {                                                                                       \
        return 0;                                                                           \
    }                                                                                       \
                                                                                            \
    size_t _map_##_key_type##_value_type##_size(Map_##_key_type##_value_type *map)          \
    {                                                                                       \
        return (size_t)0;                                                                   \
    }                                                                                       \
                                                                                            \
    Map_##_key_type##_value_type _map_create_##_key_type##_value_type()                     \
    {                                                                                       \
        Map_##_key_type##_value_type _map;                                                  \
        _map.insert = _map_##_key_type##_value_type##_insert;                               \
        _map.erase = _map_##_key_type##_value_type##_erase;                                 \
        _map.swap = _map_##_key_type##_value_type##_swap;                                   \
        _map.clear = _map_##_key_type##_value_type##_clear;                                 \
        _map.find = _map_##_key_type##_value_type##_find;                                   \
        _map.count = _map_##_key_type##_value_type##_count;                                 \
        _map.size = _map_##_key_type##_value_type##_size;                                   \
                                                                                            \
        return _map;                                                                        \
    }                                                                                       \


#define Map(_key_type, _value_type)                                                         \
    Map_##_key_type##_value_type                                                            \

#define new_map(_key_type, _value_type)                                                     \
    _map_create_##_key_type##_value_type()                                                  \


#define map_insert(_map, _key, _value)                                                      \
    _map.insert(&_map, _key, _value)                                                        \

#define map_erase(_map, _key)                                                               \
    _map.erase(&_map, _key)                                                                 \

#define map_swap(_map, _nextMap)                                                            \
    _map.swap(&_map, &_nextMap)                                                             \

#define map_clear(_map)                                                                     \
    _map.clear(&_map)                                                                       \

#define map_find(_map, _key)                                                                \
    _map.find(&_map, _key)                                                                  \

#define map_count(_map)                                                                     \
    _map.count(&_map)                                                                       \

#define map_size(_map)                                                                      \
    _map.size(&_map)                                                                        \


#endif /* HASHMAP_H */