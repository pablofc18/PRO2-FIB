  #include "Cjt_estudiants.hh"

  Cjt_estudiants::Cjt_estudiants()
  /* Pre: cert */
  /* Post: el resultat  ́es un conjunt d’estudiants buit */
  {
    nest = 0;
    vest = vector<Estudiant>(MAX_NEST);
  }

  Cjt_estudiants::~Cjt_estudiants(){
  }


  void Cjt_estudiants::afegir_estudiant(const Estudiant &est)
  /* Pre: el par`ametre impl ́ıcit no cont ́e cap estudiant amb el DNI d’est; el
  nombre d’estudiants del p.i. es menor que la mida m`axima permesa */
  /* Post: s’ha afegit l’estudiant est al par`ametre impl ́ıcit */
  {
    int i = nest-1;
    bool b = false;
    int dni = est.consultar_DNI();
    while (i >= 0 and not b) {
      if ( dni > vest[i].consultar_DNI()) b = true;
      else {
        vest[i+1]=vest[i];
        --i;
      }
    }
    // i  ́es la posici ́o m ́es avanc ̧ada amb el DNI m ́es petit que dni, si n’hi ha;
    // si no, i=-1
    vest[i+1] = est;
    ++nest;
  }

  void Cjt_estudiants::ordenar_cjt_estudiants()
  {
    cout << "*";
  }


  int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
  /* Pre: vest[left..right] est`a ordenat creixentment per DNI,
  0<=left, right<vest.size() */
  /* Post: si a vest[left..right] hi ha un element amb DNI = x, el resultat  ́es
  una posici ́o que el cont ́e; si no, el resultat  ́es -1 */
  {
    int i; bool found=false;
    while (left <= right and not found) {
      i = (left + right)/2;
      if (x < vest[i].consultar_DNI()) right = i - 1;
      else if (x > vest[i].consultar_DNI()) left = i + 1;
      else found = true;
    }
    // si l’element buscat existeix, i es la posici ́o que volem
    if (found) return i;
    else return -1;
  }

  void Cjt_estudiants::modificar_estudiant(const Estudiant &est)
  /* Pre: existeix un estudiant al par`ametre impl ́ıcit amb el DNI d’est */
  /* Post: l’estudiant del par`ametre impl ́ıcit amb el DNI d’est
  ha quedat substitu ̈ıt per est */
  {
    // per la Pre, segur que trobem el DNI d’est com a DNI d’algun element
    // de vest[0..nest-1]; apliquem-hi la cerca dicot`omica
    int i = cerca_dicot(vest,0,nest-1,est.consultar_DNI());
    // i  ́es la posici ́o amb el DNI d’est
    vest[i] = est;
  }

  void Cjt_estudiants::modificar_iessim(int i, const Estudiant &est)
  /* Pre: 1 <= i <= nombre d’estudiants del par`ametre impl ́ıcit, l’element i-`essim
  del p. i. en ordre creixent per DNI cont ́e un estudiant amb el mateix DNI que est */
  /* Post: l’estudiant i-`essim del par`ametre impl ́ıcit ha quedat substitu ̈ıt
  per est */
  {
    vest[i - 1]= est;
  }

  int Cjt_estudiants::mida() const
  /* Pre: cert */
  /* Post: el resultat  ́es el nombre d’estudiants del par`ametre impl ́ıcit */
  {
    return nest;
  }

  int Cjt_estudiants::mida_maxima()
  /* Pre: cert */
  /* Post: el resultat  ́es el nombre maxim d’estudiants que pot arribar
  a tenir el par`ametre impl ́ıcit */
  {
    return MAX_NEST;
  }

  bool Cjt_estudiants::existeix_estudiant(int dni) const
  /* Pre: dni >= 0 */
  /* Post: el resultat indica si existeix un estudiant al par`ametre
  impl ́ıcit amb DNI = dni */
  {
    // apliquem la cerca dicot`omica a l’interval [0..nest-1]
    int i = cerca_dicot(vest,0,nest-1,dni);
    return (i!=-1);
  }

  Estudiant Cjt_estudiants::consultar_estudiant(int dni) const
  /* Pre: existeix un estudiant al par`ametre impl ́ıcit amb DNI = dni */
  /* Post: el resultat  ́es l’estudiant amb DNI = dni que cont ́e el
  par`ametre impl ́ıcit */
  {
    // per la Pre, segur que trobem dni com a DNI d’algun element
    // de vest[0..nest-1]; apliquem-hi la cerca dicot`omica
    int i = cerca_dicot(vest,0,nest-1,dni);
    // i  ́es la posici ́o amb DNI = dni
    return vest[i];
  }

  Estudiant Cjt_estudiants::consultar_iessim(int i) const
  /* Pre: 1 <= i <= nombre d’estudiants que cont ́e el par`ametre impl ́ıcit */
  /* Post: el resultat  ́es l’estudiant i-`essim del par`ametre impl ́ıcit
  en ordre creixent per DNI */
  {
    return vest[i - 1];
  }

  void Cjt_estudiants::llegir()
  /* Pre: estan preparats al canal est`andar d’entrada un enter entre 0 i
  la mida m`axima permesa, que representa el nombre d’elements que llegirem,
  i les dades de tal nombre d’estudiants */
  /* Post: el par`ametre impl ́ıcit cont ́e el conjunt d’estudiants llegits
  del canal est`andard d’entrada */
  {
    cin >> nest;
    for (int i = 0; i < nest; ++i) vest[i].llegir(); // llegir de la classe Estudiant
    ordenar_cjt_estudiants(); // noteu que l’apliquem sobre el p. i.
  }

  void Cjt_estudiants::escriure() const
  /* Pre: cert */
  /* Post: s’han escrit pel canal est`andard de sortida els estudiants del
  par`ametre impl ́ıcit en ordre ascendent per DNI */
  {
    for (int i = 0; i < nest; ++i) vest[i].escriure(); // id. escriure
  }
