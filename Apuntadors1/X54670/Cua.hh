#ifndef CUA
#define CUA

#include "utils.PRO2"

template <class T> class Cua {
  friend class Test1;
private:
  struct node_cua {
    T info;
    node_cua* seguent;
  }; 
  int longitud;
  node_cua* primer_node;
  node_cua* ultim_node;

static node_cua* copia_node_cua(node_cua* m, node_cua* &u) 
    /* Pre: cert */
    /* Post: si m �s NULL, el resultat i u s�n NULL; en cas contrari, 
       el resultat apunta al primer node d'una cadena de nodes que s�n c�pia de
       de la cadena que t� el node apuntat per m com a primer, i u apunta a 
       l'�ltim node */
  { 
    // op. privada
    node_cua* n;
    if (m==NULL) {n=NULL; u=NULL;}
    else {
      n = new node_cua;
      n->info = m->info;
      n->seguent = copia_node_cua(m->seguent, u);
      if (n->seguent == NULL) u = n; 
    }
    return n;
  }



static void esborra_node_cua(node_cua* m) 
    /* Pre: cert */
    /* Post: no fa res si m �s NULL, en cas contrari, allibera espai
       dels nodes de la cadena que t� el node apuntat per m com a
       primer */
  {
     if (m != NULL) {
      esborra_node_cua(m->seguent);
      delete m;
     }
  }


public:

  Cua() 
    /* Pre: cert */
    /* Post: El resultat �s una cua sense cap element */
  {
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
  }

  Cua(const Cua& original) 
    /* Pre: cert */
    /* Post: El resultat �s una c�pia d'original */
  {
    longitud= original.longitud;
    primer_node= copia_node_cua(original.primer_node,ultim_node);
 }


  ~Cua() 
    // Destructora: Esborra autom�ticament els objectes locals en
    // sortir d'un �mbit de visibilitat
  {
    esborra_node_cua(primer_node);
  }

  void c_buida() 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una cua sense elements i qualsevol
       contingut anterior del p.i. ha estat esborrat */
  {
    esborra_node_cua(primer_node);
    longitud= 0;
    primer_node= NULL;
    ultim_node= NULL;
  }
        
  void demanar_torn (const T& x) 
    /* Pre: cert */
    /* Post: El p.i. �s com el p.i. original amb x afegit
       com a darrer element */
  {
    node_cua* aux;
    aux= new node_cua; // reserva espai pel nou element
    aux->info= x;
    aux->seguent= NULL;
    if (primer_node == NULL) primer_node= aux;
    else ultim_node->seguent= aux;
    ultim_node= aux;
    ++longitud;
  }

  void avancar () 
    /* Pre: el p.i. �s una cua no buida (<=> primer_node != NULL) */ 
    /* Post: El p.i. �s com el p.i. original per� sense el primer
       element afegit al p.i. original */
  {
    node_cua* aux;
    aux= primer_node; // conserva l'acc�s al primer node abans d'avan�ar
    if (primer_node->seguent == NULL) {
      primer_node= NULL;  ultim_node= NULL;
    }
    else primer_node= primer_node->seguent; // avan�a
    delete aux; // allibera l'espai de l'antic cim
    --longitud;
  }
   
  T primer() const 
    /* Pre: el p.i. �s una cua no buida (<=> primer_node != NULL) */
    /* Post: el resultat �s el primer element afegit al p.i. */ 
  {
    return primer_node->info;
  }

  bool es_buida() const 
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. �s una cua buida o no */
  {
    return longitud==0;
  }

  int mida() const 
    /* Pre: cert */
    /* Post: El resultat �s el nombre d'elements del p.i. */
  {
    return longitud;
  }




};



#endif
