
#include "List.h"

const char *LISTE_ERREUR = "List";

List::List()
{
  last = current = 0;
  lg = 0;
  num_current = 1;
}

int List::insert(ent a)
{
  Link *nouveau;

  if (current) // file non vide
    {
    nouveau = new Link(a, current,current->previous);
    current->previous = nouveau;
    nouveau->previous->next = nouveau;
    }
  else
    { // file vide
    last = nouveau = new Link(a,0,0);
    last->next=last;
    last->previous = last;
    num_current = 1;
    }
  current = nouveau;
  lg++;
  return 0;
}

int List::append(ent a)
{
  Link *nouveau;

  if (current)
    {// file non vide
    nouveau = new Link(a,current->next, current);
    current->next->previous = nouveau;
    current->next = nouveau;
    num_current++;
    if (current == last)
       last = nouveau;
    }
  else
    { // file vide
    nouveau = last = new Link(a, 0, 0);
    last->next=last;
    last->previous = last;
    num_current = 1;
    }
  current = nouveau;
  lg++;
  return 0;
}

int List :: detruire()
{
  Link *detruit = current;

  if (current==0) return 0;
  if (current->next == current)
     // destruction du dernier
     {
     current = last = 0;
     num_current = 1;
     }
  else
    if (current == last)
      {
      current = last->previous;
      current->next = last->next;
      last->next->previous = current;
      last = current;
      num_current--;
      }
    else
      {
      current = current->next;
      current->previous = detruit->previous;
      detruit->previous->next = current;
      }

  delete detruit;
  lg--;
  return 1;
}

ent List::getfirst()
{
  if (last==0) return 0;
  Link* f=last->next;
  ent r = f->e;
  if (f==last)
    last= current = 0;
  else
    {last->next = current = f->next;
    f->next->previous = f->previous;}
  delete f;
  lg--;
  return r;
}

ent List::getlast()
{
  if (last==0) return 0;
  ent r = last->e; // element en queue
  Link* f=last;
  lg--;
  if (last->next==last)
    last=current=0;
  else
        {
        last = current = f->previous;
        last->next = f->next;
        f->next->previous = last;
        num_current--;
        }
  delete f;
  return r;
}

ent List::readcurrent()
{
  if (last == 0)
      return 0;
  return current->e;
}

int List::gotonext()
{
  if (last == 0)
      return 1;  // List vide

  if ((lg == 1) || (current == last))
     return 1;  // pas de next
  current = current->next;
  num_current++;
  return 0;
}

int List::gotoprevious()
{
  if (last == 0)
      return 1;  // List vide

  if ((lg == 1) || (current == last->next))
     return 1;  // pas de previous
  current = current->previous;
  num_current--;
  return 0;
}

int List::gotobegin()
{
  if (last == 0) return 1;
  num_current = 1;
  current = last->next;
  return 0;
}

int List::gotolast()
{
  if (last == 0) return 1;
  current = last;
  num_current = lg;
  return 0;
}

int List::atlast()
{
  if (last == 0) return 1;
  return (current == last);
}

int List::atbegin()
{
  if (last == 0) return 1;
  return (current == last->next);
}

void List::clear()
{
  Link* l=last;
  if (l!=0)
    do
      {
      Link* ll=l;
      l=l->next;
      delete ll;
      }
    while (l!=last);
  last = current = 0;
  lg = 0;
  num_current = 1;
}

ent List::GetItem(unsigned IND)
{
   if (IND >= lg)
    return 0;

  List_iterator NEXT(*this);
  ent PTR;
  unsigned I;
  for (I = 0; I <= IND; I++)
	{
    PTR = NEXT();
	}
  return PTR;
}

void List::Edit(ostream &OUTPUT)
{
  List_iterator NEXT(*this);
  void *PTR;
  int I = 0;

  OUTPUT << LISTE_ERREUR << "lg " << lg << " num_current " << num_current;
  while ((PTR = NEXT()))
    OUTPUT << LISTE_ERREUR << "Element " << I++ << " = " << long(PTR) << endl;
}
