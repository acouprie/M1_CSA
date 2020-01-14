#ifndef List_H
#define List_H

#include <iostream>
using namespace std;


typedef void* ent;

struct Link{
  Link* next;
  Link *previous;
  ent e;
  Link(ent a, Link* n, Link *p)
      { e = a; next = n; previous = p;}
  };

class List
{
  friend class List_iterator;

  protected:
  Link* last, *current;
  unsigned lg;
  short num_current;

    void clear();        // destruction of the List
  public:
    unsigned length() const { return lg; } //List.lenght
    int insert(ent a);  // before current
    int append(ent a);  // after  current
    int detruire();     // delete current
    ent getfirst();     // from head
    ent getlast();      // efrom queue
    ent readcurrent();
    ent GetItem(unsigned IND);
    int gotonext();
    int gotoprevious();       // element precedent
    int gotobegin(); // se placer en debut de List
    int gotolast(); // se placer en fin de List
    int atlast(); // retour vrai si current = dernier
    int atbegin(); // retour vrai si current = premier

    List();
    virtual ~List(){ clear(); }
    void Edit(ostream &OUTPUT);
    short GetCurrentNumber(){ return num_current; }
  };

class List_iterator
   {
   Link *ce;
   const List *cs;
   public:
     List_iterator(const List& s)
       {
       cs = &s; ce = cs->last;
       }
     ent operator()()
        {
        ent ret = ce?(ce=ce->next)->e:0;
        if (ce == cs->last)ce=0;
        return ret;
        }
   };

#endif

