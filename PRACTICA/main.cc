/**
 * @mainpage Campeonato de torneos de tenis

Práctica PRO2 donde se construye un circuito de torneos de tenis... Se introducen
las clases <em>Circuito</em>, <em>Torneo</em>, <em>Categoria</em>, <em>Jugador</em>,
<em>Cjt_Categorias</em>, <em>Cjt_Jugadores</em>.

*/

/** @file main.cc
    @brief Programa principal para la práctica de PRO2,  <em>Circuito de torneos de tenis</em>.
*/


#include "Circuito.hh"
// #include "Torneo.hh"
// #include "Categoria.hh"
#include "Cjt_Categorias.hh"
// #include "Jugador.hh"
#include "Cjt_Jugadores.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif


int main() {

  // Circuito circ;
  Cjt_Categorias cjt_categ;
  Cjt_Jugadores cjt_jug;

  // Lee número categorias C >= 1 y niveles K >= 4 ambos constantes.
  // Y seguidamente C strings con los nombres asociados a las categorias, orden creciente
  cjt_categ.leer_categorias_niveles();
  // Lee C * K enteros >= 0 que serán los puntos por categoria y nivel ordenados crecientemente (categoria, nivel)
  cjt_categ.leer_puntos_por_categoria_nivel();
  // Lee número inicial de torneos T >= 0 y una secuencia de T pares string, int nombre y categoria
//  circ.leer_cjt_torneos();
  // Lee número inicial de jugadores P >= 0 y una secuencia de P strings con los nombres de los jugadores
  cjt_jug.leer_jugadores();

  string opc; cin >> opc;
  while (opc != "fin") {

    // 1
    if (opc == "nuevo_jugador" or opc == "nj") {
      string nombre_jug; cin >> nombre_jug;
      // Si no existe el jugador con ese identificador, añadirlo
      if (not cjt_jug.existe_jugador(nombre_jug)) {
        Jugador p(nombre_jug);
        cjt_jug.anadir_jugador(p);
        cout << "Número jugadores totales: " << cjt_jug.numero_jugadores_totales();
        cout << endl;
      }
      else {
        cout << "Ya existe un jugador con ese nombre" << endl;
      }
    }

    // 2
    // else if (opc == "nuevo_torneo" or opc == "nt") {
    //   string nombre_torneo; cin >> nombre_torneo;
    //   int id_categ; cin >> id_categ;
    //   // Si la categoria es correcta y no existe ese torneo, añadirlo
    //   if (cjt_categ.es_correcta_categoria(id_categ)) {
    //     if (not circ.existe_torneo(nombre_torneo)) {
    //       Categoria c(id_categ);
    //       Torneo t(nombre_torneo, c);
    //       circ.anadir_torneo(t);
    //       cout << "Número de torneos totales: " << Circuito::numero_torneos_totales();
    //       cout << endl;
    //     }
    //     else {
    //       cout << "Ya existe un torneo con ese nombre" << endl;
    //     }
    //   }
    //   else {
    //     cout << "La categoria no es correcta" << endl;
    //   }
    // }

    // 3
    else if (opc == "baja_jugador" or opc == "bj") {
      string nombre_jug; cin >> nombre_jug;
      // Si existe ese jugador, añadirlo
      if (cjt_jug.existe_jugador(nombre_jug)) {
        cjt_jug.eliminar_jugador(nombre_jug);
        // Al eliminar jugador ya se actualiza el ranking y la lista
        cout << "Número jugadores totales: " << cjt_jug.numero_jugadores_totales();
        cout << endl;
      }
      else {
        cout << "No existe el jugador con ese nombre" << endl;
      }
    }

    // 4
    // else if (opc == "baja_torneo" or opc == "bt") {
    //   string nombre_torneo; cin >> nombre_torneo;
    //   // Si existe el torneo, eliminarlo
    //   if (circ.existe_torneo(nombre_torneo)) {
    //     // Actualiza ranking si se ha jugado ese torneo
    //     if (circ.torneo_disputado(nombre_torneo)) {
    //       cjt_jug.actualizar_ranking(cjt_categ.consultar_puntos_categ_nivel(), circ.consultar_torneo(nombre_torneo).consultar_jugadores_del_torneo());
    //     }
    //     // Elimina torneo
    //     circ.eliminar_torneo(nombre_torneo);
    //
    //     cout << "Número de torneos totales: " << Circuito::numero_torneos_totales();
    //     cout << endl;
    //   }
    //   else {
    //     cout << "No existe ningún torneo con ese nombre" << endl;
    //   }
    // }
    //
    // // 5
    // else if (opc == "iniciar_torneo" or opc == "it") {
    //   string nombre_torneo; cin >> nombre_torneo;
    //   // Si existe el Torneo y no se ha iniciado antes, inciar
    //   if (circ.existe_torneo(nombre_torneo) and not circ.consultar_torneo(nombre_torneo).torneo_iniciado()) {
    //     circ.iniciar_torneo(nombre_torneo);
    //     // Imprime el cuadro de emparejamientos
    //     circ.consultar_torneo(nombre_torneo).escribir_cuadro_emparejamientos();
    //   }
    //   else cout << "Torneo no existe o se ha iniciado anteriormente" << endl;
    // }
    //
    // // 6
    // else if (opc == "finalizar_torneo" or opc == "ft") {
    //   string nombre_torneo; cin >> nombre_torneo;
    //   // Si existe el torneo y se ha iniciado anteriormente, finalizamos
    //   if (circ.existe_torneo(nombre_torneo)) {
    //     if (circ.consultar_torneo(nombre_torneo).torneo_iniciado() and not circ.consultar_torneo(nombre_torneo).torneo_finalizado()) {
    //       // (Actulizar ranking, datos jugadores...)
    //       circ.finalizar_torneo(nombre_torneo);
    //       // Imprime el cuadro de resultados
    //       Torneo t = circ.consultar_torneo(nombre_torneo);
    //       t.escribir_resultados_torneo();
    //       // Listar puntos -> participantes (orden ranking en el momento de iniciar torneo)
    //       t.escribir_particip_puntos_ganados();
    //     }
    //   }
    //   else cout << "No existe el Torneo con ese nombre" << endl;
    // }

    // 7
    else if (opc == "listar_ranking" or opc == "lr") {
      // cjt_jug.escribir_ranking();
    }

    // 8
    else if (opc == "listar_jugadores" or opc == "lj") {
      cjt_jug.escribir_jugadores();
    }

    // 9
    else if (opc == "consultar_jugador" or opc == "cj") {
      string nombre_jug; cin >> nombre_jug;
      // Si existe el jugador, escribir datos
      if (cjt_jug.existe_jugador(nombre_jug)) {
        cjt_jug.consultar_jugador(nombre_jug).escribir_jug();
      }
      else {
        cout << "No existe el jugador con ese nombre" << endl;
      }
    }

    // 10
    // else if (opc == "listar_torneos" or opc == "lt") {
    //   circ.escribir_torneos();
    // }

    // 11
    else if (opc == "listar_categorias" or opc == "lc") {
      cjt_categ.escribir_categorias_puntos();
    }

    cin >> opc;
  }
}
