#ifndef RAGUI_DISTRIBUTED_HASHTABLE_HPP
#define RAGUI_DISTRIBUTED_HASHTABLE_HPP

class Unit
{
  int previous, next;
};

class Entity
{
  Unit *head;
  
public:
  Entity(Unit *head) : head(head) {}
};

class DistributedHashtable
{
public:
  int init_hashtable();
};

class ArbitraryEntities
{
};

class EntityBundle
{
};

#endif // RAGUI_DISTRIBUTED_HASHTABLE_HPP