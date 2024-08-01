//// ############# STRUCTS ###############
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct node node;
    struct node
    {
        int data;
        int key;
        node * next;
    };

    node * constructor_node(int key,int data,node *next)
    {
        node * new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->next = next;
        new_node->key = key;
        return new_node;
    }
    
    typedef struct Hash{
        node ** array;
        int size;
    }Hash;

    Hash * constructor_hash(int size)
    {
        Hash * new_hash = malloc(sizeof(Hash*));
        new_hash->array = (node**)malloc(size*sizeof(node*));
        new_hash->size = size;
        return new_hash;
    }

    typedef struct Iterator
    {
        Hash * hash;
        node * current;
        int array_index;
    }Iterator;

    Iterator * constructor_iterator(Hash * hash)
    {
        Iterator * new_iterator = malloc(sizeof(Iterator));
        new_iterator->array_index = 0;
        new_iterator->current = NULL;
        new_iterator->hash = hash;
        return new_iterator;
    }    

    int iterator_hash(Iterator * iterator,int * value)
    {
        if(!iterator->current)
        {
            while(!iterator->current && iterator->array_index < iterator->hash->size)
            {
                iterator->current = iterator->hash->array[iterator->array_index++];
            }
            if(!iterator->current) return 0;
            *value = iterator->current->data;
            iterator->current = iterator->current->next;    
            return 1;
        }
        *value = iterator->current->data;
        iterator->current = iterator->current->next;
        return 1;
    }

    void add_hash(Hash** hash,int keyHash,int data)
    {
        int key = keyHash% (**hash).size;
        node * new_node = constructor_node(keyHash,data,NULL);
        if(!(**hash).array[key])
        {
            (**hash).array[key] = new_node;
            return;
        }
        node * current = (**hash).array[key];
        int count = 0;
        while (current->next)
        {
            current = current->next;
            count ++;
        }
        if(count>(**hash).size/2)
        {
            Hash * new_hash = constructor_hash((**hash).size*2);
            Iterator * iterator = 
        }
        current->next = new_node;
    }
    
/// ########




    