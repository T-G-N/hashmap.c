#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_SIZE 1024
#define RANDOM_MULTIPLIER 0.69

#define defineMap(_key_type, _value_type)                                                                               \
    typedef struct _Element_##_key_type##_value_type {                                                                  \
        _key_type key;                                                                                                  \
        _value_type value;                                                                                              \
        struct _Element_##_key_type##_value_type *_next;                                                                \
    } Element_##_key_type##_value_type;                                                                                 \
                                                                                                                        \
    typedef struct _Map_##_key_type##_value_type {                                                                      \
                                                                                                                        \
        Element_##_key_type##_value_type *_data;                                                                        \
        Element_##_key_type##_value_type *_head;                                                                        \
        Element_##_key_type##_value_type *_tail;                                                                        \
        int _entities;                                                                                                  \
                                                                                                                        \
        bool (*insert)(struct _Map_##_key_type##_value_type *map, _key_type key, _value_type value);                    \
        bool (*erase)(struct _Map_##_key_type##_value_type *map, _key_type key);                                        \
        void (*swap)(struct _Map_##_key_type##_value_type *map, struct _Map_##_key_type##_value_type *nextMap);         \
        bool (*clear)(struct _Map_##_key_type##_value_type *map);                                                       \
                                                                                                                        \
        _value_type* (*find)(struct _Map_##_key_type##_value_type *map, _key_type key);                                 \
        int (*count)(struct _Map_##_key_type##_value_type *map);                                                        \
                                                                                                                        \
        size_t (*size)(struct _Map_##_key_type##_value_type *map);                                                      \
        bool (*isEmpty)(struct _Map_##_key_type##_value_type *map);                                                      \
                                                                                                                        \
    } Map_##_key_type##_value_type;                                                                                     \
                                                                                                                        \
    uint32_t _map_##_key_type##_value_type##_hash(_key_type key)                                                        \
    {                                                                                                                   \
        /*@todo:pointer                                                                                             */  \
        /*      when having pointer we should know the real size of the array or the exact pointer and so it is not */  \
        /*      possible at this instance but can be made in further version.                                       */  \
                                                                                                                        \
        size_t keySize = sizeof(key);                                                                                   \
        uint32_t hashval = 0;                                                                                           \
        for(size_t i = 0; i < keySize; i++){                                                                            \
            hashval += *( ((uint8_t *) &key)+i ) + (i*RANDOM_MULTIPLIER);                                               \
        }                                                                                                               \
        hashval = hashval % INITIAL_SIZE;                                                                               \
        return hashval;                                                                                                 \
    }                                                                                                                   \
                                                                                                                        \
    bool _map_##_key_type##_value_type##_insert(Map_##_key_type##_value_type *map, _key_type key, _value_type value)    \
    {                                                                                                                   \
        uint32_t hashval = _map_##_key_type##_value_type##_hash(key);                                                   \
                                                                                                                        \
        Element_##_key_type##_value_type* element = (Element_##_key_type##_value_type*) malloc(sizeof(Element_##_key_type##_value_type));\
        element->key = key;element->value = value;element->_next = NULL;                                                \
        Element_##_key_type##_value_type* itr = &(map->_data[hashval]);                                                 \
                                                                                                                        \
        while(itr->_next != NULL){itr = itr->_next;}                                                                    \
        itr->_next = element;                                                                                           \
                                                                                                                        \
        map->_entities++;                                                                                               \
        return true;                                                                                                    \
    }                                                                                                                   \
                                                                                                                        \
    bool _map_##_key_type##_value_type##_erase(Map_##_key_type##_value_type *map, _key_type key)                        \
    {                                                                                                                   \
        uint32_t hashval = _map_##_key_type##_value_type##_hash(key);                                                   \
                                                                                                                        \
        Element_##_key_type##_value_type* itr = &(map->_data[hashval]);                                                 \
        Element_##_key_type##_value_type* prev = NULL;                                                                  \
                                                                                                                        \
        while(itr != NULL){                                                                                             \
            if(itr->key == key){                                                                                        \
                Element_##_key_type##_value_type* tmp = itr;                                                            \
                if(prev == NULL){                                                                                       \
                    map->_data[hashval] = *itr->_next;                                                                  \
                }else{                                                                                                  \
                    prev->_next = itr->_next;                                                                           \
                }                                                                                                       \
                free(tmp);                                                                                              \
                map->_entities--;                                                                                       \
                return true;                                                                                            \
            }                                                                                                           \
            prev = itr;                                                                                                 \
            itr = itr->_next;                                                                                           \
        }                                                                                                               \
        return false;                                                                                                   \
    }                                                                                                                   \
                                                                                                                        \
    void _map_##_key_type##_value_type##_swap(Map_##_key_type##_value_type *map, Map_##_key_type##_value_type *nextMap) \
    {                                                                                                                   \
        Map_##_key_type##_value_type tmp = *map;                                                                        \
        *map = *nextMap;                                                                                                \
        *nextMap = tmp;                                                                                                 \
    }                                                                                                                   \
                                                                                                                        \
    bool _map_##_key_type##_value_type##_clear(Map_##_key_type##_value_type *map)                                       \
    {                                                                                                                   \
        free(map->_data);                                                                                               \
        map->_entities = 0;                                                                                             \
        return true;                                                                                                    \
    }                                                                                                                   \
                                                                                                                        \
    _value_type* _map_##_key_type##_value_type##_find(Map_##_key_type##_value_type *map, _key_type key)                 \
    {                                                                                                                   \
        uint32_t hashval = _map_##_key_type##_value_type##_hash(key);                                                   \
        Element_##_key_type##_value_type* itr = &(map->_data[hashval]);                                                 \
        while(itr != NULL){                                                                                             \
            if(itr->key == key) return &(itr->value);                                                                   \
            itr = itr->_next;                                                                                           \
        }                                                                                                               \
        return NULL;                                                                                                    \
    }                                                                                                                   \
                                                                                                                        \
    int _map_##_key_type##_value_type##_count(Map_##_key_type##_value_type *map)                                        \
    {                                                                                                                   \
        return map->_entities;                                                                                          \
    }                                                                                                                   \
                                                                                                                        \
    size_t _map_##_key_type##_value_type##_size(Map_##_key_type##_value_type *map)                                      \
    {                                                                                                                   \
        return (size_t) sizeof(Element_##_key_type##_value_type)*map->_entities;                                        \
    }                                                                                                                   \
                                                                                                                        \
    bool _map_##_key_type##_value_type##_isEmpty(Map_##_key_type##_value_type *map)                                     \
    {                                                                                                                   \
        return map->_entities==0;                                                                                       \
    }                                                                                                                   \
                                                                                                                        \
    Map_##_key_type##_value_type _map_create_##_key_type##_value_type()                                                 \
    {                                                                                                                   \
        Map_##_key_type##_value_type _map;                                                                              \
        _map._entities = 0;                                                                                             \
        _map._head = NULL;                                                                                              \
        _map._data = (Element_##_key_type##_value_type*) calloc(INITIAL_SIZE, sizeof(Element_##_key_type##_value_type));\
        _map.insert = _map_##_key_type##_value_type##_insert;                                                           \
        _map.erase = _map_##_key_type##_value_type##_erase;                                                             \
        _map.swap = _map_##_key_type##_value_type##_swap;                                                               \
        _map.clear = _map_##_key_type##_value_type##_clear;                                                             \
        _map.find = _map_##_key_type##_value_type##_find;                                                               \
        _map.count = _map_##_key_type##_value_type##_count;                                                             \
        _map.size = _map_##_key_type##_value_type##_size;                                                               \
        _map.isEmpty = _map_##_key_type##_value_type##_isEmpty;                                                         \
                                                                                                                        \
        return _map;                                                                                                    \
    }                                                                                                                   \


#define Map(_key_type, _value_type)                                                                                     \
    Map_##_key_type##_value_type                                                                                        \

#define new_map(_key_type, _value_type)                                                                                 \
    _map_create_##_key_type##_value_type()                                                                              \


#define map_create(_key_type, _value_type)                                                                              \
    _map_create_##_key_type##_value_type()                                                                              \

#define map_insert(_map, _key, _value)                                                                                  \
    _map.insert(&_map, _key, _value)                                                                                    \

#define map_erase(_map, _key)                                                                                           \
    _map.erase(&_map, _key)                                                                                             \

#define map_swap(_map, _nextMap)                                                                                        \
    _map.swap(&_map, &_nextMap)                                                                                         \

#define map_clear(_map)                                                                                                 \
    _map.clear(&_map)                                                                                                   \

#define map_find(_map, _key)                                                                                            \
    _map.find(&_map, _key)                                                                                              \

#define map_count(_map)                                                                                                 \
    _map.count(&_map)                                                                                                   \

#define map_size(_map)                                                                                                  \
    _map.size(&_map)                                                                                                    \

#define map_empty(_map)                                                                                                 \
    _map.isEmpty(&_map)                                                                                                  \


#endif /* HASHMAP_H */
